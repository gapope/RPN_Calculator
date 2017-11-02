#include "Calculator.h"
#include <cmath>

Calculator::Calculator()
{
    //ctor
}

//Reorders the top 2 digits
bool Calculator::Swap() {
    if (!valid) {
        return false;
    }

    float fA = this->Pop();

    if (!valid) {
        this->Push(fA);

        return false;
    }

    float fB = this->Pop();

    this->Push(fA);
    this->Push(fB);

    return true;
}

//Performs a basic operation
bool Calculator::Operate(char op) {
    if (!valid) {
        return false;
    }

    float fA = this->Pop();

    //Errors
    if (!valid || (op == '/' && fA == 0)) {
        this->Push(fA);
        return false;
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
            return false;
    }

    this->Push(output);
    return true;
}

//Calculates absolute value of the top value
bool Calculator::Absolute() {
    if (valid) {
        this->Push(fabs(this->Pop()));
        return true;
    }

    return false;
}

//Calculates one number to the power of another
bool Calculator::Power() {
    if (valid) {
        float fA = this->Pop(), fB = this->Pop();
        this->Push(pow(fA, fB));
        return true;
    }

    return false;
}

//Calculates the square root of the top value
bool Calculator::Root() {
    if (valid && head->Value() > 0) {
        this->Push(sqrt(this->Pop()));
        return true;
    }

    return false;
}

//Calculates the sine value of the top value
bool Calculator::Sine() {
    if (valid) {
        if (rad) {
            this->Push(sin(this->Pop()));
        } else {
            this->Push(sin(this->Pop() * pi / 180));
        }

        return true;
    }

    return false;
}

//Calculates the cosine value of the top value
bool Calculator::Cosine() {
    if (valid) {
        if (rad) {
            this->Push(cos(this->Pop()));
        } else {
            this->Push(cos(this->Pop() * pi / 180));
        }
        return true;
    }

    return false;
}

//Calculates the tangent value of the top value
bool Calculator::Tangent() {
    if (valid) {
        if (rad) {
            this->Push(tan(this->Pop()));
            return true;
        } else {
            this->Push(tan(this->Pop() * pi / 180));
            return true;
        }
    }

    return false;
}

//Calculates the log of the top value
bool Calculator::Logarithm() {
    if (valid) {
        if (head->Value() > 0) {
            this->Push(log10(this->Pop()));
            return true;
        }
    }

    return false;
}

//Calculates the log of the top value
bool Calculator::Ln() {
    if (valid) {
        if (head->Value() > 0) {
            this->Push(log(this->Pop()));
            return true;
        }
    }

    return false;
}

Calculator::~Calculator()
{
    //dtor
}
