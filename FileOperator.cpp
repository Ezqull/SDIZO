#include <string>
#include <iostream>
#include "FileOperator.hpp"


using namespace std;

FileOperator ::FileOperator() {
    int choice;
    cout << "1->Get data from file\n";
    cout << "2->Create file\n->";
    cin >> choice;

    switch (choice) {
        case 1:{
            cout << endl << "Enter file name: ";
            cin >> fileName;
            break;
        }
        case 2:{
            generateNumbersToFile();
        }
        default:
            break;

    }
}

FileOperator:: ~FileOperator() {}

void FileOperator::generateNumbersToFile() {

    int range;
    int amount;

    cout << "Enter amount of numbers to generate: " << endl;
    cin >> amount;

    cout << "Enter range of numbers to generate: " << endl;
    cin >> range;

    fileName = "random-numbers.txt";


    file.open("random-numbers.txt", ios::out);
    if (file.is_open()) {
        file << amount << endl;
        for (int i = 1; i < amount; i++) {
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
