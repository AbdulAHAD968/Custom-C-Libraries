#include"23i-2014_B_Q9_header.h"
#include<iostream>

// * COMPILE THE MAIN AND FUNCTION'S FILE TOGETHER TO CREATE A LINK.* //

using namespace std;
int main(){
    
    int gime_length;
    String s1;
    char input[100];

    bool exit=true;
    
    while(exit){

    cout<<"\n ENTER A LINE [ AS A PASSING PARAMETERS ]\n ";
    cin.ignore();
    cin.getline(input, 100);

    String s2(input);

    int choice;
        
        cout<<"\n WHAT OPERATION YOU WANT TO DO ?";
        cout<<"\n 1. PARAMETER_LESS CONSTRUCTOR.";
        cout<<"\n 2. DISPLAY THE STRING.";
        cout<<"\n 3. [GET] THE LENGTH OF THE STRING.";
        cout<<"\n 4. [GET] THE CHARACTER AT A SPECIFIC INDEX OF THE STRING.";
        cout<<"\n 5. [SET] CHARACTER AT THE INDEX ON DEMAND OF THE USER.";
        cout<<"\n 6. -> SUBSTRING OF LEN[*] FROM POS[*] STRING.";
        cout<<"\n 7. -> SUBSTRING FROM POS[*] TO THE END OF STRING.";
        cout<<"\n 8. -> APPEND A CHARACTER TO POS[*] STRING.";
        cout<<"\n 9. -> APPEND A STRING AT THE END OF STRING*[HOST].";
        cout<<"\n10. -> APPEND A C-STYLE STRING AT THE END OF STRING*[HOST].";
        cout<<"\n11. -> CONVERT A STRING TO [C-STYLE] STRING.";
        cout<<"\n12. -> CHECK IF THE STRING IS EMPTY.";
        cout<<"\n13. -> COPY *[C-STRING]* TO AN-OTHER STRING.";
        cout<<"\n14. -> COPY *{C-STRING}* TO AN-OTHER *{C-STRING}*.";
        cout<<"\n15. -> FIND A CHARACTER IN THE STRING.";
        cout<<"\n16. -> [CHECK IF BOTH THE STRINGS ARE EQUAL.]";
        cout<<"\n17. -> CONVERT STRING TO INTEGER   *[stoi]*  ";
        cout<<"\n18. EXIT.";
        cout<<"\n ENTER YOUR CHOICE : ";


        cin>>choice;

        switch(choice){
            case 1:
            {
                s1 = String();
                break;
            }
            case 2:
            {
                cout<<"\n CALLING THE DISPLAY STRING FUNCTION\n ";
                s2.display();
                
                break;
            }
            case 3:
            {
                cout<<"\n THE LENGTH OF THE STRING IS :: [ "<<s2.length()<<" ] "<<endl;
                break;
            }
            case 4:
            {
                int give_index;
                cout<<"\n GET THE CHARACTER AT A SPECIFIC INDEX [**] \n"<<endl;
                cout<<"\n ENTER THE INDEX OF THE CHARACTER YOU WANT TO GET : ";
                s2.display();

                cout<<"\n\n THE LENGTH OF THE STRING IS :: [ "<<s2.length()<<" ]\n"<<endl;

                cout<<"\n ENTER THE INDEX OF THE CHARACTER YOU WANT TO GET : ";
                cin>>give_index;
                cout<<"\n THE CHARACTER AT INDEX  [ "<<give_index<<" ] IS  ::  { "<<s2.getAt(give_index-1)<<" } "<<endl;
                
                break;
            }
            case 5:
            {
                int give_index;
                char alpha;
                cout<<"\n GET THE CHARACTER AT A SPECIFIC INDEX [**] \n"<<endl;
                cout<<"\n ENTER THE INDEX OF THE CHARACTER YOU WANT TO GET : ";
                s2.display();

                cout<<"\n\n THE LENGTH OF THE STRING IS :: [ "<<s2.length()<<" ]\n"<<endl;

                cout<<"\n ENTER THE INDEX OF THE CHARACTER YOU WANT TO GET : ";
                cin>>give_index;
                cout<<"\n THE CHARACTER AT INDEX  [ "<<give_index<<" ] IS  ::  { "<<s2.getAt(give_index-1)<<" } "<<endl;

                cout<<"\n ENTER THE INDEX OF THE CHARACTER YOU WANT TO SET : ";
                cin>>give_index;
                cout<<"\n ENTER THE CHARACTER YOU WANT TO SET : ";
                cin>>alpha;
                
                cout<<"\n ORIGNAL STRING *[BEFORE CHANGE]"<<endl;
                s2.display();

                s2.setAt(give_index-1, alpha);                // changing the character at the entered position.

                break;
            }
            case 6:
            {
                int give_pos, give_len;
                cout<<"\n SUBSTRING OF LEN[*] FROM POS[*] <::> STRING [**] \n"<<endl;
                cout<<"\n ENTER THE POSITION OF THE SUBSTRING : ";
                cin>>give_pos;
                while( give_pos<0 && give_pos<s2.length() ){
                    cout<<"\n ENTER A VALID POSITION [ >= 0 ] and [ <=str.len ] : ";
                    cin>>give_pos;
                }
                cout<<"\n ENTER THE LENGTH OF THE SUBSTRING : ";
                cin>>give_len;
                while( give_len<0 && give_len+give_pos<s2.length() ){
                    cout<<"\n ENTER A VALID LENGTH [ >= 0 ] and [ <=str.len ] : ";
                    cin>>give_len;
                }
                s2.substr(give_pos-1, give_len);
                break;
            }
            case 7:
            {
                int give_pos;
                cout<<"\n SUBSTRING FROM POS[*] TO THE END OF STRING. \n"<<endl;
                cout<<"\n ENTER THE POSITION OF THE SUBSTRING : ";
                cin>>give_pos;
                while( give_pos<0 && give_pos<s2.length() ){
                    cout<<"\n ENTER A VALID POSITION [ >= 0 ] and [ <=str.len ] : ";
                    cin>>give_pos;
                }
                s2.substr(give_pos-1);
                break;
            }
            case 8:
            {
                char alpha;
                cout<<"\n APPEND A CHARACTER TO STRING. \n"<<endl;
                cout<<"\n ENTER THE CHARACTER YOU WANT TO APPEND : ";
                cin>>alpha;
                s2.append(alpha);
                break;
            }
            case 9:
            {
                string input;
                cout<<"\n APPEND A STRING TO STRING. \n"<<endl;
                cout<<"\n ENTER THE STRING YOU WANT TO APPEND : ";
                cin>>input;
                s2.append(input);
                break;
            }
            case 10:
            {
                char input[100];
                cout<<"\n APPEND A C-STYLE STRING TO STRING. \n"<<endl;
                cout<<"\n ENTER THE C-STYLE STRING YOU WANT TO APPEND : ";
                cin.ignore();
                cin.getline(input, 100);
                s2.append(input);
                break;
            }
            case 11:
            {
                cout<<"\n CONVERT A STRING TO [C-STYLE] STRING. \n"<<endl;
                cout<<"\n ORIGINAL STRING :   ";
                s2.display();
                cout<<"\n CONVERTED STRING :   "<<s2.tocstring()<<endl;
                break;
            }
            case 12:
            {
                int result;
                if( s2.isEmpty() ){
                    cout<<"\n THE STRING IS EMPTY. \n"<<endl;
                }else{
                    cout<<"\n THE STRING IS NOT EMPTY. \n"<<endl;
                }

                break;
            }
            case 13:
            {
                string input;
                cout<<"\n COPY *[C-STRING]* TO ANOTHER STRING. "<<endl;
                cout<<"\n ENTER THE STRING YOU WANT TO COPY : ";
                getline(cin, input);
                s2.copy(input);
                break;
            }
            case 14:
            {
                char input[100];
                cout<<"\n COPY *{C-STRING}* TO ANOTHER *{C-STRING}*. "<<endl;
                cout<<"\n ENTER THE STRING YOU WANT TO COPY : ";
                cin.ignore();
                cin.getline(input , 100);
                s2.copy(input);
                break;
            }
            case 15:
            {
                int is_present;
                char char_to_search;
                cout<<"\n ENTER THE CHARACTER[*] YOU WANT TO SEARCH : ";
                cin>>char_to_search;

                is_present = s2.find(char_to_search);

                if(is_present != 1){
                    cout<<"\n THE CHARACTER ["<<char_to_search<<" ] :: WAS FOUND AT THE INDEX  [ "<<is_present+1<<" ] \n"<<endl;
                }
                else{
                    cout<<"\n THE CHARACTER ["<<char_to_search<<" ] :: WAS NOT FOUND. \n"<<endl;
                }

                break;
            }
            case 16:
            {
                int is_equal;
                string input;
                cin.ignore();
                cout<<"\n ENTER THE STRING [*] YOU WANT TO CHECK : ";
                getline(cin, input);
                is_equal = s2.equal(input);
                if(is_equal == 1){
                    cout<<"\n THE STRINGS ARE EQUAL. \n"<<endl;
                }
                else{
                    cout<<"\n THE STRINGS ARE NOT EQUAL. \n"<<endl;
                }
                break;
            }
            case 17:
            {
                string str_input;
                cin.ignore();
                cout << "\n ENTER THE STRING [*] YOU WANT TO CONVERT TO INTEGER : ";
                getline(cin, str_input);

                String myString(str_input.c_str());      // converts the string to c-string

                for(int i=0 ; i<myString.length() ; ++i){
                    int integerVal=myString.getAt(i) - '0';
                    cout<<"\n THE INTEGER VALUE OF CHARACTER [ "<<myString.getAt(i)<<" ] IS :: [ "<<integerVal<<" ] ";
                }

                break;
            }
            case 18:
            {
                exit = false;
                cout<<"\n EXITING THE PROGRAM. \n"<<endl;
                break;
            }
            default:
                cout<<"\n INVALID CHOICE. \n";
                break;
        }
        cout<<endl;
    }
    
return 0;
}