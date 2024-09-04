#include<iostream>
#include<iomanip>

using namespace std;

class Integer{
    
    private:
    
        int value;
    
    public:

        Integer();                              // a default constructor

        Integer(int);                           // a parametrized constructor
        
        Integer(string);                        // a parametrized constructor
        
        void set(int);                          // set value.

        int get() const;                        // get value at i,j 

        int bitCount();                          // returns the number of bits[1] in two's complement binary.

        int compareTo(Integer);                  // compare two integer objects.

        double doubleValue();                   // returns the double value of the integer.

        float floatValue();                     // returns the float value of the integer.

        Integer plus(const Integer&);           // add two integers and returns the sum.

        Integer minus(const Integer&);         // subtract two integers and returns the difference.

        Integer multiply(const Integer&);       // multiply two integers and returns the product.

        Integer divide(const Integer&);         // divide two integers and returns the quotient.

        static int num_of_leading_zeros(int i);     // returns the number of leading zeros form MSB 1-bit to the 2's compliment form of the integer.

        static int num_of_trailing_zeros(int i);    // returns the number of trailing zeros form LSB 1-bit to the 2's compliment form of the integer.

        static string to_binary_string(int i);      // returns a string representation of i.

        static string to_hex_string(int i);         // returns a string representation of i in base[16].

        static string to_octal_string(int i);       // returns a string representation of i in base[8].

        ~Integer();                                 // destructure of class Integer

};
