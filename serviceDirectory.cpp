#include "serviceDirectory.h"
//BEGINNING OF SERVICE INFO F(X)'S
//
//CONSTRUCTORS---------------------------------
Service_info::Service_info()
{
  date = NULL;
  service_name = NULL;
  comments = NULL;
}

Service_info::Service_info(char *date, char * service_name, int service_code,int prov_num,int mem_num,   float fee, char * comments)
{
  this->date = new char[strlen(date)+1];
  strcpy(this->date, date);

  this->service_name = new char[strlen(service_name)+1];
  strcpy(this->service_name, service_name);

  this->comments = new char[strlen(comments)+1];
  strcpy(this->comments, comments);

  this->service_code = service_code;
  this->fee = fee;
  this->provider_num= provider_num;
  this->member_num= member_num;
}

Service_info::Service_info(const Service_info &src)
{
  if(src.date)
  {
    this->date = new char[strlen(src.date)+1];
    strcpy(this->date, src.date);
  }
  else 
    this->date = NULL;

  if(src.service_name)
  {
    this->service_name = new char[strlen(src.service_name)+1];
    strcpy(this->service_name, src.service_name);
  }
  else 
    this->service_name = NULL;
  if(src.comments)
  {
    this->comments = new char[strlen(src.comments)+1];
    strcpy(this->comments, src.comments);
  }
  else 
    this->comments = NULL;

  this->service_code = src.service_code;
  this->fee= src.fee;
  this->provider_num= src.provider_num;
  this->member_num= src.member_num;
}
//GETTERS-------------------------------
char * Service_info::get_date() const
{
  return date;
}
char * Service_info::get_name() const
{
  return service_name;
}
int Service_info::get_provider_num() const
{
  return provider_num;
}
int Service_info::get_member_num() const
{
  return member_num;
}

int Service_info::get_service_code() const
{
  return service_code;
}

float Service_info::get_fee() const
{
  return fee;
}
char * Service_info::get_comments() const
{
  return comments;
}
//SETTERS-------------------------------
void Service_info::set_date(char *date) 
{
  this->date = date;
}
void Service_info::set_name(char * name) 
{
  this->service_name= name;
}
void Service_info::set_provider_num(int provider_num) 
{
  this->provider_num= provider_num;
}
void Service_info::set_member_num(int member_num) 
{
  this->member_num= member_num;
}

void Service_info::set_service_code(int service_code) 
{
  this->service_code= service_code;
}

void Service_info::set_fee(float fee) 
{
  this->fee= fee;
}
void Service_info::set_comments(char *comments) 
{
  this->comments= comments;
}

Service_info::~Service_info()
{
  if(this->date)
    delete [] date;
  if(this->service_name)
    delete [] service_name;
  if(this->comments)
    delete [] comments ;
}
//END OF SERVICE INFO F(X)'S----------------------------------------

//BEGINNING OF NODE F(X)'S------------------------------------------

//Node Constructors
Node::Node()
{
  left = NULL;
  right= NULL;
}
Node::Node(Service_info &src, Node *left, Node *right):my_info(src)
{
  left = NULL;
  right = NULL;
}
Node::Node(const Service_info &src):my_info(src)
{
  left = NULL;
  right = NULL;
}
Node::~Node(){}

int Node::display_one() const
{
  time_t now = time(0);
  char * date_time = ctime(&now);
  cout <<"===================================" << endl;
  cout <<"Current Date: "<< date_time<< endl;
  cout <<"Service Name: "<< my_info.get_name() << endl;
  cout <<"Date of Service: "<< my_info.get_date() << endl;
  cout <<"Service Code: "<< my_info.get_service_code() << endl;
  cout <<"Provider Number: "<< my_info.get_provider_num() << endl;
  cout <<"Member Number: "<< my_info.get_member_num() << endl;
  cout <<"Fee: "<< my_info.get_fee() << endl;
  cout <<"Comments: "<< my_info.get_comments() << endl;
  cout <<"===================================" << endl << endl;
  return 1;
}
bool Node::is_leaf() 
{
  if(get_left()== NULL && get_right() == NULL)
    return true;
  return false;
}
Node *& Node::get_left() 
{
  return left;
}

Node *& Node::get_right() 
{
  return right;
}
Service_info & Node::get_serviceInfo() 
{
  return my_info;
}
void Node::set_left(Node * connect)
{
  left = connect;
}

void Node::set_right(Node * connect)
{
  right = connect;
}
//END OF NODE F(X)'S---------------------------------------------

//BEGINNING OF SERVICE_DIRECTORY F(X)'S -------------------------

