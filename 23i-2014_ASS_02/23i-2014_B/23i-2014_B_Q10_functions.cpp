#include"23i-2014_B_Q10_header.h"


// * DEFAULT PARAMETER - LESS CONSTRUCTOR. * //
Integer::Integer(){
    value = 0;
}

// * USER DEFINED PARAMETERIZED CONSTRUCTOR. * //
Integer::Integer(int i){
    value = i;
}

// * PARAMETRIZED CONSTRUCTOR WITH STRING AS AN INPUT PARAMETER. * //
Integer::Integer(string s){
    value = stoi(s);             // string to integer conversion.
}


// * SETTER FUNCTION FOR INTEGER VALUE. * //
void Integer::set(int i){
    value = i;
}


// * GETTER FUNCTION FOR INTEGER VALUE. * //
int Integer::get() const{
    return value;
}


// * COUNT THE NUMBER OF 1's IN 2'S COMPLIMENT FORM. * //
int Integer::bitCount(){
    int count =0;
    value = ~value;         // 1's complement
    value += 1;             // 2's complement

    for(int i=0 ; i<16 ; i++){          // 16-bit integer
        if( value & ( 1 << i ) ){           // masking with AND and using bit-shift left operator
            count++;
        }
    }
    return count;
}


// * COMPARE TWO INTEGER OBJECTS. * //
int Integer::compareTo(Integer comp_obj){
    if( comp_obj.get() == value ){
        return 0;
    }
    else if( value > comp_obj.get() ){
        return 1;
    }
    else{
        return -1;
    }
}


// * GET THE DOUBLE VALUE OF THE INTEGER. * //
double Integer:: doubleValue(){
    return static_cast<double>(value);          // type cast int to double.
}

// * GET THE FLOAT VALUE OF THE INTEGER. * //


float Integer:: floatValue(){
    return static_cast<float>(value);           // type cast int to float.
}


// * GET THE SUM BY ADDING TWO OBJECTS. * //
Integer Integer:: plus(const Integer& new_obj){     // returning the new integer object 
        return value + new_obj.get();
}


// * GET THE DIFFERENCE BY ADDING TWO OBJECTS. * //
Integer Integer::minus(const Integer& new_obj){      // returning the new integer object
        return value - new_obj.get();
}


// * GET THE PRODUCT BY MULTIPLYING TWO OBJECTS. * //
Integer Integer::multiply(const Integer& new_obj){      // returning the new integer object
        return value * new_obj.get();
}


// * GET THE QUOTIENT BY DIVIDING TWO OBJECTS. * //
Integer Integer::divide(const Integer& new_obj){      // returning the new integer object
        return value / new_obj.get();
}


// * GET THE [0] BIT'S FROM {MSB} IN 2's COMPLIMENT FORM.  * //
int Integer:: num_of_leading_zeros(int i){          // sharable functions
    
    int count=0;
    i = ~i;             // taking 1's complement
    i += 1;             // taking 2's complement
    
    for(int j=15 ; j>=0 ; j--){         // for 16-bit integers
        if(!( i & (j<<1) ) ){           // masking with AND and using bitshift left operator 
            count++;
        }
    }
    return count;
}


// * GET THE [1] BIT'S FROM {LSB} IN 2's COMPLIMENT FORM.  * //
int Integer:: num_of_trailing_zeros(int i){          // sharable functions
    
    int count=0;
    i = ~i;             // taking 1's complement
    i += 1;             // taking 2's complement
    
    for(int j=0 ; j<16 ; j++){              // 16-bit integer.
        if( !( i & (1<<j) ) ){              // masking with AND and using the bitshift left operator.
            count++;
        }
    }
    return count;
}


// * GET THE STRING REPRESENTION OF [integer]. * //
string Integer:: to_binary_string(int i){           // shareable functions.
    string s = "";

    for(int j=15 ; j>=0 ; j--){         // from MSB to LSB
        if( i & (1<<j) ){
            s += "1";           // if the bit was [1] append 1 to string.
        }
        else{
            s += "0";           // if the bit was [0] append 0 to string.
        }
    }
    return s;
}


// * GET THE OCTAL REPRESENTATION OF [integer] * //
string Integer:: to_octal_string(int i){           // shareable functions.
    string s = "";

    for(int j=7 ; j>=0 ; j--){         // from LSB to MSB
        if( i & (1<<j) ){
            s += "1";           // if the bit was [1] append 1 to string.
        }
        else{
            s += "0";           // if the bit was [0] append 0 to string.
        }
    }
    return s;
}


// * GET THE HEXADECIMAL REPRESENTATION OF [integer] * //
string Integer:: to_hex_string(int i){           // shareable functions.
    string s = "";

    for(int j=15 ; j>=0 ; j--){         // from LSB to MSB
        if( i & (1<<j) ){
            s += "1";           // if the bit was [1] append 1 to string.
        }
        else{
            s += "0";           // if the bit was [0] append 0 to string.
        }
    }
    return s;
}


// * DESTRUCTOR OF THE INTEGER CLASS. * //
Integer::~Integer(){

}