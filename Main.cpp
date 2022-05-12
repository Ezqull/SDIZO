#include <iostream>
#include <chrono>
#include "Array.hpp"
#include "List.hpp"
#include "Heap.hpp"
#include "RedBlackTree.hpp"
#include "FileOperator.hpp"

using namespace std;

const string operations = "r - Read from file\na - Add value\nd - Delete value\ns - Search if value exists\np - Print container contents\nt - Measure operation time\nm - Go back to menu\n";
const string timeOptions = "a - Adding value\nd - Deleting value\ns - Searching for value\n";

void arrayMenu(){
    Array array;
    const string options = "\nb - Beginning\ne - End\nc - Choose\n";

    while (true) {
        cout << endl << "Choose operation: \n" + operations;

        char input;
        cin >> input;

        cin.clear();

        switch (input) {
            case 'r': {
                FileOperator fileOperator;
                if(fileOperator.readFile()) {
                    for (int i = 0; i < fileOperator.getSize(); i++) {
                        array.pushBeg(fileOperator.data[i]);
                    }
                }
                break;
            }
            case 'a': {
                cout << "Choose position: " + options;

                char input1;
                cin >> input1;

                cin.clear();

                switch (input1) {
                    case 'b':{
                        cout << "Write value to add: \n";
                        int input2;
                        cin >> input2;
                        cin.clear();
                        array.pushBeg(input2);
                        break;
                    }

                    case 'e':{
                        cout << "Write value to add: \n";
                        int input2;
                        cin >> input2;
                        cin.clear();
                        array.pushEnd(input2);
                        break;
                    }

                    case 'c':{

                        cout << "Write value to add: \n";
                        int val;
                        cin >> val;
                        cin.clear();

                        cout << "Write position: \n";
                        int pos;
                        cin >> pos;
                        cin.clear();

                        array.insert(val, pos);
                        break;
                    }
                }

                break;
            }

            case 'd': {
                cout << "Choose position: " + options;

                char input1;
                cin >> input1;

                cin.clear();

                switch (input1) {
                    case 'b':{
                        array.popBeg();
                        break;
                    }

                    case 'e':{
                        array.popEnd();
                        break;
                    }

                    case 'c':{
                        cout << "Enter index: \n";
                        int index;
                        cin >> index;
                        cin.clear();
                        array.deleteIndex(index - 1);
                        break;
                    }
                }

                break;
            }

            case 's': {
                cout << "Choose value to check: \n";

                int input1;
                cin >> input1;

                cin.clear();

                if (array.contains(input1)) {
                    cout << "Array contains this value." << endl;

                } else {
                    cout << "Array doesn't contain this value." << endl;
                }

                break;
            }

            case 'p': {

                array.print();

                break;
            }

            case 't':{
                cout << "Choose operation to check:\n" + timeOptions << endl;

                char input1;
                cin >> input1;

                cin.clear();

                switch (input1) {
                    case 'a':{
                        cout << "Enter size of structure:\n";
                        int size;
                        cin >> size;

                        cin.clear();

                        cout << "Choose position:\nb - Beginning\ne - End\nc - Choose";
                        char input2;
                        cin >> input2;

                        cin.clear();

                        switch (input2) {
                            case 'b': {
                                for (int i = 0; i < size; i++) {
                                    array.pushBeg(rand() % size);
                                }
                                auto start = chrono::high_resolution_clock::now();
                                array.pushBeg(rand() % size);
                                auto end = chrono::high_resolution_clock::now();
                                cout << endl << "Time [ns]: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
                                for (int i = 0; i < size + 1; i++) {
                                    array.popBeg();
                                }
                                break;
                            }
                            case 'e': {
                                for (int i = 0; i < size; i++) {
                                    array.pushEnd(rand() % size);
                                }
                                auto start = chrono::high_resolution_clock::now();
                                array.pushEnd(rand() % size);
                                auto end = chrono::high_resolution_clock::now();
                                cout << endl << "Time [ns]: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
                                for (int i = 0; i < size + 1; i++) {
                                    array.popEnd();
                                }
                                break;
                            }
                            case 'c': {
                                int val = rand() % size;
                                int index = rand() % size;
                                for (int i = 0; i < size; i++) {
                                    array.pushEnd(rand() % size);
                                }
                                auto start = chrono::high_resolution_clock::now();
                                array.insert(val, index);
                                auto end = chrono::high_resolution_clock::now();
                                cout << endl << "Time [ns]: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
                                for (int i = 0; i < size + 1; i++) {
                                    array.popEnd();
                                }
                                break;
                            }
                        }
                        break;
                    }
                    case 'd':{
                        cout << "Enter size of structure:\n";
                        int size;
                        cin >> size;
                        cin.clear();
                        cout << "Choose position:\nb - Beginning\ne - End\nc - Choose position\n";
                        char input2;
                        cin >> input2;
                        cin.clear();
                        switch (input2) {
                            case 'b': {
                                for (int i = 0; i < size; i++) {
                                    array.pushBeg(rand() % size);
                                }
                                auto start = chrono::high_resolution_clock::now();
                                array.popBeg();
                                auto end = chrono::high_resolution_clock::now();
                                cout << endl << "Time [ns]: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
                                for (int i = 0; i < size - 1; i++) {
                                    array.popEnd();
                                }
                                break;
                            }
                            case 'e': {
                                for (int i = 0; i < size; i++) {
                                    array.pushEnd(rand() % size);
                                }
                                auto start = chrono::high_resolution_clock::now();
                                array.popEnd();
                                auto end = chrono::high_resolution_clock::now();
                                cout << endl << "Time [ns]: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
                                for (int i = 0; i < size - 1; i++) {
                                    array.popEnd();
                                }
                                break;
                            }
                            case 'c': {
                                for (int i = 0; i < size; i++) {
                                    array.pushBeg(rand() % size);
                                }
                                int index = rand() % size;
                                cin.clear();
                                auto start = chrono::high_resolution_clock::now();
                                array.deleteIndex(index - 1);
                                auto end = chrono::high_resolution_clock::now();
                                cout << endl << "Time [ns]: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
                                for (int i = 0; i < size - 1; i++) {
                                    array.popEnd();
                                }
                                break;
                            }
                        }
                        break;
                    }
                    case 's':{
                        cout << "Enter size of structure:\n";
                        int size;
                        cin >> size;
                        cin.clear();
                        int val = rand() % size;
                        for (int i = 0; i < size; i++) {
                            array.pushBeg(rand() % size);
                        }
                        auto start = chrono::high_resolution_clock::now();
                        array.contains(val);
                        auto end = chrono::high_resolution_clock::now();
                        cout << endl << "Time [ns]: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
                        for (int i = 0; i < size; i++) {
                            array.popEnd();
                        }
                        break;
                    }
                }
                break;
            }

            case 'm': {
                return;
            }

            default:
                break;
        }
    }
}

