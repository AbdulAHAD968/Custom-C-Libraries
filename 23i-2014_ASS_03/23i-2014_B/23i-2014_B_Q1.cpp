#include<iostream>

using namespace std;

//*function to normalize the fraction.*//
int normalise_fraction(int , int);

//*CUSTOM CLASS.*//
class Fraction{
    private:

        int numer;          // numerator.
        int denom;          // denominator. 

    public:

        Fraction();             // without any parameter.
        Fraction(int);          // with one parameter numer
        Fraction(int, int);     // with both parameter numerator and denominator.

        int get_numer() const;          // getter for numerator.
        int get_denom() const;          // getter for denominator.

        Fraction& copy(const Fraction& alpha);          // copy constructor.

        int* Display();         // display function.[will be returning an array of numerator and denominator.]

        //*OVERLOADED ARETHEMATIC OPERATORS.*//

        Fraction& operator+(const Fraction&);       // overloaded addition.
        Fraction& operator-(const Fraction&);       // overloaded subtraction.
        Fraction& operator*(const Fraction&);       // overloaded multiplication.
        Fraction& operator/(const Fraction&);       // overloaded division.
        Fraction& operator+=(const Fraction&);       // overloaded add-assign operator.
        Fraction& operator-=(const Fraction&);       // overloaded sub-assign operator.
        Fraction& operator*=(const Fraction&);       // overloaded mul-assign operator.
        Fraction& operator/=(const Fraction&);       // overloaded div-assign operator.
        Fraction& operator++();                      // pre-incriment operator++.
        Fraction& operator--();                      // pre-decriment operator--.
        Fraction& operator++(int);                  // post-incriment operator++.
        Fraction& operator--(int);                  // post-decriment operator--.

        
        //*COMPARISON OPERATORS.*//

        bool operator==(const Fraction&);           // check the equality operator.
        bool operator!=(const Fraction&);           // check the inequality operator.
        bool operator<(const Fraction&);            // check the less than operator.
        bool operator>(const Fraction&);            // check the greater than operator.
        bool operator<=(const Fraction&);           // check the less than or equal to operator.
        bool operator>=(const Fraction&);           // check the greater than or equal to operator.


        //*LOGICAL OPERATORS.*//

        bool operator&&(const Fraction&);            // check if both fractions are non-zero.
        bool operator||(const Fraction&);            // check if at least one of the fractions is non-zero.


        //*IOSTREAM FRIEND FUNCTIONS.*//

        friend ostream& operator<<(ostream& out, const Fraction&);          // for using cout with obj.
        friend istream &operator>>(istream &in, Fraction &);                // for using cin with obj.

        friend void OverLoad_current_obj(Fraction&);        // help-driver function

        ~Fraction();            // destructor
};

//*DEFINITION OF THE NORMALIZER FUNCTION.*//
int normalise_fraction(int Numer , int Denom){
    
    if(Denom == 0){        // base case.
        return Numer;
    }

    int temp = Numer % Denom;
    
    return normalise_fraction( Denom , temp);      // recursive case.
}

//*DEFINITION OF THE COPY CONSTRUCTOR FUNCTION.*//
Fraction& Fraction::copy(const Fraction& alpha){

    numer = alpha.numer;
    denom = alpha.denom;

    return *this;
}

//* PARAMETERLESS CONSTRUCTOR.*//
Fraction::Fraction(){
    numer = 0;
    denom = 1;
}

//* CONSTRUCTOR WITH ONE PARAMETER NUMERATOR.*//
Fraction::Fraction(int n){
    this->numer = n;
    this->denom = 1;

    int gcd = normalise_fraction(n,1);
    this->numer /= gcd;
    this->denom /= gcd;
}

//* CONSTRUCTOR WITH BOTH PARAMETER NUMERATOR AND DENOMINATOR.*//
Fraction::Fraction(int n, int d){
    this->numer = n;
    this->denom = d;
    
    int gcd = normalise_fraction(n,d);
    this->numer /= gcd;
    this->denom /= gcd;
}

//* GETTER FOR NUMERATOR.*//
int Fraction::get_numer() const{
    return numer;
}

