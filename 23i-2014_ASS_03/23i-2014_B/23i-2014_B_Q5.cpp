#include<iostream>
#include<cmath>

using namespace std;

//*CUSTOM CLASS.*//
class Polynomial{

    private:

        double* cofficents;
        int degree;
    
    public:

        Polynomial();                                   // a default constructor.
        Polynomial(int);                                // a constructor with one parameter to recieve the degree.
        Polynomial(const Polynomial& copy);             //*COPY CONSTRUCTOR.*//

        Polynomial& operator=(const Polynomial& copy);   // asssigns a polynomial.

        bool operator==(const Polynomial&);             // returns true if the polynomial is equal to another.

        Polynomial& operator+(const Polynomial& obj);   // add two polynomials.

        Polynomial& operator-(const Polynomial& obj);   // subtract two polynomials.

        void operator+=(const Polynomial& obj);         // add two polynomials.

        void operator-=(const Polynomial& obj);         // subtract two polynomials.

        ~Polynomial();                                  // destructor of the polynomial class.


        //*FRIEND FUNCTIONS OF IO-STREAM.*//
        friend ostream& operator<<(ostream& out_put , const Polynomial& obj);       // print result.
        friend istream& operator>>(istream& in_put , Polynomial& obj);              // take input from the user.


         //*CONVERSION FUNCTIONS.*//
        operator float* () const;
        operator double* () const;
        operator long double* () const;

        //* reverse conversion constructors.*//
        Polynomial(const float* float_array, int size);
        Polynomial(const double* double_array, int size);
        Polynomial(const long double* longDouble_Arr, int size);

};

//*COSTRUCTORS OF THE CLASS.*//


//*parameter-less constructor.*//
Polynomial::Polynomial(){
    degree = 0;
    cofficents = new double[degree];
}

//*constructor with one parameter(degree).*//
Polynomial::Polynomial(int degree){
    int help;
    if(degree<0){
        help = -degree;
        this->cofficents = new double[help+1];    // +1 for a constant variable if any.
    }
    else{
        this->degree = degree;
        this->cofficents = new double[this->degree+1];    // +1 for a constant variable if any.
    }
}

//*copy constructor.*//
Polynomial::Polynomial(const Polynomial& copy){
    
    int help;
    this->degree = copy.degree;
    
    if(this->degree < 0){
        help = -(this->degree);
        cofficents = new double[help+1];    // +1 for a constant variable if any.

        for(int i=0 ; i <= this->degree; i++){
            cofficents[i] = copy.cofficents[i];
        }
    }
    else{
        cofficents = new double[this->degree+1];
        for(int i=0 ; i <= this->degree; i++){
            cofficents[i] = copy.cofficents[i];    // +1 for a constant variable if any.
        }
    }
}

//*ASSIGNMENT OPERATOR.*//
Polynomial& Polynomial::operator=(const Polynomial& copy){
    if(this == &copy){
        cout<<"\nTHE OBJECT WAS ALREADY BEING POINTED. [SELF-ASSIGNMENT_CASE] \n";
        return *this;       // is the obj. is already being pointed to it-self.
    }

    delete [] this->cofficents;        // avoid memory leakage.

    this->degree = copy.degree;

    if(this->degree >= 0){
        cofficents = new double[this->degree+1];       // re-allocate the memory.
        for(int i=0 ; i<=this->degree; i++){
            if(copy.cofficents[i] ==0){
                this->cofficents[i] = 0;
            }else{
                cofficents[i] = copy.cofficents[i];
            }
        }
    }
    else{
        cofficents = new double[this->degree+1];       // re-allocate the memory.
        for(int i=this->degree ; i<=0 ; i++){
            if(copy.cofficents[i] ==0){
                this->cofficents[i] = 0;
            }else{
                cofficents[i] = copy.cofficents[i];
            }
        }
    }

return *this;
}

//*DESTRUCTOR OF THE CLASS.*//
Polynomial::~Polynomial(){
    delete []cofficents;    // delete the allocated meory.
    cofficents = NULL;      //undangle
}

//*CHECK IF THE TWO POLYNOMIALS ARE EQUAL.*//
bool Polynomial::operator==(const Polynomial& obj){
    if(this->degree!= obj.degree){
        return false;       //if the degree is diff. no need to compare further.
    }
    for(int i=0 ; i<= this->degree; i++){
        if(this->cofficents[i]!= obj.cofficents[i]){
            return false;
        }
    }

return true;
}

