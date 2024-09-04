#include "23i-2014_B_Q6_header.h"

using namespace std;

//*MAIN FUNCTION.*//
int main(){

    Array arr;          // creating an Array obj.
    cin>>arr;           // taking input via i-stream function.
    cout<<arr;

    const Array arr_1(arr);         // copied the data.

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
                conversion_functions(arr , arr_1);
            break;
            }
            case 2:
            {
                remaining_functions(arr , arr_1);

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