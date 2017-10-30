#include "Calculator.h"
#include <cmath>

Calculator::Calculator()
{
    //ctor
}


//Performs a basic operation
void Calculator::Operate(char op) {

    float fA = this->Pop();

    if (!valid) {
        this->Push(fA);
        return;
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
}

void Calculator::Root() {
    if (!valid) {
        return;
    }
    this->Push(sqrt(this->Pop()));
}

//reorders the top 2 digits
void Calculator::Swap() {

    float fA = this->Pop();

    if (!this->valid) {
        this->Push(fA);

        return;
    }

    float fB = this->Pop();

    this->Push(fA);
    this->Push(fB);
}

Calculator::~Calculator()
{
    //dtor
}