//*ADD TWO POLYNOMIALS.*//
Polynomial& Polynomial::operator+(const Polynomial& obj){

    if(obj.degree > this->degree ){

        cofficents = new double[obj.degree];

        for(int i=0  ; i<=this->degree ; i++){
            cofficents[i] = this->cofficents[i];
        }
        for(int i=this->degree  ; i<=obj.degree ; i++){
            this->cofficents[i] = 0;
        }
    }

    for(int i=0 ; i<= obj.degree ; i++){
        this->cofficents[i] = this->cofficents[i] + obj.cofficents[i];
    }
    
return *this;
}

//*SUBTRACT TWO POLYNOMIALS.*//
Polynomial& Polynomial::operator-(const Polynomial& obj){
    
    if(obj.degree > this->degree ){
        this->degree = obj.degree;
    }

    for(int i=0 ; i<= this->degree; i++){
        this->cofficents[i] = this->cofficents[i] - obj.cofficents[i];
    }
    
return *this;
}

//*ADD AND ASSIGN TWO POLYNOMIALS.*//
void Polynomial::operator+=(const Polynomial& obj){
    if(this->degree < obj.degree){
        this->degree = obj.degree;
    }
    for(int i=0 ; i<= this->degree; i++){
        this->cofficents[i] += obj.cofficents[i];
    }
}

//*SUBTRACT AND ASSIGN TWO POLYNOMIALS.*//
void Polynomial::operator-=(const Polynomial& obj){
    if(this->degree < obj.degree){
        this->degree = obj.degree;
    }
    for(int i=0 ; i<=this->degree; i++){
        this->cofficents[i] -= obj.cofficents[i];
    }
}

//*O-STREAM FUNCTION FOR PRINTING OUTPUT.*//
ostream& operator<<(ostream& out_put , const Polynomial& obj){

    cout<<"\n THE POLYNOMIAL EQUATION OF DEGREE  [ "<<obj.degree<<" ] IS  ::> "<<endl;
    
    if(obj.degree>=0){
        out_put<<"\n\t  {    ";
        for(int i=obj.degree ; i>=0; i--){

            if(obj.cofficents[i]!=0)
            {
                out_put<<" ( ";
            }
            if(obj.cofficents[i]==0){
                continue;
            }
            else{
                out_put<<obj.cofficents[i]<<"[X^"<<i<<"] ";
            }
            out_put<<")   +   ";
        }
        out_put<<"\b\b\b\b    }\n"<<endl;
    
    }else{                                  // un-used i built this for negative degree.
        out_put<<"\n\t  {    ";
        for(int i=obj.degree ; i<=0; i++){
            out_put<<" ( ";
            if(obj.cofficents[i]==0){
                continue;
            }
            else{
                out_put<<obj.cofficents[i]<<"[X^"<<-i<<"] ";
            }
            out_put<<")   +   ";
        }
        out_put<<"\b\b\b\b   }\n"<<endl;
    }

return out_put;
}

//*I-STREAM FUNCTION FOR TAKING INPUT.*//
istream& operator>>(istream& in_put , Polynomial& obj){
    cout<<"\nENTER THE COEFFICIENTS OF THE POLYNOMIAL <> \n";

    if(obj.degree==0){
        cout<<"\n ENTER THE VALUE OF CONSTANT [IF ANY] : ";
        in_put>>obj.cofficents[0];
    }
    else if(obj.degree>0){
        for(int i=0 ; i <= obj.degree; i++){
            cout<<"\nENTER COFFICENT OF { X^"<<i<<" } ";
            in_put>>obj.cofficents[i];
        }
    }else if(obj.degree<0){
        cout<<"hello;";
        for(int i=obj.degree ; i>=0 ; i++){
            cout<<"\nENTER COFFICENT OF { X^"<<i<<" } ";
            in_put>>obj.cofficents[i];
        }
    }

return in_put;
}


//*CONVERSION FUNCTIONS.*//

//*int to float conversion.*//
Polynomial::operator float* () const{

    float* f_array = new float[degree];
    for(int i=0 ; i<degree ; i++){
        f_array[i] = static_cast<float>(cofficents[i]);
    }

    cout<<"\n THE CONVERTED [FLOAT ARRAY] IS = \n";
    for(int i=0 ; i<degree ; i++){
        cout<<f_array[i]<<" ";
    }
    cout<<endl;

return f_array;
}

