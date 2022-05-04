#include "FileOperator.hpp"
#include <string>
#include <iostream>

using namespace std;

FileOperator ::FileOperator()= default;

FileOperator:: ~FileOperator() = default;

void FileOperator::generateNumbersToFile() {

    int range;
    int amount;

    cout << "Enter amount of numbers to generate: " << endl;
    cin >> amount;

    cout << "Enter range of numbers to generate: " << endl;
    cin >> range;

    file.open("random-numbers.txt", ios::out);
    if (file.is_open()) {
        file << amount << endl;
        for (int i = 0; i < amount; i++) {
            file << (rand() % range + 1) << endl;
        }
    }
    else {
        cout << "ERROR!";
        exit(-1);
    }
    file.close();
}

void FileOperator::readFile() {

    string line;
    int lineNr = 1;
    cout << endl << "Enter file name: ";
    string input;
    cin >> input;

    file.open(input, ios::in);

    if (file.is_open()) {

        getline(file, line);
        size = stoi(line);
        data = new int[size];

        while (getline(file, line)) {
            data[lineNr - 1] = stoi(line);
            lineNr++;
        }
    }
    else {
        cout << "ERROR!";
        exit(-1);
    }
    file.close();
}

int FileOperator::getSize() {
    return size;
}
