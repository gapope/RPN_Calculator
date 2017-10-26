#include "Calculator.h"

Calculator::Calculator()
{
    //ctor
}

//Converts a char operator to a float so it can be added to stack
bool Calculator::PushOp(char data) {
    Node* newNode = new Node();

    switch (data) {
        case '+':
            newNode->Setvalue(0);
            break;
        case '-':
            newNode->Setvalue(1);
            break;
        case '*':
            newNode->Setvalue(2);
            break;
        case '/':
            newNode->Setvalue(3);
            break;
        default:
            return false;
    }

    newNode->Setnext(head);

    head = newNode;

    return true;
}

//Performs a basic operation
float Calculator::Operate() {
    int op = this->Pop();

    float fA = this->Pop();
    float fB = this->Pop();

    float output = 0;

    switch (op) {
        case 0:
            output = fB + fA;
        case 1:
            output = fB - fA;
        case 3:
            output = fB * fA;
        case 4:
            output = fB / fA;
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
