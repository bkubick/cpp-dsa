#include <vector>


class Node {
    public:
        std::string key;
        int value;
        Node* next;
        Node(std::string key, int value) {
            this->key = key;
            this->value = value;
            next = nullptr;
        }
};


class HashTable {
    private:
        static const int PRIME = 31;
        int size = 7;
        int length;
        std::vector<Node*> dataMap;

        int hash(std::string key);
        void resize();

    public:
        HashTable();
        ~HashTable();
        void set(std::string key, int value);
        int get(std::string key, int defaultValue);
        bool remove(std::string key);
        std::vector<std::string> keys();
        std::vector<int> values();
        int getLength();
        void printTable();
};
