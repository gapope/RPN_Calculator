#include "Calculator.h"
#include <cmath>

Calculator::Calculator()
{
    //ctor
}

//Reorders the top 2 digits
void Calculator::Swap() {
    float fA = this->Pop();

    if (!valid) {
        this->Push(fA);

        return;
    }

    float fB = this->Pop();

    this->Push(fA);
    this->Push(fB);
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

//Calculates absolute value of the top value
void Calculator::Absolute() {
    if (valid)
        this->Push(fabs(this->Pop()));
}

//Calculates one number to the power of another
void Calculator::Power() {
    if (valid) {
        float fA = this->Pop(), fB = this->Pop();
        this->Push(pow(fA, fB));
    }
}

//Calculates the square root of the top value
void Calculator::Root() {
    if (valid)
        this->Push(sqrt(this->Pop()));
}

//Calculates the sine value of the top value
void Calculator::Sine() {
    if (valid) {
        if (rad) {
            this->Push(sin(this->Pop()));
        } else {
            this->Push(sin(this->Pop() * pi / 180));
        }
    }
}

//Calculates the cosine value of the top value
void Calculator::Cosine() {
    if (valid) {
        if (rad) {
            this->Push(cos(this->Pop()));
        } else {
            this->Push(cos(this->Pop() * pi / 180));
        }
    }
}

//Calculates the tangent value of the top value
void Calculator::Tangent() {
    if (valid) {
        if (rad) {
            this->Push(tan(this->Pop()));
        } else {
            this->Push(tan(this->Pop() * pi / 180));
        }
    }
}

//Calculates the log of the top value
void Calculator::Logarithm() {
    if (valid)
        this->Push(log10(this->Pop()));
}

//Calculates the log of the top value
void Calculator::Ln() {
    if (valid)
        this->Push(log(this->Pop()));
}

Calculator::~Calculator()
{
    //dtor
}
