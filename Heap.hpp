
class Heap {

public:
    int *array;                             // tablica kopca
    unsigned int size;                      // rozmiar kopca
    unsigned int maxSize;                   // maksymalny rozmiar kopca

    Heap();                                 // konstruktor
    ~Heap();                                // destruktor

    void extendHeap();                      // zwiększenie rozmiaru kopca
    void add(int val);                      // dodanie elementu

    void deleteVal(int val);                // usunięcie elementu

    void heapify(int index);               // posortowanie kopca

    bool contains(int val);                 // sprawdzenie czy kopiec zawiera element

    void print() const;                     // wyświetlenie kopca

    int getParent(int index) const;         // zwraca wartość rodzica
    int getLeftChild(int index) const;      // zwraca wartość lewego dziecka
    int getRightChild(int index) const;     // zwraca wartość prawego dziecka

};
