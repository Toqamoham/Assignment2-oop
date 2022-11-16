#include "LabelGenerator.h"

LabelGenerator::LabelGenerator(string label, int number) {

    this -> label = label;

    this -> number = number;
}

string LabelGenerator::getLabel() {

    return label;
}

string LabelGenerator::nextLabel() {

    string str;

    number++;

    str = label + " ";
    str += to_string(number);

    return str;
}
