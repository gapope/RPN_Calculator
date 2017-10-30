#include "Stack.h"
#include <iostream>

void Stack::Push(float data) {
    Node* newNode = new Node(data);

    newNode->Setnext(head);

    head = newNode;

    valid = true;
}

float Stack::Pop() {
    if (!valid) {
        std::cerr << "Accessing empty stack" << std::endl;
        return -1;
    }

    float temp = head->Value();

    head = head->Next();

    if (head == nullptr) {
        valid = false;
    }

    return temp;
}

void Stack::Empty() {
    head = nullptr;
 }
Stack::~Stack()
{
    //dtor
}
