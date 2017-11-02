#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <Stack.h>


class Calculator : public Stack
{
    public:
        Calculator();
        Calculator(bool angles) {rad = angles;}
        virtual ~Calculator();

        //Number control
        void Swap();

        //General
        void Operate(char op);

        //Power
        void Power();
        void Root();

        //Trig
        void SetRad(bool value) {rad = value;}
        void Sine();
        void Cosine();
        void Tangent();

        //Logarithmic
        void Logarithm();
        void Ln();

        //Constants
        void Pi() {this->Push(pi);}
        void E() {this->Push(e);}

    private:
        bool rad;
        const float pi = 3.14159, e = 2.71828;
};

#endif // CALCULATOR_H
