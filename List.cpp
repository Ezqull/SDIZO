#include <iostream>
#include "List.hpp"

List::List() : size(0){}

List::~List() {
    Node *node = first;

    while (node) {
        Node *next = node->next;

        delete node;
        node = next;
    }
}

void List::pushBeg(int val) {

    Node *node = first;

    first = new Node();
    first->val = val;
    first->next = node;

    if (node) {
        node->prev = first;
    }else {
        last = first;
    }

    size++;
}

void List::pushEnd(int val) {

    Node *node = new Node();
    node->val = val;
    node->prev = last;

    if (last) {
        last->next = node;
    }else {
        first = node;
    }

    last = node;

    size++;
}

void List::insert(int val, int index) {

    if (size != 0 && index < size){
        if (index == 0){
            pushBeg(val);
        }else if (index == size){
            pushEnd(val);
        } else{
            Node *node = first;

            for (int i = 0; i < index; i++) {
                node = node->next;
            }

            Node *tmp = new Node();
            tmp->val = val;
            tmp->prev = node;
            tmp->next = node->next;
            node->next = node;
            (node->next)->prev = node;
            size++;

            delete tmp;
            delete node;
        }
    }
}

void List::popBeg() {
    if (!first) {
        return;
    }

    if (!first->next) {
        delete first;

        last = nullptr;
        first = nullptr;
        size = 0;

        return;
    }

    Node *node = first;
    first = first->next;
    first->prev = nullptr;

    delete node;

    size--;
}

void List::popEnd() {
    if (!last) {
        return;
    }

    if (!last->prev) {
        // Tail is the last node in the list
        delete last;

        last = nullptr;
        first = nullptr;
        size = 0;

        return;
    }

    Node *node = last;
    last = last->prev;
    last->next = nullptr;

    delete node;
    size--;
}

void List::deleteVal(int val) {

    if(!contains(val)){
        std::cout << "Value not found";
        return;
    }else{

        Node *tmp = first;

        for(int i = 0; i < size; i++){
            if(val == tmp->val && i == 0){
                popBeg();
            }else if(val == tmp->val && i == size - 1){
                popEnd();
            }else if(val == tmp->val && i != 0 && i != size - 1){
                (tmp->next)->prev = tmp->prev;
                (tmp->prev)->next = tmp->next;
                delete tmp;
                size--;
                return;
            }
        }
    }
}

bool List::contains(int val) {
    Node *node = first;
    for(int i = 0; i < size; i++){
        std::cout<<node->val << " " << val << " ";
        if(val == node->val) {
            std::cout << 1;
            return true;
        }
        node = node->next;
    }
    return false;
}

void List::print() const {
    Node *node = first;

    for (int i = 0; i < size; i++) {
        if(i != size-1) {
            std::cout << node->val << ", ";
            node = node->next;
        }else{
            std::cout << node->val << std::endl;
            node = node->next;
        }
    }
}