void listMenu(){
    List list;
    const string options = "\nb - Beginning\ne - End\nc - Choose\n";

    while (true){
        cout << endl << "Choose operation: \n" + operations;

        char input;
        cin >> input;
        cin.clear();

        switch (input) {
            case 'r': {
                FileOperator fileOperator;
                if(fileOperator.readFile()) {
                    for (int i = 0; i < fileOperator.getSize(); i++) {
                        list.pushBeg(fileOperator.data[i]);
                    }
                }
                break;
            }
            case 'a': {
                cout << "Choose position: " + options;

                char input1;
                cin >> input1;
                cin.clear();

                switch (input1) {
                    case 'b':{
                        cout << "Write value to add: \n";
                        int val;
                        cin >> val;
                        cin.clear();
                        list.pushBeg(val);
                        break;
                    }

                    case 'e':{
                        cout << "Write value to add: \n";
                        int val;
                        cin >> val;
                        cin.clear();
                        list.pushEnd(val);
                        break;
                    }

                    case 'c':{

                        cout << "Write value to add: \n";
                        int val;
                        cin >> val;
                        cin.clear();

                        cout << "Write position: \n";
                        char pos;
                        cin >> pos;
                        cin.clear();

                        list.insert(val, pos);
                        break;
                    }
                }
                break;
            }

            case 'd': {
                cout << "Choose position: " + options;

                char input1;
                cin >> input1;
                cin.clear();

                switch (input1) {
                    case 'b':{
                        list.popBeg();
                        break;
                    }

                    case 'e':{
                        list.popEnd();
                        break;
                    }

                    case 'c':{
                        cout << "Enter index: \n";
                        int index;
                        cin >> index;
                        cin.clear();
                        list.deleteIndex(index - 1);
                        break;
                    }
                }
                break;
            }

            case 's': {
                cout << "Choose value to check: \n";

                int input1;
                cin >> input1;
                cin.clear();

                if (list.contains(input1)) {
                    cout << "List contains this value." << endl;

                } else {
                    cout << "List doesn't contain this value." << endl;
                }

                break;
            }

            case 'p': {

                list.print();

                break;
            }

            case 't':{
                cout << "Choose operation to check:\n" + timeOptions << endl;

                char input1;
                cin >> input1;

                cin.clear();

                switch (input1) {
                    case 'a':{
                        cout << "Enter size of structure:\n";
                        int size;
                        cin >> size;

                        cin.clear();

                        cout << "Choose position:\nb - Beginning\ne - End\nc - Choose index\n";
                        char input2;
                        cin >> input2;

                        cin.clear();

                        switch (input2) {
                            case 'b': {
                                for (int i = 0; i < size; i++) {
                                    list.pushBeg(rand() % size);
                                }
                                auto start = chrono::high_resolution_clock::now();
                                list.pushBeg(rand() % size);
                                auto end = chrono::high_resolution_clock::now();
                                cout << endl << "Time [ns]: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
                                for (int i = 0; i < size + 1; i++) {
                                    list.popBeg();
                                }
                                break;
                            }
                            case 'e': {
                                for (int i = 0; i < size; i++) {
                                    list.pushEnd(rand() % size);
                                }
                                auto start = chrono::high_resolution_clock::now();
                                list.pushEnd(rand() % size);
                                auto end = chrono::high_resolution_clock::now();
                                cout << endl << "Time [ns]: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
                                for (int i = 0; i < size + 1; i++) {
                                    list.popEnd();
                                }
                                break;
                            }
                            case 'c': {
                                int val = rand() % size;
                                int index = rand() % size;
                                for (int i = 0; i < size; i++) {
                                    list.pushEnd(rand() % size);
                                }
                                auto start = chrono::high_resolution_clock::now();
                                list.insert(val, index);
                                auto end = chrono::high_resolution_clock::now();
                                cout << endl << "Time [ns]: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
                                for (int i = 0; i < size + 1; i++) {
                                    list.popEnd();
                                }
                                break;
                            }
                        }
                        break;
                    }
                    case 'd':{
                        cout << "Enter size of structure:\n";
                        int size;
                        cin >> size;
                        cin.clear();
                        cout << "Choose position:\nb - Beginning\ne - End\nc - Choose position\n";
                        char input2;
                        cin >> input2;
                        cin.clear();
                        switch (input2) {
                            case 'b': {
                                for (int i = 0; i < size; i++) {
                                    list.pushBeg(rand() % size);
                                }
                                auto start = chrono::high_resolution_clock::now();
                                list.popBeg();
                                auto end = chrono::high_resolution_clock::now();
                                cout << endl << "Time [ns]: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
                                for (int i = 0; i < size - 1; i++) {
                                    list.popEnd();
                                }
                                break;
                            }
                            case 'e': {
                                for (int i = 0; i < size; i++) {
                                    list.pushEnd(rand() % size);
                                }
                                auto start = chrono::high_resolution_clock::now();
                                list.popEnd();
                                auto end = chrono::high_resolution_clock::now();
                                cout << endl << "Time [ns]: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
                                for (int i = 0; i < size - 1; i++) {
                                    list.popEnd();
                                }
                                break;
                            }
                            case 'c': {
                                for (int i = 0; i < size; i++) {
                                    list.pushBeg(rand() % size);
                                }
                                int index = rand() % size;
                                auto start = chrono::high_resolution_clock::now();
                                list.deleteIndex(index - 1);
                                auto end = chrono::high_resolution_clock::now();
                                cout << endl << "Time [ns]: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
                                for (int i = 0; i < size - 1; i++) {
                                    list.popEnd();
                                }
                                break;
                            }
                        }
                        break;
                    }
                    case 's':{
                        cout << "Enter size of structure:\n";
                        int size;
                        cin >> size;
                        cin.clear();
                        int val = rand() % size;
                        for (int i = 0; i < size; i++) {
                            list.pushBeg(rand() % size);
                        }
                        auto start = chrono::high_resolution_clock::now();
                        list.contains(val);
                        auto end = chrono::high_resolution_clock::now();
                        cout << endl << "Time [ns]: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
                        for (int i = 0; i < size; i++) {
                            list.popEnd();
                        }
                        break;
                    }
                }
                break;
            }

            case 'm': {
                return;
            }

            default:
                break;
        }
    }
}

