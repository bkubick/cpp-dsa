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
        /**
         * @brief Sets a key-value pair in the hash table.
         * 
         * @param key The key.
         * @param value The value.
        */
        void set(std::string key, int value);

        /**
         * @brief Gets the value of a key in the hash table.
         * 
         * @param key The key.
         * @return The value of the key.
        */
        int get(std::string key, int defaultValue);

        /**
         * @brief Removes a key-value pair from the hash table.
         * 
         * @param key The key.
         * @return true if the key-value pair was removed successfully.
        */
        bool remove(std::string key);

        /**
         * @brief Returns all the keys in the hash table.
         * 
         * @return A vector of all the keys in the hash table.
        */
        std::vector<std::string> keys();

        /**
         * @brief Returns all the values in the hash table.
         * 
         * @return A vector of all the values in the hash table.
        */
        std::vector<int> values();

        /**
         * @brief Returns the length of the hash table.
         * 
         * @return The length of the hash table.
        */
        int getLength();

        /**
         * @brief Prints the hash table.
        */
        void printTable();
};
