class Node {
    public:
        int value;
        Node* next;
        Node(int value) {
            this->value = value;
            next = nullptr;
        }
};


class LinkedList {
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        LinkedList();
        LinkedList(int value);
        ~LinkedList();

        /**
         * @brief Adds a value to the end of the linked list.
         * 
         * @param value The value to add.
        */
        void append(int value);

        /**
         * @brief Deletes the last value of the linked list.
        */
        void deleteLast();

        /**
         * @brief Deletes the first value of the linked list.
        */
        void deleteFirst();

        /**
         * @brief Deletes a value from the linked list at the given index.
         * 
         * @param index The index to delete.
        */
        void deleteNode(int index);

        /**
         * @brief Adds a value to the beginning of the linked list.
         * 
         * @param value The value to add.
        */
        void prepend(int value);

        /**
         * @brief Reverses the linked list.
        */
        void reverse();

        /**
         * @brief Gets the Node at the given index.
         * 
         * @param index The index to get.
         * @return The Node at the given index.
        */
        Node* get(int index);

        /**
         * @brief Sets the value of the Node at the given index.
         * 
         * @param index The index to set.
         * @param value The value to set.
         * @return true if the value was set successfully.
        */
        bool set(int index, int value);

        /**
         * @brief Inserts a value into the linked list at the given index.
         * 
         * @param index The index to insert.
         * @param value The value to insert.
         * @return true if the value was inserted successfully.
        */
        bool insert(int index, int value);

        /**
         * @brief Returns the length of the linked list.
         * 
         * @return The length of the linked list.
        */
        int getLength();

        /**
         * @brief Prints the linked list.
        */
        void printList();

        /**
         * @brief Prints the value of the head of the linked list.
        */
        void printHead();

        /**
         * @brief Prints the value of the tail of the linked list.
        */
        void printTail();

        /**
         * @brief Prints the length of the linked list.
        */
        void printLength();
};
