#ifndef STACK_H
#define STACK_H

#include "Node.h"

class Stack
{
    public:
        Stack() {head = nullptr;}
        Stack(Node link) {head = &link; head->Setnext(nullptr);}
        virtual ~Stack();


        void Push(char data);
        char Pop();

    private:
        Node *head;
};

#endif // STACK_H