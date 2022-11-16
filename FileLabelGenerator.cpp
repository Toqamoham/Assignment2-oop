# include "LabelGenerator.h"

FileLabelGenerator::FileLabelGenerator(string label, int number, string labelText) {

    Label_number = number ;
    this->labelText = labelText;
    file.open(labelText);
}

string FileLabelGenerator::nextLabel(){

    string line , str1;

    getline(file , line);

    Label_number++ ;

    str1 = getLabel() + " ";
    str1 += to_string(Label_number) + " ";
    str1 += line;

    return str1;
}