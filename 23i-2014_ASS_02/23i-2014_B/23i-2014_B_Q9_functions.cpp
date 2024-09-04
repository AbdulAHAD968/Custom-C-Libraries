#include"23i-2014_B_Q9_header.h"
#include<iostream>


// * COMPILE THE MAIN AND FUNCTION'S FILE TOGETHER TO CREATE A LINK. * //


using namespace std;


// * INITIALLIZE THE STRING WITH NULL. [DEFAULT CASE]* //
String::String(){
    str = new char[1];
    str[0] = '\0';          // null terminate
}

// * COPY THE INPUT OF USER IN A C-TYPE STRING. * //
String::String(char* input){
    
    int len=0;
    while(input[len]!='\0'){               // get the length of the string
        len++;
    }
    str = new char[len+1];               // dyamically allocate a string

    for(int i=0 ; i<len ; i++){
        str[i] = input[i];              // coppy the string data.
    }
    str[len] = '\0';                // terminate the string
}

// * DISPLAY THE STRING. * //
void String::display(){
    int len=length();

    for(int i=0 ; i<len ; i++){
        cout<<str[i];
    }
}

// * FIND THE LENGTH OF THE STRING. * //
int String::length(){
    int len=0;
    while(str[len]!='\0'){               // get the length of the string
        len++;
    }
    return len;
}

// * COPY CONSTRUCTOR. * //
String::String(const std::string &input){

    int len = input.length();            // Get the length of the input string
    str = new char[len+1];                // Dynamically allocate a string
    
    for(int i=0; i<len ; i++){
        str[i] = input[i];                  // Copy the string data
    }
    str[len] = '\0';                    // Terminate the string

}


// * INITIALLZE A STRING OF 'X' SIZE. * //
String::String(int x){          // initiallize a string of x size
    
    cout<<"\n INSIDE FUNCTION TO INITIALLIZE STRING OF A CONSTANT SIZE. \n"<<endl;

    str_1 = new char[x+1];
    for(int i=0 ; i<x ; i++){
        str_1[i] = '\0';
    }
    str_1[x] = '\0';            // terminate the string with a null terminator

    cout<<"\n THE STRING IS  ::  \n";
    display();
}

// * GET THE CHARACTER AT A SPECIFIC INDEX OF THE STRING. * //

char String::getAt(int i){
    return str[i];
}

// * SET CHARACTER AT THE INDEX ON DEMAND OF THE USER. * //

void String :: setAt(int i, char c){
    str[i] = c;
    cout<<"\n *[ THE STRING AFTER CHANGE. ]* ::  \n";
    display();
}

// * SUBSTRING OF LEN[*] FROM POS[*] <::> STRING [**] * //
void String::substr(int pos, int len){
    
    cout<<"\n *[ THE SUBSTRING OF THE STRING. ]* ::  \n";

    for(int i=pos ; i<pos+len ; i++){
        if(str[i]=='\0'){
            break;
        }
        cout<<str[i];
    }
    cout<<endl;
}

// * SUBSTRING FROM POS[*] TO THE END OF STRING. * //

void String::substr(int pos){
    
    cout<<"\n *[ THE SUBSTRING OF THE STRING. ]* ::  \n";

    for(int i=pos ; i<length() ; i++){
        if(str[i]=='\0'){
            break;
        }
        cout<<str[i];
    }
    cout<<endl;
}

// * APPEND A CHARACTER TO THE CURRENT STRING AT THE END. * //
void String::append(char a){
    int len = length();
    char* appended_string = new char[len + 2];
    strcpy(appended_string, str);
    appended_string[len] = a;
    appended_string[len + 1] = '\0'; // null terminate the string.

    str = appended_string;      // coppied string

    cout<<"\n THE APPENDED STRING IS "<<endl;
    display();

    delete [] appended_string;          // delete the allocated memory.
    appended_string = NULL;             // undangle the string
}

// * APPEND A STRING TO A STRING. * //

void String::append(std::string str_1){
    int len = length();
    char* appended_string = new char[len+str_1.length()+1];
    for(int i=0 ; i<len ; i++){
        appended_string[i] = str[i];
    }
    for(int i=0 ; i<str_1.length() ; i++){
        appended_string[len+i] = str_1[i];
    }
    appended_string[len+str_1.length()] = '\0';          // null terminate the string.
    str = appended_string;      // coppied string
    cout<<"\n THE APPENDED STRING IS "<<endl;
    display();
    delete [] appended_string;          // delete the allocated memory.
    appended_string = NULL;             // undangle the string
}

// * APPEND A C-STYLED STRING TO A STRING. * //

void String::append(char *new_str){

    int len_0 = length();               // host array length
    int len_1 = strlen(new_str)-1;      // host array length

    char* appended_string = new char[len_0 + len_1 + 1];
    
    for(int i=0 ; i<len_0 ; i++){
        appended_string[i] = str[i];
    }
    
    for(int i=0 ; i<len_1+1 ; i++){
        appended_string[len_0+i+1] = new_str[i];          // concatinaete the rest of string[new string]
    }
    
    appended_string[len_0+len_1] = '\0';          // null terminate the string.

    for(int i=0 ; i<len_0+len_1+2 ; i++){
        cout<<appended_string[i];
    }

    delete [] appended_string;
    appended_string = NULL;
}


// * CONVERT A STRING TO C-STRING AND RETURN IT ALSO. * //
char* String:: tocstring(){
    int len = length();
    char* c_str = new char[len+1];
    for(int i=0 ; i<len ; i++){
        c_str[i] = this->str[i];
    }
    c_str[len] = '\0';
    return c_str;
}

// * CHECK IF THE STRING IS EMPTY. * //

bool String::isEmpty(){
    if(str[0]=='\0'){               // starting with the base address if it is empty or not.
        return true;
    }
    else{
        return false;
    }
}

// * COPY C-STRING TO AN-OTHER STRING. * //
void String::copy(const std::string&){

    int len = strlen(str);
    string being_coppied;
    for(int i=0 ; i<len ; i++){
        being_coppied[i] = str[i];          // copy the c-string to string.
    }
    being_coppied[len] = '\0';          // null terminate string

    cout<<"\n THE COPIED C-STRING IS  ::  \n";
    
    for(int i=0 ; i<len ; i++){             // display the coppied string.
        cout<<" "<<being_coppied[i];
    }
    cout<<endl;
}

// * COPY ONE C-STRING TO ANOTHER C-STRING. * //

void String::copy(const char *temp){

    int len = strlen(temp);
    
    char* c_str = new char[len+1];
    for(int i=0 ; i<len ; i++){
        c_str[i] = temp[i];
    }
    c_str[len] = '\0';          // null terminate string
    str = c_str;

    cout<<"\n THE COPIED C-STRING IS  ::  \n";
    for(int i=0 ; i<len ; i++){             // display the coppied string.
    cout<<" "<<c_str[i];
    }
    cout<<endl;
}


// * FIND A CHARACTER IN THE STRING. * //
int String::find(char c){
    for(int i=0 ; i<length() ; i++){
        if(str[i]==c){
            return i;           // return the index of the character
        }
    }
    return -1;          // else return -1[not in string]
}

bool String::equal(std::string s){
    int length = strlen(str);
    for(int i=0 ; i<length ; i++){
        if(str[i]!=s[i]){
            return false;
        }
    }
    return true;
}

// * CONVERT STRING TO INTEGER. * //
int String::stoi(){
    return std::stoi(str);
}
// * DISTRUCTOR OF STRING CLASS. * //
String::~String(){
    delete [] str;
    str = NULL;
}
    
