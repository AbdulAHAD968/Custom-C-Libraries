#include "23i-2014_B_Q3_header.h"

using namespace std;


//*CONSTRUCTORS.*//

//*parameterless constructor.*//
STRING :: STRING(){

    input = new char[2];    // array must be atleast of 2 size.
    input[1] = '\0';        // null terminate the array. 
}

//*parametrized constructor.*//
STRING :: STRING(char* fill){

    input = new char[strlen(fill)];
    strcpy(input,fill);
    input[strlen(fill)] = '\0'; // Null-terminate the copied string
}

//*parameterized constructor if c-string is passed.*//
STRING :: STRING(const STRING& fill){

    input = new char[strlen(fill.input)];
    strcpy(input , fill.input);
    input[strlen(fill.input)] = '\0'; // Null-terminate the copied string
}

//*initialize a string of predefined size.*//
STRING::STRING(int x){
    input = new char[x];        // define a new array of 'x' size.
}

//*get the character at a specific index.*//
char& STRING::operator [](int index){
    return input[index];
}

//*same- we have to return the character at the index but this time the obj. will be constant.*//
const char& STRING:: operator [](int index) const{
    return input[index];
}

//*concatinate two strings.*//
STRING& STRING :: operator+(const STRING &str){

    int len = strlen(this->input)+strlen(str.input) + 1;    //   [+1] for null terminator
    char* add_up = new char[len];
    
    strcpy(add_up, this->input);
    strcat(add_up, str.input);

    STRING result(add_up);
    delete[] input;            // Free dynamically allocated memory
    input = add_up;

    *this = result;

return *this;
}

//*append a character at the end of array.*//
STRING& STRING::operator+(const char &ch){
    int len = strlen(input)+2;
    char* add_up = new char[len];

    strcpy(add_up , this->input);
    add_up[len-2] = ch;         // Append the character
    add_up[len-1] = '\0';       // Null terminate the string

    STRING result(add_up);
    delete[] input;            // Free dynamically allocated memory
    input = add_up;

    *this = result;

return *this;
}

//*append a c-string at the end of string.*//
STRING& STRING::operator+(char *&ch){

    int len = strlen(ch) + strlen(this->input) + 1;

    char* add_up = new char[len];
    strcpy(add_up, this->input);
    strcat(add_up, ch);
    delete[] input;            // Free dynamically allocated memory
    input = add_up;

return *this;
}

//* remove the substring from the string*//
STRING& STRING::operator-(const STRING &str){

    char* loc = strstr(this->input , str.input);        // Get the position of the substring.

    if(loc == NULL){
        return *this;       // if the string to be deleted is not avialble.
    }else{
        int len = strlen(this->input) - strlen(str.input) + 1;
        char* add_up = new char[len];
        strncpy(add_up, this->input , len);
        add_up[len-1] = '\0';       // null terminate
        strcat(add_up, loc+strlen(str.input) );
        delete[] this->input;            // Free dynamically allocated memory
        this->input = add_up;
    }

return *this;
}

//*remove the substring from the string.*//
STRING& STRING::operator-(const string& str){
    const char* sub_str = str.c_str();
    int input_len = strlen(this->input);
    int sub_len = strlen(sub_str);

    if(sub_len==0 || sub_len>=input_len){
        return *this;       // return the orignal string.
    }else{
        int len = input_len - sub_len + 1;
        char* result = new char[len];
        int idx=0;

        for(int i=0 ; i<input_len ; ++i){
            bool found = true;
            for(int j=0 ; j<sub_len ; ++j){
                if( i+j >= input_len || this->input[i+j] != sub_str[j]){
                    found = false;
                    break;
                }
            }
            if(!found){
                result[idx++] = this->input[i];     // Skip the remaining characters
            }else{
                i += sub_len - 1;           // Skip the substring characters
            }
        }
        result[idx] = '\0';             // Null-terminate.

        delete[] this->input;       // prevent memory leakage.

        this->input = result;
    }

return *this;
}

//* return true is the string is not empty.*//
bool STRING::operator!(){
    if(input[0] == '\0'){
        return true;
    }else{
        return false;
    }
}

//* COPY ASSIGNMENT OPERATOR. *//
STRING& STRING :: operator=(const STRING &str){
    int len = strlen(str.input) + 1;
    char* add_up = new char[len];
    strcpy(add_up, str.input);
    delete[] input;            // Free dynamically allocated memory
    input = add_up;
return *this;
}

