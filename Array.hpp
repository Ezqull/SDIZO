#include <initializer_list>

//
// Created by ezzqu on 27.04.2022.
//
class Array{
private:
    int arraySize = 0;
    int* array = nullptr;

public:
    Array(const int &arraySize = 0);
    Array(const std::initializer_list<int> &list);
    ~Array();

    void resize(const int &size);

    void insert(const int &val, const int &index);

    void pushBeg(const int &val);
    void pushEnd(const int &val);

    void popBeg();
    void popEnd();
    void deleteVal(const int &val);

    bool containst(const int &val);

    void print() const;
};