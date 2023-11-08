#include "LinkedList.hpp"


class Queue {
    private:
        Node* first;
        Node* last;
        int length;

    public:
        Queue();
        Queue(int value);
        ~Queue();
        void enqueue(int value);
        int dequeue();
        int getLength();
        void printQueue();
        void printFirst();
        void printLast();
        void printLength();
};
