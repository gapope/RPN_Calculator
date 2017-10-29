#include "Calculator.h"

Calculator::Calculator()
{
    //ctor
}


//Performs a basic operation
float Calculator::Operate(char op) {

    float fA = this->Pop();

    if (!valid) {
        this->Push(fA);
        return -1;
    }

    float fB = this->Pop();

    float output = 0;

    switch (op) {
        case '+':
            output = fB + fA;
            break;
        case '-':
            output = fB - fA;
            break;
        case '*':
            output = fB * fA;
            break;
        case '/':
            output = fB / fA;
            break;
        default:
            output = -1;
    }


    this->Push(output);
    return output;
}

//reorders the top 2 digits
bool Calculator::Swap() {

    float fA = this->Pop();

    if (!this->valid) {
        this->Push(fA);

        return false;
    }

    float fB = this->Pop();

    this->Push(fA);
    this->Push(fB);

    return true;
}

Calculator::~Calculator()
{
    //dtor
}
