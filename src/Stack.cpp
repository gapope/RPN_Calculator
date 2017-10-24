#include "Stack.h"

Stack::Stack()
{
    //ctor
}

void push(char data) {
    Stack *temp = new Stack;

    temp->value = data;
    temp->next = this;

    this = temp;
}

char pop() {
    char temp = value;
    this = this.next;

    return temp;
}

Stack::~Stack()
{
    //dtor
}
