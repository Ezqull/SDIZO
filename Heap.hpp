
class Heap {

public:
    int *array;                             // tablica kopca
    int size;                               // rozmiar kopca
    int max;                                // max wielkość kopca

    Heap();                                 // konstruktor
    ~Heap();                                // destruktor

    void expandSize();                      // zwiększa max wielkość kopca

    void add(int val);                      // dodanie elementu

    void deleteVal(int val);                // usunięcie elementu
    void pop();                             // usunięcie ostatniego elementu

    void heapify(int index) const;          // posortowanie kopca

    bool contains(int val) const;           // sprawdzenie czy kopiec zawiera element

    void print() const;                     // wyświetlenie kopca

private:
    static int getParent(int index) ;       // zwraca wartość rodzica
    static int getLeftChild(int index) ;    // zwraca wartość lewego dziecka
    static int getRightChild(int index) ;   // zwraca wartość prawego dziecka

};
