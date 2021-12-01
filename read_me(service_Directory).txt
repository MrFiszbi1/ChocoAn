Service directory is a BST in which the nodes are organized by service code
In the directions it says to organize them by date but removal by date seemed more tricky
since there could be multiple of the same date. So instead I made a display by date to make
it seem like they were organized by date. 

The node holds a Service_info object which contains the following information:

char * date
char * service_name
int provider number
int member number
int service code
float fee
char * comments
-----------------

The ServiceDirectory can:

add a service
remove a service (by service code)
remove all services (used for garbage collection)
display by date
display by service code
display all 

I made a parameterized constructor for service_info so someone could initialize an object
by passing in the information via text file. 


