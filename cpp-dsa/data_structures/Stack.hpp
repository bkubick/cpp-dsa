#include "LinkedList.hpp"


class Stack {
    private:
        Node* top;
        int height;

    public:
        Stack();
        Stack(int value);
        ~Stack();

        /**
         * @brief Adds a value to the top of the stack.
         * 
         * @param value The value to add.
        */
        void push(int value);

        /**
         * @brief Removes a value from the top of the stack.
         * 
         * @return The value removed.
        */
        int pop();
        
        /**
         * @brief Returns the height of the stack.
         * 
         * @return The height of the stack.
        */
        int getHeight();

        /**
         * @brief Prints the stack.
        */
        void printStack();

        /**
         * @brief Prints the top value of the stack.
        */
        void printTop();

        /**
         * @brief Prints the height of the stack.
        */
        void printHeight();
};
