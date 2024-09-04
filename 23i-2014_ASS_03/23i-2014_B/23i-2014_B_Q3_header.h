#include<iostream>
#include<cstring>

using namespace std;


//*CUSTOM CLASS.*//
class STRING{
    
    private:

        char* input;

    public:

        //*CONSTRUCTORS.*//

        STRING();                               // parameterless constructor.
        STRING(char* str);                      // constructor for constant c-string.
        STRING(const STRING&);                  // copy constructor.
        STRING(int x);                          // initiallize a string of predefined size.


        char& operator [](int index);               // returns the character at index.
        const char& operator [](int index) const;     // returns the character at index for sonstant obj.

        STRING& operator+(const STRING &str);       // append a string at the end of string.
        STRING& operator+(const char &ch);           // append a character at the end of string.
        STRING& operator+(char *&ch);               // append a c-string at the end of string.

        STRING& operator-(const STRING &str);       // remove the substring from the string.
        STRING& operator-(const string &str );      // remove the substring from the string.
        bool operator!();                           // return true is the string is not empty.

        //*COPYING THE TWO STRINGS.*//

        STRING& operator=(const STRING &str);   // copy-assignment one string to an-other string.
        STRING& operator=(const string &str);   // copy-assignment one string to an-other string.
        STRING& operator=(const char *str);     // copy one c-string to an-other string.

        //*CHECK THE EQUALITY OF THE STRINGS.*//

        bool operator==(const STRING&) const;   // returns true if the strings are equal.
        bool operator==(const string&) const;   // returns true if the strings are equal.
        bool operator==(char* ) const;          // returns true if the strings are equal.


        //*GETTER TYPE FUNCTIONS FOR INDEX.*//

        int& operator() (char);                // returns the index of character being searched. 
        int& operator() (const STRING);        // GET THE INDEX OF [WORD] IF THE [OBJ] IS PASSED.
        int& operator() (const string&);       // GET THE INDEX OF [WORD] IF THE [STRING] IS PASSED.
        int& operator() (char *);              // GET THE INDEX OF [WORD] IF THE [C-STRING] IS PASSED.
        STRING operator*(int a);               //multiples the string by i times and return the string.

        int length();                   // returns the length of string

        ~STRING();                       // destructor...


    //*FRIEND FUNCTIONS.*//
    friend ostream& operator<<(ostream& input, const STRING&);          //Outputs the string.
    friend istream& operator>> (istream& ouput, STRING&);               //Inputs the string.

    //*CONVERSION FUNCTIONS.*//
    static string to_string(const char* cstr);         //from native to user defined(c-string to string conversion).
    static char* to_c_string(const string str);        // from user dfined to native(string to c-string conversion).

};

//*ACCESSING THE REMAINING FUNCTIOS.*//
void other_functions(STRING &s_1, const STRING &s_3);

//*ACCESSING THE CONVERSION FUNCTIONS.*//
void conversion_functions();