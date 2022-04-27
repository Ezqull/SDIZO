//
// Created by ezzqu on 27.04.2022.
//

#include <iostream>
#include "Array.hpp"

Array::Array(const int &arraySize) : arraySize(arraySize) {
    if(arraySize == 0){
        return;
    }
    array = new int[arraySize];
}

Array::Array(const std::initializer_list<int> &list) : Array(list.size()){
    int i = 0;
    for(int val : list){
        array[i] = val;
    }
}

Array::~Array() {
    delete[] array;
}

void Array::resize(const int &size) {

    int *newArray = new int[size];

    std::copy(array, array + std::min(arraySize, size), newArray);

    delete[] array;
    array = newArray;

    arraySize = size;
}

void Array::insert(const int &val, const int &index){
    if (index >= arraySize) {
        std::cout << "Inserting element outside of array!";
    }

    int newSize = arraySize + 1;
    int *newArray = new int[newSize];

    std::copy(array, array + index, newArray);
    std::copy(array + index, array + arraySize, newArray + index + 1);

    newArray[index] = val;

    delete[] array;
    array = newArray;

    arraySize = newSize;
}

void Array::pushBeg(const int &val) {

    int newSize = arraySize + 1;
    int *newArray = new int[newSize];

    std::copy(array, array + arraySize, newArray + 1);

    newArray[0] = val;

    delete[] array;
    array = newArray;

    arraySize = newSize;
}

void Array::pushEnd(const int &val) {

    int newSize = arraySize + 1;
    int *newArray = new int[newSize];

    std::copy(array, array + arraySize, newArray);

    newArray[arraySize] = val;

    delete[] array;
    array = newArray;

    arraySize = newSize;
}

void Array::popBeg() {

    int newSize = arraySize - 1;
    int *newArray = new int[newSize];

    std::copy(array + 1, array + arraySize, newArray);

    delete[] array;
    array = newArray;

    arraySize = newSize;
}

void Array::popEnd() {

    int newSize = arraySize - 1;
    int *newArray = new int[newSize];

    std::copy(array, array + arraySize - 1, newArray);

    delete[] array;
    array = newArray;

    arraySize = newSize;
}

void Array::deleteVal(const int &val) {

    if(!containst(val)){
        std::cout << "Value not found";
        return;

    }else {

        int i = 0;

        while(array[i] != val){
            i++;
        }

        int newSize = arraySize - 1;
        int *newArray = new int[newSize];

        std::copy(array, array + i, newArray);
        std::copy(array + i + 1, array + arraySize, newArray + i);

        delete[] array;
        array = newArray;

        arraySize = newSize;
    }
}

bool Array::containst(const int &val) {

    for (int i = 0; i < arraySize; i++) {
        if (array[i] == val) {
            return true;
        }
    }
    return false;
}

void Array::print() const
{
    for (size_t i = 0; i < arraySize; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}