#include "Stack.h"
#include <iostream>

//Creates a new node and adds it to the top of the stack
void Stack::Push(float data) {
    Node* newNode = new Node(data);

    newNode->Setnext(head);

    head = newNode;

    valid = true;
}

//Outputs value of head and removes this node from the stack
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

//Dumps the contents of the stack
void Stack::Empty() {
    while (valid) {
        this->Pop();
    }
 }

Stack::~Stack()
{
    //dtor
}
