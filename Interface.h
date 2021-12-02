// This code is to make the interface class and its functions' prototype and members
using namespace std;

// class interfaces
class Interface
{
	public:
		Interface(); //default constructor, initialize data members to zero
		~Interface(); //deallocate any dynamic memory and reset data members to zero
		void log_in(); // To login as a user into the ChocoAn apps
		void member_option(); // To print the member option
		void provider_option(); // To print the provider option
		void manager_option(); // To print the manager option
};