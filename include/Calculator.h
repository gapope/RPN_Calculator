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
        bool Swap();

        //General
        bool Operate(char op);
        bool Absolute();

        //Power
        bool Power();
        bool Root();

        //Trig
        void SetRad(bool value) {rad = value;}
        bool Sine();
        bool Cosine();
        bool Tangent();

        //Logarithmic
        bool Logarithm();
        bool Ln();

        //Constants
        void Pi() {this->Push(pi);}
        void E() {this->Push(e);}

    private:
        bool rad;
        const float pi = 3.14159, e = 2.71828;
};

#endif // CALCULATOR_H
