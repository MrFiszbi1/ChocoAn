#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

const int SIZE = 100;

//base class for member, provider, and manager
class person
{

    public:
    
        //default constructor
        person(){};
        //this is the constructor for person
        person(char *name);

        //this is the destructor for person
        ~person();

        //this is the copy constructor for person
        person(const person &to_copy);

        //this is the "getter" for left in the person class
        person *&get_left();

        //this is the "setter" for left in the person class
        void set_left(person *to_set);

        //this is the "getter" for right for the person class
        person *&get_right();

        //this is the setter for right for the person class
        void set_right(person *to_set);

        //this is the "getter" for the id
        int get_id();

        //this is the "setter" for the id
        void set_id(int to_set);

        //this is the "getter" for the zip
        int get_zip();

        //this is the "setter" for the zip
        void set_zip(int to_set);

        //this is the "getter" for the height
        int get_height();

        //this is the "setter" for the id
        void set_height(int to_set);

        //this is the "getter" for name
        char *get_name();

        //this is the "setter" for the name
        void set_name(char *to_set);

        //this is the "getter" for address
        char *get_address();

        //this is the "setter" for the address
        void set_address(char *to_set);

        //this is the "getter" for city
        char *get_city();

        //this is the "setter" for the city
        void set_city(char *to_set);

        //this is the "getter" for state
        char *get_state();

        //this is the "setter" for the state
        void set_state(char *to_set);

    protected:

        //user info
        char *name;
        int id; //this is what the tree is sorted by
        char *address;
        char * city;
        char * state;
        int zip;

        //node
        person *left;
        person *right;
        int height;
};