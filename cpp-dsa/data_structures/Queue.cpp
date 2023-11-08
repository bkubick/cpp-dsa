#include <iostream>

#include "Queue.hpp"


Queue::Queue(int value)
{
    Node* newNode = new Node(value);
    first = newNode;
    last = newNode;
    length = 1;
}


Queue::Queue()
{
    first = nullptr;
    last = nullptr;
    length = 0;
}


Queue::~Queue()
{
    Node* temp = first;
    while (first != nullptr)
    {
        first = first -> next;
        delete temp;
        temp = first; 
    }
}


void Queue::enqueue(int value)
{
    Node* newNode = new Node(value);
    if (length == 0)
    {
        first = newNode;
        last = newNode;
    } else
    {
        last->next = newNode;
        last = newNode;
    }

    length++;
}


int Queue::dequeue()
{
    if (length == 0) return INT_MIN;

    Node* firstNode = first;
    int firstValue = first->value;
    if (length == 1)
    {
        first = nullptr;
        last = nullptr;
    } else
    {
        first = first->next;
    }

    length--;

    delete firstNode;
    return firstValue;
}


int Queue::getLength()
{
    return length;
}


void Queue::printQueue()
{
    Node* node = first;
    while (node != nullptr)
    {
        std::cout << node->value << " ";
        node = node->next;
    }
    std::cout << std::endl;
}


void Queue::printFirst()
{
    if (first == nullptr)
    {
        std::cout << "First: nullptr" << std::endl;
    } else
    {
        std::cout << "First: " << first->value << std::endl;
    }
}


void Queue::printLast()
{
    if (last == nullptr)
    {
        std::cout << "Last: nullptr" << std::endl;
    } else
    {
        std::cout << "Last: " << last->value << std::endl;
    }
}


void Queue::printLength()
{
    std::cout << length << std::endl;
}


int main() {
    Queue* myQueue = new Queue(4);

    myQueue->printFirst();
    myQueue->printLast();
    myQueue->printLength();
    myQueue->printQueue();

    myQueue->enqueue(12);
    myQueue->enqueue(21);
    myQueue->printQueue();

    myQueue->dequeue();
    myQueue->printQueue();
}
