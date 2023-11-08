#include <iostream>

#include "LinkedList.hpp"


LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    length = 0;
}


LinkedList::LinkedList(int value)
{
    Node* newNode = new Node(value);
    head = newNode;
    tail = head;
    length = 1;
}

LinkedList::~LinkedList()
{
    Node* temp = head;
    while (head != nullptr)
    {
        head = head -> next;
        delete temp;
        temp = head; 
    }
}


void LinkedList::append(int value)
{
    Node* newNode = new Node(value);

    if (length == 0)
    {
        head = newNode;
        tail = newNode;
    } else
    {
        tail->next = newNode;
        tail = newNode;
    }

    length++;
}


void LinkedList::printList()
{
    Node* temp = head;

    while (temp != nullptr)
    {
        std::cout << temp->value << std::endl;
        temp = temp->next;
    }
}


void LinkedList::deleteLast()
{
    if (length == 0) return;
    Node* temp = head;
    if (length == 1)
    {
        head = nullptr;
        tail = nullptr;
    } else
    {
        Node* pre = head;
        while (temp->next != nullptr)
        {
            pre = temp;
            temp = temp->next;
        }

        tail = pre;
        tail->next = nullptr;
    }

    length--;
    delete temp;
}


void LinkedList::prepend(int value)
{  
    Node* newNode = new Node(value);

    if (length == 0)
    {
        head = newNode;
        tail = newNode;
    } else
    {
        newNode->next = head;
        head = newNode;
    }

    length++;
}


void LinkedList::deleteFirst()
{
    if (length == 0) return;
    Node* temp = head;
    if (length == 1)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        head = head->next;
    }

    length--;
    delete temp;
}


Node* LinkedList::get(int index)
{
    if (index < 0 || index >= length) return nullptr;

    Node* temp = head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }

    return temp;
}


bool LinkedList::set(int index, int value)
{
    Node* temp = get(index);

    if (temp != nullptr)
    {
        temp->value = value;
        return true;
    } else
    {
        return false;
    }
}


bool LinkedList::insert(int index, int value)
{
    if (index < 0 || index >= length)
    {
        return false;
    }

    if (index == 0)
    {
        this->prepend(value);
    } else if (index == length - 1)
    {
        this->append(value);
    } else
    {
        Node* newNode = new Node(value);
        Node* temp = this->get(index-1);
        newNode->next = temp->next;
        temp->next = newNode;
        length++;
    }

    return true;
}


void LinkedList::deleteNode(int index)
{
    if (index < 0 || index >= length) return;
    if (index == 0) return this->deleteFirst();
    if (index == length - 1) return this->deleteLast();

    Node* prev = this->get(index-1);
    Node* temp = prev->next;
    prev->next = prev->next->next;
    delete temp;
    length --;
}


void LinkedList::reverse()
{
    if (length == 0) return;

    Node* temp = head;
    head = tail;
    tail = temp;

    Node* before = nullptr;
    Node* after = temp->next;
    for (int i = 0; i < length; i++)
    {
        after = temp->next;
        temp->next = before;
        before = temp;
        temp = after;
    }
}


int LinkedList::getLength()
{
    return length;
}


void LinkedList::printHead()
{
    std::cout << "Head: " << this->head->value << std::endl;
}


void LinkedList::printTail()
{
    std::cout << "Tail: " << this->tail->value << std::endl;
}


void LinkedList::printLength()
{
    std::cout << "Length: " << this->length << std::endl;
}



int main() {
    LinkedList* myLinkedList = new LinkedList(4);

    myLinkedList->printHead();
    myLinkedList->printTail();
    myLinkedList->printLength();

    myLinkedList->printList();

    myLinkedList->append(27);

    myLinkedList->printList();
}
