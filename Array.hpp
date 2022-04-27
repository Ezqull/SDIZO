
class Array{
private:
    int arraySize = 0;
    int* array = nullptr;

public:
    Array(int arraySize = 0);
    ~Array();

    void pushBeg(int val);
    void pushEnd(int val);
    void insert(int val, int index);

    void popBeg();
    void popEnd();
    void deleteVal(int val);

    bool containst(int val);

    void print() const;
};