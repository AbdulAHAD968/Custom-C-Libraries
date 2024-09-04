#include<iostream>

using namespace std;

// * CLASS ACCOUNT. * //

class Account{
    private:

    double balance;

    public:

    Account(double set_balance);

    // inquire the balance...
    void displayBalance();

    void deposit(double amount);
    void withdraw(double amount);

    double getBalance();

};

// * UTILITY FUNCTIONS. * //

void Account::deposit(double amount){
    balance += amount;
}

void Account::withdraw(double amount){
    if(balance < amount){
        cout<<"\n INSUFFICENT BALANCE. [ "<<balance<<" ]  "<<endl;
        cout<<"\n PENALTY DEDUCTION [ $5 ] \n";
        balance -= 5;
    }
    else{
        balance -= amount;
    }
}


Account::Account(double set_balance){
    balance = set_balance;
}

double Account::getBalance(){
    return balance;
}

void Account::displayBalance(){
    cout<<"\n THE UPDATED BALANCE IS  =  [ "<<balance<<" ] \n";
}

// * CLASS [BANK]. * //

class Bank{
    private:

    Account checking;
    Account savings;

    public:

    Bank();

    Bank(double , double );

    void deposit(double amount , string account_type);

    void withdraw(double amount, string account);

    void transfer(double amount, string account);

    void printBalances();
};

Bank::Bank() : checking(0), savings(0){}           // initiallizer list.

Bank::Bank(double bal_01, double bal_02) : checking(bal_01), savings(bal_02){}     // initiallizer list.


// * DEPOSIT MONEY FUNCTION. * //
void Bank ::deposit(double amount, string account){
    if(account == "C" || account == "c"){
        checking.deposit(amount);
    }else if(account == "S" || account == "s"){
        savings.deposit(amount);
    }else{
        cout<<"\n INVALID ACCOUNT TYPE \n";
    }
}

// * WITHDRAW MONEY FUNCTION. * //

void Bank ::withdraw(double amount, string account){
    if(account == "C" || account == "c"){
        checking.withdraw(amount);
    }else if(account == "S" || account == "s"){
        savings.withdraw(amount);
    }else{
        cout<<"\n INVALID ACCOUNT TYPE \n";
    }
}

// * TRANSFER MONEY FUNCTION. * //

void Bank ::transfer(double amount, string account){
    if(account == "C" || account == "c"){
        savings.deposit(amount);
        checking.withdraw(amount);
    }else if(account == "S" || account == "s"){
        checking.deposit(amount);
        savings.withdraw(amount);
    }else{
        cout<<"\n INVALID ACCOUNT TYPE \n";
    }
}

void Bank ::printBalances(){
    cout<<"\n CHECKING BALANCE [ "<<checking.getBalance()<<" ] \n";
    cout<<"\n SAVINGS BALANCE [ "<<savings.getBalance()<<" ] \n";
}


// * MANI FUNCTION. * //

int main(){

    double set_balance, amount;
    char choice;
    Bank a2;

    cout<<"\n DO YOU WANT TO SET THE INITIAL BALANCE  <?> \n";
    cout<<"\n [Y/y] __ YES \n [N/n] __ NO \n";
    cin>>choice;
    if(choice == 'y' || choice == 'Y'){
        cout<<"\n SET THE INITIAL BALANCE = ";
        cin>>set_balance;
        cout<<"\n DO YOU WANT TO DEPOSIT THIS BALANCE IN CURRENT OR SAVING ACCOUNT?\n";
        cout<<"\n [C/c] __ CURRENT ACCOUNT \n [S/s] __ SAVING ACCOUNT \n";
        cin>>choice;
        if(choice == 'c' || choice == 'C'){
            a2 = Bank(set_balance, 0);          // set the current account balance. [using default copy constructor.]
        }
        else if(choice == 's' || choice == 'S'){
            a2 = Bank(0 , set_balance);         // set the savings account balance. [using default copy constructor.]
        }
    }
    else{
        set_balance = 0;
    }

    Account a1(set_balance);                // set the initial balance...

    a1.displayBalance();                // display function..

    string account_type;

 while(true){

    cout<<"\n WHICH OPERATION DO YOU WANT TO PERFORM ? "<<endl;
    cout<<"\n 1. DEPOSIT MONEY \n";
    cout<<"\n 2. WITHDRAW MONEY \n";
    cout<<"\n 3. TRANSFER MONEY \n";
    cout<<"\n 4. EXIT \n";
    cin>>choice;

    switch(choice){
        case '1':
        {
            cout<<"\n DO YOU WANT TO DEPOSIT  <?> \n";
            cout<<"\n [Y/y] __ YES \n [N/n] __ NO \n";
            cin>>choice;
            if(choice == 'y' || choice == 'Y'){
                cout<<"\n ENTER THE AMOUNT  = ";
                cin>>amount;

                cout<<"\n ENTER THE ACCOUNT TYPE  = ";
                cout<<"\n [C/c]   FOR CURRENT ACCOUNT. "
                <<"\n [S/s]   FOR SAVINGS ACCOUNT. \n";
                cin>>account_type;

                a2.deposit(amount, account_type);
                a2.printBalances();
            }
        }
        break;
        case '2':
        {
            cout<<"\n DO YOU WANT TO WITHDRAW  <?> \n";
            cout<<"\n [Y/y] __ YES \n [N/n] __ NO \n";
            cin>>choice;
            if(choice == 'y' || choice == 'Y'){
                cout<<"\n ENTER THE AMOUNT  = ";
                cin>>amount;

                 cout<<"\n ENTER THE ACCOUNT TYPE  = ";
                cout<<"\n [C/c]   FOR CURRENT ACCOUNT. "
                <<"\n [S/s]   FOR SAVINGS ACCOUNT. \n";
                cin>>account_type;

                 a2.withdraw(amount, account_type);
                 a2.printBalances();
    
            }else{
                cout<<"\n CANCELLED \n";
                break;
            }
        }
        break;
        case '3':
        {
                cout<<"\n O YOU WANT TO TRANSFER MONEY BETWEEN THE ACCOUNTS  <?> \n";
                cout<<"\n [Y/y] __ YES \n [N/n] __ NO \n";
                cin>>choice;
                if(choice == 'y' || choice == 'Y'){
                    cout<<"\n ENTER THE AMOUNT  = ";
                    cin>>amount;
                    cout<<"\n ENTER THE ACCOUNT TYPE  = ";
                    cout<<"\n [C/c]   FOR CURRENT ACCOUNT. "
                    <<"\n [S/s]   FOR SAVINGS ACCOUNT. \n";
                    cin>>account_type;

                    a2.transfer(amount, account_type);
                    a2.printBalances();
                }
                else{
                    cout<<"\n CANCELLED \n";
                    break;
                }
        }
        break;
        case '4':
        {
            cout<<"\n EXITING... \n";
            break;
        }
        default:
        {
            cout<<"\n INVALID CHOICE \n";
            break;
        }
    }

    cout<<"\n CONTINUE  <?> \n";
    cout<<"\n [Y/y] __ YES \n [N/n] __ NO \n";
    cin>>choice;

    if(choice == 'N' || choice == 'n'){
        break;
    }

 }

return 0;
}