void heapMenu(){
    Heap heap;

    while (true){
        cout << endl << "\nChoose operation: \n" + operations;

        char input;
        cin >> input;
        cin.clear();

        switch (input) {
            case 'r': {
                FileOperator fileOperator;
                if(fileOperator.readFile()) {
                    for (int i = 0; i < fileOperator.getSize(); i++) {
                        if (!heap.contains(fileOperator.data[i])) {
                            heap.add(fileOperator.data[i]);
                        } else {
                            continue;
                        }
                    }
                }
                break;
            }

            case 'a': {
                cout << "Write value to add: \n";
                int input1;
                cin >> input1;
                cin.clear();
                heap.add(input1);
                break;
            }

            case 'd': {
                cout << "Write value to delete: \n";
                int input1;
                cin >> input1;
                cin.clear();
                heap.deleteIndex(input1);
                break;
            }

            case 's': {
                cout << "Choose value to check: \n";

                int input1;
                cin >> input1;
                cin.clear();

                if (heap.contains(input1)){
                    cout << "Heap contains this value." << endl;

                }else {
                    cout << "Heap doesn't contain this value." << endl;
                }

                break;
            }

            case 'p': {
                heap.print();
                break;
            }

            case 't':{
                cout << "Choose operation to check:\n" + timeOptions << endl;

                char input1;
                cin >> input1;
                cin.clear();

                switch (input1) {
                    case 'a':{
                        cout << "How much number to add?\n";

                        int size;
                        cin >> size;
                        cin.clear();

                        for (int i = 0; i < size; i++) {
                            heap.add(rand() % size);
                        }
                        auto start = chrono::high_resolution_clock::now();
                        heap.add(rand() % size);
                        auto end = chrono::high_resolution_clock::now();
                        cout << endl << "Time [ns]: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
                        for (int i = 0; i < heap.size; i++) {
                            heap.pop();
                        }
                        break;
                    }
                    case 'd': {
                        cout << "How many numbers to delete?\n";
                        int size;
                        cin >> size;
                        cin.clear();

                        for (int i = 0; i < size; i++) {
                            heap.add(rand() % size);
                        }
                        auto start = chrono::high_resolution_clock::now();
                        heap.pop();
                        auto end = chrono::high_resolution_clock::now();
                        cout << endl << "Time [ns]: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
                        for (int i = 0; i < heap.size; i++) {
                            heap.pop();
                        }
                        break;
                    }
                    case 's':{
                        cout << "Enter size of structure:\n";
                        int size;
                        cin >> size;
                        cin.clear();
                        int val = rand() % size;
                        for (int i = 0; i < size; i++) {
                            heap.add(rand() % size);
                        }
                        auto start = chrono::high_resolution_clock::now();
                        heap.contains(val);
                        auto end = chrono::high_resolution_clock::now();
                        cout << endl << "Time [ns]: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
                        for (int i = 0; i < heap.size; i++) {
                            heap.pop();
                        }
                        break;
                    }
                }
                break;
            }

            case 'm': {
                return;
            }

            default:
                break;
        }
    }
}

