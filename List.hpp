
class List {

public:
    struct Node{
        int val;
        Node *prev = nullptr;
        Node *next = nullptr;
    };

    List();
    ~List();

    void pushBeg(int val);
    void pushEnd(int val);
    void insert(int val, Node *index);

    void popBeg();
    void popEnd();
    void deleteVal(int val);

    bool containst(int val);

    void print() const;

private:
    Node *head = nullptr;
    Node *tail = nullptr;
};
