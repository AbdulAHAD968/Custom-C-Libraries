#include<iostream>
#include<iomanip>

using namespace std;


// PROTOYPE OF THE FUNCTIONS. //

int find_factorial(int num);

int pascal(int row, int col);

// MAIN FUNCTION. //

int main(){

    int row,col;
    bool exit= true;

    while(exit){

    cout<<"\nENTER THE NUMBER OF ROW  [**  C  col] = "; 
    cin>>row;

    while(row<0){
        cout<<"\nENTER A POSITIVE ONE. THANKS  :) \n";
        cout<<"\nENTER THE NUMBER OF ROW  [**  C  col] = "; 
        cin>>row;
    }
    cout<<"\nENTER THE NUMBER OF COL  [row  C  **] = "; 
    cin>>col;

    while(col<0 || col > row){
        cout<<"\nENTER A POSITIVE NUMBER LESS THAN THE NUMBER OF ROWS. THANKS  :) \n";
        cout<<"\nENTER THE NUMBER OF COL  [row  C  **] = "; 
        cin>>col;
    }

    int result = pascal(row,col);               // basically teh combinations...

    cout<<"\nTHE PASCAL TRIANGLE VALUE IS = "<<result<<endl<<endl;


     cout<<"\nDO YOU WISH TO CONTINUE? [1/0] = ";
     cin>>exit;
    }
return 0;
}

// UTILITY FUNCTIIONS. //

int pascal(int row, int col){

    int cobination =  find_factorial(row)  /  ( find_factorial(col) * find_factorial(row -col) );

    return cobination;                  // return
}


int find_factorial(int num){

    if(num==0){                     // base case...
        return 1;
    }
    else{                   // recusrive case...
        return num * find_factorial(num-1);             // calculating the factorial...
    }
}