//*COPY ONE STRING TO AN-OTHER STRING. *//
STRING& STRING::operator=(const string &str){
    int len = strlen(str.c_str()) + 1;
    char* add_up = new char[len];
    strcpy(add_up, str.c_str());
    delete[] input;            // Free dynamically allocated memory
    input = add_up;
return *this;
}

//*COPY ONE C-STRING TO AN-OTHER STRING. *//
STRING& STRING::operator=(const char *str){
    int len = strlen(str) + 1;
    char* add_up = new char[len];
    strcpy(add_up, str);
    delete[] input;            // Free dynamically allocated memory
    input = add_up;
return *this;
}

//*returns true if the strings are equal.*//
bool STRING::operator==(const STRING& pass) const{
    if(strcmp(input, pass.input) == 0){
        return true;
    }else{
        return false;
    }
}
//*returns true if the strings are equal.*//
bool STRING::operator==(const string& pass) const{
    if(strcmp(input, pass.c_str()) == 0){
        return true;
    }else{
        return false;
    }
}

//*returns true if the strings are equal.*//
bool STRING::operator==(char* str) const{
    if(strcmp(input, str) == 0){
        return true;
    }else{
        return false;
    }
}

//*returns the index of character being searched.*//
int& STRING::operator() (char ch){

    static int index;
    index = -1;         // IF NOT FOUND SET to -1

    for(int i=0 ; i<strlen(this->input) ; i++){
        if(this->input[i] == ch){
            index=i;
            return index;
        }
    }
return index;
} 

//*GET THE INDEX OF [WORD] IF THE [OBJ] IS PASSED.*//
int& STRING::operator() (const STRING obj){

    static int index;
    index = -1;         // IF NOT FOUND SET to -1

    int l2 = strlen(obj.input);
    for(int i=0 ; i<strlen(this->input) ; i++){
        int j;
        for(j=0 ; j<l2 ; ++j){
            if(this->input[i+j] != obj.input[j]){
                break;
            }
        }
        if(j == l2){
            index=i;
            return index;
        }
    }

return index;
}

//*GET THE INDEX OF [WORD] IF THE [STRING] IS PASSED.*//
int& STRING::operator() (const string& str){

    static int index;
    index = -1;         // IF NOT FOUND SET to -1

    int l2 = strlen(str.c_str());
    for(int i=0 ; i<strlen(this->input) ; i++){
        int j;
        for(j=0 ; j<l2 ; ++j){
            if(this->input[i+j] != str[j]){
                break;
            }
        }
        if(j == l2){
            index=i;
            return index;
        }
    }
    
return index;
}

//*GET THE INDEX OF [WORD] IF THE [C-STRING] IS PASSED.*//
int& STRING::operator() (char* ch){

    static int index;
    index = -1;         // IF NOT FOUND SET to -1
    int l2 = strlen(ch);
    for(int i=0 ; i<strlen(this->input) ; i++){
        int j;
        for(j=0 ; j<l2 ; ++j){
            if(this->input[i+j] != ch[j]){
                break;
            }
        }
        if(j == l2){
            index=i;
            return index;
        }
    }

return index;
}

//*multiples the string by a times and return the string.*//
STRING STRING::operator* (int a){
    int len = strlen(this->input) * a + 1;
    
    char* add_up = new char[len];
    
    for(int i=0 ; i<a ; i++){
        strcat(add_up, this->input);
    }
    delete[] this->input;                           // Free previously allocated memory for input
    this->input = new char[strlen(add_up) + 1];     // Allocate memory for updated input
    strcpy(this->input, add_up);                    // Copy the concatenated string to input
    delete[] add_up;                                // Free dynamically allocated memory for temporary add_up
    

return *this; 
}

//*returns the length of string.*//
int STRING::length(){
    return strlen(this->input);
}

//*DESTRUCTOR.*//
STRING::~STRING(){
    delete[] input;
}

//*O-STREAM FUNCTION TO PRINT THE OUTPUT.*//
ostream& operator<<(ostream& out, const STRING& obj){

    out<<"\n {  "<< obj.input<<"  }"<<endl;

return out;
}

//*I-STREAM FUNCTION TO READ THE INPUT.*//
istream& operator>>(istream& in, STRING& obj){

    cout<<"\n ENTER A LINE TO PROCEED [RANDOM]"<<endl;
    in.getline(obj.input,100);

return in;
}


//*CONVERSION FUNCTIONS.*//

//*from native to user defined(c-string to string conversion).*//
string STRING::to_string(const char* cstr){
    
    string str(cstr);

return str;
}

