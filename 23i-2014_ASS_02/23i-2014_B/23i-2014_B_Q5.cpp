#include<iostream>
#include<cstring>

using namespace std;

class Employee{
    private:

    char* name;
    double salary;

    public:

   Employee(char*NAME=NULL , double SALARY=0);      // constructor

   const char* ret_name();
   double ret_salary();

   ~Employee();             // destructor
};

// * UTILITY FUNCTIONS * //
Employee::Employee(char* NAME, double SALARY){

    name = new char[strlen(NAME) + 1];
    strcpy(name, NAME);             // copy name
    salary = SALARY;
}

// * RETURN THE NAME * //
const char* Employee::ret_name(){
    return name;
}

// * RETURN THE SALARY * //
double Employee::ret_salary(){
    return salary;
}


// * DESTRUCTOR * //
Employee::~Employee(){              // free the memory allocated...
    delete[] name;
}

// * MAIN FUNCTION * //
int main(){

    //Employee e2;
    char* name = new char[20];              // dynamically allocated..
    double salary;

    cout<<"ENTER THE NAME OF EMPLOYEE: ";
    cin.getline(name, 20);                      // to accomodate spaces in name..

    cout<<"ENTER THE SALARY OF THE EMPLOYEE: ";
    cin>>salary;
    Employee e1(name,salary);


    cout<<"\n Returned Name: "<<e1.ret_name()<<endl;
    cout<<"\n Returned Salary: "<<e1.ret_salary()<<endl;

    delete name;            // delete name.

    name = nullptr;         //undangling

return 0;
}