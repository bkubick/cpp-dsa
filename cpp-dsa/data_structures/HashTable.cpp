#include <iostream>

#include "HashTable.hpp"


HashTable::HashTable()
{
    this->dataMap = std::vector<Node*>(this->size);
    this->length = 0;
}


HashTable::~HashTable()
{
    for (int i = 0; i < size; i++)
    {
        Node* current = dataMap[i];
        while (current != nullptr)
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
}


int HashTable::hash(std::string key)
{
    int hash = 0;
    for (int i = 0; i < key.length(); i++)
    {
        int asciiValue = int(key[i]);
        hash = (hash + asciiValue * PRIME) % size;
    }
    return hash;
}


void HashTable::set(std::string key, int value)
{
    int index = hash(key);
    Node* newNode = new Node(key, value);
    if (dataMap[index] == nullptr)
    {
        dataMap[index] = newNode;
    }
    else
    {
        Node* current = dataMap[index];
        while (current->next != nullptr)
        {
            if (current->key == key)
            {
                current->value = value;
                return;
            }
            current = current->next;
        }
        current->next = newNode;
    }

    this->length++;

    if (this->length > 0.7 * size) resize();
}


int HashTable::get(std::string key, int defaultValue = INT_MIN)
{
    int index = hash(key);

    Node* current = dataMap[index];
    while (current != nullptr)
    {
        if (current->key == key) return current->value;
        current = current->next;
    }
    return defaultValue;
}


std::vector<std::string> HashTable::keys()
{
    std::vector<std::string> keys;
    for (int i = 0; i < size; i++)
    {
        Node* current = dataMap[i];
        while (current != nullptr)
        {
            keys.push_back(current->key);
            current = current->next;
        }
    }
    return keys;
}


std::vector<int> HashTable::values()
{
    std::vector<int> values;
    for (int i = 0; i < size; i++)
    {
        Node* current = dataMap[i];
        while (current != nullptr)
        {
            values.push_back(current->value);
            current = current->next;
        }
    }
    return values;
}


bool HashTable::remove(std::string key)
{
    int index = hash(key);

    Node* current = dataMap[index];
    Node* previous = nullptr;
    while (current != nullptr)
    {
        if (current->key == key)
        {
            if (previous == nullptr)
            {
                dataMap[index] = current->next;
            }
            else
            {
                previous->next = current->next;
            }
            delete current;
            this->length--;
            return true;
        }
        previous = current;
        current = current->next;
    }
    return false;
}


void HashTable::resize()
{
    std::vector<Node*> temp = dataMap;
    dataMap = std::vector<Node*>(2 * size);
    this->size *= 2;

    for (int i = 0; i < temp.size(); i++)
    {
        Node* current = temp[i];
        while (current != nullptr)
        {
            set(current->key, current->value);
            current = current->next;
        }
    }
}


int HashTable::getLength()
{
    return this->length;
}


void HashTable::printTable()
{
    for (int i = 0; i < size; i++)
    {
        std::cout << i << ": ";
        Node* current = dataMap[i];
        while (current != nullptr)
        {
            std::cout << " { "  << current->key << ", " << current->value << " } ->";
            current = current->next;
        }
        std::cout << std::endl;
    }
}


int main()
{
    std::cout << "Running HashTable Methods" << std::endl;

    HashTable* hashTable = new HashTable();

    std::cout << "HashTable Generated" << std::endl;

    hashTable->set("grapes", 10000);
    hashTable->set("apples", 54);
    hashTable->set("oranges", 2);
    hashTable->set("bananas", 10);
    hashTable->set("watermelons", 1);
    hashTable->set("pineapples", 0);
    hashTable->set("strawberries", 0);
    hashTable->set("blueberries", 0);
    hashTable->set("raspberries", 0);

    hashTable->printTable();

    std::cout << hashTable->get("grapes") << std::endl;
    std::cout << hashTable->get("apples") << std::endl;
    std::cout << hashTable->get("kiwis", 27) << std::endl;
    std::cout << hashTable->get("kiwis") << std::endl;

    hashTable->remove("blueberries");

    hashTable->printTable();

    delete hashTable;

    return 0;
}