//*from user defined to native(string to c-string conversion).*//
char* STRING::to_c_string(const string str){
    
    char* c_string = new char[str.length() + 1];
    strcpy(c_string, str.c_str());      // using builtin functions for conversion process.

return c_string;
}


//*ACCESSING THE CONVERSION FUNCTIONS.*//
void conversion_functions(){

    while(true){

        int choice;
        cout<<"\n WHAT CONVERSION YOU WANT TO PERFORM <?> "<<endl;
        cout<<"\n [1]. STRING TO C-STRING. ";
        cout<<"\n [2]. C-STRING TO STRING. ";
        cout<<"\n [0]. {!!!---EXIT---!!!}."<<endl;
        cout<<"\n\t {ENTER YOUR CHOICE} :: ";
        cin>>choice;

        switch(choice){
            case 1:
            {
                cout<<"\n ENTER A LINE TO PROCEED [RANDOM]"<<endl;
                char* input = new char[100];
                cin.ignore();
                cin.getline(input,100);
                
                string converted_string = STRING::to_string(input);
                cout<<"\n THE CONVERTED [STRING] TO [C-STRING] IS =  {  ";
                cout<<converted_string<<"  } "<<endl;

            break;
            }
            case 2:
            {
                cout<<"\n ENTER A LINE TO PROCEED [RANDOM]"<<endl;
                string input;
                cin.ignore();
                getline(cin,input);
                
                char* converted_string = STRING::to_c_string(input);
                cout<<"\n THE CONVERTED [C-STRING] TO [STRING] IS =  {  ";
                cout<<converted_string<<"  } "<<endl;
            
            break;
            }
            case 0:
            {
                cout<<"\n {!!!---RETURNING TO MAIN---!!!}"<<endl;
                return;     // empty return for void.
            }

        }//switch.
    }//loop

return;
}

