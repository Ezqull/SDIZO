#include <deque>
#include <iostream>
#include "Heap.hpp"

Heap::Heap() : size(0), max(1){}

Heap::~Heap() {

    delete[] array;
}

void Heap::expandSize(){

    max = max * 2;
    int *tmp = new int[max];
    for (int i = 0; i <= max / 2; i++)
    {

        tmp[i]= array[i];
    }
    array = tmp;
}

void Heap::add(int val) {

    if (size == max){
        expandSize();
    }

    size++;

    int index = size - 1;
    array[index] = val;
    int parent = getParent(index);

    while (index >= 0 && array[parent] < array[index]){

        int tmp = array[parent];
        array[parent] = array[index];
        array[index] = tmp;
        index = parent;
        parent = getParent(index);
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
        std::copy(array + i + 1, array + size, tmp + i);

        delete[] array;
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

    delete[] array;
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
        index = largest;
        largest = getParent(index);
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
        int n = 0;


        for (int i = 0; i < size; i++) {

            for(int j = 0; j < max / levelElements; j++){
                std::cout << "  ";
            }
            std::cout << array[i];
            n++;
            if (n == levelElements){
                levelElements *= 2;
                n = 0;
                std::cout << std::endl;
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