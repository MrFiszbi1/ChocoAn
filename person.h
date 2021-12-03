#ifndef __PERSON_H_
#define __PERSON_H_

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <list>
#include <iterator>

#include "serviceDirectory.h"

using namespace std;

const int MAX = 100;

class person
{
public:
	person();
	person(const person &);
	~person();
	void add();
  void display() const;
  //virtual void update_userdata()=0;
  //virtual void add_record(const member &) = 0;
  void update_address();
  //Permissoion levels: member = 1, providor = 2, manager = 3
  void update_permission(const int);
  bool check_manager();
  bool check_member();
  bool check_providor();
  bool find_user(const char *);
  char * get_name();
  char * get_id();
  //friend istream & operator >>(istream &, person &);
  //friend ostream & operator <<(ostream &, const person &);

private:
	char * name;
	char * address;
	char * id;
	int zip;
	int permission;
};

class member : public person
{
public:
	member();
	member(const member &);
	~member();
  void add();
  void display() const;
  //will update members standing
  void update_userdata();
  void add_services(const Service_info &);
  void display_services();
  //remove based off of comapring names of services. input should be service name.
  void remove_services(const char *);


private:
	bool standing;	//The standing of the member. 0 = good standing, 1 = suspended.
  list <Service_info> services;
  list <Service_info> :: iterator it;

};

class provider : public person
{
public:
	provider();
	provider(const provider &);
	~provider();
  void add();
  void display() const;
  //will update the number of members
  void update_userdata();
  void add_record(const member &);
  void display_records();
  void remove_record(const char *);
private:
	int number;
  int member_count;
  //keeps a record of the member it provides too.
  list <member> records;
  list <member> :: iterator it;
};

class manager : public person
{
public:
	manager();
	manager(const manager &);
	~manager();
  void add();
  void display() const; 
  //void update_userdata(); 
  //void add_record(const member &);
};

#endif
