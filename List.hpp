
class List {

public:
    struct Node{
        int val;
        Node *prev = nullptr;
        Node *next = nullptr;
    };
    int size;

    List();
    ~List();

    void pushBeg(int val);
    void pushEnd(int val);
    void insert(int val, int index);

    void popBeg();
    void popEnd();
    void deleteVal(int val);

    bool contains(int val);

    void print() const;

private:
    Node *first = nullptr;
    Node *last = nullptr;
};
