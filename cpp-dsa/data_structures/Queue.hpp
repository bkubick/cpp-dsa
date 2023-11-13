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

        /**
         * @brief Adds a value to the end of the queue.
         * 
         * @param value The value to add.
        */
        void enqueue(int value);

        /**
         * @brief Removes a value from the front of the queue.
         * 
         * @return The value removed.
        */
        int dequeue();
        
        /**
         * @brief Returns the length of the queue.
         * 
         * @return The length of the queue.
        */
        int getLength();

        /**
         * @brief Prints the queue.
        */
        void printQueue();

        /**
         * @brief Prints the first value of the queue.
        */
        void printFirst();

        /**
         * @brief Prints the last value of the queue.
        */
        void printLast();

        /**
         * @brief Prints the length of the queue.
        */
        void printLength();
};
