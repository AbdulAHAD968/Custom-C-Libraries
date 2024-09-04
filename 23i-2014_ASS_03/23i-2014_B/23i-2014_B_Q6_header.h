#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

//*CUSTOM CLASS.*//
class Array{

    private:

        int *arr;
        int size;

    public:

        int get_size();

        Array();                                // a default constructor.
        Array(int size);                        // a constructor with one parameter of size.
        Array(int* arr , int size);             // initiallize the array with an existing array.

        Array(const Array& obj_passed);         // a copy constructor.

        int& operator[] (int index);            // returns the integer at the specified index.[check out_of_range error]

        int& operator[](int index)const;        // returns the integer at the specified index

        const Array& operator=(const Array& );        // copies the array

        //*ARITHEMATIC OPERATORS.*//

        Array operator+(const Array& obj_passed);      // adds the two arrays.
        Array operator-(const Array& obj_passed);      // subtracts the two arrays.
        Array operator++();                             // pre-incriment operator.
        Array operator--();                             // pre-decriment operator.
        Array operator++(int);                          // post-incriment operator.
        Array operator--(int);                          // post-decriment operator.

        //*COMPARISON OPERATORS.*//

        bool operator==(const Array& obj_passed) const;         // compares the two arrays.
        bool operator!();                                       // returns true if the two arrays not are equal
        void operator+=(const Array& obj_passed);               // adds the two arrays
        void operator-=(const Array& obj_passed);               // subtracts the two arrays.
        int operator() (int index , int val);               // remove the value at the index and then shifts the 
                                                            // array to the left. return 1 if operation was successful. else [-1]

        //*DESTRUCTOR*//
        ~Array();

        //*FRIEND FUNCTIONS OF IO-STREAM.*//
        friend ostream& operator<<(ostream& out_put , const Array& obj);       // print result.
        friend istream& operator>>(istream& in_put , Array& obj);              // take input


        //*CONVERSION FUNCTIONS.*//
        operator float* () const;
        operator double* () const;
        operator long double* () const;

        //* reverse conversion constructors.*//
        Array(const float* float_array, int size);
        Array(const double* double_array, int size);
        Array(const long double* longDouble_Arr, int size);

};


//*ACCESS THE CONVERSION FUNCTIONS.*//
void conversion_functions(Array& a_1 , const Array& a_2);

//*ACCESS THE REMAINING FUNCTIONS.*//
void remaining_functions(Array& arr , const Array& arr_1);
