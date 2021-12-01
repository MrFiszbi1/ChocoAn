#include <iostream>
#include <cctype> 
#include <cstring> 
#include <cmath> 
#include <ctime> 

using namespace std;

//Service_info is the data container that will be inside the tree nodes
class Service_info
{
  public: 
    //Constructors----------
    Service_info();
    Service_info(char *date, char *service_name, int service_code,int provider,int member_num, float fee, char * comments);
    Service_info(const Service_info &src);//copy constructor
    //getters---------------
    char * get_date() const;
    char * get_name() const;
    int    get_service_code() const;
    int    get_provider_num() const;
    int    get_member_num() const;
    float  get_fee() const;
    char * get_comments() const;
    //setters---------------
    void set_date(char *date);
    void set_name(char *name);
    void set_provider_num(int num);
    void set_member_num(int num);
    void set_service_code(int service_code);
    void set_fee(float fee);
    void set_comments(char *comments);
    //Destructor------------
    ~Service_info();
  private:
    char * date;
    char * service_name;
    int provider_num;
    int member_num;
    int service_code;
    float fee;
    char * comments;
};

//Node will be the Nodes that make up the tree
class Node
{
  public:
    //Constructors----------
    Node();
    Node(Service_info &src, Node * left, Node * right);
    Node(const Service_info &src);
    ~Node();
    //functions
    int display_one() const;
    bool is_leaf();
    //getters---------------
    Node *& get_left(); 
    Node *& get_right();
    Service_info & get_serviceInfo();
    //setters---------------
    void set_left(Node *connect);
    void set_right(Node *connect);
  private:
    Service_info my_info;
    Node *left;
    Node *right;

};
//BST for Services
class Service_directory
{
  public:
 //Con/destructors---------- 
  Service_directory();
  ~Service_directory();
  //Functions--------------
  void menu(int &user_input); //TODO delete this
  void clear(); //TODO delete this
  int add_node(const Service_info &to_add);
  int remove_node(const int service_code);
  int remove_all_nodes();
  int display_by_date(char * date) const;
  int display_by_service_code(int service_code) const;
  int display_all() const;
  Node * findIOS(Node *root, Node *target);
  Node * findMin(Node *&root);
  
  private:
  Node *root;
  int add_node(Node *&root, const Service_info &to_add);
  int remove_node(Node *&root, const int service_code);
  int remove_all_nodes(Node *&root);
  int display_by_service_code(Node *root, int service_code) const;
  int display_by_date(Node *root, char *date) const;
  int display_all(Node *root) const;
};




