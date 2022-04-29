
class List {

public:
    struct Node{                            // struktura służąca za elementy listy
        int val;
        Node *prev = nullptr;
        Node *next = nullptr;
    };

    List();                                 // kontruktor
    ~List();                                // destruktor

    void pushBeg(int val);                  // wstawienie na początek
    void pushEnd(int val);                  // wstawienie na koniec
    void insert(int val, unsigned int index);        // wstawienie na podaną pozycje

    void popBeg();                          // usunięcie z początku
    void popEnd();                          // usunięcie z końca
    void deleteVal(int val);                // usunięcie podanej wartości

    bool contains(int val) const;                 // sprawdzenie czy lista zawiera element

    void print() const;                     // wydrukowanie listy

private:
    Node *first = nullptr;                  // pierwszy element
    Node *last = nullptr;                   // ostatni element
    unsigned int size;                      // rozmiar listy
};
