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

    RedBlackTree();                     // konstruktor
    ~RedBlackTree();                    // destruktor

    void add(int val);                  // dodanie elementu

    void deleteVal(int val);            // usuwa podany element
    void popRoot();                     // usuwa ostatni element

    void print(Node *node);             // wyświetla drzewo

    bool contains(int val);             // sprawdza czy element występuje w drzewie

    Node* getRoot();                    // Zwraca Korzeń

private:
    Node guard;                         // Strażnik
    Node *root;                         // Korzeń

    void rotateRight(Node *node);       // prawa rotacja
    void rotateLeft(Node *node);        // lewa rotacja

    void deleteNode(Node *node);        // usunięcie Node'a
    void clearNode(Node *node);         // wyczyszczenie Node'a

    Node *succesor(Node *node);         // znalezienie następnika

    Node *minNode(Node *node);          // znalezienie najmniejszego elementu w drzewie
};
