//
// Created by ezzqu on 27.04.2022.
//

#include <iostream>
#include "Array.hpp"

Array::Array(int arraySize) : arraySize(arraySize) {
    if(arraySize == 0){
        return;
    }
    array = new int[arraySize];
}

Array::~Array() {
    delete[] array;
}

void Array::insert(int val, int index){
    if (index >= arraySize) {
        std::cout << "Inserting nodePointer outside of array!";
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

void Array::pushBeg(int val) {

    int newSize = arraySize + 1;
    int *newArray = new int[newSize];

    std::copy(array, array + arraySize, newArray + 1);

    newArray[0] = val;

    delete[] array;
    array = newArray;

    arraySize = newSize;
}

void Array::pushEnd(int val) {

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

void Array::deleteVal(int val) {

    if(!contains(val)){
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

bool Array::contains(int val) {

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