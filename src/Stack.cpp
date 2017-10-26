#include "Stack.h"
#include <iostream>

void Stack::Push(float data) {
    Node* newNode = new Node();

    newNode->Setvalue(data);
    newNode->Setnext(head);

    head = newNode;

    valid = true;
}

float Stack::Pop() {
    if (head == nullptr) {
        std::cerr << "Accessing empty stack" << std::endl;
        valid = false;
        return -1;
    }

    float temp = head->Value();

    head = head->Next();

    return temp;
}

Stack::~Stack()
{
    //dtor
}