//*int to double conversion.*//
Polynomial::operator double* () const{
    double* d_array = new double[degree];
    for(int i=0 ; i<degree ; i++){
        d_array[i] = static_cast<double>(cofficents[i]);
    }

    cout<<"\n THE CONVERTED [DOUBLE ARRAY] IS = \n";
    for(int i=0 ; i<degree ; i++){
        cout<<d_array[i]<<" ";
    }
    cout<<endl;

return d_array;
}

//*int to long double conversion.*//
Polynomial::operator long double* () const{
    long double* ld_array = new long double[degree];
    for(int i=0 ; i<degree ; i++){
        ld_array[i] = static_cast<long double>(cofficents[i]);
    }

    cout<<"\n THE CONVERTED [LONG DOUBLE ARRAY] IS = \n";
    for(int i=0 ; i<degree ; i++){
        cout<<ld_array[i]<<" ";
    }
    cout<<endl;

return ld_array;
}

//*reverse conversion functions.*//

//*float to int conversion.*//
Polynomial::Polynomial(const float* float_array, int size){
    this->degree = size;
    this->cofficents = new double[size];
    for(int i=0 ; i<=size ; i++){
        this->cofficents[i] = static_cast<int>( float_array[i] );
    }

    cout<<"\n THE CONVERTED POLYNOMIAL EQ. IS AS PER MENTIONED."<<endl;

    cout<<"\n\t  {    ";
        for(int i=size ; i>=0; i--){

            if(this->cofficents[i]!=0)
            {
                cout<<" ( ";
            }
            if(this->cofficents[i]==0){
                continue;
            }
            else{
                cout<<this->cofficents[i]<<"[X^"<<i<<"] ";
            }
            cout<<")   +   ";
        }
    cout<<"\b\b\b\b    }\n"<<endl;

    // as it is a constructor,therefore no return.
}

//*double to int conversion.*//
Polynomial::Polynomial(const double* double_array, int size){
    this->degree = size;
    this->cofficents = new double[size];
    for(int i=0 ; i<=size ; i++){
        this->cofficents[i] = static_cast<int>( double_array[i] );
    }

    cout<<"\n THE CONVERTED POLYNOMIAL EQ. IS AS PER MENTIONED."<<endl;

    cout<<"\n\t  {    ";
        for(int i=size ; i>=0; i--){

            if(this->cofficents[i]!=0)
            {
                cout<<" ( ";
            }
            if(this->cofficents[i]==0){
                continue;
            }
            else{
                cout<<this->cofficents[i]<<"[X^"<<i<<"] ";
            }
            cout<<")   +   ";
        }
    cout<<"\b\b\b\b    }\n"<<endl;

    // as it is a constructor,therefore no return.
}

//*long double to int conversion.*//
Polynomial::Polynomial(const long double* longDouble_Arr, int size){
    this->degree = size;
    this->cofficents = new double[size];
    for(int i=0 ; i<=size ; i++){
        this->cofficents[i] = static_cast<int>( longDouble_Arr[i] );
    }

    cout<<"\n THE CONVERTED POLYNOMIAL EQ. IS AS PER MENTIONED."<<endl;

    cout<<"\n\t  {    ";
        for(int i=size ; i>=0; i--){

            if(this->cofficents[i]!=0)
            {
                cout<<" ( ";
            }
            if(this->cofficents[i]==0){
                continue;
            }
            else{
                cout<<this->cofficents[i]<<"[X^"<<i<<"] ";
            }
            cout<<")   +   ";
        }
    cout<<"\b\b\b\b    }\n"<<endl;

    // as it is a constructor,therefore no return.
}



//*ACCESS THE CONVERSION FUNCTIONS.*//
void conversion_functions(Polynomial& a_1 , Polynomial& a_2);

//*ACCESS THE REMAINING FUNCTIONS.*//
void remaining_functions(Polynomial& arr , Polynomial& arr_1);



