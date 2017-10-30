#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <Stack.h>


class Calculator : public Stack
{
    public:
        Calculator();
        virtual ~Calculator();

        void Operate(char op);
        void Root();
        void Swap();

        short Length() {return length;}

    protected:

    private:

    short length;
};

#endif // CALCULATOR_H
