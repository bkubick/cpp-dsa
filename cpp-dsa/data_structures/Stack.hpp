#include "LinkedList.hpp"


class Stack {
    private:
        Node* top;
        int height;

    public:
        Stack();
        Stack(int value);
        ~Stack();
        void push(int value);
        int pop();
        int getHeight();
        void printStack();
        void printTop();
        void printHeight();
};