//*ACCESSING THE REMAINING FUNCTIOS.*//
void other_functions(STRING& s_1, const STRING& s_3)
{
    while (true)
    {

        int choice;
        cout << "\n { SELECT THE OPERATION YOU WANT TO PERFORM }" << endl;
        cout << "\n [1].  APPEND A [STRING] TO ANOTHER STRING.";
        cout << "\n [2].  APPEND A [CHARACTER] TO A STRING.";
        cout << "\n [3].  APPEND A C-STRING TO ANOTHER STRING.";
        cout << "\n [4].  GET THE CHARACTER AT THE INDEX [NON-CONSTANT].";
        cout << "\n [5].  GET THE CHARACTER AT THE INDEX [CONSTANT].";
        cout << "\n [6].  CHECK IF THE PASSED STRING IS EMPTY.";
        cout << "\n [7].  REMOVE A SUB-STRING FROM ANOTHER STRING [OBJ].";
        cout << "\n [8].  REMOVE A SUB-STRING FROM ANOTHER STRING [STR].";
        cout << "\n [9].  COPY-ASSIGNMENT OF [ONE OBJ] TO [OTHER OBJ].";
        cout << "\n [10]. COPY-ASSIGNMENT OF [PASSED STRING] TO [OBJ].";
        cout << "\n [11]. COPY-ASSIGNMENT OF [PASSED C-STRING] TO [OBJ].";
        cout << "\n [12]. CHECK IF [BOTH THE OBJECTS ]ARE EQUAL.";
        cout << "\n [13]. CHECK IS THE [PASSED STRING] IS SIMILAR TO THE [REFERED OBJ].";
        cout << "\n [14]. CHECK IS THE [PASSED C-STRING] IS SIMILAR TO THE [REFERED OBJ].";
        cout << "\n [15]. GET THE INDEX OF [CHARACTER] BEING SEARCHED.";
        cout << "\n [16]. GET THE INDEX OF [WORD] IF THE [OBJ] IS PASSED.";
        cout << "\n [17]. GET THE INDEX OF [WORD] IF THE [STRING] IS PASSED.";
        cout << "\n [18]. GET THE INDEX OF [WORD] IF THE [C-STRING] IS PASSED.";
        cout << "\n [19]. MULTIPLY THE STRING BY [n] TIMES AND RETURN THE STRING.";
        cout << "\n [20]. RETURN THE LENGTH OF STRING.";
        cout << "\n [0]. {!!!---EXIT---!!!}." << endl;
        cout << "\n\t {ENTER YOUR CHOICE} :: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            STRING s_2;
            cout << "\n ENTER DATA FOR THE SECOND OBJECT [TO BE OVER_LOADED]. " << endl;
            cin.ignore();
            cin >> s_2;

            cout << "\n THE [FIRST OBJ]. BEFORE APPENDING. " << endl;
            cout << s_1 << endl;

            s_1 = s_1 + s_2;
            cout << "\n THE [FIRST OBJ]. AFTER APPENDING. " << endl;
            cout << s_1 << endl;
            break;
        }
        case 2:
        {
            char ch;
            cout << "\nENTER A CHARACTER TO APPEND [*] " << endl;
            cin >> ch;

            cout << "\n THE [FIRST OBJ]. BEFORE APPENDING. " << endl;
            cout << s_1 << endl;

            s_1 = s_1 + ch;

            cout << "\n THE [FIRST OBJ]. AFTER APPENDING. " << endl;
            cout << s_1 << endl;

            break;
        }
        case 3:
        {
            char *ch = new char[100];
            cout << "\n ENTER A C-STRING TO APPEND [***] " << endl;
            cin.ignore();
            cin.getline(ch, 100);

            cout << "\n THE [FIRST OBJ]. BEFORE APPENDING. " << endl;
            cout << s_1 << endl;

            s_1 = s_1 + ch;

            cout << "\n THE [FIRST OBJ]. AFTER APPENDING A [C-STRING]. " << endl;
            cout << s_1 << endl;

            delete[] ch; // unallocate the meomory.
            ch = NULL;   // undangle the array.

            break;
        }
        case 4:
        {
            int index;
            cout << "\n ENTER THE INDEX OF CHARACTER TO GET [*] " << endl;
            cin >> index;
            cout << "\nTHE CHARACTER AT THE INDEX IS  = [ ";
            cout << s_1[index - 1] << " ] " << endl;

            break;
        }
        case 5:
        {
            int index;
            cout << "\n ENTER THE INDEX OF CHARACTER TO GET [*] " << endl;
            cin >> index;
            cout << "\nTHE CHARACTER AT THE INDEX IS  = [ ";
            cout << s_3[index - 1] << " ] " << endl;
            break;
        }
        case 6:
        {
            if (s_1[0] != '\0')
            {
                cout << "\n THE STRING IS NOT EMPTY. " << endl;
            }
            else
            {
                cout << "\n THE STRING IS EMPTY. " << endl;
            }
            break;
        }
        case 7:
        {
            STRING s_2;
            cout << "\n ENTER DATA FOR THE SECOND OBJECT [TO BE SUBTRACTED]. " << endl;
            cin.ignore();
            cin >> s_2;

            cout << "\n THE [FIRST OBJ]. BEFORE REMOVING. " << endl;
            cout << s_1 << endl;

            s_1 = s_1 - s_2;
            cout << "\n THE [FIRST OBJ]. AFTER REMOVING. " << endl;
            cout << s_1 << endl;
            break;
        }
        case 8:
        {
            string s_2;
            cout << "\n ENTER DATA FOR THE STRING[TO BE SUBTRACTED]. " << endl;
            cin.ignore();
            getline(cin, s_2);

            cout << "\n THE [FIRST OBJ]. BEFORE REMOVING. " << endl;
            cout << s_1 << endl;

            s_1 = s_1 - s_2;
            cout << "\n THE [FIRST OBJ]. AFTER REMOVING. " << endl;
            cout << s_1 << endl;
            break;
        }
        case 9:
        {
            STRING s_2;
            cout << "\n ENTER DATA FOR THE SECOND OBJECT [TO BE OVER_LOADED]. " << endl;
            cin.ignore();
            cin >> s_2;

            cout << "\n THE [FIRST OBJ]. BEFORE ASSIGNING TO THE SECOND OBJ. " << endl;
            cout << s_1 << endl;

            s_1 = s_2;
            cout << "\n THE [FIRST OBJ]. AFTER ASSIGNING TO THE SECOND OBJ. " << endl;
            cout << s_1 << endl;

            break;
        }
        case 10:
        {
            string s_2;
            cout << "\n ENTER A LINE [STRING]. " << endl;
            cin.ignore();
            getline(cin, s_2);

            cout << "\n THE [FIRST OBJ]. BEFORE ASSIGNING TO THE [STRING]. " << endl;
            cout << s_1 << endl;

            s_1 = s_2;
            cout << "\n THE [FIRST OBJ]. AFTER ASSIGNING TO THE [STRING]. " << endl;
            cout << s_1 << endl;

            break;
        }
        case 11:
        {
            char *ch = new char[100];
            cout << "\n ENTER A C-STRING [STRING]. " << endl;
            cin.ignore();
            cin.getline(ch, 100);

            cout << "\n THE [FIRST OBJ]. BEFORE ASSIGNING TO THE [C-STRING]. " << endl;
            cout << s_1 << endl;

            s_1 = ch;
            cout << "\n THE [FIRST OBJ]. AFTER ASSIGNING TO THE [C-STRING]. " << endl;
            cout << s_1 << endl;

            delete[] ch; // unallocate the meomory.
            ch = NULL;   // undangle the array.

            break;
        }
        case 12:
        {
            if (s_1 == s_3)
            {
                cout << "\n THE [FIRST OBJ] AND THE [SECOND OBJ] ARE EQUAL. " << endl;
            }
            else
            {
                cout << "\n THE [FIRST OBJ] AND THE [SECOND OBJ] ARE NOT EQUAL. " << endl;
            }

            break;
        }
        case 13:
        {
            string str;
            cout << "\n ENTER A LINE [STRING]. " << endl;
            cin.ignore();
            getline(cin, str);

            if (s_1 == str)
            {
                cout << "\n THE [FIRST OBJ] AND THE [PASSED STRING] ARE SIMILAR. " << endl;
            }
            else
            {
                cout << "\n THE [FIRST OBJ] AND THE [PASSED STRING] ARE NOT SIMILAR. " << endl;
            }

            break;
        }
        case 14:
        {
            char *ch = new char[100];
            cout << "\n ENTER A C-STRING [STRING]. " << endl;
            cin.ignore();
            cin.getline(ch, 100);

            if (s_1 == ch)
            {
                cout << "\n THE [FIRST OBJ] AND THE [PASSED C-STRING] ARE SIMILAR. " << endl;
            }
            else
            {
                cout << "\n THE [FIRST OBJ] AND THE [PASSED C-STRING] ARE NOT SIMILAR. " << endl;
            }

            delete[] ch; // unallocate the meomory.
            ch = NULL;   // undangle the array.

            break;
        }
        case 15:
        {
            char ch;
            cout << "\n ENTER A CHARACTER [*]. " << endl;
            cin >> ch;

            int index = s_1(ch);

            if (index != -1)
            {
                cout << "\n THE INDEX OF [CHARACTER] BEING SEARCHED IS = [ " << index << " ] " << endl;
            }
            else
            {
                cout << "\n THE CHARACTER WAS NOT FOUND IN THE STRING." << endl;
            }

            break;
        }
        case 16:
        {
            STRING ch;
            cout << "\n ENTER DATA FOR THE [OBJ]. " << endl;
            cin.ignore();
            cin >> ch;

            int index = s_1(ch);

            if (index != -1)
            {
                cout << "\n THE INDEX OF [CHARACTER] BEING SEARCHED IS = [ " << index << " ] " << endl;
            }
            else
            {
                cout << "\n THE CHARACTER WAS NOT FOUND IN THE STRING." << endl;
            }

            break;
        }
        case 17:
        {
            string ch;
            cout << "\n ENTER A C-STRING [WORD] " << endl;
            cin.ignore();
            getline(cin, ch);

            int index = s_1(ch);

            if (index != -1)
            {
                cout << "\n THE INDEX OF [CHARACTER] BEING SEARCHED IS = [ " << index << " ] " << endl;
            }
            else
            {
                cout << "\n THE CHARACTER WAS NOT FOUND IN THE STRING." << endl;
            }

            break;
        }
        case 18:
        {
            char *ch = new char[100];
            cout << "\n ENTER A C-STRING [WORD] " << endl;
            cin.ignore();
            cin.getline(ch, 100);

            int index = s_1(ch);

            if (index != -1)
            {
                cout << "\n THE INDEX OF [CHARACTER] BEING SEARCHED IS = [ " << index << " ] " << endl;
            }
            else
            {
                cout << "\n THE CHARACTER WAS NOT FOUND IN THE STRING." << endl;
            }

            break;
        }
        case 19:
        {
            int num;
            cout << "\nENTER THE NUMBER OF TIMES YOU WANT THE STRING TO BE [SELF-MULTIPLIED] \n";
            cin >> num;

            s_1 = s_1 * num;

            cout << s_1 << endl;

            break;
        }
        case 20:
        {
            int length = s_1.length();
            cout << "\n THE LENGTH OF THE STRING IS  = " << length << endl;

            break;
        }
        case 0:
        {
            cout << "\n {!!!----RETURNING TO MAIN-----!!!}" << endl;
            return;
        }
        default:
        {
            cout << "\nINVALID INPUT.\nPLEASE ENTER THE CHOICE AGAIN  { :) }\n";
        }
        }
    }
}