//*MAIN FUNCTION.*//
int main(){

    int degree;
    cout<<"\nENTER THE HIGHEST DEGREE OF THE POLYNOMIAL <> ";
    cin>>degree;

    Polynomial obj(degree);
    cin>>obj;
    cout<<obj;

    ///////////////////////////////////////////

    cout<<"\n==> PLEASE ENTER THE DATA FOR THE OTHER OBJECT TO BE OVERLOADED. \n";
    cout<<"\n==> ENTER THE HIGHEST DEGREE OF THE POLYNOMIAL <> ";
    cin>>degree;
    
    Polynomial obj_1(degree);
    cin>>obj_1;
    cout<<obj_1;

    while(true){

        int sup_choice;
        cout<<"\n [1]. VIEW THE CONVERSION FUNCTIONS. ";
        cout<<"\n [2]. VIEW THE REMAINING [OVERLOAD] FUNCTIONS. ";
        cout<<"\n [0]. {!!!---EXIT---!!!}."<<endl;
        cout<<"\n\t {ENTER YOUR CHOICE} :: ";
        cin>>sup_choice;

        switch(sup_choice){
            case 1:
            {
                conversion_functions(obj , obj_1);
            break;
            }
            case 2:
            {
                remaining_functions(obj , obj_1);

            break;
            }
            case 0:
            {
                cout<<"\n {!!!---EXITING THE PROGRAM---!!!}"<<endl;
                return 0;
            }
            default:
            {
                cout<<"\n INVALID CHOICE!!!"<<endl;
            break;
            }
        }//switch
    }//loop[]

    

return 0;
}


//*ACCESS THE CONVERSION FUNCTIONS.*//
void conversion_functions(Polynomial& a_1 , Polynomial& a_2){
    
    while(true){

        int choice;
        cout<<"\n [1]. FLOAT TO INT. ";
        cout<<"\n [2]. DOUBLE TO INT. ";
        cout<<"\n [3]. LONG DOUBLE TO INT. ";
        cout<<"\n [4]. INT TO FLOAT. ";
        cout<<"\n [5]. INT TO DOUBLE. ";
        cout<<"\n [6]. INT TO LONG DOUBLE. ";
        cout<<"\n [0]. {!!!---EXIT---!!!}."<<endl;
        cout<<"\n\t {ENTER YOUR CHOICE} :: ";
        cin>>choice;

        switch(choice){
            case 1:
            {
                int size;
                cout<<"\n ENTER THE HIGHEST DEGREE OF THE POLYNOMIAL <*>  \n";
                cin>>size;
                float* float_array = new float[size];
                cout<<"\nENTER THE ELEMENTS OF THE POLYNOMIAL [FLOATING ARRAY]\n";
                for(int i=0 ; i<=size ; i++){
                    cout<<"FOR DEGREE  =  [ "<<i<<" ]  =  ";
                    cin>>float_array[i];
                }
                Polynomial float_arr(float_array, size);

                delete [] float_array;
                float_array = NULL;
            
            break;
            }
            case 2:
            {
                int size;
                cout<<"\n ENTER THE HIGHEST DEGREE OF THE POLYNOMIAL <*>  \n";
                cin>>size;
                double* double_array = new double[size];
                cout<<"\nENTER THE ELEMENTS OF THE POLYNOMIAL [DOUBLEING ARRAY]\n";
                for(int i=0 ; i<=size ; i++){
                    cout<<"FOR DEGREE  =  [ "<<i<<" ]  =  ";
                    cin>>double_array[i];
                }
                Polynomial double_arr(double_array, size);

                delete [] double_array;
                double_array = NULL;
            
            break;
            }
            case 3:
            {
                int size;
                cout<<"\n ENTER THE HIGHEST DEGREE OF THE POLYNOMIAL <*>  \n";
                cin>>size;
                long double* longDouble_Arr = new long double[size];
                cout<<"\nENTER THE ELEMENTS OF THE POLYNOMIAL [LONG DOUBLEING ARRAY]\n";
                for(int i=0 ; i<=size ; i++){
                    cout<<"FOR DEGREE  =  [ "<<i<<" ]  =  ";
                    cin>>longDouble_Arr[i];
                }
                Polynomial longDouble_arr(longDouble_Arr, size);

                delete [] longDouble_Arr;
                longDouble_Arr = NULL;

            break;
            }
            case 4:
            {
                float* f_array;
                cout<<"\n THE POLYNOMIAL EQUATION AFTER [INT] TO [FLOAT] CONVERSION.\n";
                f_array = a_1;

                delete f_array;
                f_array = NULL;

            break;               
            }
            case 5:
            {
                double* d_array;
                cout<<"\n THE POLYNOMIAL EQUATION AFTER [INT] TO [DOUBLE] CONVERSION.\n";
                d_array = a_1;

                delete d_array;
                d_array = NULL;

            break;
            }
            case 6:
            {
                long double* ld_array;
                cout<<"\n THE POLYNOMIAL EQUATION AFTER [INT] TO [LONG DOUBLE] CONVERSION.\n";
                ld_array = a_1;

                delete ld_array;
                ld_array = NULL;

            break;
            }
            case 0:
            {
                cout<<"\n {!!!---RETURNING TO MAIN---!!!}"<<endl;
                return;
            }
            default:
            {
                cout<<"\n INVALID CHOICE!!!"<<endl;
            break;
            }

        }//end switch

    }//end loop
}



