#include <iostream>

#include "Stack.hpp"


Stack::Stack()
{
    top = nullptr;
    height = 0;
}


Stack::Stack(int value)
{
    Node* newNode = new Node(value);
    top = newNode;
    height = 1;
}


Stack::~Stack()
{
    Node* temp = top;
    while (top != nullptr)
    {
        top = top -> next;
        delete temp;
        temp = top; 
    }
}


void Stack::push(int value)
{
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
    height++;
}


int Stack::pop()
{
    if (height == 0) return INT_MIN;

    Node* poppedNode = top;
    int poppedValue = poppedNode->value;
    top = top->next;
    height--;

    delete poppedNode;
    return poppedValue;
}


int Stack::getHeight()
{
    return height;
}


void Stack::printStack()
{
    Node* node = top;
    while (node != nullptr)
    {
        std::cout << node->value << " ";
        node = node->next;
    }
    std::cout << std::endl;
}


void Stack::printTop()
{
    if (top == nullptr)
    {
        std::cout << "Top: nullptr" << std::endl;
    } else
    {
        std::cout << "Top: " << top->value << std::endl;
    }
}


void Stack::printHeight()
{
    std::cout << "Height: " << height << std::endl;
}


int main() {
    Stack* myStack = new Stack(4);
    myStack->printTop();
    myStack->printHeight();

    myStack->push(1);
    myStack->printStack();

    myStack->pop();
    myStack->printStack();

    myStack->pop();
    myStack->printStack();
}
