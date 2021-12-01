#include "userdirectory.h"

// call with data in order of name, ID, address, city, state, then zip code
void userdirectory::insert(char *new_name, int new_id, char *new_address, char *new_city, char *new_state, int new_zip)
{
    root = insert(new_name, new_id, new_address, new_city, new_state, new_zip, root);
}

//call with ChocAn ID Number (9-digit number)
void userdirectory::remove(int new_id)
{
    root = remove(new_id, root);
}

void userdirectory::display()
{
    inorder(root);
    cout << endl;
}

person *userdirectory::insert(char *new_name, int new_id, char *new_address, char *new_city, char *new_state, int new_zip, person *t)
{
    if (t == NULL)
    {
        t = new person;

        t->set_name(new_name);
        t->set_id(new_id);
        t->set_address(new_address);
        t->set_city(new_city);
        t->set_state(new_state);
        t->set_zip(new_zip);

        t->set_height(0);
        t->set_left(NULL);
        t->set_right(NULL);
    }

    else if (new_id < t->get_id())
    {
        t->set_left(insert(new_name, new_id, new_address, new_city, new_state, new_zip, t->get_left()));

        if (height(t->get_left()) - height(t->get_right()) == 2)
        {
            if (new_id < t->get_left()->get_id())
                t = singleRightRotate(t);
            else
                t = doubleRightRotate(t);
        }
    }

    else if (new_id > t->get_id())
    {
        t->set_right(insert(new_name, new_id, new_address, new_city, new_state, new_zip, t->get_right()));
        if (height(t->get_right()) - height(t->get_left()) == 2)
        {
            if (new_id > t->get_right()->get_id())
                t = singleLeftRotate(t);
            else
                t = doubleLeftRotate(t);
        }
    }

    t->set_height(max(height(t->get_left()), height(t->get_right())) + 1);
    return t;
}

person *userdirectory::singleRightRotate(person *&t)
{
    if (t->get_left() != NULL)
    {
        person *u = t->get_left();
        t->set_left(u->get_right());
        u->set_right(t);
        t->set_height(max(height(t->get_left()), height(t->get_right())) + 1);
        u->set_height(max(height(u->get_left()), t->get_height()) + 1);
        return u;
    }
    return t;
}

person *userdirectory::singleLeftRotate(person *&t)
{
    if (t->get_right() != NULL)
    {
        person *u = t->get_right();
        t->set_right(u->get_left());
        u->set_left(t);
        t->set_height(max(height(t->get_left()), height(t->get_right())) + 1);
        u->set_height(max(height(t->get_right()), t->get_height()) + 1);
        return u;
    }
    return t;
}

person *userdirectory::doubleLeftRotate(person *&t)
{
    t->set_right(singleRightRotate(t->get_right()));
    return singleLeftRotate(t);
}

person *userdirectory::doubleRightRotate(person *&t)
{
    t->set_left(singleLeftRotate(t->get_left()));
    return singleRightRotate(t);
}

person *userdirectory::findMin(person *t)
{
    if (t == NULL)
        return NULL;
    else if (t->get_left() == NULL)
        return t;
    else
        return findMin(t->get_left());
}

person *userdirectory::remove(int new_id, person *t)
{
    person *temp;

    if (t == NULL)
        return NULL;

    else if (new_id < t->get_id())
        t->set_left(remove(new_id, t->get_left()));
    else if (new_id > t->get_id())
        t->set_right(remove(new_id, t->get_right()));

    else if (t->get_left() && t->get_right())
    {
        temp = findMin(t->get_right());
        t->set_id(temp->get_id());
        t->set_right(remove(t->get_id(), t->get_right()));
    }

    else
    {
        temp = t;
        if (t->get_left() == NULL)
            t = t->get_right();
        else if (t->get_right() == NULL)
            t = t->get_left();
        delete temp;
    }
    if (t == NULL)
        return t;

    t->set_height(max(height(t->get_left()), height(t->get_right())) + 1);

    if (height(t->get_left()) - height(t->get_right()) == 2)
    {
        if (height(t->get_left()->get_left()) - height(t->get_left()->get_right()) == 1)
            return singleLeftRotate(t);
        else
            return doubleLeftRotate(t);
    }
    else if (height(t->get_right()) - height(t->get_left()) == 2)
    {
        if (height(t->get_right()->get_right()) - height(t->get_right()->get_left()) == 1)
            return singleRightRotate(t);
        else
            return doubleRightRotate(t);
    }
    return t;
}

int userdirectory::height(person *t)
{
    return (t == NULL ? -1 : t->get_height());
}

void userdirectory::inorder(person *t)
{
    if (t == NULL)
        return;
    inorder(t->get_left());
    cout << "Name: " << t->get_name() << endl;
    cout << "9-digit ID: " << t->get_id() << endl;
    cout << "Address: " << t->get_address() << endl;
    cout << "City: " << t->get_city() << endl;
    cout << "State: " << t->get_state() << endl;
    cout << "Zip Code: " << t->get_zip() << endl
         << endl;
    inorder(t->get_right());
}




//just showing examples of the database being run (does not need to be in actual program)
// int main()
// {
//     char name[] = "name";
//     char name2[] = "name2";
//     char name3[] = "name3";
//     char name4[] = "name4";
//     char name5[] = "name5";
//     char address[] = "ex_address";
//     char city[] = "ex_city";
//     char state[] = "ex_state";

//     userdirectory t;

//     //name, 9-digit ID, address, city, state, zip code
//     t.insert(name, 123456789, address, city, state, 32145);
//     t.insert(name2, 432456728, address, city, state, 67542);
//     t.insert(name3, 988024321, address, city, state, 12742);
//     t.insert(name4, 105423567, address, city, state, 89432);
//     t.insert(name5, 757210839, address, city, state, 19854);
//     t.display();
//     t.remove(988024321);
//     t.display();
// }