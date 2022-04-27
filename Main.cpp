#include <iostream>
#include <vector>
#include <fstream>
#include "Array.hpp"

using namespace std;

const string operations = "r - read from file\na - add value\nd - delete value\nc - search if value exists\np - print container contents\nm - go back to menu\n";

vector<int> readFile() {

    string filename;

    cout << "Enter file name: \n";
    cin >> filename;

    fstream file;
    file.open(filename, ios::out);

    cout << file.is_open();

    if (!file.is_open()) {
        cout << "File not found";
        exit(-1);
    }

    vector<int> vals;
    size_t size;
    file >> size;

    while (size > 0) {
        int val;
        file >> val;
        vals.push_back(val);
        size--;
        cout << size << " ";
    }

    return vals;
}

char getUserInputChar(){
    char input;
    cin >> input;

    cin.clear();

    return input;
}

int getUserInputNum(){
    int input;
    cin >> input;

    cin.clear();

    return input;
}

void arrayMenu(){
    Array array;
    const string options = "\nb - beginning\ne - end\nc - choose\n";

    while (1) {
        cout << "Choose operation: \n" + operations;

        switch (getUserInputChar()) {
            case 'r': {
                auto vals = readFile();
                for (auto val: vals) {
                    array.pushBeg(val);
                }
                break;
            }
            case 'a': {
                cout << "Choose position: " + options;

                switch (getUserInputChar()) {
                    case 'b':{
                        cout << "Write value to add: \n";
                        array.pushBeg(getUserInputNum());
                        break;
                    }

                    case 'e':{
                        cout << "Write value to add: \n";
                        array.pushEnd(getUserInputNum());
                        break;
                    }

                    case 'c':{

                        cout << "Write value to add: \n";
                        const int val = getUserInputNum();

                        cout << "Write position: \n";
                        const int pos = getUserInputNum();

                        array.insert(val, pos);
                        break;
                    }
                }

                break;
            }

            case 'd': {
                cout << "Choose position: " + options;

                switch (getUserInputChar()) {
                    case 'b':{
                        array.popBeg();
                        break;
                    }

                    case 'e':{
                        array.popEnd();
                        break;
                    }

                    case 'c':{
                        cout << "Write value to delete: \n";
                        array.deleteVal(getUserInputNum());
                        break;
                    }
                }

                break;
            }

            case 'c':
                cout << "Choose value to check: \n";

                if (array.containst(getUserInputChar())){
                    cout << "Array containst this value." << endl;

                }else {
                    cout << "Array doesn't contain this value." << endl;
                }

                break;

            case 'p': {

                array.print();

                break;
            }

            case 'm': {
                return;
            }
        }
    }
}

int main() {
    const string structures = "a - Array\nl - List\nb - Binary Heap\nr - Red Black Tree\nq - Quit\n";

    while(1){
        cout << "Choose structure: \n" + structures;
        switch (getUserInputChar()) {
            case 'a':
                arrayMenu();
                break;

            case 'q':
                return 1;
                break;
        }
    }
    return 0;
}
