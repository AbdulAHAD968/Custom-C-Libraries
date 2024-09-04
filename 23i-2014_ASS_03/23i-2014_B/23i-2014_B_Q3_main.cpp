#include "23i-2014_B_Q3_header.h"

using namespace std;

int main()
{

    char* input = new char[100];
    cout<<"\n ENTER A LINE TO PROCEED [RANDOM]"<<endl;
    cin.getline(input,100);

    STRING s_1(input);
    cout<<s_1<<endl;

    cout<<"\n ENTER DATA FOR THE [CONSTANT] OBJECT. "<<endl;
    cin.getline(input,100);
    const STRING s_3(input);         // constant object.

    ////////////////////////////////////////////////////////////////////////

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
                conversion_functions();
            break;
            }
            case 2:
            {
                other_functions(s_1, s_3);

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

    delete[] input; // unallocate memory
    input = NULL;   // undangle the array.

return 0;
}
