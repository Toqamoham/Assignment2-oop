#ifndef MAIN_CPP_LABELGENERATOR_H
#define MAIN_CPP_LABELGENERATOR_H
#include <iostream>
#include <fstream>

using namespace std;


class LabelGenerator{

    string label ;
    int number;

public:

    LabelGenerator(){} ;
    LabelGenerator(string label , int number) ;
    string getLabel() ;
    virtual string nextLabel() ;
};

class FileLabelGenerator:public LabelGenerator{

    string labelText;
    int Label_number ;
    fstream file ;

public:

    FileLabelGenerator(string label , int number , string labelText) ;

    string nextLabel() override ;
};

#endif //MAIN_CPP_LABELGENERATOR_H