//* GETTER FOR DENOMINATOR.*//
int Fraction::get_denom() const{
    return denom;
}

//* DISPLAY FUNCTION.*//
int* Fraction::Display(){
    int* arr = new int[2];
    arr[0] = numer;
    arr[1] = denom;
    if(denom == 0){
        cout<<"\n UN-DEFINED ERROR.";
        return 0;
    }
    cout<<"\n THE FRACTION IS  = "<<arr[0]<<" / "<<arr[1]<<endl;

return arr;
}

//* OVERLOADED ARETHEMATIC OPERATORS.*//

//*overloaded addition.*//
Fraction& Fraction::operator+(const Fraction& alpha){
    int* arr = new int[2];
    arr[0] = this->numer * alpha.denom + alpha.numer * this->denom;
    arr[1] = this->denom * alpha.denom;

    int gcd = normalise_fraction(arr[0],arr[1]);
    this->numer = arr[0] / gcd;
    this->denom = arr[1] / gcd;

return *this;
}

//*overloaded subtraction.*//
Fraction& Fraction::operator-(const Fraction& alpha){
    int* arr = new int[2];
    arr[0] = this->numer * alpha.denom - alpha.numer * this->denom;
    arr[1] = this->denom * alpha.denom;

    int gcd = normalise_fraction(arr[0],arr[1]);
    this->numer = arr[0] / gcd;
    this->denom = arr[1] / gcd;

return *this;
}

//*overloaded multiplication.*//
Fraction& Fraction::operator*(const Fraction& alpha){
    this->numer = this->numer * alpha.numer;
    this->denom = this->denom * alpha.denom;
    
    int neutral = normalise_fraction(this->numer,this->denom);
    
    this->numer /= neutral;
    this->denom /= neutral;

return *this;
}

//*overloaded division.*//
Fraction& Fraction::operator/(const Fraction& alpha){
    this->numer = this->numer * alpha.denom;
    this->denom = this->denom * alpha.numer;
    
    int neutral = normalise_fraction(this->numer,this->denom);
    
    this->numer /= neutral;
    this->denom /= neutral;

return *this;
}

//*overloaded add-assign operator.*//
Fraction& Fraction::operator+=(const Fraction& alpha){
    int* arr = new int[2];
    arr[0] = this->numer * alpha.denom + alpha.numer * this->denom;
    arr[1] = this->denom * alpha.denom;
    
    int gcd = normalise_fraction(arr[0],arr[1]);
    
    this->numer = arr[0] / gcd;
    this->denom = arr[1] / gcd;

return *this;
}

//*overloaded sub-assign operator.*//
Fraction& Fraction::operator-=(const Fraction& alpha){
    int* arr = new int[2];
    arr[0] = this->numer * alpha.denom - alpha.numer * this->denom;
    arr[1] = this->denom * alpha.denom;

    int gcd = normalise_fraction(arr[0],arr[1]);
    this->numer = arr[0] / gcd;
    this->denom = arr[1] / gcd;

return *this;
}

//*overloaded mul-assign operator.*//
Fraction& Fraction::operator*=(const Fraction& alpha){
    this->numer *= alpha.numer;
    this->denom *= alpha.denom;
    
    int neutral = normalise_fraction(this->numer,this->denom);

    this->numer /= neutral;
    this->denom /= neutral;

return *this;
}

//*overloaded div-assign operator.*//
Fraction& Fraction::operator/=(const Fraction& alpha){

    this->numer *= alpha.denom;
    this->denom *= alpha.numer;

    int gcd = normalise_fraction(this->numer,this->denom);

    this->numer /= gcd;
    this->denom /= gcd;

return *this;
}

//*pre-incriment operator.*//
Fraction& Fraction::operator++(){
    ++numer;
    ++denom;
    
    int neutral = normalise_fraction(numer,denom);

    numer /= neutral;
    denom /= neutral;

return *this;
}

//*pre-decriment operator.*//
Fraction& Fraction::operator--(){
    --numer;
    --denom;
    
    int neutral = normalise_fraction(numer,denom);

    numer /= neutral;
    denom /= neutral;

return *this;
}

