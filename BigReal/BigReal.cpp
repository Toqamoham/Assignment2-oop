#include "BigDecimalIntClass.h"
#include "BigReal.h"

//Default constructor...................
BigReal::BigReal() {

    realNumber = 0.0;
    realNum = "0.0" ;
    signNum = '+' ;
}
//parameterized constructor............................
BigReal::BigReal(string realNumber) {

    realNum = realNumber;
    if (realNum[0] != '-' && realNum[0] != '+')
        realNum.insert(0, "+") ;

    if (realNumber[1] == '.')
        realNumber.insert(1, "0") ;

    signNum = realNum[0] ;
}

//Copy constructor..........................
BigReal::BigReal(BigReal &other) {

    this -> realNum = other.realNum ;

    this -> realNumber = other.realNumber ;

    this -> signNum = other.signNum ;

}

//Move constructor.......................
BigReal::BigReal(BigReal &&other) {

    this -> realNum = other.realNum;
    this -> signNum = other.signNum;
    this -> realNumber = other.realNumber;

    other.realNum = '\0' ;
    other.signNum = '\0' ;
    other.realNumber = 0 ;
}

// function to return the size of number.........................
int BigReal::Size() {

    return realNum.size() - 1;
}

BigReal::BigReal(BigDecimalInt other) {
    realNum = other.getNumber();
    if (other.sign())
        realNum.insert(0, "+");
    else
        realNum.insert(0, "-");
    realNum += ".0" ;
}

void BigReal::setNumber(string num) {
    realNum = num ;
}

int BigReal::sign() {
    if (realNum[0] == '+')
        return 1 ;

    return 0 ;
}

string BigReal::Get_Number() {
    return realNum ;
}

BigReal::BigReal(double RealNumber) {
    realNumber = RealNumber ;
    realNum = to_string(RealNumber) ;
    if (realNum[0] != '+' && realNum[0] != '-')
        realNum.insert(0, "+") ;

    signNum = realNum[0] ;
}

//operator >> overloading function...................
istream &operator>>(istream &input, BigReal &other) {

    input >> other.realNum;

    return input;

}

//operator << overloading function...................
ostream &operator<<(ostream &output,const BigReal&other) {

    output << other.realNum;

    return output;
}

//operator = overloading function...................
BigReal &BigReal::operator=(const BigReal &other) {

    realNumber = other.realNumber ;
    realNum = other.realNum;
    signNum = other.signNum;

    return *this;
}

//Move Assignment..................................
BigReal &BigReal::operator=(BigReal &&other) {

    this -> realNum = other.realNum;
    this -> signNum = other.signNum;
    this -> realNumber = other.realNumber;
    other.realNum = '\0' ;
    other.signNum = '\0' ;
    other.realNumber = 0 ;

    return *this;
}

void BigReal::add_zeros(string & RealNumber, string & other) {
    int Size_1 = (int)RealNumber.size() - (int)RealNumber.find('.') ;
    int Size_2 =  (int)other.size() - (int)other.find('.') ;

    while (Size_1 < Size_2){
        RealNumber += '0';
        Size_1++;
    }
    while (Size_1 > Size_2){
        other += '0';
        Size_2++;
    }
}

//operator + overloading function....................
BigReal BigReal::operator+(BigReal &other) {
    string Number_1 = realNum, Number_2 = other.realNum;
    add_zeros(Number_2, Number_1) ;
    int index = realNum.find('.');

    int index1 = other.realNum.find('.');

    Number_1.erase(remove(Number_1.begin(),Number_1.end(),'.'),Number_1.end());

    Number_2.erase(remove(Number_2.begin(),Number_2.end(),'.') ,Number_2.end());

    BigDecimalInt B1(Number_1) , B2(Number_2);

    BigDecimalInt B3 = B1 + B2;

    this->realNum = B3.getNumber();
    if (B3.sign())
        realNum.insert(0, "+");

    else
        realNum.insert(0, "-") ;

    Number_1 = realNum[0] + Number_1.substr(index, -1) ;
    Number_2 = other.realNum[0] + Number_2.substr(index1, -1) ;

    B1.setNumber(Number_1) ;
    B2.setNumber(Number_2) ;
    B3 = B1 + B2 ;

    int Point_Index = (int)realNum.size() - B3.size();

    if (B3.size() > Number_1.size() - 1 && B3.size() > Number_2.size() - 1)
        Point_Index = (int)realNum.size() - B3.size() + 1;

    realNum.insert(Point_Index, ".") ;

    if (realNum[1] == '.')
        realNum.insert(1, "0") ;

    return *this ;
}

//operator - overloading function..................
BigReal BigReal::operator-(BigReal&other) {

    string Number_1 = realNum, Number_2 = other.realNum;
    add_zeros(Number_2, Number_1) ;
    int index = realNum.find('.');

    int index1 = other.realNum.find('.');

    Number_1.erase(remove(Number_1.begin(),Number_1.end(),'.'),Number_1.end());

    Number_2.erase(remove(Number_2.begin(),Number_2.end(),'.') ,Number_2.end());

    BigDecimalInt B1(Number_1) , B2(Number_2);

    BigDecimalInt B3 = B1 - B2;

    this->realNum = B3.getNumber();
    if (B3.sign())
        realNum.insert(0, "+");

    else
        realNum.insert(0, "-") ;

    Number_1 = realNum[0] + Number_1.substr(index, -1) ;
    Number_2 = other.realNum[0] + Number_2.substr(index1, -1) ;

    B1.setNumber(Number_1) ;
    B2.setNumber(Number_2) ;
    B3 = B1 - B2 ;

    int Point_Index = (int)realNum.size() - B3.size();

    if (B3.size() > Number_1.size() - 1 && B3.size() > Number_2.size() - 1)
        Point_Index = (int)realNum.size() - B3.size() + 1;

    realNum.insert(Point_Index, ".") ;

    if (realNum[1] == '.')
        realNum.insert(1, "0") ;
    return *this ;
}

//operator < overloading function..................
bool BigReal::operator<(BigReal &other) {

    string real1 = realNum , real2 = other.realNum;

    real1.erase(remove(real1.begin(),real1.end(),'.'),real1.end());

    real2.erase(remove(real2.begin(),real2.end(),'.'),real2.end());

    BigDecimalInt B1(real1) , B2(real2);
    if (B1 < B2)
        return true ;

    return false ;
}

//operator > overloading function..................
bool BigReal::operator>(BigReal &other) {

    string real1 = realNum , real2 = other.realNum;

    real1.erase(remove(real1.begin(),real1.end(),'.'),real1.end());

    real2.erase(remove(real2.begin(),real2.end(),'.'),real2.end());

    BigDecimalInt B1(real1) , B2(real2);

    if (B1 > B2)
        return true ;

    return false ;
}

//operator == overloading function..................
bool BigReal::operator==(BigReal &other) {

    string real1 = realNum , real2 = other.realNum;

    real1.erase(remove(real1.begin(),real1.end(),'.'),real1.end());

    real2.erase(remove(real2.begin(),real2.end(),'.'),real2.end());

    BigDecimalInt B1(real1) , B2(real2);

    if (B1 == B2)
        return true ;

    return false ;
}