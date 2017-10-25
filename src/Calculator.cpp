#include "Calculator.h"

Calculator::Calculator()
{
    //ctor
}

int Calculator::Operate() {
    int op = this->Pop();

    int intA = this->Pop();
    int intB = this->Pop();

    switch (op) {
        case 0:
            return intB + intA;
        case 1:
            return intB - intA;
        case 3:
            return intB * intA;
        case 4:
            return intB / intA;
        default:
            return -1;
    }
}

Calculator::~Calculator()
{
    //dtor
}