//*post-incriment operator.*//
Fraction& Fraction::operator++(int){
    numer++;
    denom++;
    
    int neutral = normalise_fraction(numer,denom);

    numer /= neutral;
    denom /= neutral;

return *this;
}

//*post-decriment operator.*//
Fraction& Fraction::operator--(int){
    numer--;
    denom--;
    
    int neutral = normalise_fraction(numer,denom);

    numer /= neutral;
    denom /= neutral;

return *this;
}

//*COMPARISON OPERATORS.*//

//*is_equal operator.*//
bool Fraction::operator==(const Fraction& obj){
    if(numer == obj.numer && denom == obj.denom){
        return true;
    }
    else{
        return false;
    }
}

//*is_not_equal operator.*//
bool Fraction::operator!=(const Fraction& obj){
    if(this->numer!= obj.numer && this->denom!= obj.denom){
        return true;
    }
    else{
        return false;
    }
}

//*is_less_than operator.*//
bool Fraction::operator<(const Fraction& obj){
    if(this->numer * obj.denom < obj.numer * this->denom){
        return true;
    }
    else{
        return false;
    }
}

//*is_greater_than operator.*//
bool Fraction::operator>(const Fraction& obj){
    if(this->numer * obj.denom > obj.numer * this->denom){
        return true;
    }
    else{
        return false;
    }
}

//*is_less_than_or_equal_to operator.*//
bool Fraction::operator<=(const Fraction& obj){
    if(this->numer * obj.denom <= obj.numer * this->denom){
        return true;
    }
    else{
        return false;
    }
}

//*is_greater_than_or_equal_to operator.*//
bool Fraction::operator>=(const Fraction& obj){
    if(this->numer * obj.denom >= obj.numer * this->denom){
        return true;
    }
    else{
        return false;
    }
}

//*LOGICAL OPERATORS.*//

//*logical and operator.*//
bool Fraction::operator&&(const Fraction& obj){
    if(numer != 0 && obj.numer != 0){
        return true;        // if both are not 0's return true.
    }
    else{
        return false;
    }
}

//*logical or operator.*//
bool Fraction::operator||(const Fraction& obj){
    if(numer != 0 || obj.numer != 0){
        return true;        // if anyone is not 0 return true.
    }
    else{
        return false;
    }
}

//*O-STREAM FRIEND FUNCTION.*//
ostream& operator<<(ostream& out_put , const Fraction& to_print){
    cout<<"\n THE FRACTION IS  =  {  ";
    out_put<<to_print.numer<<" / "<<to_print.denom<<"  }"<<endl;
}

//*I-STREAM FRIEND FUNCTION.*//
istream& operator>>(istream& in_put , Fraction& to_read){
    int numer, denom;
    cout<<"\n ENTER THE NUMERATOR OF THE FRACTION =  ";
    cin>>numer;
    cout<<"\n ENTER THE {DE-NOMINATOR} OF THE FRACTION =  ";
    cin>>denom;
    while(denom<0){
        cout<<"\n ENTER THE <NON-ZERO>  {DE-NOMINATOR} OF THE FRACTION =  ";
        cin>>denom;
    }
    to_read.numer = numer;
    to_read.denom = denom;
}

//*DESTRUCTOR.*//
Fraction::~Fraction(){
    // just roaming around...
}


//*MAIN FUNCTION.*//
int main(){

    while(1){

        int select_construct;
        cout<<"\n [1]. CONTINUE WITH PARAMETERLESS CONSTRUCTOR.";
        cout<<"\n [2]. CONTINUE WITH ONE PARAMETER {NUMERATOR}.";
        cout<<"\n [3]. CONTINUE WITH BOTH PARAMETER {NUMERATOR} AND {DENOMINATOR}.";
        cout<<"\n [0]. EXIT.";
        cout<<"\n [All the overloading functions will be performed according to your CONSTRUCTOR choice.]  :) ";
        cout<<"\n ENTER YOUR CHOICE. ";
        cin>>select_construct;

        switch(select_construct){
            case 1:
            {
                Fraction f1;
                f1.Display();
                OverLoad_current_obj(f1);
            break;
            }
            case 2:
            {
                int numer;
                cout<<"\n ENTER THE NUMERATOR OF THE FRACTION =  ";
                cin>>numer;
                Fraction f2(numer);
                f2.Display();
                OverLoad_current_obj(f2);
            break;
            }
            case 3:
            {
                int numer, denom;
                cout<<"\n ENTER THE NUMERATOR OF THE FRACTION =  ";
                cin>>numer;
                cout<<"\n ENTER THE {DE-NOMINATOR} OF THE FRACTION =  ";
                cin>>denom;
                while(denom<0){
                    cout<<"\n ENTER THE <NON-ZERO>  {DE-NOMINATOR} OF THE FRACTION =  ";
                    cin>>denom;
                }
                Fraction f3(numer, denom);
                f3.Display();
                OverLoad_current_obj(f3);
            break;
            }
            case 0:
            {
                cout<<"\n EXITING THE PROGRAM.\n";
                return 0;
            break;
            }
            default:
            {
                cout<<"\n INVALID CHOICE.\n";
            }
        }
    }

return 0;
}


