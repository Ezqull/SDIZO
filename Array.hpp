
class Array{
private:
    int arraySize;         // rozmiar tablicy
    int* array;               // dane tablicy

public:
    Array(int arraySize = 0);           // konstruktor
    ~Array();                           // destruktor

    void pushBeg(int val);              // wstawienie na początek
    void pushEnd(int val);              // wstawienie na koniec
    void insert(int val, int index);    // wstawienie na podaną pozycje

    void popBeg();                      // usunięcie z początku
    void popEnd();                      // usunięcie z końca
    void deleteIndex(int val);            // usunięcie podanej wartości

    bool contains(int val);             // sprawdzenie czy tablica zawiera element

    void print() const;                 // wydrukowanie tablicy na ekranie
};