# ifndef UNTITLED41_BIGREAL_H
# define UNTITLED41_BIGREAL_H

# include "BigDecimalIntClass.h"

#include<iomanip>
class BigReal {
private:
    double realNumber{};
    string realNum;
    char signNum;
    void add_zeros(string & RealNumber, string & other);
public:
    BigReal();
    BigReal(string realNumber);
    BigReal(BigReal&other);
    BigReal(double RealNumber) ;
    BigReal(BigDecimalInt other);
    BigReal(BigReal&&other);
    BigReal &operator = (const BigReal &other);
    BigReal &operator = (BigReal&&other);
    BigReal operator + (BigReal& other);
    friend istream &operator >>(istream&input , BigReal&other);
    friend ostream &operator<<(ostream&output,const BigReal&other);
    BigReal operator - (BigReal&other);
    bool operator < (BigReal&other);
    bool operator > (BigReal&other);
    bool operator == (BigReal&other);
    int Size();
    int sign();
    void setNumber(string num) ;
    string Get_Number() ;
};

# endif //UNTITLED41_BIGREAL_H
