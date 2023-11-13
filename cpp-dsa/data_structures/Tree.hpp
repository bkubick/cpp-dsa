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

        /**
         * @brief Prints the tree in either
         * preorder, inorder, or postorder.
         * 
         * @param node The node to start at.
         * @param order The order to print in (Can be "in", "pre", "post", "bfs").
        */
        void printTree(Node* node, std::string order);

    public:
        BinarySearchTree();
        BinarySearchTree(int value);

        /**
         * @brief Inserts a value into the tree.
         * 
         * @param value The value to insert.
         * @return true if the value was inserted successfully.
        */
        bool insert(int value);

        /**
         * @brief Searches for a value in the tree.
         * 
         * @param value The value to search for.
         * @return true if the value was found.
        */
        bool contains(int value);

        /**
         * @brief Prints the tree.
         * 
         * @param order The order to print in (Can be "in", "pre", "post", "bfs").
        */
        void printTree(std::string order);
};