//*ACCESS THE REMAINING FUNCTIONS.*//
void remaining_functions(Polynomial& obj , Polynomial& obj_1){
    
    while(1){

        int choice;
        cout<<"\nWHICH OPERATION DO YOU WANT TO PERFORM ? \n";
        cout<<"\n[1]. FOR COPYING THE OBJECT. ";
        cout<<"\n[2]. FOR ASSIGNING ONE POLYNOMIAL TO OTHER. ";
        cout<<"\n[3]. FOR ADDING TWO POLYNOMIALS. ";
        cout<<"\n[4]. FOR SUBTRACTING TWO POLYNOMIALS. ";
        cout<<"\n[5]. FOR ADDING AND ASSIGNING TWO POLYNOMIALS. ";
        cout<<"\n[6]. FOR SUBTRACTING AND ASSIGNING TWO POLYNOMIALS. ";
        cout<<"\n[7]. CHECK IF BOTH THE POLYNOMIALS ARE EQUAL TO EACH OTHER.";
        cout<<"\n[0]. EXIT. \n";
        cout<<"\nENTER YOUR CHOICE : ";
        cin>>choice;

            switch(choice){
                case 1:
                {
                    cout<<"\n COPYING THE POLYNOMIALS IN A NEW OBJ. OF POLYNOMIAL CLASS. \n";
                    Polynomial copy(obj);
                    cout<<copy;
                break;
                }
                case 2:
                {   
                    cout<<"\n ASSIGNING ONE POLYNOMIAL TO OTHER. \n";
                    cout<<"\nTHE OBJECT BEFORE ASSIGNING  =  \n";
                    cout<<obj;
                    
                    obj=obj_1;           // assigning it to already created object.
                    cout<<"\nTHE OBJECT AFTER ASSIGNING  =  \n";
                    cout<<obj;
                break;
                }
                case 3:
                {
                    cout<<"\n ADDING TWO POLYNOMIALS. \n";
                    cout<<"\nTHE OBJECT BEFORE ADDING  =  \n";
                    cout<<obj;

                    obj = obj + obj_1;
                    cout<<"\nTHE OBJECT AFTER ADDING  =  \n";
                    cout<<obj;
                break;
                }
                case 4:
                {
                    cout<<"\n SUBTRACTING TWO POLYNOMIALS. \n";
                    cout<<"\nTHE OBJECT BEFORE SUBTRACTING  =  \n";
                    cout<<obj;

                    obj = obj - obj_1;
                    cout<<"\nTHE OBJECT AFTER SUBTRACTING  =  \n";
                    cout<<obj;
                break;
                }
                case 5:
                {
                    cout<<"\n ADDING AND ASSIGNING TWO POLYNOMIALS. \n";
                    cout<<"\nTHE OBJECT BEFORE ADDING  =  \n";
                    cout<<obj;

                    obj += obj_1;
                    cout<<"\nTHE OBJECT AFTER ADDING AND ASSIGNING =  \n";
                    cout<<obj;
                break;
                }
                case 6:
                {
                    cout<<"\n SUBTRACTING AND ASSIGNING TWO POLYNOMIALS. \n";
                    cout<<"\nTHE OBJECT BEFORE SUBTRACTING  =  \n";
                    cout<<obj;

                    obj -= obj_1;
                    cout<<"\nTHE OBJECT AFTER SUBTRACTING  =  \n";
                    cout<<obj;
                break;
                }
                case 7:
                {
                    cout<<"\n CHECKING IF BOTH THE POLYNOMIALS ARE EQUAL TO EACH OTHER. \n";
                    if(obj == obj_1){
                        cout<<"\n BOTH THE POLYNOMIALS ARE EQUAL TO EACH OTHER. \n";
                    }
                    else{
                        cout<<"\n BOTH THE POLYNOMIALS ARE NOT EQUAL TO EACH OTHER. \n";
                    }
                break;
                }
                case 0:
                {
                    cout<<"\n {!!!---RETURNING TO MAIN---!!!}"<<endl;
                    return;
                }
                default:
                {
                    cout<<"\n INVALID CHOICE. \n";
                    break;
                }

            }//switch
        int exit=1;
        cout<<"\nDO YOU WANT TO CONTINUE ?";
        cout<<"\n [1]. YES.   [0]. EXIT.  \n";
        cin>>exit;
        if(exit==0){
            return;
        }
    }//loop
}