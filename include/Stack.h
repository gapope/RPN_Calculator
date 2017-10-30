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
        bool Valid() {return valid;}

        void Push(float data);
        float Pop();
        void Empty();

    protected:
        Node* head;
        bool valid;
};

#endif // STACK_H
