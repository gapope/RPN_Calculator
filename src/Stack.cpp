#include "Stack.h"
#include <iostream>

void Stack::Push(char data) {
    Node* newNode = new Node();

    newNode->Setvalue(data);
    newNode->Setnext(head);

    head = newNode;

    //this = temp;
}

char Stack::Pop() {
    if (head == nullptr) {
        std::cerr << "Accessing empty stack" << std::endl;
        return '*';
    }

    char temp = head->Value();

    head = head->Next();

    return temp;
}

Stack::~Stack()
{
    //dtor
}