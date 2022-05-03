#include <iostream>

class RedBlackTree{

public:

    struct Node{
        Node *parent;
        Node *left;
        Node *right;
        int value;
        char color;
    };
    int size = 0;

    RedBlackTree();
    ~RedBlackTree();

    void add(int val); //done

    void deleteVal(int val);

    void print();

    bool contains(int val);

private:
    Node guard;
    Node *root;

    void rotateRight(Node *node);
    void rotateLeft(Node *node);

    void deleteNode(Node *node);

    Node *succesor(Node *node);

    Node *minNode(Node *node); //finds lowest node

    void clearNode(Node *node);
};

