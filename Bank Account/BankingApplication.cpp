# include "BankingApplication.h"

BankingApplication::BankingApplication(string & M) {
    name = M ;
    file.open(name)  ;
    string Line ;
    while (getline(file, Line))
    {
        Client C  ;
        BankAccount A ;
        string name = Line.substr(0, (int)Line.find('&') - 1) ;
        C.Set_Name(name) ;

        Line = Line.substr((int)Line.find('&') + 2, - 1) ;
        string address = Line.substr(0, (int)Line.find('&') - 1)  ;
        C.Set_Address(address) ;

        Line = Line.substr((int)Line.find('&') + 2, - 1) ;
        string phone = Line.substr(0, (int)Line.find('&') - 1) ;
        C.Set_Phone(phone) ;

        Line = Line.substr((int)Line.find('&') + 2, - 1) ;
        string id = Line.substr(0, (int)Line.find('(') - 2) ;
        A.set_id(id) ;

        Line = Line.substr((int)Line.find('('), - 1) ;
        string  type = Line.substr(0, (int)Line.find(')') + 1) ;
        A.set_type(type) ;

        Line = Line.substr((int)Line.find('&') + 2, - 1) ;
        Line = Line.substr(0, (int)Line.find(';') - 1) ;
        double balance = stod(Line) ;
        A.set_balance(balance) ;

        accounts.insert(accounts.end(), {C, A}) ;
    }
    file.close() ;
    file.open(name, ios::app) ;
}

void BankingApplication::Update_File()
{
    file.close() ;
    file.open(name, ios::out) ;

    for (int i = 0; i < Client::Get_Number_Clients(); ++i) {
        file << accounts[i].first.Get_Name() << " & "
             << accounts[i].first.Get_Address() << " & "
             << accounts[i].first.Get_Phone() << " & "
             << accounts[i].second.get_id() << "  " << accounts[i].second.get_type()
             << " & " << accounts[i].second.get_balance() << " ;\n" ;
    }
}

bool BankingApplication::addClient() {
    string Temp ;
    Client c1 ;
    cout << "Please Enter Client Name =========>" ;
    cin >> Temp ;
    c1.Set_Name(Temp);

    cout << "Please Enter Client Address =========>" ;
    cin.sync() ;
    getline(cin, Temp) ;
    c1.Set_Address(Temp) ;

    Phone:
    cout << "Please Enter Client Phone =========>" ;
    cin >> Temp ;
    if (Temp.size() != 11) {
        cout << "Invalid Input :(\n";
        goto Phone;
    }

    c1.Set_Phone(Temp);
    Again:
    cout << "\nWhat Type of Account Do You Like? (1) Basic (2) Saving – Type 1 or 2 =========>" ;
    char Option ;
    cin >> Option ;
    if (Option == '1')
    {
        double Bal ;
        cout  << "\nPlease Enter the Starting Balance =========>" ;
        cin >> Bal ;
        BankAccount Acc (Bal, Client::Get_Number_Clients()) ;
        accounts.emplace_back(c1, Acc) ;
    }
    else if(Option == '2')
    {
        Input :
        double Bal ;
        cout  << "\nEnter the Balance\nNotice that there is 1000 L.E (minimum balance) "
                 "will be refunded in your Account =========>" ;
        cin >> Bal ;

        if (Bal < 1000)
        {
            cout << "You must deposit at least 1000 L.E\n" ;
            goto Input ;
        }

        SavingBankAccount S(Bal, Client::Get_Number_Clients()) ;
        accounts.emplace_back(c1, S) ;
    }
    else
    {
        cout << "Invalid Input :(\n" ;
        goto Again;
    }

    cout << "An account was created with ID " << accounts[Client::Get_Number_Clients() - 1].second.get_id()
         << " and Starting Balance " << accounts[Client::Get_Number_Clients() - 1].second.get_balance() << " L.E.\n" ;

    Update_File() ;
    return true;
}

void BankingApplication::Check_Id(string & ID, int Choice) {
    bool Exist = false;

    for (auto & client : accounts) {
        if (client.second.get_id() == ID)
        {
            cout << "Account ID : " <<  client.second.get_id() << endl ;
            cout << "Account type : "  << client.second.get_type() << endl ;
            cout << "Balance : " << client.second.get_balance() << endl ;

            Again :
            double amount ;
            cout << "\nEnter the Amount =========>" ;
            cin >> amount ;

            if (Choice == 1)
            {
                if(!client.second.withdraw(amount)) {
                    goto Again;
                }
            }
            else
            {
                client.second.deposit(amount) ;
            }

            Update_File() ;
            Exist = true ;
        }
    }
    if (!Exist){
        cout << "The ID isn't Exist :(" << endl ;
    }
}

BankingApplication::~BankingApplication() {
    file.close() ;
}

void BankingApplication::Print_Info() {
    for (auto & client : accounts) {
        cout << setw(5) << setfill('-') << " " << client.first.Get_Name() << " " << setw(5) << setfill('-') << "-" ;
        cout << "\nAddress : " << client.first.Get_Address() << " Phone : " << client.first.Get_Phone() <<
             "\nAccount ID : " << client.second.get_id() << " " << client.second.get_type() <<
             "\nBalance : " << client.second.get_balance() << endl ;
    }
}