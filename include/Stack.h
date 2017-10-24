#ifndef STACK_H
#define STACK_H


class Stack
{
    public:
        Stack();
        Stack (char data) {value = data;}
        Stack (char data, Stack link) {value = data; next = &link;}
        virtual ~Stack();

        char Getvalue() { return value; }
        void Setvalue(char val) { value = val; }
        Stack Getnext() { return *next; }
        void Setnext(Stack val) { next = &val; }

        void push(char data);
        char pop();

    protected:

    private:
        char value;
        Stack *next;
};

#endif // STACK_H
