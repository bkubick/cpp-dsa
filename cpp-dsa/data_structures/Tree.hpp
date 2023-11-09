class Node {
    public:
        int value;
        Node* left;
        Node* right;
        Node(int value) {
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
};


class BinarySearchTree {
    private:
        Node* root;
        void printTree(Node* node, std::string order);

    public:
        BinarySearchTree();
        BinarySearchTree(int value);
        bool insert(int value);
        bool contains(int value);
        void printTree(std::string order);
};