Service_directory::Service_directory()
{
  root = NULL;
}
Service_directory::~Service_directory()
{
  remove_all_nodes(root);
}
int Service_directory::add_node(const Service_info &to_add)
{
  return add_node(root,to_add);
}
int Service_directory::add_node(Node *&root, const Service_info &to_add)
{
  if(!root)
    root = new Node(to_add);
  else if(to_add.get_service_code() < root->get_serviceInfo().get_service_code()) 
    add_node(root->get_left(), to_add);
  else 
    add_node(root->get_right(), to_add);
  return 1;
}
Node * Service_directory::findIOS(Node *root, Node * target)
{
  if(!root)
    return NULL;

  if(target->get_right())
  {
    target = target->get_right();
    findIOS(root, target->get_left());
    if(target->get_left()==NULL)
      return target;
  }
  else
  {
    Node *prev = NULL;
    Node *rootHolder = root;
    if(target->get_serviceInfo().get_service_code() < rootHolder->get_serviceInfo().get_service_code())
    {
      prev = rootHolder;
      rootHolder = rootHolder->get_left();
    }
    else
      rootHolder = rootHolder->get_right();
    return prev;
  }
}
Node * Service_directory::findMin(Node *&root)
{
  Node * current = root;
  while(current->get_left() != NULL)
    current = current->get_left();
  return current;
}
int Service_directory::remove_node(const int service_code)
{
  return remove_node(root,service_code);
}
int Service_directory::remove_node(Node *&root, const int service_code)
{
  if(!root)
    return 0;
  else if(service_code < root->get_serviceInfo().get_service_code()) 
    remove_node(root->get_left(), service_code);
  else if(service_code > root->get_serviceInfo().get_service_code()) 
    remove_node(root->get_right(), service_code);
  else 
  {
    if(root->is_leaf())
    {
      delete root;
      root = NULL;
    }
    else if(root->get_left() == NULL)
    {
      Node * temp = root;
      root = root->get_right();
      delete temp;
    }
    else if(root->get_right() == NULL)
    {
      Node * temp = root;
      root = root->get_left();
      delete temp;
    }
    else
    {
      Node * temp = findMin(root->get_right());
      temp->set_right(root->get_right());
      temp->set_left(root->get_left());
      delete root;
      root = temp;
    }
  }
  return 1;
}
int Service_directory::remove_all_nodes()
{
  return remove_all_nodes(root);
}
int Service_directory::remove_all_nodes(Node *&root)
{
  if(!root)
    return 0;
  int count = 1 + remove_all_nodes(root->get_left()) + remove_all_nodes(root->get_right());
  delete root;
  root = NULL;
  return count;
}
int Service_directory::display_by_service_code(int service_code) const
{
  return display_by_service_code(root,service_code);
}
int Service_directory::display_by_service_code(Node * root, int service_code) const
{
  int count = 0;
  if(!root)
    return 0;
  else if(service_code < root->get_serviceInfo().get_service_code()) 
    display_by_service_code(root->get_left(), service_code);
  else if(service_code > root->get_serviceInfo().get_service_code()) 
    display_by_service_code(root->get_right(), service_code);
  else 
    count += 1 + root->display_one();
  return count; 
}
int Service_directory::display_by_date(char *date) const
{
  return display_by_date(root,date);
}
int Service_directory::display_by_date(Node * root, char * date) const
{
  int count = 0;
  if(!root)
    return 0;
  display_by_date(root->get_left(),date);
  if(strcmp(date, root->get_serviceInfo().get_date()) == 0)
    count += 1 + root->display_one();
  display_by_date(root->get_right(),date);
  return count; 
}
int Service_directory::display_all() const
{
  return display_all(root);
}
int Service_directory::display_all(Node * root) const
{
  int count = 0;
  if(!root)
    return 0;
  else
  {
    count = 1 + display_all(root->get_left());
    root->display_one();
    count += display_all(root->get_right());
    return count; 
  }
}
void Service_directory::menu(int &user_input)
{
    cout << "----------------------------------------- " << endl
        << "----------------------------------------- " << endl << endl
        << "Please select from the following options: " <<endl
        << "1. Add a service. " << endl
        << "2. Remove service." << endl
        << "3. Remove all." <<endl
        << "4. Display by service code." <<endl
        << "5. Display by date." <<endl
        << "6. Display all. " <<endl
        << "7. Exit the program. " << endl << endl
        << "----------------------------------------- " << endl
        << "----------------------------------------- " << endl; 
    cin >> user_input;
    cin.ignore(100, '\n');
    //if user inputs wrong menu option
    //display list again
    if(user_input <= 0 || user_input > 7)
    {   
        cout << "----------------------------------------- " << endl
            << "----------------------------------------- " << endl << endl
            << "Please select A VALID option: " <<endl
            << "1. Add a service. " << endl
            << "2. Remove service." << endl
            << "3. Remove all." <<endl
            << "4. Display by service code." <<endl
            << "5. Display by date." <<endl
            << "6. Display all. " <<endl
            << "7. Exit the program. " << endl << endl
            << "----------------------------------------- " << endl
            << "----------------------------------------- " << endl; 
    }   

}
void Service_directory::clear()
{
  for(int i = 0; i<250; ++i)
    cout << '\n';
}








