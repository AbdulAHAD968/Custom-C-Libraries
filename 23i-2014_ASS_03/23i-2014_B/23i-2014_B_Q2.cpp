#include<iostream>

using namespace std;


//*CUSTOM CLASS.*//
class Money{
    
    private:
        
        double dollar;
        double cents;

    public:
    
        Money();                            // parameterless constructor.
        Money(double dollar, double cents);         // parameterized constructor.

        Money& copy(const Money&);          // copy constructor.

        //*ARITHEMATIC OPERATORS.*//

        Money operator+(const Money &obj);              // addition operator.
        Money operator-(const Money &obj);              // subtraction operator.
        const Money operator=(const Money &obj);        // assignment operator.
        Money& operator++ ();                           // pre-increment operator
        Money& operator-- ();                           // pre-decrement operator
        Money operator++ (int);                          // post-increment operator
        Money operator-- (int);                          // post-decrement operator


         //*COMPARISON OPERATORS.*//

        bool operator==(const Money &right);            // is-equal operator
        bool operator!=(const Money &right);            // is-not-equal operator
        bool operator > (const Money& right);           // is-greater operator

        //*IO-STREAM OPERATORS. [FRIEND's]*//

        friend ostream& operator<<(ostream& out, const Money& obj);     // for output.
        friend istream& operator>>(istream& in, Money& obj);            // for input.

        //*HELP-DRIVER FUNCTION.*//
        friend void OverLoad_current_obj(Money&);

        //*DESTRUCTOR.*//
        ~Money();
};

//*PARAMETER-LESS CONSTRUCTOR.*//
Money::Money(){
    dollar = 0;
    cents = 0;
}

//*PARAMETERIZED CONSTRUCTOR.*//
Money::Money(double dollar, double cents){
    this->dollar = dollar;
    this->cents = cents;
}

//*COPY CONSTRUCTOR.*//
Money& Money::copy(const Money& obj){
    this->dollar = obj.dollar;
    this->cents = obj.cents;
    return *this;
}

//*ARITHEMATIC OPERATORS.*//

//*addition of two objects.*//
Money Money::operator+(const Money &obj){
    this->cents += obj.cents;
    this->dollar += obj.dollar;

return *this;    
}

//*subtraction of two objects.*//
Money Money::operator-(const Money &obj){
    this->cents -= obj.cents;
    this->dollar -= obj.dollar;

return *this; 
}

//*assignment operator.*//
const Money Money::operator=(const Money &obj){
    
    this->dollar = obj.dollar;      // assigining the values as the data was static.
    this->cents = obj.cents;

return *this;
}

//*pre-increment operator.*//
Money& Money::operator++(){
    
    this->dollar += 1;
    this->cents += 1;

return *this;
}

//*pre-decrement operator.*//
Money& Money::operator--(){
    
    this->dollar -= 1;
    this->cents -= 1;

return *this;
}

//*post-increment operator.*//
Money Money::operator++(int){
    
    this->dollar++;
    this->cents++;

return (*this);
}

//*post-decrement operator.*//
Money Money::operator--(int){
    
    this->dollar--;
    this->cents--;

return (*this);
}

//*is-equal operator.*//
bool Money::operator==(const Money &right){
    if( (this->dollar == right.dollar) && (this->cents== right.cents) ){
        return true;
    }
    else{
        return false;
    }
}

//*is-not-equal operator.*//
bool Money::operator!=(const Money &right){
    if( (this->dollar != right.dollar) && (this->cents != right.cents) ){
        return true;
    }
    else{
        return false;
    }
}

//*is-greater operator.*//
bool Money::operator>(const Money& right){
    if(this->dollar> right.dollar && this->cents> right.cents){
        return true;          // if both the dollars and cents are greater.
    }
    else if(this->dollar > right.dollar){   // if only the dollars are greater
        return true;
    }
    else if(this->dollar == right.dollar && this->cents > right.cents){         // if only the cents are greater
        return true;
    }
    else{
        return false;           // if both are lesser than.[pased obj.]
    }
}

//*O-STREAM OPERATORS. [FRIEND's]*//
ostream& operator<<(ostream& out , const Money& amount){
    cout<<"\n THE AMOUNT IS  =  {  "; 
    out<<"$ "<<amount.dollar<<"."<<amount.cents<<"  } "<<endl;

return out;
}

//*I-STREAM OPERATORS. [FRIEND's]*//
istream& operator>>(istream& in_put, Money& amount){
    double dollar;
    double cents;

    cout<<"\n ENTER THE AMOUNT [DOLLARS] "; 
    in_put>>dollar;
    while(dollar<0){
        cout<<"\n ENTER A POSITIVE AMOUNT [DOLLARS] ";
        in_put>>dollar;
    }

    cout<<"\n ENTER THE AMOUNT [CENTS]   R=[0-100] "; 
    in_put>>cents;
    while(cents<0 || cents>100){
        cout<<"\n ENTER A POSITIVE AMOUNT [CENTS]  R=[0-100] ";
        in_put>>cents;
    }
    if(cents==100){
        cents = 00;
        dollar += 1;
    }
    amount = Money(dollar, cents);

return in_put;
}

//*DESTRUCTOR.*//
Money::~Money(){
    // just roaming around...
}


