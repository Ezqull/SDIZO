#include <iostream>

class RedBlackTree {

public:

    struct Node{
        Node *parent;
        Node *left;
        Node *right;
        char color;
        int val;
    };
    int size;
    RedBlackTree();
    ~RedBlackTree();
    void delete_tree();
    void add_node(int);
    void delete_node(int);
    void left_rotation(Node *rotation_node);
    void right_rotation(Node *rotation_node);
    void find_node(int);
    void display_tree();

private:
    Node *root;
    Node *guard;
    void delete_node(Node *node_to_delete);
    void find_node(int value, Node *node_to_find, Node *&found_node);
    void find_value(int wartosc, Node *korzenElementuDrzewa, bool &znalezione);
    Node *find_next(Node *p);
    Node *find_minimum(Node *p);

};
