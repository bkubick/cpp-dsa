#include <iostream>
#include <queue>
#include <stdexcept>

#include "Tree.hpp"


BinarySearchTree::BinarySearchTree()
{
    root = nullptr;
}


BinarySearchTree::BinarySearchTree(int value)
{
    Node* newNode = new Node(value);
    root = newNode;
}


bool BinarySearchTree::insert(int value)
{
    Node* newNode = new Node(value);

    if (root == nullptr)
    {
        root = newNode;
        return true;
    }

    Node* node = root;
    while (true)
    {
        if (node->value == value) return false;

        if (node->value < value)
        {
            if (node->right == nullptr)
            {
                node->right = newNode;
                break;
            } else
            {
                node = node->right;
            }
        } else
        {
            if (node->left == nullptr)
            {
                node->left = newNode;
                break;
            } else
            {
                node = node->left;
            }
        }
    }

    return true;
}


bool BinarySearchTree::contains(int value)
{
    if (root == nullptr) return false;

    Node* node = root;
    while (node != nullptr)
    {
        if (node->value < value)
        {
            node = node->right;
        } else if (node->value > value)
        {
            node = node->left;
        } else
        {
            return true;
        }
    }

    return false;
}


void BinarySearchTree::printTree(Node* node, std::string order)
{
    if (node == nullptr) return;

    if (order == "in")
    {
        this->printTree(node->left, order);
        std::cout << node->value << std::endl;
        this->printTree(node->right, order);
    } else if (order == "pre")
    {
        std::cout << node->value << std::endl;
        this->printTree(node->left, order);
        this->printTree(node->right, order);
    } else if (order == "post")
    {
        this->printTree(node->left, order);
        this->printTree(node->right, order);
        std::cout << node->value << std::endl;
    } else
    {
        std::queue<Node*> queue;
        queue.push(node);

        Node* curNode;
        while (queue.size() > 0)
        {
            curNode = queue.front();
            queue.pop();
            std::cout << curNode->value << std::endl;
            if (curNode->left != nullptr)
            {
                queue.push(curNode->left);
            }

            if (curNode->right != nullptr)
            {
                queue.push(curNode->right);
            }
        }
    }
}


void BinarySearchTree::printTree(std::string order = "in")
{
    if (!(order == "pre" || order == "post" || order == "in" || order == "level"))
    {
        throw std::runtime_error("Order must be: 'pre', 'post', 'in', 'level'");
    }

    this->printTree(root, order);
}


int main()
{
    BinarySearchTree* tree = new BinarySearchTree();

    tree->insert(47);
    tree->insert(21);
    tree->insert(76);
    tree->insert(18);
    tree->insert(52);
    tree->insert(82);
    tree->insert(27);

    tree->printTree();

    std::cout << "Contains 18: " << tree->contains(18) << std::endl;
    std::cout << "Contains 19: " << tree->contains(19) << std::endl;

    tree->printTree("level");
}
