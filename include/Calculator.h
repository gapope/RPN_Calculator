#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <Stack.h>


class Calculator : public Stack
{
    public:
        Calculator();
        virtual ~Calculator();

        float Operate();
        bool PushOp(char data);

    protected:

    private:
};

#endif // CALCULATOR_H
