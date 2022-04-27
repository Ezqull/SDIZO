#include <initializer_list>

//
// Created by ezzqu on 27.04.2022.
//
class Array{
private:
    int arraySize = 0;
    int* array = nullptr;

public:
    Array(int arraySize = 0);
    ~Array();

    void insert(int val, int index);

    void pushBeg(int val);
    void pushEnd(int val);

    void popBeg();
    void popEnd();
    void deleteVal(int val);

    bool containst(int val);

    void print() const;
};