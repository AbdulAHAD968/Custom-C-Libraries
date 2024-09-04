#include<iostream>
#include<iomanip>
#include<cstring>

using namespace std;

bool queens(int** board, int n, int col);
void print_chess_board(int** board, int n);
bool find_position(int** board, int row, int col, int n);

int main() {
    
    int num;
    cout<<"\n ENTER A POSITIVE NUMBER ";
    cin>>num;

    while(num < 0){
        cout<<"\n ENTER A POSITIVE NUMBER ";
        cin>>num;
    }

    int** board = new int*[num];
    for(int i=0 ; i<num ; i++){
        board[i] = new int[num];
    }

    for(int i=0 ; i<num ; i++){
        for(int j=0 ; j<num ; j++){
            board[i][j] = 0;
        }
    }

    if(queens(board, num, 0)){
        cout<<"\n QUEENS CAN BE PLACED. \n";
    }
    else{
        cout<<"\n QUEENS CANNOT BE PLACED. \n";
    }

    // Deallocate memory
    for(int i=0 ; i<num ; i++){
        delete[] board[i];
    }
    delete[] board;

    return 0;
}

bool queens(int** board, int n, int col){
    if(col == n){
        print_chess_board(board, n);
        return true;
    }

    bool result = false;
    for(int i=0 ; i<n ; i++){
        if(find_position(board, i, col, n)){
            board[i][col] = 1;               // Place the queen set the queen to Q
            
            result = queens(board, n, col + 1) || result;           // check if we can place further.
            board[i][col] = 0;              // Backtrack set the queen back to 0
        }
    }

    return result;
}

void print_chess_board(int** board, int n){
    cout<<"\n THE ARRANGEMENT OF QUEEN ON THE BOARD IS = \n\n";

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(board[i][j] == 1){ 
                cout<<"Q";
            }
            cout<<"  |  ";
        }
        cout<<"\n  ";
        for(int k=0 ; k<n*2+1 ; k++){
            cout<<"--";
        }
        cout<<"\n";
    }
}

bool find_position(int** board, int row, int col, int n){

    for(int i=0 ; i<col ; i++){
        if(board[row][i] != 0){             // Check the row
            return false;
        }
    }

    for(int i=row , j=col; i>=0 && j>=0; i--, j--) {
        if(board[i][j] != 0){                       // Check upper diagonal on left side.  
            return false;
        }
    }

    for(int i=row , j=col ; i<n && j>=0 ; i++ , j--){
        if(board[i][j] != 0){                   // function to check for the lower diagonal
            return false;
        }
    }

    return true;
}
