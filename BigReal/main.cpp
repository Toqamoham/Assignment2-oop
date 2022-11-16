#include "BigReal.h"

int main(){




    string num = "-353890.658904", num_2 = "13457.8743053" ;

//----------------------------------------------------------
    cout << left << setw(10) << setfill('-') << '-' << " General Tests " << setw(10) << setfill('-') << '-' << endl ;
    BigReal real1(num), real2("-12.57491"), real3(real2), real4(BigDecimalInt("1000")), b5(+5000) ;
    cout  << "Number 1 -> " << real1 << "\nNumber 2 -> " << real2 << "\nNumber 3 -> " << real3
          << "\nNumber 4 -> " << real4 << "\nNumber 5 -> " << b5 << endl ;
//----------------------------------------------------------
    real3.setNumber(num_2) ;
    cout << left << setw(10) << setfill('-') << '-' << " Plus Tests " << setw(10) << setfill('-') << '-' << endl ;
    cout << real1 << " (+) " << real2 << " --> " << real1 + real2 << endl ;
    cout << real3 << " (+) " << real4 << " --> " << real3 + real4 << endl ;
    cout << real3 << " (+) " << real4 << " (+) " << real1 << " --> " << real3 + real4 + real1 << endl ;
//----------------------------------------------------------
    cout << left << setw(10) << setfill('-') << '-' << " Minus Tests " << setw(10) << setfill('-') << '-' << endl ;
    cout << real1 << " (-) " << real2 << " --> " << real1 - real2 << endl ;
    cout << real3 << " (-) " << real4 << " --> " << real3 - real4 << endl ;
    cout << real3 << " (-) " << real4 << " (-) " << real1 << " --> " << real3 - real4 - real1 << endl ;
//----------------------------------------------------------
    cout << left << setw(10) << setfill('-') << '-' << " Mixed Tests " << setw(10) << setfill('-') << '-' << endl ;
    cout << real1 << " (-) " << real2 << " (+) " << real3 << " --> " << real1 - real2 + real3 << endl ;
    cout << real3 << " (-) " << real4 << " (+) " << real1 << " --> " << real3 - real4 + real1 << endl ;
    cout << real3 << " (+) " << real4 << " (+) " << real1 << " (-) " << real2 << " --> " << real3 + real4 + real1 - real2 << endl ;
//----------------------------------------------------------
    cout << left << setw(10) << setfill('-') << '-' << " Greater Tests " << setw(10) << setfill('-') << '-' << endl ;
    if (real1 > real2)
    {
        cout << real1 << " is greater than " << real2 << endl ;
    }
    else
    {
        cout << real1 << " isn't greater than " << real2 << endl ;
    }
    if (real3 > real4)
    {
        cout << real3 << " is greater than " << real4 << endl ;
    }
    else
    {
        cout << real3 << " isn't greater than " << real4 << endl ;
    }
//----------------------------------------------------------
    cout << left << setw(10) << setfill('-') << '-' << " Smaller Tests " << setw(10) << setfill('-') << '-' << endl ;
    if (real3 < real4)
    {
        cout << real3 << " is smaller than " << real4 << endl ;
    }
    else
    {
        cout << real3 << " isn't smaller than " << real4 << endl ;
    }
    if (real1 < real3)
    {
        cout << real1 << " is smaller than " << real3 << endl ;
    }
    else
    {
        cout << real1 << " isn't smaller than " << real3 << endl ;
    }
//----------------------------------------------------------
    cout << left << setw(10) << setfill('-') << '-' << " Equality Tests " << setw(10) << setfill('-') << '-' << endl ;
    real1 = real3 ;
    if (real1 == real3)
    {
        cout << real1 << " is equal to " << real3 << endl ;
    }
    else
    {
        cout << real1 << " isn't equal to " << real3 << endl ;
    }
    if (real4 == real2)
    {
        cout << real4 << " is equal than " << real2 << endl ;
    }
    else
    {
        cout << real4.Get_Number() << " isn't equal than " << real2 << endl ;
    }

    return 0;
}