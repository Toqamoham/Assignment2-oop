# include "BankingApplication.h"

int Client::num_client = 0 ;

int main() {

    string File_Name = "Bank Accounts.txt" ;
    BankingApplication B1(File_Name) ;

    while (true)
    {
        cout << "\n1. Create a New Account \n"
                "2. List Clients and Accounts \n"
                "3. Withdraw Money \n"
                "4. Deposit Money\n"
                "0. Exit\n=========>" ;

        string Choice = "" ;
        cin.sync() ;
        getline(cin, Choice) ;

        if (Choice == "1"){
            B1.addClient() ;
        }
        else if(Choice == "2"){
            B1.Print_Info() ;
        }
        else  if(Choice == "3"){
            string ID ;
            cout << "Please Enter Account ID (e.g., FCAI-015) =========>" ;
            cin >> ID ;

            B1.Check_Id(ID, 1) ;
        }
        else if(Choice == "4"){
            string ID ;
            cout << "Please Enter Account ID (e.g., FCAI-015) =========>" ;
            cin >> ID ;

            B1.Check_Id(ID, 2) ;
        }
        else if (Choice ==  "0"){
            return 0 ;
        }
        else{
            cout << "invalid input :(\n" ;
        }
    }
}