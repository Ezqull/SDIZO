//
// Created by Michal on 02.05.2022.
//

#include "RedBlackTree.hpp"

using namespace std;

RedBlackTree::RedBlackTree() {

    size = 0;
    //inicjalizowanie guarda wskazuje sam na siebie
    guard->color = 'B';
    guard->parent = guard;
    guard->left = guard;
    guard->right = guard;
    root = guard;
}

RedBlackTree::~RedBlackTree() {
    if (root) {
        delete_tree();
    }
}

void RedBlackTree::delete_tree() {
    delete_node(root);

    //Inicjalizacja strażnika
    guard->color = 'B';
    guard->parent = guard;
    guard->right = guard;
    guard->right = guard;
    root = guard;
    size = 0;
}

void RedBlackTree::delete_node(Node *node_to_delete) {

    //Jeżeli element nie jest strażnikiem, usuń jego dzieci
    //A nastepnie sam element
    if (node_to_delete != guard) {
        delete_node(node_to_delete->left);
        delete_node(node_to_delete->right);
        delete node_to_delete;

        //Zmniejsz size drzewa
        RedBlackTree::size--;
    } else {

        cout << "Usuwany element jest strażnikiem!!!" << endl;

    }
}

void RedBlackTree::left_rotation(Node *rotation_node) {

    Node *y, *p;

    y = rotation_node->right;
    if (y != guard) {
        p = rotation_node->parent;
        rotation_node->right = y->right;
        if (rotation_node->right != guard) rotation_node->right->parent = rotation_node;

        y->left = rotation_node;
        y->parent = p;
        rotation_node->parent = y;

        if (p != guard) {
            if (p->left == rotation_node) p->left = y; else p->right = y;
        } else root = y;
    }

}

void RedBlackTree::right_rotation(Node *rotation_node) {

    Node *y, *p;

    y = rotation_node->left;
    if (y != guard) {
        p = rotation_node->parent;
        rotation_node->left = y->right;
        if (rotation_node->left != guard) rotation_node->left->parent = rotation_node;

        y->right = rotation_node;
        y->parent = p;
        rotation_node->parent = y;

        if (p != guard) {
            if (p->left == rotation_node) p->left = y; else p->right = y;
        } else root = y;
    }

}

void RedBlackTree::add_node(int wartosc) {

    Node *X, *Y;

    //Stworzenie nowego węzła dla drzewa
    X = new Node;
    X->left = guard;
    X->left = guard;
    X->parent = root;
    X->val = wartosc;

    //Przypisanie korzenia jako X, jeżeli parent jest strażnikiem
    //W przeciwnym wypadku, zastąpienie liścia
    if (X->parent == guard) {
        root = X;
    } else {
        //Pętla wyszukuje liść do zastąpienia przez X
        //Zależnie od sytuacji zastępuje prawy lub lewy liść drzewa
        while (true) {
            //X zastępuje lewy liść
            if (wartosc < X->parent->val) {
                if (X->parent->left == guard) {
                    X->parent->left = X;
                    break;
                }
                X->parent = X->parent->left;

                // X zastępuje prawy liść
            } else if (wartosc > X->parent->val) {
                if (X->parent->right == guard) {
                    X->parent->right = X;
                    break;
                }
                X->parent = X->parent->right;

                //Brak możliwości zastąpienia liścia
            } else {
                delete X;
                return;
            }
        }

        //Kolorowanie węzła na czerwono
        X->color = 'R';
        while ((X != root) && (X->parent->color == 'R')) {
            if (X->parent == X->parent->parent->left) {
                Y = X->parent->parent->left;

                //Przypadek 1
                if (Y->color == 'R') {
                    X->parent->color = 'B';
                    Y->color = 'B';
                    X->parent->parent->color = 'R';
                    X = X->parent->parent;
                    continue;
                }

                //Przypadek 2
                if (X == X->parent->right) {
                    X = X->parent;
                    left_rotation(X);
                }

                //Przypadek 3
                X->parent->color = 'B';
                X->parent->parent->color = 'R';
                right_rotation(X->parent->parent);
                break;

                //Przypadki lustrzane
            } else {
                Y = X->parent->parent->left;

                //Przypadek lustrzany 1
                if (Y->color == 'R') {
                    X->parent->color = 'B';
                    Y->color = 'B';
                    X->parent->parent->color = 'R';
                    X = X->parent->parent;
                    continue;
                }

                //Przypadek lustrzany 2
                if (X == X->parent->left) {
                    X = X->parent;
                    right_rotation(X);
                }

                //Przypadek lustrzany 3
                X->parent->color = 'B';
                X->parent->parent->color = 'R';
                left_rotation(X->parent->parent);
                break;
            }
        }
        root->color = 'B';

        //Zwiększenie rozmiaru drzewa o 1
        size++;
    }
}

