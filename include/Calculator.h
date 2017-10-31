#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <Stack.h>


class Calculator : public Stack
{
    public:
        Calculator();
        virtual ~Calculator();

        void Operate(char op);
        void Swap();
        void Exp();
        void Root();
        void Pi() {this->Push(3.14159);}
        void e() {this->Push(2.71828);}
};

#endif // CALCULATOR_H
