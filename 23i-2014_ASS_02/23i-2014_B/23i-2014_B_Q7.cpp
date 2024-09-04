#include<iostream>

using namespace std;

class Address{
    private:

    int house_number;
    int street;
    int apartment_number;
    string city;
    string state;
    int postal_code;

    public:

    // constructor with appartment number.
    Address(int house_number, int street, int apartment_number, string city, string state, int postal_code);
    
    // constructor without appartment number.
    Address(int house_number, int street, string city, string state, int postal_code);

    // setter functions for class members...
    void set_house_number(int house_number);
    void set_street(int street);
    void set_apartment_number(int apartment_number);
    void set_city(string city);
    void set_state(string state);
    void set_postal_code(int postal_code);

    // getter functions for class members...
    int get_house_number();
    int get_street();
    int get_apartment_number();
    string get_city();
    string get_state();
    int get_postal_code();
    
    void display_01();

    int compare_to(int p1);
    ~Address();

};

// * USER DEFINED CONSTRUCTORS* //

// constructor with appartment number.
Address::Address(int house_number, int street, int apartment_number, string city, string state, int postal_code){
    this->house_number = house_number;
    this->street = street;
    this->apartment_number = apartment_number;
    this->city = city;
    this->state = state;
    this->postal_code = postal_code;
}

// constructor without appartment number.
Address::Address(int house_number, int street, string city, string state, int postal_code){
    this->house_number = house_number;
    this->street = street;
    this->city = city;
    this->state = state;
    this->postal_code = postal_code;
}


// * UTILITY FUNCTIONS. * //

// * SETTERS OF DATA. * //
void Address::set_house_number(int house_number){
    this->house_number = house_number;
}

void Address::set_street(int street){
    this->street = street;
}

void Address::set_apartment_number(int apartment_number){
    this->apartment_number = apartment_number;
}

void Address::set_city(string city){
    this->city = city;
}

void Address::set_state(string state){
    this->state = state;
}

void Address::set_postal_code(int postal_code){
    this->postal_code = postal_code;
}

// * GETTERS OF DATA. * //

int Address::get_house_number(){
    return this->house_number;
}

int Address::get_street(){
    return this->street;
}

int Address::get_apartment_number(){
    return this->apartment_number;
}

string Address::get_city(){
    return this->city;
}

string Address::get_state(){
    return this->state;
}

int Address::get_postal_code(){
    return this->postal_code;
}

int Address::compare_to(int p1){

    if(p1 > this->postal_code){
        return 1;           // The current address comes after the other address
    }else if(p1 < this ->postal_code){
        return -1;          // The current address comes before the other address
    }else{
        return 0;           // The addresses have the same postal code
    }
}

Address::~Address(){
    // Delete the address class constructor...
}

// * Display data function. * //

void Address::display_01(){

    cout<<"\n STREET =  "<<this->street<<endl;
    cout<<"\n CITY = [ "<<this->city;
    cout<<" ] :: STATE = { "<<this->state;
    cout<<" } :: ZIP = [ "<<this->postal_code<<" ] \n"<<endl;

}


// * MAIN FUNCTION. * //

int main(){

    int house_number, street, apartment_number;
    string city, state;
    int postal_code_01, postal_code_02;

    cout<<"\n ENTER DATA FOR [ FIRST ] OBJECT ::>>  \n\n";

    cout<<"\n ENTER HOUSE NUMBER = ";
    cin>>house_number;
    while(house_number<0){
        cout<<"\n ENTER A VALID HOUSE NUMBER. THANKS.\n";
        cout<<"\n ENTER HOUSE NUMBER = ";
        cin>>house_number;
    }

    cout<<"\n ENTER STREET NUMBER = ";
    cin>>street;
    while(house_number<0){
        cout<<"\n ENTER A VALID HOUSE NUMBER. THANKS.\n";
        cout<<"\n ENTER HOUSE NUMBER = ";
        cin>>street;
    }

    cout<<"\n ENTER APPARTMENT NUMBER = ";
    cin>>apartment_number;
    while(house_number<0){
        cout<<"\n ENTER A VALID APPARTMENT NUMBER. THANKS.\n";
        cout<<"\n ENTER HOUSE NUMBER = ";
        cin>>apartment_number;
    }

    cout<<"\n ENTER CITY = ";
    cin>>city;

    cout<<"\n ENTER STATE = ";
    cin>>state;

    cout<<"\n ENTER POSTAL CODE = ";
    cin>>postal_code_01;
    while(postal_code_01 <0){
        cout<<"\n ENTER A VALID POSTAL CODE. THANKS.\n";
        cout<<"\n ENTER POSTAL CODE = ";
        cin>>postal_code_01;
    }

    Address A1(house_number, street, apartment_number, city, state, postal_code_01);
    A1.display_01();

                ////////////////////////////////////////////

    cout<<"\n ENTER DATA FOR [ SECOND ] OBJECT ::>>  \n\n";

    cout<<"\n ENTER HOUSE NUMBER = ";
    cin>>house_number;

    while(house_number<0){
        cout<<"\n ENTER A VALID HOUSE NUMBER. THANKS.\n";
        cout<<"\n ENTER HOUSE NUMBER = ";
        cin>>house_number;
    }

    cout<<"\n ENTER STREET NUMBER = ";
    cin>>street;

    while(street<0){
        cout<<"\nENTER A POSITIVE NUMBER. THANKS  :) \n";
        cout<<"\n ENTER THE NUMBER = ";
        cin>>street;
    }

    cout<<"\n ENTER CITY = ";
    cin>>city;

    cout<<"\n ENTER STATE = ";
    cin>>state;

    cout<<"\n ENTER POSTAL CODE = ";
    cin>>postal_code_02;

    while(postal_code_02<0){
        cout<<"\n ENTER A POSITIVE NUMBER.";
        cout<<"\n ENTER THE NUMBER = ";
        cin>>postal_code_02;
    }

    Address A2(house_number, street, city, state, postal_code_02);
    A2.display_01();

    int comp_to = A1.compare_to( postal_code_02);           // comparing the postal codes...

    if(comp_to > 0){
        cout<<"\n THE FIRST HOUSE IS ABOVE TO THE SECOND HOUSE. \n\n";
    }else if(comp_to < 0){
        cout<<"\n THE FIRST HOUSE IS AFTER TO THE SECOND HOUSE. \n\n";
    }else if(comp_to == 0){
        cout<<"\n BOTH ADDRESS ARE SAME. \n\n";
    }



return 0;
}