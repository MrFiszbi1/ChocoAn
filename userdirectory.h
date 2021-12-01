//Matthew Pickett

#include "person.h"

//sorts the data by the id from the person class
class userdirectory : public person
{
    protected:
        person *root;

    public:
        //default constructor
        userdirectory()
        {
            root = NULL;
        }

        //constructor with initialization list
        userdirectory(char *str) : person(str){};

        //copy constructor with initialization list
        userdirectory(const userdirectory &to_copy) : person(to_copy){}

        //call with data in order of name, ID, address, city, state, then zip code
        void insert(char *new_name, int new_id, char *new_address, char *new_city, char *new_state, int new_zip);

        //call with ChocAn ID Number (9-digit number)
        void remove(int new_id);

        void display();

        person *insert(char *new_name, int new_id, char *new_address, char *new_city, char *new_state, int new_zip, person *t);

        person *singleRightRotate(person *&t);

        person *singleLeftRotate(person *&t);

        person *doubleLeftRotate(person *&t);

        person *doubleRightRotate(person *&t);

        person *findMin(person *t);

        person *remove(int new_id, person *t);

        int height(person *t);

        //displays the data inorder
        void inorder(person *t);
};