#ifndef BankingApplication_CPP_BANKINGAPPLICATION_H
#define BankingApplication_CPP_BANKINGAPPLICATION_H

# include <iostream>
# include <fstream>
# include <vector>
# include <iomanip>
# include <regex>

using namespace std ;

class BankAccount {
protected:
    string AccountId ;
    string Type_Account ;
    double Balance ;
public:
    BankAccount() ;
    explicit BankAccount(double amount, int Id) ;
    virtual bool  withdraw(double amount) ;
    virtual void deposit(double amount) ;
    void set_id(const string & Id) ;
    void set_balance(double Balance) ;
    void set_type(const string & Type) ;
    double get_balance() const ;
    string get_type() ;
    string get_id() ;
};

class Client {
private:
    BankAccount acc ;
    string name ;
    string  add ;
    string ph ;
    static int num_client ;

public:
    Client() ;
    void Set_Name(string & Name) ;
    void Set_Address(string & Address_) ;
    void Set_Phone(string & phone_) ;
    string Get_Name() ;
    string Get_Address() ;
    string Get_Phone() ;
    static int Get_Number_Clients () ;
};

class SavingBankAccount : public BankAccount{
private:
    double MinBalance = 1000 ;
public:
    SavingBankAccount(double amount, int Id) ;
    bool withdraw(double amount) ;
    void deposit(double amount) ;
};

class BankingApplication {
private:
    string name ;
    fstream file ;
    vector <pair<Client, BankAccount>> accounts ;

public:
    BankingApplication() = default ;
    BankingApplication(string & M) ;
    bool addClient() ;
    void Update_File() ;
    void Check_Id(string & ID, int Choice) ;
    void Print_Info() ;
    ~BankingApplication() ;
};


#endif //BankingApplication_CPP_BANKINGAPPLICATION_H
