#include<iostream>
#include<string>
#include<cstring>

// * COMPILE THE MAIN AND FUNCTION'S FILE TOGETHER TO CREATE A LINK. * //

using namespace std;

class String{

    char* str;
    char* str_1;
    int len;

public:
    String();                           // default constructor
    String(char *str);                  // intialize a string
    String(const string & input);       // copy constructor*
    String(int x);                      // initiallize a string of x size
    char getAt(int i);                  // get the character at index
    void setAt(int i, char c);          // set a character at index
    void substr(int pos, int len);      // get the substring from position to the given length.
    void substr(int pos);               // get the substring from position to the end of the string
    void append(char a);                // append a character to the end of the string
    void append(std::string str_1);     // append a string to the end of the string*
    void append(char *new_str);         // append a c-string to the end of the string
    int length();                      // returns the length of the string
    char *tocstring();                  // returns the c-string from a string{simple string}
    void display();                     // displays the string
    bool isEmpty();                     // returns true if the string is empty
    void copy(const std::string&);      // copy one string to another.
    void copy(const char *);            // copy c-string to another c-string
    int find(char);                     // returns the index of the character being searched.
    bool equal(std::string);            // returns true if the string is equal
    int stoi();                         // returns the integer value of the string
    ~String();                          // deletes the string class from the memory
};



