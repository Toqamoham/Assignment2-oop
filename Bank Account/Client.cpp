#include "BankingApplication.h"

void Client::Set_Name(string & Name) {
    name = Name ;
}

void Client::Set_Address(string & Address) {
    add = Address ;
}

void Client::Set_Phone(string & phone) {
    ph = phone ;
}

string Client::Get_Name() {
    return name ;
}

string Client::Get_Address() {
    return add ;
}

string Client::Get_Phone() {
    return ph ;
}

int Client::Get_Number_Clients() {
    return num_client;
}

Client::Client() {
    num_client++  ;
}