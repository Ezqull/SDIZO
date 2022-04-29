
#include <deque>
#include <iostream>
#include "Heap.hpp"

Heap::Heap() : size(0), maxSize(1), array(new int[maxSize]){}

Heap::~Heap() {

    delete[] array;
}

void Heap::extendHeap() {
    maxSize *= 2;
    int *tmp = new int[maxSize];

    std::copy(array, array + maxSize/2, tmp);

    std::copy(tmp, tmp + maxSize, array);

    delete[] tmp;
}

void Heap::add(int val) {
    if(size == maxSize){
        extendHeap();
    }

    size++;

    int i = size -1;
    array[i] = val;
    int parent = getParent(i);

    while (i > 0 && array[parent] < array[i]){

        int tmp = array[parent];
        array[parent] = array[i];
        array[i] = tmp;
        i = parent;
        parent = getParent(i);
    }

}

void Heap::deleteVal(int val) {

    if(!contains(val)){
        std::cout << "Value not found";
        return;

    }else{
        int i = size - 1;
        while (array[i] != val){
            i--;
        }

        int *tmp = new int[size - 1];

        std::copy(array, array + i, tmp);
        std::copy(array + i + 1, array + size, tmp);

        delete[] array;
        array = tmp;

        size--;

        for(int i = 0; i < size; i++){
            heapify(i);
        }
    }
}

void Heap::heapify(int index) {

    int left = getLeftChild(index);
    int right = getRightChild(index);
    int largest = getParent(index);

    if (left < size && array[left] > array[largest]){
        largest = left;
    }

    if (right < size && array[right] > array[largest]){
        largest = right;
    }

    if (largest != index){
        int tmp = array[index];
        array[index] = array[largest];
        array[largest] = tmp;
        heapify(index);
    }
}

bool Heap::contains(int val) {
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
        int n = 0;


        for (int i = 0; i < size; i++) {

            std::cout << array[i] << " ";
            n++;
            if (n == levelElements){
                levelElements *= 2;
                n = 0;
                std::cout << std::endl;
            }
        }
    }
}

int Heap::getParent(int index) const {
    return (index - 1) / 2;
}

int Heap::getLeftChild(int index) const {
    return 2 * index + 1;
}

int Heap::getRightChild(int index) const {
    return 2 * index + 2;
}