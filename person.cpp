#include "person.h"

//Default constructor, initialize all values to NULL or 0.
person::person() : name(NULL), address(NULL), id(NULL), zip(0), permission(1) {}

//Copy constructor.
person::person(const person & to_copy): name(NULL), address(NULL), id(NULL), zip(0), permission(1)
{
  if(name)
    delete[] name;
  if(address)
    delete[] address;
  if(id)
    delete[] id;

  name = new char[strlen(to_copy.name)+1];
  strcpy(name, to_copy.name);

  address = new char[strlen(to_copy.address)+1];
  strcpy(address, to_copy.address);

  id = new char[strlen(to_copy.id)+1];
  strcpy(id, to_copy.id);

  zip = to_copy.zip;
  permission = to_copy.permission;
}

//Destructor.
person::~person()
{
	if (name)
		delete[] name;
	if (address)
		delete[] address;
  if(id)
    delete[] id;
}

void person::add()
{
  int num = 0;
  char temp[MAX];
  cout << "Enter the new user's name: ";
  cin.get(temp, MAX, '\n');
  cin.ignore(MAX, '\n');
  name = new char[strlen(temp)+1];
  strcpy(name, temp);

  cout << "Enter the new user's address (include city and state): ";
  cin.get(temp, MAX, '\n');
  cin.ignore(MAX, '\n');
  address = new char[strlen(temp)+1];
  strcpy(address, temp);

  cout << "Enter the new user's zip code: ";
  cin >> num;
  cin.clear();
  cin.ignore(MAX, '\n');
  zip = num;

  do
  {
  cout << "Enter the new user's new 9 digit id number (must be 9 digits): ";
  cin.get(temp, MAX, '\n');
  cin.ignore(MAX, '\n');
  id = new char[strlen(temp)+1];
  strcpy(id, temp);
  num = strlen(temp);
  }while(num != 9);
}

void person::display() const
{
  cout << "Id: " << id << endl;
  cout << "Name: " << name << endl;
  cout << "Address: " << address << endl;
  cout << "Zip Code: " << zip << endl;
  cout << "Permission level: ";
  if(permission == 1)
    cout << "Member" << endl;
  else if(permission == 2)
    cout << "Providor" << endl;
  else if(permission == 3)
    cout << "Manager" << endl;
}

void person::update_address()
{
  int num = 0;
  char temp[MAX];

  if (address)
		delete[] address;
  address = NULL;

  cout << "Enter the user's new address (include city and state): ";
  cin.get(temp, MAX, '\n');
  cin.ignore(MAX, '\n');
  address = new char[strlen(temp)+1];
  strcpy(address, temp);

  cout << "Enter the user's new zip code: ";
  cin >> num;
  cin.clear();
  cin.ignore(MAX, '\n');
  zip = num;
}

void person::update_permission(const int level)
{
  permission = level;
}

bool person::check_manager()
{
  if(permission == 3)
      return true;
  return false;
}

bool person::check_member()
{
  if(permission >= 1)
      return true;
  return false;
}

bool person::check_providor()
{
  if(permission >= 2)
      return true;
  return false;
}

bool person::find_user(const char * to_check){
  if(strcmp(to_check, id) == 0)
      return true;
  return false;
}

char * person::get_name()
{
  return name;
}

char * person::get_id()
{
  return id;
}

member::member(): standing(false) {}

member::member(const member & to_copy): person(to_copy), standing(false)
{
  standing = to_copy.standing;
}
	
member::~member(){}

void member::add()
{
  int num = 0;
  person::add();
  update_permission(1);
  cout << "Standings: 0 is a good standing and 1 is suspended." << endl;
  cout << "Enter the new user's standing (0 or 1): ";
  cin >> num;
  cin.clear();
  cin.ignore(MAX, '\n');
  if(num == 0)
    standing = false;
  else
    standing = true;
}

void member::display() const
{
  cout << endl;
  cout << "User Type: member" << endl;
  person::display();
  cout << "Standing: ";
  if(!standing)
    cout << "Good standing" << endl;
  else
    cout << "Suspended" << endl;
}

void member::update_userdata()
{
  cout << "Current Standing is: ";
  if(!standing)
    cout << "Good standing" << endl;
  else
    cout << "Suspended" << endl;

  int num = 0;
  cout << "Standings: 0 is a good standing and 1 is suspended." << endl;
  cout << "Enter the new user's standing (0 or 1): ";
  cin >> num;
  cin.clear();
  cin.ignore(MAX, '\n');
  if(num == 0)
    standing = false;
  else
    standing = true;
}

void member::add_services(const Service_info & to_copy) 
{
  it = services.begin();
  services.insert(it, to_copy);  
}

void member::display_services()
{
  cout << endl;
  cout << "The name of all services used:" << endl;
  for(it = services.begin(); it != services.end(); ++it)
  {
    cout << it->get_name() << endl;
  }
}

void member::remove_services(const char * to_find)
{
  for(it = services.begin(); it != services.end(); ++it)
  {
    if(strcmp(to_find, it->get_name()) == 0)
    {
      services.erase(it);
      break;
    }
  }
}

provider::provider(): number(0), member_count(0) {}

provider::provider(const provider & to_copy): person(to_copy), number(0), member_count(0) 
{
  number = to_copy.number;
  member_count = to_copy.member_count;
}

provider::~provider() {}

void provider::add()
{
  int num = 0;
  person::add();
  update_permission(2);
  cout << "Enter the providor's phone number :";
  cin >> num;
  cin.clear();
  cin.ignore(MAX, '\n');
  number = num;

  cout << "Enter the number of member that use this providor :";
  cin >> num;
  cin.clear();
  cin.ignore(MAX, '\n');
  member_count = num;
 
}

void provider::display() const
{
  cout << endl;
  cout << "User Type: Provider" << endl;
  person::display();
  cout << "Providor Phone Number: " << number << endl;
  cout << "Number of Members: " << member_count << endl;
}

void provider::update_userdata()
{
  int num = 0;
  cout << "Current Number of Members: " << number << endl;
  cout << "Enter the new number of members: ";
  cin >> num;
  cin.clear();
  cin.ignore(MAX, '\n');
  member_count = num; 
}

void provider::add_record(const member & to_copy) 
{
  it = records.begin();
  records.insert(it, to_copy); 
  member_count++; 
}

void provider::display_records()
{
  cout << endl;
  cout << "The records of all members for this providor:" << endl;
  for(it = records.begin(); it != records.end(); ++it)
  {
    it->display();
  }
}

void provider::remove_record(const char * to_find)
{
  for(it = records.begin(); it != records.end(); ++it)
  {
    if(it->find_user(to_find))
    {
      records.erase(it);
      member_count--;
      break;
    }
  }

}

manager::manager() {}

manager::manager(const manager & to_copy): person(to_copy) {}

manager::~manager() {}

void manager::add()
{
  person::add();
  update_permission(3); 
}

void manager::display() const
{
  cout << endl;
  cout << "User Type: Manager" << endl;
  person::display();
}

/*
void manager::update_userdata() {}

void manager::add_record(const member & to_copy) {}

istream & operator >>(istream & in, person & obj)
{
  obj.add();
  return in;
}

ostream & operator <<(ostream & out, const person & obj)
{
  obj.display();
  return out;
}
*/