void RBTreeMenu(){
    RedBlackTree redBlackTree;


    while (true){
        cout << endl << "\nChoose operation: \n" + operations;

        char input;
        cin >> input;
        cin.clear();

        switch (input) {
            case 'r': {
                FileOperator fileOperator;
                if(fileOperator.readFile()) {
                    for (int i = 0; i < fileOperator.getSize(); i++) {
                        if (!redBlackTree.contains(fileOperator.data[i])) {
                            redBlackTree.add(fileOperator.data[i]);
                        }
                    }
                }
                break;
            }

            case 'a': {
                cout << "Write value to add: \n";
                int input1;
                cin >> input1;
                cin.clear();
                redBlackTree.add(input1);
                break;
            }

            case 'd': {
                cout << "Write value to delete: \n";
                int input1;
                cin >> input1;
                cin.clear();
                redBlackTree.deleteVal(input1);
                break;
            }

            case 's': {
                cout << "Choose value to check: \n";

                int input1;
                cin >> input1;
                cin.clear();

                if (redBlackTree.contains(input1)){
                    cout << "Heap contains this value." << endl;

                }else {
                    cout << "Heap doesn't contain this value." << endl;
                }

                break;
            }

            case 'p': {
                redBlackTree.print(redBlackTree.getRoot());
                break;
            }

            case 't':{
                cout << "Choose operation to check:\n" + timeOptions << endl;

                char input1;
                cin >> input1;
                cin.clear();

                switch (input1) {
                    case 'a':{
                        cout << "How much number to add?\n";
                        int size;
                        cin >> size;
                        cin.clear();
                        for (int i = 0; i < size; i++){
                            redBlackTree.add(rand() % size);
                        }
                        auto start = chrono::high_resolution_clock::now();
                        redBlackTree.add(rand() % size);
                        auto end = chrono::high_resolution_clock::now();
                        cout << endl << "Time [ns]: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
                        for (int i = 0; i < redBlackTree.size; i++){
                            redBlackTree.popRoot();
                        }
                        break;
                    }

                    case 'd':{
                        cout << "How many numbers to delete?\n";
                        int size;
                        cin >> size;
                        cin.clear();

                        for (int i = 0; i < size; i++){
                            redBlackTree.add(rand() % size);
                        }
                        auto start = chrono::high_resolution_clock::now();
                        redBlackTree.popRoot();
                        auto end = chrono::high_resolution_clock::now();
                        cout << endl << "Time [ns]: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
                        for (int i = 0; i < redBlackTree.size; i++){
                            redBlackTree.popRoot();
                        }
                        break;
                    }

                    case 's':{
                        cout << "Enter size of structure:\n";
                        int size;
                        cin >> size;
                        cin.clear();
                        int val = rand() % size;
                        for (int i = 0; i < size; i++) {
                            redBlackTree.add(rand() % size);
                        }
                        auto start = chrono::high_resolution_clock::now();
                        redBlackTree.contains(val);
                        auto end = chrono::high_resolution_clock::now();
                        cout << endl << "Time [ns]: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
                        for (int i = 0; i < redBlackTree.size; i++) {
                            redBlackTree.popRoot();
                        }
                        break;
                    }
                }
                break;
            }

            case 'm': {
                return;
            }

            default:
                break;
        }
    }
}

int main() {
    const string structures = "a - Array\nl - List\nb - Binary Heap\nr - Red Black Tree\ng - Generate numbers to file\nq - Quit\n";
    srand(time(nullptr));

    while(true){
        cout << endl << "Choose structure: \n" + structures;
        char input;
        cin >> input;
        cin.clear();
        switch (input) {
            case 'a':
                arrayMenu();
                break;

            case 'l':
                listMenu();
                break;

            case 'b':
                heapMenu();
                break;

            case 'r':
                RBTreeMenu();
                break;

            case 'g': {
                FileOperator fileOperator;
                fileOperator.generateNumbersToFile();
                break;
            }

            case 'q':
                return 1;
        }
    }
    return 0;
}
