#include "RedBlackTree.hpp"


RedBlackTree::RedBlackTree() : size(0){

    guard.color = 'b';
    guard.parent = &guard;
    guard.left = &guard;
    guard.right = &guard;
    root = &guard;
}

RedBlackTree::~RedBlackTree(){
    if (root != &guard){
        clearNode(root->left);
        clearNode(root->right);
        delete root;
        guard.color = 'b';
        guard.parent = &guard;
        guard.left = &guard;
        guard.right = &guard;
        root = &guard;
        size = 0;
    }
}

void RedBlackTree::rotateRight(Node * node){
    Node *son, *parent;

    son = node->left;
    if (son != &guard){
        parent = node->parent;
        node->left = son->right;

        if (node->left != &guard) {
            node->left->parent = node;
        }

        son->right= node;
        son->parent = parent;
        node->parent =son;

        if (parent != &guard){
            if (parent->left == node) {
                parent->left = son;
            }else {
                parent->right = son;
            }
        }else {
            root = son;
        }
    }
}

void RedBlackTree::rotateLeft(Node * node){
    Node *son, *parent;

    son = node->right;
    if (son != &guard){
        parent = node->parent;
        node->right = son->left;

        if (node->right != &guard) {
            node->right->parent = node;
        }

        son->left = node;
        son->parent = parent;
        node->parent = son;

        if (parent != &guard){
            if (parent->left == node) {
                parent->left = son;
            }else {
                parent->right = son;
            }
        }else {
            root = son;
        }
    }
}

void RedBlackTree::add(int val){
    size++;
    Node *newNode, *uncle;
    newNode = new Node();
    newNode->left = &guard;
    newNode->right = &guard;
    newNode->parent = root;
    newNode->value = val;
    if (newNode->parent == &guard) {
        root = newNode;
    } else {
        while (1) {
            if (newNode->value < newNode->parent->value) {
                if (newNode->parent->left == &guard) {
                    newNode->parent->left = newNode;
                    break;
                }
                newNode->parent = newNode->parent->left;
            } else {
                if (newNode->parent->right == &guard) {
                    newNode->parent->right = newNode;
                    break;
                }
                newNode->parent = newNode->parent->right;
            }

        }
    }
    newNode->color = 'r';
    while ((newNode != root) && (newNode->parent->color == 'r')){
        if (newNode->parent == newNode->parent->parent->left){
            uncle = newNode->parent->parent->right;

            if (uncle->color == 'r'){

                newNode->parent->color = 'b';
                uncle->color = 'b';
                newNode->parent->parent->color = 'r';
                newNode = newNode->parent->parent;
                continue;
            }

            if (newNode == newNode->parent->right){
                newNode = newNode->parent;
                rotateLeft(newNode);
            }
            newNode->parent->color = 'b';
            newNode->parent->parent->color = 'r';
            rotateRight(newNode->parent->parent);
            break;

        } else {
            uncle = newNode->parent->parent->left; // mirror uncle
            if (uncle->color == 'r'){
                newNode->parent->color = 'b';
                uncle->color = 'b';
                newNode->parent->parent->color = 'r';
                newNode = newNode->parent->parent;
                continue;
            }

            if (newNode == newNode->parent->left){
                newNode = newNode->parent;
                rotateRight(newNode);
            }
            newNode->parent->color = 'b';
            newNode->parent->parent->color = 'r';
            rotateLeft(newNode->parent->parent);
            break;
        }
    }
    root->color = 'b';
}

void RedBlackTree::deleteVal(int val){
    Node *node = root;
    if(!contains(val)) {
        std::cout << "Value not found." << std::endl;
    }else{
        while ((node != &guard) && (node->value != val)) {
            if (val < node->value) {
                node = node->left;
            }else {
                node = node->right;
            }
        }

        deleteNode(node);
    }
}

void RedBlackTree::deleteNode(Node *node) {

    size--;
    Node *x, *y, *z;

    if ((node->left == &guard) || (node->right == &guard)) {
        y = node;
    } else {
        y = succesor(node);
    }

    if (y->left != &guard) {
        z = y->left;
    } else {
        z = y->right;
    }

    z->parent = y->parent;

    if (y->parent == &guard) {
        root = z;
    }

    if (y == y->parent->left) {
        y->parent->left = z;
    }else {
        y->parent->right = z;
    }

    if (y != node) {
        node->value = y->value;
    }

    if (y->color == 'b') {
        while ((z != root) && (z->color == 'b')) {
            if (z == z->parent->left) {
                x = z->parent->right;

                if (x->color == 'r') {
                    x->color = 'b';
                    z->parent->color = 'r';
                    rotateLeft(z->parent);
                    x = z->parent->right;
                }

                if ((x->left->color == 'b') && (x->right->color == 'b')) {
                    x->color = 'r';
                    z = z->parent;
                    continue;
                }

                if (x->right->color == 'b') {
                    x->left->color = 'b';
                    x->color = 'r';
                    rotateRight(x);
                    x = z->parent->right;
                }

                x->color = z->parent->color;
                z->parent->color = 'b';
                x->right->color = 'r';
                rotateLeft(z->parent);
                z = root;

            } else {
                x = z->parent->left;

                if (x->color == 'R') {
                    x->color = 'b';
                    z->parent->color = 'r';
                    rotateRight(z->parent);
                    x = z->parent->left;
                }

                if ((x->left->color == 'B') && (x->right->color == 'B')) {
                    x->color = 'r';
                    z = z->parent;
                    continue;
                }

                if (x->left->color == 'B') {
                    x->right->color = 'b';
                    x->color = 'r';
                    rotateLeft(x);
                    x = z->parent->left;
                }

                x->color = z->parent->color;
                z->parent->color = 'b';
                x->left->color = 'b';
                rotateRight(z->parent);
                z = root;
            }
        }
    }
    z->color = 'b';

    delete y;
}

void RedBlackTree::popRoot() {
    deleteVal(root->value);
}

RedBlackTree::Node *RedBlackTree::succesor(Node * node){
    Node* tmp;
    if (node != &guard)
    {
        if (node->right != &guard) {
            return minNode(node->right);

        }else{
            tmp = node->parent;
            while ((tmp != &guard) && (tmp->left != node))
            {
                node = tmp;
                tmp = tmp->parent;
            }
            return tmp;
        }
    }

    return &guard;
}

RedBlackTree::Node *RedBlackTree::minNode(Node * node){
    if (node != &guard) {
        while (node->left != &guard) {
            node = node->left;
        }
    }

    return node;
}

bool RedBlackTree::contains(int value){
    Node *node;
    node = root;
    while ((node != &guard) && (node->value != value)) {
        if (value < node->value) {
            node = node->left;
        }else {
            node = node->right;
        }
    }
    if (node == &guard) {
        return false;
    }
    return true;
}

void RedBlackTree::clearNode(Node * node){

    if (node != &guard){
        clearNode(node->left);
        clearNode(node->right);
        delete node;
    }
}

void RedBlackTree::print(Node *node){

    if(node != &guard){
        print(node->left);
        if(node != root) {
            std::cout << "value: " << node->value << " color: " << node->color << " parent: " << node->parent->value;
        }else {
            std::cout << "value: " << node->value << " color: " << node->color << " ROOT";
        }
        print(node->right);
    }
    std::cout << std::endl;
}
