#include "userdirectory.h"

person::person(char *name)
{
    name = new char[SIZE];
    address = new char[SIZE];
    city = new char[SIZE];
    state = new char[SIZE];
}

//this is the destructor for person
person::~person()
{
    delete[] name;
    name = NULL;

    delete[] address;
    address = NULL;

    delete[] city;
    city = NULL;

    delete[] state;
    state = NULL;
}

//this is the copy constructor for person
person::person(const person &to_copy)
{
    if (to_copy.name)
    {
        name = new char[strlen(to_copy.name) + 1];
        strcpy(name, to_copy.name);
    }
    else
        name = NULL;

    if (to_copy.address)
    {
        address = new char[strlen(to_copy.address) + 1];
        strcpy(address, to_copy.address);
    }
    else
        address = NULL;

    if (to_copy.city)
    {
        city = new char[strlen(to_copy.city) + 1];
        strcpy(city, to_copy.city);
    }
    else
        city = NULL;

    if (to_copy.state)
    {
        state = new char[strlen(to_copy.state) + 1];
        strcpy(state, to_copy.state);
    }
    else
        state = NULL;
}

//this is the "getter" for left in the person class
person *& person::get_left()
{
    return left;
}

//this is the "setter" for left in the person class
void person::set_left(person *to_set)
{
    if (to_set == NULL)
        left = NULL;
    else
        left = to_set;
}

//this is the "getter" for right for the person class
person *& person::get_right()
{
    return right;
}

//this is the setter for right for the person class
void person::set_right(person *to_set)
{
    if (to_set == NULL)
        right = NULL;
    else
        right = to_set;
}

//this is the "getter" for the id
int person::get_id()
{
    return id;
}

//this is the "setter" for the id
void person::set_id(int to_set)
{
    id = to_set;
}

//this is the "getter" for the zip
int person::get_zip()
{
    return zip;
}

//this is the "setter" for the zip
void person::set_zip(int to_set)
{
    zip = to_set;
}

//this is the "getter" for the height
int person::get_height()
{
    return height;
}

//this is the "setter" for the id
void person::set_height(int to_set)
{
    height = to_set;
}

//this is the "getter" for name
char * person::get_name()
{
    return name;
}

//this is the "setter" for the name
void person::set_name(char *to_set)
{
    name = new char[strlen(to_set) + 1];
    strcpy(name, to_set);
}

//this is the "getter" for address
char * person::get_address()
{
    return address;
}

//this is the "setter" for the address
void person::set_address(char *to_set)
{
    address = new char[strlen(to_set) + 1];
    strcpy(address, to_set);
}

//this is the "getter" for city
char * person::get_city()
{
    return city;
}

//this is the "setter" for the city
void person::set_city(char *to_set)
{
    city = new char[strlen(to_set) + 1];
    strcpy(city, to_set);
}

//this is the "getter" for state
char * person::get_state()
{
    return state;
}

//this is the "setter" for the state
void person::set_state(char *to_set)
{
    state = new char[strlen(to_set) + 1];
    strcpy(state, to_set);
}




