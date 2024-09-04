#include"23i-2014_B_Q10_header.h"


int main(){
    
    Integer obj_1;          // the parameterless constructor.

    int value;
    static int counter_for_loops=0;
    bool exit = true;

    while(exit){
        
        cout<<"\n\n ------------------------------ ";
        cout<<"\n | COUNTER FOR LOOP = "<<setw(5)<<counter_for_loops<<"   | ";
        cout<<"\n ------------------------------ \n";

        cout<<"\n ------------------------------ ";
        cout<<"\n | ENTER AN INTEGER VALUE  =  | ";
        cout<<"\n ------------------------------ \n";
        cin>>value;

        Integer obj_2(value); 

    
            int choice;
            cout<<"\n WHAT OPERATION DO YOU WANT TO PERFORM ? "<<endl;
            cout<<"\n 1. GET THE INTEGER VALUE";
            cout<<"\n 2. COUNT THE NUMBER OF [1's] IN [2's COMPLIMENT FORM] ";
            cout<<"\n 3. COMPARE TWO INTEGER OBJECTS. ";
            cout<<"\n 4. -> GET THE DOUBLE VALUE OF INTEGER ";
            cout<<"\n 5. -> GET THE FLOAT VALUE OF INTEGER ";
            cout<<"\n 6. -> [ADD] TWO INTEGER OBJECTS AND RETURN {THE SUM.}";
            cout<<"\n 7. -> [SUBTRACT] TWO INTEGER OBJECTS AND RETURN {THE Difference.}";
            cout<<"\n 8. -> [MULTIPLY] TWO INTEGER OBJECTS AND RETURN {THE Product.}";
            cout<<"\n 9. -> [DIVIDE] TWO INTEGER OBJECTS AND RETURN {THE Quotient.}";
            cout<<"\n10. -> GET THE [0] BIT'S FROM {MSB} IN 2's COMPLIMENT FORM. ";
            cout<<"\n11. -> GET THE [0] BIT'S FROM {LSB} IN 2's COMPLIMENT FORM";
            cout<<"\n12. -> GET THE * STRING *      REPRESENTATION OF [integer].";
            cout<<"\n13. -> GET THE * OCTAL *       REPRESENTATION OF [integer].";
            cout<<"\n14. -> GET THE * HEXADECIMAL * REPRESENTATION OF [integer].";
            cout<<"\n15.            {-- EXIT AT 15 --} ";
            cin>>choice;

            switch(choice){
                case 1:
                {
                    cout<<"\n THE INTEGER VALUE IS  :: "<<obj_2.get();
                    break;
                }
                case 2:
                {
                    cout<<"\n THE NUMBER OF [1's] IN [2's COMPLIMENT FORM] IS  :: "<<obj_2.bitCount();
                    cout<<"\n ! NOTE ! THE REPRESENTATION IS IN 16-bits.\n";
                    break;
                }
                case 3:
                {
                    int int_to_comp;
                    cout<<"\n * COMPARE TWO INTEGER OBJECTS *  \n";
                    
                    Integer comp_obj;
                    cout<<"\n ENTER AN INTEGER VALUE  =  ";
                    cin>>int_to_comp;
                    
                    comp_obj.set(int_to_comp);      // set the value of object.
                    
                    int result = obj_2.compareTo(comp_obj);
                    
                    if(result==0){
                        cout<<"\n THE TWO INTEGER OBJECTS ARE EQUAL.";
                    }else if(result==1){
                        cout<<"\n THE FIRST OBJECT  [ "<<value<<" ] IS LESS THAN THE SECOND  [ "<<int_to_comp<<" ]  \n";
                    }else{
                        cout<<"\n THE FIRST OBJECT  [ "<<value<<" ] IS GREATER THAN THE SECOND  [ "<<int_to_comp<<" ]  \n";
                    }
                    break;
                }
                case 4:
                {
                    cout<<"\n THE DOUBLE VALUE OF INTEGER IS  :: "<<obj_2.doubleValue();
                    break;
                }
                case 5:
                {
                    cout<<"\n THE FLOAT VALUE OF INTEGER IS  :: "<<obj_2.floatValue();
                    break;
                }
                case 6:
                {
                    Integer returned_sum;           // this will be the sum returning object.
                    
                    int int_to_comp;
                    cout<<"\n * ADD TWO INTEGER OBJECTS AND RETURN {THE SUM.} *  \n";
                    
                    Integer obj_4;
                    cout<<"\n ENTER AN INTEGER VALUE  =  ";
                    cin>>int_to_comp;
                    
                    obj_4.set(int_to_comp);      // set the value of object.
                    
                    returned_sum = obj_2.plus(obj_4);
                    
                    cout<<"\n THE SUM IS  :: "<<returned_sum.get();
                    break;
                }
                case 7:
                {
                    Integer returned_diff;           // this will be the difference returning object.
                    
                    int int_to_comp;
                    cout<<"\n * SUBTRACT TWO INTEGER OBJECTS AND RETURN {THE Difference.} *  \n";
                    
                    Integer obj_4;
                    cout<<"\n ENTER AN INTEGER VALUE  =  ";
                    cin>>int_to_comp;
                    
                    obj_4.set(int_to_comp);           // set the value of object.
                    
                    returned_diff = obj_2.minus(obj_4);
                    
                    cout<<"\n THE Difference IS  :: "<<returned_diff.get();
                    break;

                }
                case 8:
                {
                    Integer returned_product;           // this will be the product returning object.
                    
                    int int_to_comp;
                    cout<<"\n * MULTIPLY TWO INTEGER OBJECTS AND RETURN {THE Product.} *  \n";
                    
                    Integer obj_4;
                    cout<<"\n ENTER AN INTEGER VALUE  =  ";
                    cin>>int_to_comp;
                    
                    obj_4.set(int_to_comp);           // set the value of object.
                    
                    returned_product = obj_2.multiply(obj_4);
                    
                    cout<<"\n THE Product IS  :: "<<returned_product.get();
                    break;
                }
                case 9:
                {
                    Integer returned_quotient;           // this will be the quotient returning object.
                    
                    int int_to_comp;
                    cout<<"\n * DIVIDE TWO INTEGER OBJECTS AND RETURN {THE Quotient.} *  \n";
                    
                    Integer obj_4;
                    cout<<"\n ENTER AN INTEGER VALUE [no floating point var is allowed]  =  ";
                    cin>>int_to_comp;
                    
                    while(int_to_comp<0){
                        cout<<"\n INVALID INPUT. ENTER A POSITIVE INTEGER VALUE  =  ";
                        cin>>int_to_comp;
                    }
                    
                    obj_4.set(int_to_comp);           // set the value of object.
                    
                    returned_quotient = obj_2.divide(obj_4);
                    
                    cout<<"\n THE Quotient IS  :: "<< returned_quotient.get() <<endl;
                    break;
                }
                case 10:
                {
                    cout<<"\n THE [0] BIT'S FROM {MSB} -> {LSB} IN 2's COMPLIMENT FORM IS  :: "<<obj_2.num_of_leading_zeros(value);
                    break;
                }
                case 11:
                {
                    cout<<"\n THE [0] BIT'S FROM {LSB} -> {MSB} IN 2's COMPLIMENT FORM IS  :: "<<obj_2.num_of_trailing_zeros(value);
                    break;
                }
                case 12:
                {
                    cout<<"\n WORKING WIHT A 16-BIT INTEGER...\n";
                    cout<<"\n THE STRING REPRESENTATION OF [integer] IS  :: "<<obj_2.to_binary_string(value);
                    break;
                }
                case 13:
                {
                    cout<<"\n WORKING WIHT A 8-BIT INTEGER...\n";
                    cout<<"\n THE {OCTAL} REPRESENTATION OF [integer] IS  :: "<<obj_2.to_octal_string(value);
                    break;
                }
                case 14:
                {
                    cout<<"\n WORKING WIHT A 16-BIT INTEGER...\n";
                    cout<<"\n THE {HEXA-DECIMAL} REPRESENTATION OF [integer] IS  :: "<<obj_2.to_hex_string(value);
                    break;
                }
                case 15:
                {
                    exit = false;
                    cout<<"\n EXITING...";
                    break;
                }
                default:
                {
                    cout<<"\n INVALID CHOICE :) ";
                    break;
                }
            }

        counter_for_loops++;

   }

return 0;
}