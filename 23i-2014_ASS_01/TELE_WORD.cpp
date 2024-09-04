#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>
#include<chrono>

using namespace std;

using namespace std::chrono;


// Function to print the contents of the blank_array
void printBlankArray(char** blank_array , int row, int col);

int printTeleWord(char** grid, char** blank_array , int* length_bus , int row, int col);

// Function to check for the word horizontally in both forward and backward directions
bool checkHorizontal(char** grid, char** blank_array , int* length_bus , const char* word, int row, int col, int i, int j);

// Function to check for the word vertically in both forward and backward directions
bool checkVertical(char** grid, char** blank_array ,  int* length_bus , const char* word, int row, int col, int i, int j);

// Main function to search for the word in the grid
bool search_word(char** grid, char** blank_array , int* length_bus , char* words, int row, int col);

bool right_diagonal_up(char **letters, char **blank_array , int* length_bus , const char *word, int GridSize, int wordLength);
void Main_search(int g, char **grid, char **blank_array , int* length_bus , char **words, const int row_2d, const int col_2d, int &cp);
bool right_diagonal_down(char** letters, char** blank_array , int* length_bus , const char* word, int GridSize, int wordLength);
bool left_diagonal_up(char** letters, char** blank_array , int* length_bus , const char* word, int GridSize, int wordLength);
bool left_diagonal_down(char** letters, char** blank_array , int* length_bus , const char* word, int GridSize, int wordLength);



