#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <Stack.h>


class Calculator : public Stack
{
    public:
        Calculator();
        virtual ~Calculator();

        bool PushOp(char data);
        float Operate();
        bool Swap();

    protected:

    private:
};

#endif // CALCULATOR_H
