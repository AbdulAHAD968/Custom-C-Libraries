#include <iostream>
using namespace std;

// PRINTING STRING FUNCTION. //
void print_str(int arr[], int n);

// ASSISTING FUNCTION. //
void convert_Binary(int* arr, int n, int i);

string* binary_string(int n);


// MAIN_FUNCTION. //

int main()
{
    int n;
    int exit;

    while(exit){

        cout<<"\n ENTER THE NUMBER OF STRINGS TO BE GENERATED = ";
        cin>>n;

    while(n<0){
        cout<<"\nENTER A POSITIVE NUMBER. THANKS  :) \n";
        cout<<"\n ENTER THE NUMBER = ";
        cin>>n;
    }

    string* result = binary_string(n);              // calling the binary gen. function...

    delete[] result;

    cout<<"\n DO YOU WANT TO CONTINUE [1] <> ELSE CASE [0] = ";
    cin>>exit;
    }

    
return 0;
}


string* binary_string(int n)
{
    string* result = new string[n];         // allocate memory for string...

    int* arr = new int[n];         // create array of n size...
    convert_Binary( arr, n , 0);
    delete [] arr;
    return result;

    delete[] result;            // but it will not be executed... end of scope == delete string
}

// ASSISTING FUNCTION. //
void convert_Binary(int* arr, int n, int i)
{
    if(i==n){
        print_str(arr, n);              // call the print function....
        return;
    }

    arr[i] = 0;
    convert_Binary(arr, n , i+1);

    if(i==0 || (i>0 && arr[i-1] != 1)){                 // ensure no consective 1's...
        arr[i] = 1;
        convert_Binary( arr , n , i+1);
    }
}

// PRINTING STRING FUNCTION. //
void print_str(int arr[], int n)
{
    for(int i=0 ; i<n ; i++){
        cout<<arr[i];
    }
    cout<<endl;
}