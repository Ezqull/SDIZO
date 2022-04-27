#include <iostream>
#include "List.hpp"

List::List() {}

List::~List() {
    Node *node = head;

    while (node) {
        Node *next = node->next;

        delete node;
        node = next;
    }
}

void List::pushBeg(int val) {

    Node *node = head;

    head = new Node();
    head->val = val;
    head->next = node;

    if (node) {
        node->prev = head;
    }else {
        tail = head;
    }
}

void List::pushEnd(int val) {

    Node *node = new Node();
    node->val = val;
    node->prev = tail;

    if (tail) {
        tail->next = node;
    }else {
        head = node;
    }

    tail = node;
}

void List::insert(int val, Node *index) {

    if(!index){
        std::cout << "Node is empty";
    }

    Node *node = new Node();
    node->val = val;
    node->prev = index->prev;
    node->next = index;

    if (index->prev) {
        index->prev->next = node;
    }else {
        head = node;
    }

    index->prev = node;
}