int main(){

    const int row_2d=15;
    const int col_2d=15;


    int* length_bus = new int[8];

    for(int i=0; i<8; i++){
        length_bus[i]=0;
    }

    // Allocate memory for the grid
    char** grid = new char*[row_2d];
    for(int i=0 ; i<row_2d ; i++){
        grid[i] = new char[col_2d];
    }

    char** blank_array = new char*[row_2d];
    for(int i=0 ; i<row_2d ; i++){
         blank_array[i] = new char[col_2d];
    }

    for(int i=0 ; i<row_2d ; i++){
        for(int j = 0; j < col_2d; j++){
            blank_array[i][j] = ' ';
        }
    }

    fstream count("alphabets.txt" , ios::in);

    if(!count){
        cerr<<"\n\t FILE NOT FOUND.\n"<<endl;
        return 0;
    }

    count.ignore(1000 , '\n');                  // IGNOTING FORST TWO LINES...
    count.ignore(1000 , '\n');

    int wordCount=1;
    char alpha;
    while(count.get(alpha) && alpha != '\n'){
        if(alpha == ','){
            wordCount++;
        }
    }

    count.close();
    // Allocate memory for the word array

    cout<<"\n\t NUMBER OF WORDS = "<<wordCount<<endl<<endl;


    char** words = new char*[wordCount];
    for(int i=0 ; i<wordCount ; i++){
         words[i] = new char[20];
    }


    // Open the file
    ifstream read("alphabets.txt");
    if(!read){
        cerr<<"FILE NOT FOUND. CHECK THE FILE NAME.\n";
        return 0;
    }

    for(int i = 0; i < row_2d; i++){
        for(int j=0 ; j<col_2d ; j++){              // reading words...
            char c;
            while(read>>c  &&  c==',');            // Skip commas
            grid[i][j] = c;
        }
    }
    
    //read.ignore(1000 , '\n');
    read.ignore(row_2d*col_2d*2,'\n');
    read.ignore();

    int g=0;
    while(g<wordCount && read.getline(words[g], 20, ',')){          // PICKING WORDS IGNORING COMMAS
        g++;
    }

    read.close();               // CLOSING THE FILE TO PREVENT DATA CORRUPTION...

    float average = 0;

    int* calc_average = new int[wordCount];
    for(int i = 0; i < wordCount; i++)
    {
        calc_average[i] = strlen(words[i]);
    }
    for(int i = 0; i < wordCount; i++){            // CALCULATING THE RUNNING SUM...
        average += calc_average[i];
    }

    for(int i=0 ; i<row_2d ; i++) {
        for(int j=0 ; j<col_2d; j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    for(int i=0 ; i<g ; i++)
    {
        cout<<left<<setw(12)<<words[i]<<"  ";
        if( (i+1 )%5 == 0){
            cout<<endl;
        }
    }
    cout<<endl;

    int cp = 0;

    Main_search(g, grid, blank_array ,length_bus , words, row_2d, col_2d, cp);


    int scater_word = printTeleWord(grid, blank_array,length_bus, row_2d, col_2d);

    cout<<"\n\t NUMBER OF WORDS FOUND AFTER THE SEARCH =  "<<cp<<endl;

    cout<<"\n\tAVERAGE WORD LENGTH = "<<average / wordCount<<endl;

    cout<<"\n\t THE TELE_WORD SCATTER IS  = "<<scater_word<<endl;

    int h_forward = length_bus[0];
    int h_backward = length_bus[1];
    int v_forward = length_bus[2];
    int v_backward = length_bus[3];
    int right_diagonal_down = length_bus[4];
    int right_diagonal_up = length_bus[5];
    int left_diagonal_down = length_bus[6];
    int left_diagonal_up = length_bus[7];

    int horizontal_length = h_forward + h_backward ;
    int vertical_length = v_forward + v_backward ;
    int right_diagonal_length = right_diagonal_up + right_diagonal_down ;
    int left_diagonal_length = left_diagonal_up + left_diagonal_down ;

    cout<<"\n NUMBER OF HORIZONTAL WORDS =  "<<horizontal_length<<" {"<<h_forward<<" , "<<h_backward<<" } \n"<<endl;
    cout<<"\n NUMBER OF VERTICAL WORDS =  "<<vertical_length<<" {"<<v_forward<<" , "<<v_backward<<" } \n"<<endl;
    cout<<"\n NUMBER OF RIGHT DIAGONAL WORDS =  "<<right_diagonal_length<<" { "<<right_diagonal_up<<" , "<<right_diagonal_down<<" } \n"<<endl;
    cout<<"\n NUMBER OF LEFT DIAGONAL WORDS =  "<<left_diagonal_length<<" { "<<left_diagonal_up<<" , "<<left_diagonal_down<<" } \n"<<endl;

    for(int i=0 ; i<row_2d ; i++){
        delete[] grid[i];                       // deleeting the allocated memory...
        delete[] blank_array[i];
    }
    delete[] grid;
    delete[] blank_array;

    for(int i=0 ; i<wordCount ; i++){
        delete[] words[i];
    }
    delete[] words;

    delete[] length_bus;

    grid = NULL;                        // UNDAGLING THE ARRAYS...
    words = NULL;
    blank_array = NULL;
    length_bus = NULL;

    //cout<<"\n\t NUMBER OF WORDS FOUND AFTER THE SEARCH =  "<<cp<<endl;

    return 0;
}

void Main_search(int g, char **grid, char **blank_array , int* length_bus, char **words, const int row_2d, const int col_2d, int &cp)
{
    auto totalDuration = microseconds(0);

    int maxRowCount = 0;
    int maxRowIdx = -1;
    int maxColumnCount = 0;
    int maxColumnIdx = -1;

    int* rowCounts = new int[row_2d];           // Array to store word counts per row
    int* columnCounts = new int[col_2d];        // Array to store word counts per column

    for(int i=0 ; i<row_2d ; i++){              // Initialize the counts to 0
        rowCounts[i] = 0;
        columnCounts[i] = 0;
    }

    for(int i=0 ; i<g ; i++)
    {
        auto start_time = high_resolution_clock::now();
        if( search_word(grid, blank_array,length_bus, words[i], row_2d, col_2d) ||
            right_diagonal_up(grid, blank_array,length_bus, words[i], row_2d, strlen(words[i]) )   ||
            right_diagonal_down(grid, blank_array,length_bus, words[i], row_2d, strlen(words[i]) ) ||
            left_diagonal_up(grid, blank_array,length_bus, words[i], row_2d, strlen(words[i]) )    ||
            left_diagonal_down(grid, blank_array,length_bus, words[i], row_2d, strlen(words[i]) )  )
        {
            auto end_time = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(end_time - start_time);

            totalDuration += duration;
            
            // CALLING THE ARRAY AT REAL TIME TO SEE THE FOUND WORDS...
            printBlankArray(blank_array, row_2d, col_2d);

            cout<<" { "<<words[i]<<" } IS IN THE GRID. \n";
            if( (cp==0) || (cp==20) || (cp==30) || (cp==40) ){
                cout<<"  NOTE THAT THIS IS THE { "<<cp+1<<" st }  WORD. \n";
            }else if( (cp==1) || (cp==21) || (cp==31) || (cp==41) ){
                cout<<"  NOTE THAT THIS IS THE { "<<cp+1<<" nd }  WORD. \n";
            }else if( (cp==2) || (cp==22) || (cp==32) || (cp==43) ){
                cout<<"  NOTE THAT THIS IS THE { "<<cp+1<<" rd }  WORD. \n";
            }else{
                cout<<"  NOTE THAT THIS IS THE { "<<cp+1<<" th }  WORD. \n";
            }

            cout<<"\n TIME TAKEN TO SEARCH THIS WORD = "<<duration.count()<<" MICRO_SECONDS"<<endl;

    
            for(int row=0 ; row<row_2d ; row++){            // Update the row and column counts...
                for(int col=0 ; col<col_2d ; col++){
                    if(blank_array[row][col] != ' ')
                    {
                        rowCounts[row]++;
                        columnCounts[col]++;
                    }
                }
            }
            
            cp++;
        }

    int choice;
    if(cp<g){
            
            cout<<"\n\t --------------------------------";
            cout<<"\n\t | DO YOU WANT TO SEARCH MORE?  |";
            cout<<"\n\t |    { 1.} YES  |  { 2.} NO    |";
            cout<<"\n\t --------------------------------\n";
            cin>>choice;

            if(choice != 1)
            {
                  break;          // EXIT CASE...
            }
        }
        else{
            cout<<"\n\t --------------------------------------------------";
            cout<<"\n\t |           SEARCH TERMINATED...                 |";
            cout<<"\n\t |        PRESS ANY KEY TO CONTINUE...            |";
            cout<<"\n\t | TOTAL TIME TAKEN  =  "<<totalDuration.count() <<" MICRO_SECONDS      |";
            cout<<"\n\t --------------------------------------------------\n";
            cin>>choice;
            break;
        }
    }

    // Find the heaviest row and column
    for(int i=0 ; i<row_2d ; i++){
        if(rowCounts[i] > maxRowCount)
        {
            maxRowCount = rowCounts[i];
            maxRowIdx = i;
        }
    }
    for(int j=0 ; j<col_2d ; j++){
        if(columnCounts[j] > maxColumnCount)
        {
            maxColumnCount = columnCounts[j];
            maxColumnIdx = j;
        }
    }

    cout<<"\n\t------------------------";
    cout<<"\n\t| HEAVIEST ROW    =  "<<maxRowIdx<<"  | ";
    cout<<"\n\t| HEAVIEST COLUMN =  "<<maxColumnIdx<<" | ";
    cout<<"\n\t------------------------\n";

    delete[] rowCounts;
    delete[] columnCounts;

return;
}

bool search_word(char** grid, char** blank_array , int* length_bus , char* word, int row, int col){
    int len = strlen(word);

    for(int i=0 ; i<row ; i++)
    {
        for(int j=0 ; j<col ; j++)
        {
            if(grid[i][j] == word[0])
            {
                if( checkHorizontal(grid, blank_array,length_bus, word, row, col, i, j) ||
                    checkVertical(grid, blank_array,length_bus , word, row, col, i, j)  )
                {
                    cout<<"\n\t FOUND AT POSITION ("<<i<<" , "<<j<<")\n";
                    cout<<"\n\t LENGTH OF WORD = "<<len<<endl;
                    return true;
                }
            }
        }
    }

    return false;
}

bool checkHorizontal(char** grid, char** blank_array , int* length_bus , const char* word, int row, int col, int i, int j){
    int len = strlen(word);
    int k;

    if( j+len <= col)
    {
        for(k=0 ; k<len ; k++)          // CHECKING HORIZONTAL FORWARD...
        {
            if(j+k >= 0 && j+k<col && grid[i][j+k] != word[k])
            {
                break;
            }
        }
        if(k == len)
        {
            for(k=0 ; k<len ; k++)
            {             
                if(j+k >= 0 && j+k < col)                   // UPDATING THE BLANK ARRAY...
                {
                    blank_array[i][j+k] = word[k];
                }
            }

            length_bus[0] ++;
            return true;
        }
    }

    
    if(j-len+1 >= 0)                    // Check horizontally backward
    {
        for(k=0 ; k<len ; k++)
        {
            if(j-k >= 0 && j-k<col && grid[i][j-k] != word[k])
            {
                break;
            }
        }
        if(k == len)
        {
            for(k=0 ; k<len ; k++)
            {
                if (j-k>=0  &&  j-k<col)              // UPDATING THE BLANK ARRAY...
                {
                    blank_array[i][j-k] = word[k];
                }
            }
            length_bus[1]++;
            return true;
        }
    }

    return false;
}

bool checkVertical(char** grid, char** blank_array , int* length_bus , const char* word, int row, int col, int i, int j){
    int len = strlen(word);
    int k;

                                    // Check vertically forward
    if(i+len <= row)
    {
        for(k=0 ; k<len ; k++)
        {
            if(i+k>=0 && i+k<row && grid[i+k][j] != word[k]){
                break;
            }
        }
        if(k == len){
            
            for(k=0 ; k<len ; k++)
            {
                if(i+k >= 0 && i+k < row)               // UPDATING THE BLANK ARRAY...
                {
                    blank_array[i+k][j] = word[k];
                }
            }

            length_bus[2]++;

            return true;
        }
    }

    // Check vertically backward
    if(i-len+1 >= 0){

        for(k=0 ; k<len ; k++)
        {
            if(i-k >= 0 && i-k<row && grid[i-k][j] != word[k]){
                break;
            }
        }
        if(k == len){
            
            for(k=0 ; k<len ; k++)
            {
                if(i-k >= 0 && i-k < row){              // UPDATING THE BLANK ARRAY...
                    blank_array[i-k][j] = word[k];
                }
            }

            length_bus[3]++;

            return true;
        }
    }

    return false;
}




bool right_diagonal_up(char** letters, char** blank_array, int* length_bus , const char* word, int GridSize, int wordLength){
    
    for(int i=0 ; i<=GridSize-wordLength ; i++)
    {
        for(int j=0 ; j<=GridSize-wordLength ; j++)
        {
            int k;
            for(k=0 ; k<wordLength ; k++){
                if(letters[i+k][j+k] != word[k]){
                    break;
                }
            }
            if(k == wordLength)
            {
                cout<<"\n WORD FOUND { RIGHT } DIAGONALLY AT THE POSITION ("<<i<<" , "<<j<< ")\n";
                cout<<"\n\t LENGTH OF WORD = "<<wordLength<<endl;

                if(i+wordLength <= GridSize  && j + wordLength <= GridSize){
                    for(int l=0 ; l<wordLength ; l++) {
                        blank_array[i+l][j+l] = word[l];            // UPDATING THE BLANK ARRAY...
                    }
                }
                length_bus[5]++;
                return true;
            }
        }
    }

    return false;
}


bool right_diagonal_down(char** letters, char** blank_array , int* length_bus , const char* word, int GridSize, int wordLength){
    for(int i=wordLength-1 ; i<GridSize ; i++)
    {
        for(int j=0 ; j<=GridSize-wordLength ; j++)
        {
            int k;
            for(k=0 ; k<wordLength ; k++){
                if(letters[i-k][j+k] != word[k]){
                    break;
                }
            }
            if(k == wordLength)
            {
                cout<<"\n WORD FOUND { RIGHT } DIAGONALLY AT THE POSITION ("<<i<<" , "<<j<< ")\n";
                cout<<"\n\t LENGTH OF WORD = "<<wordLength<<endl;

                if(i-wordLength+1 >= 0  &&  j+wordLength <= GridSize){
                    for(int l=0 ; l<wordLength ; l++)
                    {
                        blank_array[i-l][j+l] = word[l];            // UPDATING THE BLANK ARRAY...
                    }
                }
                length_bus[4]++;
                return true;
            }
        }
    }

    return false;
}


bool left_diagonal_up(char** letters, char** blank_array , int* length_bus , const char* word, int GridSize, int wordLength){
    
    for(int i=0 ; i<=GridSize-wordLength ; i++)
    {
        for(int j=wordLength-1 ; j<GridSize ; j++)
        {
            int k;
            for(k=0 ; k<wordLength ; k++){
                if(letters[i+k][j-k] != word[k]){
                    break;
                }
            }
            if(k == wordLength)
            {
                cout<<"\n WORD FOUND { LEFT } DIAGONALLY AT THE POSITION ("<<i<<" , "<<j<< ")\n";
                cout<<"\n\t LENGTH OF WORD = "<<wordLength<<endl;

                if(i+wordLength<=GridSize  &&  j-wordLength+1 >= 0)
                {
                    for(int l=0 ; l<wordLength ; l++){
                        blank_array[i+l][j-l] = word[l];            // UPDATING THE BLANK ARRAY...
                    }
                }
                length_bus[7]++;
                return true;
            }
        }
    }

    return false;
}


bool left_diagonal_down(char** letters, char** blank_array , int* length_bus , const char* word, int GridSize, int wordLength) {
    
    for(int i=wordLength-1 ; i<GridSize ; i++)
    {
        for(int j=wordLength-1 ; j<GridSize ; j++)
        {
            int k;
            for (k=0 ; k<wordLength ; k++){
                if (letters[i-k][j-k] != word[k]){
                    break;
                }
            }
            if(k == wordLength){

                cout<<"\n WORD FOUND { LEFT } DIAGONALLY AT THE POSITION ("<<i<<" , "<<j<< ")\n";
                cout<<"\n\t LENGTH OF WORD = "<<wordLength<<endl;

                if(i-wordLength+1 >= 0 && j-wordLength+1 >= 0){
                    for(int l=0 ; l<wordLength ; l++){
                        blank_array[i-l][j-l] = word[l];            // UPDATING THE BLANK ARRAY...
                    }
                }
                length_bus[6]++;
                return true;
            }
        }
    }

    return false;
}



// Function to print the contents of the blank_array
void printBlankArray(char** blank_array, int row, int col){
    
    cout<<"\n CURRENT STATE OF BLANK_ARRAY \n\n";
    
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            cout<<blank_array[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;
}


int printTeleWord(char** grid, char** blank_array,int* length_bus, int row, int col){
    
    int count=0;

    cout<<"THE TELE_WORD AFTER THE SEARCH IS ::>> \n";
    
    for(int i=0 ; i<row ; i++)
    {
        bool row_touced=false;

        for(int j=0 ; j<col ; j++)
        {
            if(blank_array[i][j] == ' '){
                cout << grid[i][j];                  // if the array is empty, fill it with grids data...
                row_touced = true;
            }
        }
        if(row_touced){                 // INCRIMENTING THE COUNTER IF ROW TOUCHED...
            count++;
        }
    }
    cout<<endl<<endl;

    return count;
}


