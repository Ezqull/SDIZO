//
// Created by Michal on 20.04.2022.
//

#include "File_Operator.h"
#include "File_Operator.h"
#include <string>
#include <fstream>
#include <iostream>


using namespace std;

File_Operator ::File_Operator() {
    int choice;
    cout << "1->Wprowadz dane z pliku\n";
    cout << "2->Utworz pliku z liczbami pseudolosowymi\n->";
    cin >> choice;

    if(choice==1){
        set_file_name();
    } else {
        generate_numbers_to_file();
    }
}

void File_Operator ::set_file_name() {
    cout << endl << "Podaj nazwe pliku/sciezke z ktorego chcesz wczytac liczby: "; cin >> file_name;
}

void File_Operator::generate_numbers_to_file() {

    int zakres, ile_liczb;

    cout << "Podaj ile liczb chcesz wygenerowac: "; cin >> ile_liczb;
    cout << endl << "Podaj zakres liczb do wygenerowania (max zakres int)" << endl;
    cout << "zakres: "; cin >> zakres;
    file_name = "losowe_liczby.txt";


    plik.open("losowe_liczby.txt", ios::out);
    if (plik.good()) {
        plik << ile_liczb << endl;
        for (int i = 1; i < ile_liczb; i++) {
            plik << (rand() % zakres + 1) << endl;
        }
    }
    else {
        cout << "Plik nie zosta� utworzony!";
    }
    plik.close();
}

int*  File_Operator::read_file() {
    string linia;
    int* tablica = nullptr;
    int nr_lini = 1, rozmiar;
//    cout << endl << "Podaj nazwe pliku/sciezke z ktorego chcesz wczytac liczby: "; cin >> file_name;

    plik.open(file_name, ios::in);
    if (plik.good()) {
        getline(plik,linia);
        rozmiar = stoi(linia);
        tablica = new int[rozmiar];
        while (getline(plik, linia)) {

//            cout << linia << endl;
            tablica[nr_lini - 1] = stoi(linia);
            nr_lini++;
        }
    }
    else {
        cout << "Podany plik nie istenije/sciezka jest niepoprawna!";
    }
    plik.close();

    return tablica;
}

int File_Operator::read_quantity_of_numbers() {

    string linia;
    plik.open(file_name, ios::in);
    if (plik.good()) {
        getline(plik, linia);
        plik.close();
        return stoi(linia);
    }
    else {
        cout << endl <<"Nie wczytano ilosci liczb!";
        plik.close();
        return -1;
    }
}

File_Operator:: ~File_Operator() {
    cout << "Usuniecie File operatora";
}



