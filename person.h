#include <cctype>

class person
{
public:
	person();
	person(person&)
	~person();
	void copy_person(person&);

private:
	char* name;
	char* address;
	int id;
	int zip;
	const int permission;
};

class member : public person
{
public:
	member();
	member(&member);
	member(&person);
	~member();

private:
	bool standing;	//The standing of the member. 0 = good standing, 1 = suspended.

};

class provider : public person
{
public:
	provider();
	provider(&provider);
	provider(&person);
	~provider();

private:
	int provider_num;
};