void RedBlackTree::delete_node(int wartosc) {

    Node *node_to_delete;
    find_node(wartosc, root, node_to_delete);

    Node *W, *Y, *Z;

    if ((node_to_delete->left == guard) || (node_to_delete->right == guard))
        Y = node_to_delete;
    else Y = find_next(node_to_delete);

    if (Y->left != guard) Z = Y->left;
    else Z = Y->right;

    Z->parent = Y->parent;

    if (Y->parent == guard) root = Z;
    else if (Y == Y->parent->left) Y->parent->left = Z;
    else Y->parent->right = Z;

    if (Y != node_to_delete) node_to_delete->val = Y->val;

    if (Y->color == 'B')   // Naprawa struktury drzewa czerwono-czarnego
        while ((Z != root) && (Z->color == 'B'))
            if (Z == Z->parent->left) {
                W = Z->parent->right;

                //Przypadek 1
                if (W->color == 'R') {
                    W->color = 'B';
                    Z->parent->color = 'R';
                    left_rotation(Z->parent);
                    W = Z->parent->right;
                }

                //Przypadek 2
                if ((W->left->color == 'B') && (W->right->color == 'B')) {
                    W->color = 'R';
                    Z = Z->parent;
                    continue;
                }

                //Przypadek 3
                if (W->right->color == 'B') {
                    W->right->color = 'B';
                    W->color = 'R';
                    right_rotation(W);
                    W = Z->parent->right;
                }

                //Przypadek 4
                W->color = Z->parent->color;
                Z->parent->color = 'B';
                W->right->color = 'B';
                left_rotation(Z->parent);

                //Zakończenie pętli
                Z = root;

                //Przypadki lustrzane
            } else {
                W = Z->parent->left;

                //Lustrzany przypadek 1
                if (W->color == 'R') {
                    W->color = 'B';
                    Z->parent->color = 'R';
                    left_rotation(Z->parent);
                    W = Z->parent->left;
                }

                //Lustrzany przypadek 2
                if ((W->left->color == 'B') && (W->right->color == 'B')) {
                    W->color = 'R';
                    Z = Z->parent;
                    continue;
                }

                //Lustrzany przypadek 3
                if (W->left->color == 'B') {
                    W->right->color = 'B';
                    W->color = 'R';
                    left_rotation(W);
                    W = Z->parent->left;
                }

                //Lustrzany przypadek 4
                W->color = Z->parent->color;
                Z->parent->color = 'B';
                W->left->color = 'B';
                right_rotation(Z->parent);

                //Zakończenie pętli
                Z = root;
            }

    Z->color = 'B';

    delete Y;
}

    void RedBlackTree::find_node(int value, Node *node_to_find, Node *&found_node) {
    if (node_to_find != guard) {
        if (node_to_find->val == value) {
            found_node = node_to_find;
            return;
        }
        find_node(value, node_to_find->left, found_node);
        find_node(value, node_to_find->right, found_node);
    }
}

void RedBlackTree::find_node(int wartosc) {
    bool znalezione = false;
    find_value(wartosc, root, znalezione);

    if (znalezione) {
        cout << "Wartość " << wartosc << " występuje w drzewie" << endl;
    } else {
        cout << "Wartość " << wartosc << " nie występuje w drzewie" << endl;

    }
}

void RedBlackTree::find_value(int wartosc, Node *korzenElementuDrzewa, bool &znalezione) {

    if (korzenElementuDrzewa != guard) {
        if (korzenElementuDrzewa->val == wartosc) {
            znalezione = true;
            return;
        }
        find_value(wartosc, korzenElementuDrzewa->left, znalezione);
        find_value(wartosc, korzenElementuDrzewa->right, znalezione);
    }

}

void RedBlackTree::display_tree() {

}

RedBlackTree::Node *RedBlackTree::find_next(Node *p) {
    Node *nastepnyElementDrzewa;

    if (p != guard) {
        if (p->right != guard) return find_minimum(p->right);
        else {
            nastepnyElementDrzewa = p->parent;
            while ((nastepnyElementDrzewa != guard) && (p == nastepnyElementDrzewa->right)) {
                p = nastepnyElementDrzewa;
                nastepnyElementDrzewa = nastepnyElementDrzewa->parent;
            }
            return nastepnyElementDrzewa;
        }
    }
    return guard;
}

RedBlackTree::Node *RedBlackTree::find_minimum(Node *p) {
    if (p != guard) {
        while (p->left != guard){
            p = p->left;
        }
    }
    return p;
}

