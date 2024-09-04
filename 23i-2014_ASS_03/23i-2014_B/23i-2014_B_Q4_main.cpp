#include "23i-2014_B_Q4_header.h"

using namespace std;


//*MAIN FUNCTION.*//
int main(){
    
    int row,col;
    cout<<"\nENTER THE NUMBER OF ROWS. [TRY TO KEEP SYMMETRY PLEASE.]";
    cin>>row;
    while(row<0){
        cout<<"\nTRY AGAIN. ENTER THE [+VE] NUMBER OF ROWS.";
        cin>>row;
    }
    cout<<"\nENTER THE NUMBER OF COLUMNS. [TRY TO KEEP SYMMETRY PLEASE.]";
    cin>>col;
    while(col<0){
        cout<<"\nTRY AGAIN. ENTER THE [+VE] NUMBER OF COLUMNS.";
        cin>>col;
    }

    Matrix mat_1(row,col);
    cin>>mat_1;
    cout<<mat_1;

    ////////////////////////////////

    cout<<"\n ENTER DATA FOR THE OTHER OBJECT [TO BE OVERLOADED]. \n";
    cout<<"\nENTER THE NUMBER OF ROWS. [TRY TO KEEP SYMMETRY PLEASE.]";
    cin>>row;
    while(row<0){
        cout<<"\nTRY AGAIN. ENTER THE [+VE] NUMBER OF ROWS.";
        cin>>row;
    }
    cout<<"\nENTER THE NUMBER OF COLUMNS. [TRY TO KEEP SYMMETRY PLEASE.]";
    cin>>col;
    while(col<0){
        cout<<"\nTRY AGAIN. ENTER THE [+VE] NUMBER OF COLUMNS.";
        cin>>col;
    }

    Matrix mat_2(row, col);
    cin>>mat_2;
    cout<<mat_2;

    ////////////////////////////////

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
                conversion_functions(mat_1 , mat_2 , row , col);
            break;
            }
            case 2:
            {
                remaining_functions(mat_1 , mat_2 , row , col);

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