//*MAIN REFERENCING FUNCTION TO THE OVERLOADED OPERATORS.*//
void OverLoad_current_obj(Fraction& obj_pass)
{

    Fraction to_comp;
    cout<<"\n INVOKING THE [I-STREAM] FRIEND FUNCTION TO TAKE INPUT. \n";
    cout<<"\n FOR THE OBJECT TO BE OVERLOADED. \n";
    cin>>to_comp;
    cout<<to_comp;

    while(1){

        int choice;
        cout<<"\n    [1].      ADDITION.";
        cout<<"\n    [2].      SUBTRACTION.";
        cout<<"\n    [3].      MULTIPLICATION.";
        cout<<"\n    [4].      DIVISION.";
        cout<<"\n    [5].      ADD-ASSIGN OPERATOR.";
        cout<<"\n    [6].      SUB-ASSIGN OPERATOR.";
        cout<<"\n    [7].      MUL-ASSIGN OPERATOR.";
        cout<<"\n    [8].      DIV-ASSIGN OPERATOR.";
        cout<<"\n    [9].      PRE-INCREMENT OPERATOR.";
        cout<<"\n    [10].     PRE-DECREMENT OPERATOR.";
        cout<<"\n    [11].     POST-INCREMENT OPERATOR.";
        cout<<"\n    [12].     POST-DECREMENT OPERATOR.";
        cout<<"\n    [13].     EQUALITY OPERATOR.";
        cout<<"\n    [14].     NOT EQUALITY OPERATOR.";
        cout<<"\n    [15].     LESS THAN OPERATOR.";
        cout<<"\n    [16].     GREATER THAN OPERATOR.";
        cout<<"\n    [17].     LESS THAN OR EQUAL TO OPERATOR.";
        cout<<"\n    [18].     GREATER THAN OR EQUAL TO OPERATOR.";
        cout<<"\n    [19].     LOGICAL AND OPERATOR.";
        cout<<"\n    [20].     LOGICAL OR OPERATOR.";
        cout<<"\n    [0].      EXIT.";
        cout<<"\n\n    ENTER YOUR CHOICE. [**]   ";
        cin>>choice;

        switch(choice){
            case 1:
            {
                Fraction new_obj;
                new_obj = obj_pass + to_comp;
                cout<<"\n PERFORMING ADDITION."<<endl;
                cout<<new_obj;
            break;
            }
            case 2:
            {
                Fraction new_obj;
                new_obj = obj_pass - to_comp;
                cout<<"\n PERFORMING SUBTRACTION."<<endl;
                cout<<new_obj;
            break;
            }
            case 3:
            {
                Fraction new_obj;
                new_obj = obj_pass * to_comp;
                cout<<"\n PERFORMING MULTIPLICATION."<<endl;
                cout<<new_obj;
            break;
            }
            case 4:
            {
                Fraction new_obj;
                new_obj = obj_pass / to_comp;
                cout<<"\n PERFORMING DIVISION."<<endl;
                cout<<new_obj;
            break;
            }
            case 5:
            {
                to_comp += obj_pass;
                cout<<"\n PERFORMING ADD-ASSIGN OPERATOR."<<endl;
                cout<<to_comp;
            break;
            }
            case 6:
            {
                to_comp -= obj_pass;
                cout<<"\n PERFORMING SUB-ASSIGN OPERATOR."<<endl;
                cout<<to_comp;
            break;
            }
            case 7:
            {
                to_comp *= obj_pass;
                cout<<"\n PERFORMING MUL-ASSIGN OPERATOR."<<endl;
                cout<<to_comp;
            break;
            }
            case 8:
            {
                to_comp /= obj_pass;
                cout<<"\n PERFORMING DIV-ASSIGN OPERATOR."<<endl;
                cout<<to_comp;
            break;
            }
            case 9:
            {
                ++obj_pass;
                cout<<"\n PERFORMING PRE-INCREMENT OPERATOR."<<endl;
                cout<<obj_pass;
            break;
            }
            case 10:
            {
                --obj_pass;
                cout<<"\n PERFORMING PRE-DECREMENT OPERATOR."<<endl;
                cout<<obj_pass;
            break;
            }
            case 11:
            {
                obj_pass++;
                cout<<"\n PERFORMING POST-INCREMENT OPERATOR."<<endl;
                cout<<obj_pass;
            break;
            }
            case 12:
            {
                obj_pass--;
                cout<<"\n PERFORMING POST-DECREMENT OPERATOR."<<endl;
                cout<<obj_pass;
            break;
            }
            case 13:
            {
                if(obj_pass == to_comp){
                    cout<<"\n THE OBJECTS OF [FRACTION] ARE EQUAL."<<endl;
                }
                else{
                    cout<<"\n THE OBJECTS OF [FRACTION] ARE NOT EQUAL."<<endl;
                }
            break;
            }
            case 14:
            {
                if(obj_pass!= to_comp){
                    cout<<"\n THE OBJECTS OF [FRACTION] ARE NOT EQUAL."<<endl;
                }
                else{
                    cout<<"\n THE OBJECTS OF [FRACTION] ARE EQUAL."<<endl;
                }
            break;
            }
            case 15:
            {
                if(obj_pass < to_comp){
                    cout<<"\n THE [PASSED OBJECT] IS LESS THAN [TO_COMPARE_OBJ.]"<<endl;
                }
                else{
                    cout<<"\n THE [TO_COMPARE_OBJ.] IS LESS THAN [PASSED OBJECT]"<<endl;
                }
            break;
            }
            case 16:
            {
                if(obj_pass > to_comp){
                    cout<<"\n THE [PASSED OBJECT] IS GREATER THAN [TO_COMPARE_OBJ.]"<<endl;
                }
                else{
                    cout<<"\n THE [TO_COMPARE_OBJ.] IS GREATER THAN [PASSED OBJECT]"<<endl;
                }
            break;
            }
            case 17:
            {
                if(obj_pass <= to_comp){
                    cout<<"\n THE [PASSED OBJECT] IS LESS THAN OR EQUAL TO [TO_COMPARE_OBJ.]"<<endl;
                }
                else{
                    cout<<"\n THE [TO_COMPARE_OBJ.] IS LESS THAN OR EQUAL TO [PASSED OBJECT]"<<endl;
                }
            break;
            }
            case 18:
            {
                if(obj_pass >= to_comp){
                    cout<<"\n THE [PASSED OBJECT] IS GREATER THAN OR EQUAL TO [TO_COMPARE_OBJ.]"<<endl;
                }
                else{
                    cout<<"\n THE [TO_COMPARE_OBJ.] IS GREATER THAN OR EQUAL TO [PASSED OBJECT]"<<endl;
                }
            break;
            }
            case 19:
            {
                if(obj_pass && to_comp){
                    cout<<"\n BOTH OF THE FRACTIONS HAVE [SETTED_BITS]."<<endl;
                }
                else{
                    cout<<"\n EITHER OF THE FRACTION HAS [UN-SETTED_BITS]."<<endl;
                }
            break;
            }
            case 20:
            {
                if(obj_pass || to_comp){
                    cout<<"\n BOTH OF THE FRACTIONS HAVE [UN-SETTED_BITS]."<<endl;
                }
                else{
                    cout<<"\n EITHER OF THE FRACTION HAS [SETTED_BITS]."<<endl;
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
        }
    }

}