//*MAIN FUNCTION.*//
int main(){

    while(1){

        int const_type;
        cout<<"\n WHICH CONSTRUCTOR DO YOU WANT TO USE ? ";
        cout<<"\n [1]. PARAMETERLESS CONSTRUCTOR.";
        cout<<"\n [2]. PARAMETERIZED CONSTRUCTOR.";
        cout<<"\n [0]. EXIT";
        cout<<"\n ENTER YOUR CHOICE....  ";
        cin>>const_type;

        switch(const_type){
            case 1:
            {
                cout<<"\n USING PARAMETERLESS CONSTRUCTOR.";
                Money m1;
                cout<<m1;
                OverLoad_current_obj(m1);
            break;
            }
            case 2:
            {
                cout<<"\n USING PARAMETERIZED CONSTRUCTOR.";
                double dollar;
                double cents;
                cout<<"\n ENTER THE AMOUNT DOLLARS <-> [$$] "; 
                cin>>dollar;
                while(dollar<0){
                    cout<<"\n ENTER THE AMOUNT {+ve} <-> [$$] "; 
                    cin>>dollar;
                }

                cout<<"\n ENTER THE AMOUNT CENTS   <-> R=[0-100] "; 
                cin>>cents;
                while(cents<0 || cents>100){
                    cout<<"\n ENTER THE AMOUNT {+ve} <-> R=[0-100] "; 
                    cin>>cents;
                }

                if(cents==100){         // if cents==100 add 1 to dollar.
                    cents = 00;
                    dollar += 1;
                }

                    Money m2(dollar, cents);
                    cout<<m2;
                    OverLoad_current_obj(m2);
            break;
            }
            case 0:
            {
                cout<<"\n EXITING THE PROGRAM...";
                return 0;
            break;
            }
            default:
            {
                cout<<"\n INVALID INPUT [ :) ]";
            }
        }

    }

return 0;
}

//*MAIN REFERENCING FUNCTION TO THE OVERLOADED OPERATORS.*//
void OverLoad_current_obj(Money& obj_pass)
{
    Money to_comp;
    cout<<"\n INVOKING THE [I-STREAM] FRIEND FUNCTION TO TAKE INPUT. \n";
    cout<<"\n FOR THE OBJECT TO BE OVERLOADED. \n";
    cin>>to_comp;
    cout<<to_comp;

    while(1){

        int choice;
        cout<<"\n    [1].      ADDITION.";
        cout<<"\n    [2].      SUBTRACTION.";
        cout<<"\n    [3].      ASSIGNMENT.";
        cout<<"\n    [4].      PRE-INCREMENT.";
        cout<<"\n    [5].      PRE-DECREMENT.";
        cout<<"\n    [6].      POST-INCREMENT.";
        cout<<"\n    [7].      POST-DECREMENT.";
        cout<<"\n    [8].      IS-EQUAL.";
        cout<<"\n    [9].      IS-NOT-EQUAL.";
        cout<<"\n    [10].     IS-GREATER.";
        cout<<"\n    [0].      EXIT.";
        cout<<"\n\n    ENTER YOUR CHOICE. [**]...  ";
        cin>>choice;

        switch(choice){
            case 1:
            {
                Money new_obj;
                new_obj = obj_pass + to_comp;
                cout<<"\n PERFORMING ADDITION."<<endl;
                cout<<new_obj;
            break;
            }
            case 2:
            {
                Money new_obj;
                new_obj = obj_pass - to_comp;
                cout<<"\n PERFORMING SUBTRACTION."<<endl;
                cout<<new_obj;
            break;
            }
            case 3:
            {
                obj_pass = to_comp;
                cout<<"\n PERFORMING ASSIGNMENT."<<endl;
                cout<<obj_pass;
            break;
            }
            case 4:
            {
                ++obj_pass;
                cout<<"\n PERFORMING PRE-INCREMENT."<<endl;
                cout<<obj_pass;
            break;
            }
            case 5:
            {
                --obj_pass;
                cout<<"\n PERFORMING PRE-DECREMENT."<<endl;
                cout<<obj_pass;
            break;
            }
            case 6:
            {
                Money new_obj;
                new_obj = obj_pass++;
                cout<<"\n PERFORMING POST-INCREMENT."<<endl;
                cout<<new_obj;
            break;
            }
            case 7:
            {
                Money new_obj;
                new_obj = obj_pass--;
                cout<<"\n PERFORMING POST-DECREMENT."<<endl;
                cout<<new_obj;
            break;
            }
            case 8:
            {
                if(obj_pass == to_comp){
                    cout<<"\n BOTH THE OBJECTS ARE EQUAL."<<endl;
                }
                else{
                    cout<<"\n THE OBJECTS ARE NOT EQUAL TO EACH OTHER."<<endl;
                }
            break;
            }
            case 9:
            {
                if(obj_pass!= to_comp){
                    cout<<"\n BOTH THE OBJECTS ARE NOT EQUAL. "<<endl;
                }
                else{
                    cout<<"\n THE OBJECTS ARE EQUAL TO EACH OTHER."<<endl;
                }
            break;
            }
            case 10:
            {
                if(obj_pass > to_comp){
                    cout<<"\n THE [Obj_Passed] IS GREATER THEN [To_Comp] OBJ."<<endl;
                }
                else{
                    cout<<"\n THE [To_Comp] OBJ IS GREATER THEN OR MAYBE EQUAL [Obj_Passed]."<<endl;
                }
            break;
            }
            case 0:
            {
                cout<<"\n EXITING THE PROGRAM.\n";
                return;         // simple return is terminating point for void fun.
            }
            default:
            {
                cout<<"\n INVALID CHOICE.\n";
            }

        }//switch
    }//loop

return;
}
