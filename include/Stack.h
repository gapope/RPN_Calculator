#ifndef STACK_H
#define STACK_H

#include "Node.h"

class Stack
{
    public:
        Stack() {head = nullptr; valid = false;}
        Stack(Node link) {head = &link; head->Setnext(nullptr); valid = true;}
        virtual ~Stack();

        Node* Head() {return head;}

        void Push(float data);
        float Pop();

    protected:
        Node *head;
        bool valid;
};

#endif // STACK_H
