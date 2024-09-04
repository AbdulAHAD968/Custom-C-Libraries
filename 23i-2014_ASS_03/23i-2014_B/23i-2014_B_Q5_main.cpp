#include "23i-2014_B_Q5_header.h"

using namespace std;


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