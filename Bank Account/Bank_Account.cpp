#include "BankingApplication.h"

BankAccount::BankAccount() {
    AccountId = ""  ;
    Type_Account = "" ;
    Balance = 0 ;
}

BankAccount::BankAccount(double amount, int Id) {
    Balance = amount ;
    string ID = to_string(Id) ;
    Id = 3 - (int)ID.size() ;
    while (Id--)
    {
        ID.insert(0, "0") ;
    }
    ID = "FCAI-" + ID ;
    Type_Account = "(Basic)" ;

    AccountId = ID ;
}

bool BankAccount::withdraw(double amount) {
    if (Balance >= amount)
    {
        Balance -= amount ;
        cout << "Thank you.\nAccount ID : " << AccountId << "\nNew Balance "
             << Balance << endl ;
        return true ;
    }
    else
    {
        cout << "Sorry. This is more than what you can withdraw.\n" ;
        return false ;
    }
}

void BankAccount::deposit(double amount) {

    Balance += amount ;
    cout << "Thank you.\nAccount ID : " << AccountId << "\nNew Balance "
         << Balance << endl ;
}

void BankAccount::set_id(const string & Id) {
    AccountId = Id ;
}

void BankAccount::set_balance(double Balance_) {
    Balance = Balance_ ;
}

double BankAccount::get_balance() const {
    return Balance;
}

string BankAccount::get_id() {
    return AccountId ;
}

string BankAccount::get_type() {
    return Type_Account ;
}

void BankAccount::set_type(const string &Type) {
    Type_Account = "( " + Type + " )" ;
}