
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
    if (index >= arraySize || index < 0) {
        std::cout << "Out of bounds";
        return;
    }

    int newSize = arraySize + 1;
    int *newArray = new int[newSize];

    std::copy(array, array + index, newArray);
    std::copy(array + index, array + arraySize, newArray + index + 1);

    newArray[index] = val;

    array = newArray;

    arraySize = newSize;
}

void Array::pushBeg(int val) {

    int newSize = arraySize + 1;
    int *newArray = new int[newSize];

    std::copy(array, array + arraySize, newArray + 1);

    newArray[0] = val;

    array = newArray;

    arraySize = newSize;
}

void Array::pushEnd(int val) {

    int newSize = arraySize + 1;
    int *newArray = new int[newSize];

    std::copy(array, array + arraySize, newArray);

    newArray[arraySize] = val;

    array = newArray;

    arraySize = newSize;
}

void Array::popBeg() {

    if(arraySize == 0){
        return;
    }

    int newSize = arraySize - 1;
    int *newArray = new int[newSize];

    std::copy(array + 1, array + arraySize, newArray);

    array = newArray;

    arraySize = newSize;
}

void Array::popEnd() {

    if(arraySize == 0){
        return;
    }

    int newSize = arraySize - 1;
    int *newArray = new int[newSize];

    std::copy(array, array + arraySize - 1, newArray);

    array = newArray;

    arraySize = newSize;
}

void Array::deleteIndex(int index) {

    if(index >= arraySize || index < 0){
        return;
    }

    if(arraySize == 0){
        return;
    }

    if(index == 0){
        popBeg();
    }else if(index == arraySize - 1){
        popEnd();
    }

    int newSize = arraySize - 1;
    int *newArray = new int[newSize];

    std::copy(array, array + index, newArray);
    std::copy(array + index + 1, array + arraySize, newArray + index);

    array = newArray;
    arraySize = newSize;
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
        if(i != arraySize-1) {
            std::cout << array[i] << ", ";
        }else{
            std::cout << array[i] << std::endl;
        }

    }
    std::cout << std::endl;
}
