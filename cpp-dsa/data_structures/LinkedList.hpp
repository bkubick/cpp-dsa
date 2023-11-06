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
        void append(int value);
        void deleteLast();
        void deleteFirst();
        void deleteNode(int index);
        void prepend(int value);
        void reverse();
        Node* get(int index);
        bool set(int index, int value);
        bool insert(int index, int value);
        int getLength();
        void printList();
        void printHead();
        void printTail();
        void printLength();
};
