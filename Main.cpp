#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include "Array.hpp"
#include "List.hpp"
#include "Heap.hpp"
#include "Stoper.hpp"
#include "RedBlackTree.hpp"

using namespace std;

const string operations = "r - read from file\na - add value\nd - delete value\nc - search if value exists\np - print container contents\nt - zmierz czas operacji\nm - go back to menu\n";
const string timeOptions = "a - adding value\nd - deleting value\ns - searching for value\np - printing structure";

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

    while (true) {
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

                if (array.contains(getUserInputNum())){
                    cout << "Array contains this value." << endl;

                }else {
                    cout << "Array doesn't contain this value." << endl;
                }

                break;

            case 'p': {

                array.print();

                break;
            }

            case 't':{
                Stoper stoper;
                cout << "Choose operation to check:\n" + timeOptions << endl;

                switch (getUserInputChar()) {
                    case 'a':{
                        cout << "How much number to add?\n";
                        int size = getUserInputNum();
                        cout << "Choose position:\nb - beginning\ne - end\n";
                        switch (getUserInputChar()) {
                            case 'b':{
                                stoper.startStoper();
                                for (int i = 0; i < size; i++){
                                    array.pushBeg(rand()%15);
                                }
                                stoper.stopStoper();
                                stoper.showResult();
                                break;
                            }
                            case 'e':{
                                stoper.startStoper();
                                for (int i = 0; i < size; i++){
                                    array.pushEnd(rand()%15);
                                }
                                stoper.stopStoper();
                                stoper.showResult();
                                break;
                            }
                        }
                    }
                    case 'd':{
                        cout << "How much number to delete?\n";
                        int size = getUserInputNum();
                        cout << "Choose position:\nb - beginning\ne - end\n";
                        switch (getUserInputChar()) {
                            case 'b':{
                                for (int i = 0; i < size; i++){
                                    array.pushBeg(rand()%15);
                                }
                                stoper.startStoper();
                                for (int i = 0; i < size; i++){
                                    array.popBeg();
                                }
                                stoper.stopStoper();
                                stoper.showResult();
                                break;
                            }
                            case 'e':{
                                for (int i = 0; i < size; i++){
                                    array.pushEnd(rand()%15);
                                }
                                stoper.startStoper();
                                for (int i = 0; i < size; i++){
                                    array.popEnd();
                                }
                                stoper.stopStoper();
                                stoper.showResult();
                                break;
                            }
                        }
                    }
                    case 's':{
                        cout << "Choose value to look for:\n";
                        int val = getUserInputNum();
                        stoper.startStoper();
                        array.contains(val);
                        stoper.stopStoper();
                        stoper.showResult();
                    }
                    case 'p':{
                        stoper.startStoper();
                        array.print();
                        stoper.stopStoper();
                        stoper.showResult();
                    }
                }
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
    const string options = "\nb - beginning\ne - end\nc - choose\n";

    while (true){
        cout << "Choose operation: \n" + operations;

        switch (getUserInputChar()) {
            case 'r': {
                auto vals = readFile();
                for (auto val: vals) {
                    list.pushBeg(val);
                }
                break;
            }
            case 'a': {
                cout << "Choose position: " + options;

                switch (getUserInputChar()) {
                    case 'b':{
                        cout << "Write value to add: \n";
                        list.pushBeg(getUserInputNum());
                        break;
                    }

                    case 'e':{
                        cout << "Write value to add: \n";
                        list.pushEnd(getUserInputNum());
                        break;
                    }

                    case 'c':{

                        cout << "Write value to add: \n";
                        const int val = getUserInputNum();

                        cout << "Write position: \n";
                        const int pos = getUserInputNum();

                        list.insert(val, pos);
                        break;
                    }
                }

                break;
            }

            case 'd': {
                cout << "Choose position: " + options;

                switch (getUserInputChar()) {
                    case 'b':{
                        list.popBeg();
                        break;
                    }

                    case 'e':{
                        list.popEnd();
                        break;
                    }

                    case 'c':{
                        cout << "Write value to delete: \n";
                        list.deleteVal(getUserInputNum());
                        break;
                    }
                }

                break;
            }

            case 'c':
                cout << "Choose value to check: \n";

                if (list.contains(getUserInputNum())){
                    cout << "List contains this value." << endl;

                }else {
                    cout << "List doesn't contain this value." << endl;
                }

                break;

            case 'p': {

                list.print();

                break;
            }

            case 't':{
                cout << "Choose operation to check:\n" + timeOptions << endl;
                Stoper stoper;

                switch (getUserInputChar()) {
                    case 'a':{
                        cout << "How much number to add?\n";
                        int size = getUserInputNum();
                        cout << "Choose position:\nb - beginning\ne - end\n";
                        switch (getUserInputChar()) {
                            case 'b':{
                                stoper.startStoper();
                                for (int i = 0; i < size; i++){
                                    list.pushBeg(rand()%15);
                                }
                                stoper.stopStoper();
                                stoper.showResult();
                                break;
                            }
                            case 'e':{
                                stoper.startStoper();
                                for (int i = 0; i < size; i++){
                                    list.pushEnd(rand()%15);
                                }
                                stoper.stopStoper();
                                stoper.showResult();
                                break;
                            }
                        }
                    }
                    case 'd':{
                        cout << "How much number to delete?\n";
                        int size = getUserInputNum();
                        cout << "Choose position:\nb - beginning\ne - end\n";
                        switch (getUserInputChar()) {
                            case 'b':{
                                for (int i = 0; i < size; i++){
                                    list.pushBeg(rand()%15);
                                }
                                stoper.startStoper();
                                for (int i = 0; i < size; i++){
                                    list.popBeg();
                                }
                                stoper.stopStoper();
                                stoper.showResult();
                                break;
                            }
                            case 'e':{
                                for (int i = 0; i < size; i++){
                                    list.pushEnd(rand()%15);
                                }
                                stoper.startStoper();
                                for (int i = 0; i < size; i++){
                                    list.popEnd();
                                }
                                stoper.stopStoper();
                                stoper.showResult();
                                break;
                            }
                        }
                    }
                    case 's':{
                        cout << "Choose value to look for:\n";
                        int val = getUserInputNum();
                        stoper.startStoper();
                        list.contains(val);
                        stoper.stopStoper();
                        stoper.showResult();
                    }
                    case 'p':{
                        stoper.startStoper();
                        list.print();
                        stoper.stopStoper();
                        stoper.showResult();
                    }
                }
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
        cout << "\nChoose operation: \n" + operations;

        switch (getUserInputChar()) {
            case 'r': {
                auto vals = readFile();
                for (auto val: vals) {
                    heap.add(val);
                }
                break;
            }

            case 'a': {
                cout << "Write value to add: \n";
                heap.add(getUserInputNum());
                break;
            }

            case 'd': {
                cout << "Write value to delete: \n";
                heap.deleteVal(getUserInputNum());
                break;
            }

            case 'c': {
                cout << "Choose value to check: \n";

                if (heap.contains(getUserInputNum())){
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
                Stoper stoper;
                cout << "Choose operation to check:\n" + timeOptions << endl;

                switch (getUserInputChar()) {
                    case 'a':{
                        cout << "How much number to add?\n";
                        int size = getUserInputNum();
                        stoper.startStoper();
                        for (int i = 0; i < size; i++){
                            heap.add(rand()%15);
                        }
                        stoper.stopStoper();
                        stoper.showResult();
                        break;
                    }
                    case 'd':{
                        cout << "How many numbers to delete?\n";
                        int size = getUserInputNum();

                        for (int i = 0; i < size; i++){
                            heap.add(rand()%15);
                        }
                        stoper.startStoper();
                        for (int i = 0; i < size; i++){
                            heap.pop();
                        }
                        stoper.stopStoper();
                        stoper.showResult();
                        break;
                    }
                    case 's':{
                        cout << "Choose value to look for:\n";
                        int val = getUserInputNum();
                        stoper.startStoper();
                        heap.contains(val);
                        stoper.stopStoper();
                        stoper.showResult();
                    }
                    case 'p':{
                        stoper.startStoper();
                        heap.print();
                        stoper.stopStoper();
                        stoper.showResult();
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
        cout << "\nChoose operation: \n" + operations;

        switch (getUserInputChar()) {
            case 'r': {
                auto vals = readFile();
                for (auto val: vals) {
                    redBlackTree.add(val);
                }
                break;
            }

            case 'a': {
                cout << "Write value to add: \n";
                redBlackTree.add(getUserInputNum());
                break;
            }

            case 'd': {
                cout << "Write value to delete: \n";
                redBlackTree.deleteVal(getUserInputNum());
                break;
            }

            case 'c': {
                cout << "Choose value to check: \n";

                if (redBlackTree.contains(getUserInputNum())){
                    cout << "Heap contains this value." << endl;

                }else {
                    cout << "Heap doesn't contain this value." << endl;
                }

                break;
            }

            case 'p': {
                redBlackTree.print();
                break;
            }

            case 't':{
                Stoper stoper;
                cout << "Choose operation to check:\n" + timeOptions << endl;

                switch (getUserInputChar()) {
                    case 'a':{
                        cout << "How much number to add?\n";
                        int size = getUserInputNum();
                        stoper.startStoper();
                        for (int i = 0; i < size; i++){
                            redBlackTree.add(rand()%15);
                        }
                        stoper.stopStoper();
                        stoper.showResult();
                        break;
                    }
                    case 'd':{
                        cout << "How many numbers to delete?\n";
                        int size = getUserInputNum();

                        for (int i = 0; i < size; i++){
                            redBlackTree.add(rand()%15);
                        }
//                        stoper.startStoper();
//                        for (int i = 0; i < size; i++){
//                            redBlackTree.pop();
//                        }
//                        stoper.stopStoper();
//                        stoper.showResult();
                        break;
                    }
                    case 's':{
                        cout << "Choose value to look for:\n";
                        int val = getUserInputNum();
                        stoper.startStoper();
                        redBlackTree.contains(val);
                        stoper.stopStoper();
                        stoper.showResult();
                    }
                    case 'p':{
                        stoper.startStoper();
                        redBlackTree.print();
                        stoper.stopStoper();
                        stoper.showResult();
                    }
                }
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
    const string structures = "a - Array\nl - List\nb - Binary Heap\nr - Red Black Tree\nq - Quit\n";
    srand(time(nullptr));

    while(true){
        cout << "Choose structure: \n" + structures;
        switch (getUserInputChar()) {
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

            case 'q':
                return 1;
        }
    }
    return 0;
}
