#include "FileOperator.hpp"
#include <string>
#include <iostream>

using namespace std;

FileOperator ::FileOperator() = default;

FileOperator:: ~FileOperator() = default;

bool FileOperator::generateNumbersToFile() {

    int range;
    int amount;

    cout << "Enter amount of numbers to generate: " << endl;
    cin >> amount;

    if(amount < 1){
        return false;
    }

    cout << "Enter range of numbers to generate: " << endl;
    cin >> range;

    if(range < 1){
        return false;
    }

    file.open("random-numbers.txt", ios::out);
    if (file.good()) {
        file << amount << endl;
        for (int i = 0; i < amount; i++) {
            file << (rand() % range + 1) << endl;
        }
    }
    else {
        cout << "ERROR!" << endl;
        return false;
    }
    file.close();
    return true;
}

bool FileOperator::readFile() {

    string line;
    int lineNr = 1;
    cout << endl << "Enter file name: \n";
    string input;
    cin >> input;

    file.open(input, ios::in);

    if (file.good()) {

        getline(file, line);
        size = stoi(line);
        data = new int[size];

        while (getline(file, line)) {
            data[lineNr - 1] = stoi(line);
            lineNr++;
        }
    }
    else {
        cout << "ERROR!" << endl;
        return false;
    }
    file.close();
    return true;
}

int FileOperator::getSize() const {
    return size;
}
