#include "person.h"

//Default constructor, initialize all values to NULL or 0.
person::person() : name(NULL), address(NULL), zip(0), id(0), permission(1) {}

//Copy constructor.
person::person(person& to_copy)
{

}

//Destructor.
person::~person()
{
	if (name)
		delete name;
	if (address)
		delete address;
	name = NULL;
	address = NULL;
	zip = 0;
	id = 0;
	permission = 0;
}

