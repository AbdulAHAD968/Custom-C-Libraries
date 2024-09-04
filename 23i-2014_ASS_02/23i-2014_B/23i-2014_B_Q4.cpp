#include<iostream>
using namespace std;


void print_hollow_diamond(int num);

void print(int n, char ch);
void print_pattern(int num, int i, char char1, char char2, char char3, char char4);

void print_inverted_pattern(int num,int i , char char1, char char2, char char3, char char4);

int main(){

    int num;
    int exit;

    while(exit){

    cout<<"\n ENTER THE NUMBER OF ROWS = ";
    cin>>num;

    while(num<0){
        cout<<"\n KINDLY ENTER A POSITIVE NUMBER. THANKS :) ";
        cout<<"\n ENTER THE NUMBER OF [ROWS] = ";
        cin>>num;
    }

    cout<<endl;
    print_hollow_diamond(num);

    cout<<"\n ENTER [1] TO CONTINUE OR [0] TO EXIT : ";
    cin>>exit;
    }
    return 0;
}

void print_hollow_diamond(int num){
    print_inverted_pattern(num,1, '*', ' ', ' ', '*');
    print_pattern(num,num , '*' , ' ' , ' ' , '*');
}


// * HELPER FUNCTION * //

void print_pattern(int num, int i, char char1, char char2, char char3, char char4) {
    if(i>0){
        int k = num-i+1;

        // Printing first increasing triangle
        print(k, char1);

        // Printing second decreasing triangle
        print(i-1, char2);

        // Printing third decreasing triangle
        print(i-1, char3);

        // Printing fourth decreasing triangle
        print(num-i+1 , char4);

        cout<<endl;

        // Move to the next line and decrement i
        print_pattern(num, i-1, char1, char2, char3, char4);
    }
}

// * INVERTED PATTERN * //

void print_inverted_pattern(int num, int i, char char1, char char2, char char3, char char4){
    if(i<=num){
        int k=num-i+1;

        // Printing first decreasing triangle
        print(k, char1);

        // Printing second increasing triangle
        print(i-1, char2);

        // Printing third increasing triangle
        print(i-1, char3);

        // Printing fourth increasing triangle
        print(num-i+1, char4);

        cout<<endl;

        // Move to the next line and increment i
        print_inverted_pattern(num, i+1, char1, char2, char3, char4);
    }
}

// * CHARACTER PRINT FUNCTION * // 

void print(int n, char ch){
    if(n>0){
        cout<<ch<<" ";
        print(n-1, ch);
    }

return;
}

