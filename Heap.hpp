
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
    void pop();

    void heapify(int index);               // posortowanie kopca

    bool contains(int val) const;                 // sprawdzenie czy kopiec zawiera element

    void print() const;                     // wyświetlenie kopca

    static int getParent(int index) ;         // zwraca wartość rodzica
    static int getLeftChild(int index) ;      // zwraca wartość lewego dziecka
    static int getRightChild(int index) ;     // zwraca wartość prawego dziecka

};
