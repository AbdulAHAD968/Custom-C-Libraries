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


//*ACCESS THE CONVERSION FUNCTIONS.*//
void conversion_functions(Polynomial& a_1 , Polynomial& a_2);

//*ACCESS THE REMAINING FUNCTIONS.*//
void remaining_functions(Polynomial& arr , Polynomial& arr_1);

