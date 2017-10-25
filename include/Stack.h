#ifndef STACK_H
#define STACK_H

#include "Node.h"

class Stack
{
    public:
        Stack() {head = nullptr;}
        Stack(Node link) {head = &link; head->Setnext(nullptr);}
        virtual ~Stack();

        Node* Head() {return head;}

        void Push(float data);
        float Pop();

    protected:
        Node *head;
};

#endif // STACK_H
