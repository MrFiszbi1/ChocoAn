#include <iostream>;
#include "Interface.h";
using namespace std;

const int SIZE = 200;

Interface::Interface() {}

Interface::~Interface() {}

void Interface::log_in()
{
	int option = 0;
	//prompt the user to select an option
	cout << "\n**********Choco An**********\n\n"
		 << "Welcome to ChocoAn Application\nPlease Select one of the options:\n\n"
		 << "1 - Log in\n\n"
		 << "2 - Exit\n\n";
	cin >> option;
	cin.ignore(100, '\n');

	if (option == 1)
	{
		option = 0;
		cout << "\n**********Choco An**********\n\n"
			 << "Please Select one of the options:\n\n"
			 << "1 - Member\n\n"
			 << "2 - provider\n\n"
			 << "3 - Manager\n\n"
			 << "4 - Exit\n\n";
		cin >> option;
		cin.ignore(100, '\n');
		if (option == 1)
		{
			// call login function of the users class
			// if login was successfull call the member option function
			member_option();
			// otherwise call the login function again
		}
		if (option == 2)
		{
			//call login function of the users class
			// if login was successfull call the provider option function
			provider_option();
			// otherwise call the login function again
		}
		if (option == 3)
		{
			//call login function of the users class
			// if login was successfull call the manager option function
			manager_option();
			// otherwise call the login function again
		}
		if (option == 4)
		{
			return;
		}
	}

	if (option == 2)
	{
		return;
	}
}

void Interface::member_option() {
	int option = 0;
	cout << "\n**********Choco An**********\n\n"
			<< "Please Select one of the options:\n\n"
			<< "1 - Summary of used services\n\n"
			<< "2 - Log out\n\n";
	cin >> option;
	cin.ignore(100, '\n');
	if (option == 1)
	{
		/* code */
	}
	if (option == 2)
	{
		log_in();
	}
}

void Interface::provider_option() {
	int option = 0;
	char name[SIZE];
	char address[SIZE];
	char city[SIZE];
	int zip_code = 0;
	int id = 0;
	cout << "\n**********Choco An**********\n\n"
			<< "Please Select one of the options:\n\n"
			<< "1 - Add a member\n\n"
			<< "2 - Remove a member\n\n"
			<< "3 - Report of used services for a member\n\n"
			<< "4 - Find a service by the service id\n\n"
			<< "5 - List of all services\n\n"
			<< "6 - Log out\n\n";
	cin >> option;
	cin.ignore(100, '\n');
	switch (option)
	{
	case 1:
		option = 0;
		cout << "\n**********Choco An**********\n\n"
			<< "Please enter required information:\n\n"
			<< "Member's name:\n\n";
		cin.get(name, SIZE, '\n');
		cin.ignore(100, '\n');

		cout << "\n**********Choco An**********\n\n"
			<< "Please enter required information:\n\n"
			<< "Member's address:\n\n";
		cin.get(address, SIZE, '\n');
		cin.ignore(100, '\n');

		cout << "\n**********Choco An**********\n\n"
			<< "Please enter required information:\n\n"
			<< "Member's city:\n\n";
		cin.get(city, SIZE, '\n');
		cin.ignore(100, '\n');

		cout << "\n**********Choco An**********\n\n"
			<< "Please enter required information:\n\n"
			<< "Member's Zip code:\n\n";
		cin >> zip_code;
		cin.ignore(100, '\n');

		// call add user function of the user directory class
		provider_option();
		break;
	
	case 2:
	    id = 0;
		cout << "\n**********Choco An**********\n\n"
			<< "Please enter the member id:\n\n";
		cin >> id;
		cin.ignore(100, '\n');

		// call remove user function of the user directory class
		provider_option();
		break;

	case 3:
		id = 0;
		cout << "\n**********Choco An**********\n\n"
			<< "Please enter the member id:\n\n";
		cin >> id;
		cin.ignore(100, '\n');

		// call display services of the user directory class
		provider_option();
		break;

	case 4:
		id = 0;
		cout << "\n**********Choco An**********\n\n"
			<< "Please enter the service id:\n\n";
		cin >> id;
		cin.ignore(100, '\n');

		// call find service of the service directory class
		provider_option();
		break;

	case 5:
		// call display all service of the service directory class
		
		// after displaying the list the user ables to get back to the main menu 
		provider_option();

		break;

	case 6:
		log_in();
		break;

	default:
		break;
	}
}

void Interface::manager_option() {
	int option = 0;
	char name[SIZE];
	char address[SIZE];
	char city[SIZE];
	int zip_code = 0;
	int id = 0;
	cout << "\n**********Choco An**********\n\n"
			<< "Please Select one of the options:\n\n"
			<< "1 - Add a provider\n\n"
			<< "2 - Remove a provider\n\n"
			<< "3 - List of all services\n\n"
			<< "4 - Find a service by the service id\n\n"
			<< "5 - Log out\n\n";
	cin >> option;
	cin.ignore(100, '\n');
	switch (option)
	{
	case 1:
		option = 0;
		cout << "\n**********Choco An**********\n\n"
			<< "Please enter required information:\n\n"
			<< "provider's name:\n\n";
		cin.get(name, SIZE, '\n');
		cin.ignore(100, '\n');

		cout << "\n**********Choco An**********\n\n"
			<< "Please enter required information:\n\n"
			<< "provider's address:\n\n";
		cin.get(address, SIZE, '\n');
		cin.ignore(100, '\n');

		cout << "\n**********Choco An**********\n\n"
			<< "Please enter required information:\n\n"
			<< "provider's city:\n\n";
		cin.get(city, SIZE, '\n');
		cin.ignore(100, '\n');

		cout << "\n**********Choco An**********\n\n"
			<< "Please enter required information:\n\n"
			<< "provider's Zip code:\n\n";
		cin >> zip_code;
		cin.ignore(100, '\n');

		// call add provider function of the user directory class
		provider_option();
		break;
	
	case 2:
	    id = 0;
		cout << "\n**********Choco An**********\n\n"
			<< "Please enter the provider id:\n\n";
		cin >> id;
		cin.ignore(100, '\n');

		// call remove provider function of the user directory class
		provider_option();
		break;

	case 3:
		id = 0;
		cout << "\n**********Choco An**********\n\n"
			<< "Please enter the member id:\n\n";
		cin >> id;
		cin.ignore(100, '\n');

		// call display services of the user directory class
		provider_option();
		break;

	case 4:
		// call display all service of the service directory class
		
		// after displaying the list the user ables to get back to the main menu 
		provider_option();

		break;

	case 5:
		log_in();
		break;

	default:
		break;
	}
}