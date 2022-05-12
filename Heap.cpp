#include <deque>
#include <iostream>
#include "Heap.hpp"

Heap::Heap() : size(0){
    array = nullptr;
}

Heap::~Heap() {
    delete[] array;
}


void Heap::add(int val) {

    if(size == 0){
        array = new int[1];
        array[0] = val;
    }else {

        int *tmp = new int[size + 1];
        std::copy(array, array + size, tmp);

        delete[] array;
        array = tmp;

        int index = size;
        int parent = getParent(index);

        while (index > 0 && array[parent] < val) {

            array[index] = array[parent];
            index = parent;
            parent = getParent(parent);
        }
        array[index] = val;
    }
    size++;
}

void Heap::deleteIndex(int index) {

    if(index >= size){
        std::cout << "Out of range";
        return;

    }else{

        int *tmp = new int[size - 1];

        std::copy(array, array + index, tmp);
        std::copy(array + index + 1, array + size, tmp + index);

        array = tmp;

        size--;

        for(int j = 0; j < size; j++){
            heapify(j);
        }
    }
}

void Heap::pop(){

    int *tmp = new int[size - 1];

    std::copy(array, array + size - 1 , tmp);

    array = tmp;

    size--;
}

void Heap::heapify(int index) const {

    int left = getLeftChild(index);
    int right = getRightChild(index);
    int largest = getParent(index);

    if (left < size && array[left] > array[largest]){
        largest = left;
    }

    if (right < size && array[right] > array[largest]){
        largest = right;
    }

    while (index >= 0 && array[largest] < array[index]){

        int tmp = array[largest];
        array[largest] = array[index];
        array[index] = tmp;
        heapify(largest);
    }
}

bool Heap::contains(int val) const {
    for (int i = 0; i < size; i++) {
        if(array[i] == val){
            return true;
        }
    }
    return false;
}

void Heap::print() const {

    if (size == 0){
        std::cout << "Heap is empty" << std::endl;
        return;

    }else {
        int levelElements = 1;
        int n = 1;


        for (int i = 0; i < size; i++) {

            for(int j = 0; j <  n * (size / (levelElements)); j++){
                std::cout << "  ";
            }
            std::cout << array[i];
            n++;
            if (n - 1 == levelElements){
                levelElements *= 2;
                n = 1;
                std::cout << std::endl << std::endl;
            }
        }
    }
}

int Heap::getParent(int index) {
    return (index - 1) / 2;
}

int Heap::getLeftChild(int index) {
    return 2 * index + 1;
}

int Heap::getRightChild(int index) {
    return 2 * index + 2;
}