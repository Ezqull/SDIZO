#include <iostream>
#include <ctime>
#include "Array.hpp"
#include "List.hpp"
#include "Heap.hpp"
#include "Stoper.hpp"
#include "RedBlackTree.hpp"
#include "FileOperator.hpp"

using namespace std;

const string operations = "r - read from file\na - add value\nd - delete value\ns - search if value exists\np - print container contents\nt - zmierz czas operacji\nm - go back to menu\n";
const string timeOptions = "a - adding value\nd - deleting value\ns - searching for value\n";

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
                FileOperator fileOperator;
                fileOperator.readFile();
                for(int i = 0; i < fileOperator.getSize(); i ++){
                    array.pushBeg(fileOperator.data[i]);
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
                        cout << "Enter index: \n";
                        array.deleteIndex(getUserInputNum() - 1);
                        break;
                    }
                }

                break;
            }

            case 's':
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
                        cout << "Enter size of structure:\n";
                        int size = getUserInputNum();
                        cout << "Choose position:\nb - beginning\ne - end\n";
                        switch (getUserInputChar()) {
                            case 'b': {
                                for (int i = 0; i < size; i++) {
                                    array.pushBeg(rand() % size);
                                }
                                stoper.startStoper();
                                array.pushBeg(rand() % size);
                                stoper.stopStoper();
                                stoper.showResult();
                                for (int i = 0; i < size + 1; i++) {
                                    array.popBeg();
                                }
                                break;
                            }
                            case 'e': {
                                for (int i = 0; i < size; i++) {
                                    array.pushEnd(rand() % size);
                                }
                                stoper.startStoper();
                                array.pushEnd(rand() % size);
                                stoper.stopStoper();
                                stoper.showResult();
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
                        int size = getUserInputNum();
                        cout << "Choose position:\nb - beginning\ne - end\nc - choose position\n";
                        switch (getUserInputChar()) {
                            case 'b': {
                                for (int i = 0; i < size; i++) {
                                    array.pushBeg(rand() % size);
                                }
                                stoper.startStoper();
                                array.popBeg();
                                stoper.stopStoper();
                                stoper.showResult();
                                for (int i = 0; i < size - 1; i++) {
                                    array.popEnd();
                                }
                                break;
                            }
                            case 'e': {
                                for (int i = 0; i < size; i++) {
                                    array.pushEnd(rand() % size);
                                }
                                stoper.startStoper();
                                array.popEnd();
                                stoper.stopStoper();
                                stoper.showResult();
                                for (int i = 0; i < size - 1; i++) {
                                    array.popEnd();
                                }
                                break;
                            }
                            case 'c': {
                                for (int i = 0; i < size; i++) {
                                    array.pushBeg(rand() % size);
                                }
                                cout << "Choose index: " << endl;
                                int index = getUserInputNum();
                                stoper.startStoper();
                                array.deleteIndex(index - 1);
                                stoper.stopStoper();
                                stoper.showResult();
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
                        int size = getUserInputNum();
                        cout << "Choose value to look for:\n";
                        int val = getUserInputNum();
                        for (int i = 0; i < size; i++) {
                            array.pushBeg(rand() % size);
                        }
                        stoper.startStoper();
                        array.contains(val);
                        stoper.stopStoper();
                        stoper.showResult();
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
    const string options = "\nb - beginning\ne - end\nc - choose\n";

    while (true){
        cout << "Choose operation: \n" + operations;

        switch (getUserInputChar()) {
            case 'r': {
                FileOperator fileOperator;
                fileOperator.readFile();
                for(int i = 0; i < fileOperator.getSize(); i ++){
                    list.pushBeg(fileOperator.data[i]);
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
                        cout << "Enter index: \n";
                        list.deleteIndex(getUserInputNum() - 1);
                        break;
                    }
                }
                break;
            }

            case 's': {
                cout << "Choose value to check: \n";

                if (list.contains(getUserInputNum())) {
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
                Stoper stoper;

                switch (getUserInputChar()) {
                    case 'a':{
                        cout << "How much number to add?\n";
                        int size = getUserInputNum();
                        cout << "Choose position:\nb - beginning\ne - end\n";
                        switch (getUserInputChar()) {
                            case 'b':{
                                for (int i = 0; i < size; i++){
                                    list.pushBeg(rand() % size);
                                }
                                stoper.startStoper();
                                list.pushBeg(rand() % size);
                                stoper.stopStoper();
                                stoper.showResult();
                                for (int i = 0; i < size + 1; i++) {
                                    list.popBeg();
                                }
                                break;
                            }
                            case 'e':{
                                for (int i = 0; i < size; i++){
                                    list.pushEnd(rand() % size);
                                }
                                stoper.startStoper();
                                list.pushEnd(rand()%size);
                                stoper.stopStoper();
                                stoper.showResult();
                                for (int i = 0; i < size + 1; i++) {
                                    list.popEnd();
                                }
                                break;
                            }
                        }
                        break;
                    }
                    case 'd':{
                        cout << "How much number to delete?\n";
                        int size = getUserInputNum();
                        cout << "Choose position:\nb - beginning\ne - end\n";
                        switch (getUserInputChar()) {
                            case 'b': {
                                for (int i = 0; i < size; i++) {
                                    list.pushBeg(rand() % size);
                                }
                                stoper.startStoper();
                                list.popBeg();
                                stoper.stopStoper();
                                stoper.showResult();
                                for (int i = 0; i < size - 1; i++) {
                                    list.popBeg();
                                }
                                break;
                            }
                            case 'e': {
                                for (int i = 0; i < size; i++) {
                                    list.pushEnd(rand() % size);
                                }
                                stoper.startStoper();
                                list.popEnd();
                                stoper.stopStoper();
                                stoper.showResult();
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
                        int size = getUserInputNum();
                        cout << "Choose value to look for:\n";
                        int val = getUserInputNum();
                        for (int i = 0; i < size; i++) {
                            list.pushBeg(rand() % size);
                        }
                        stoper.startStoper();
                        list.contains(val);
                        stoper.stopStoper();
                        stoper.showResult();
                        for (int i = 0; i < size; i++) {
                            list.popEnd();
                        }
                        break;
                    }
                    break;
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
        cout << "\nChoose operation: \n" + operations;

        switch (getUserInputChar()) {
            case 'r': {
                FileOperator fileOperator;
                fileOperator.readFile();
                for(int i = 0; i < fileOperator.getSize(); i ++){
                    if(!heap.contains(fileOperator.data[i])){
                        heap.add(fileOperator.data[i]);
                    }else {
                        continue;
                    }
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

            case 's': {
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

                        for (int i = 0; i < size; i++) {
                            heap.add(rand() % size);
                        }
                        stoper.startStoper();
                        heap.add(rand() % size);
                        stoper.stopStoper();
                        stoper.showResult();
                        for (int i = 0; i < size + 1; i++) {
                            heap.pop();
                        }
                        break;
                    }
                    case 'd': {
                        cout << "How many numbers to delete?\n";
                        int size = getUserInputNum();

                        for (int i = 0; i < size; i++) {
                            heap.add(rand() % size);
                        }
                        stoper.startStoper();
                        heap.pop();
                        stoper.stopStoper();
                        stoper.showResult();
                        for (int i = 0; i < size - 1; i++) {
                            heap.pop();
                        }
                        break;
                    }
                    case 's':{
                        cout << "Enter size of structure:\n";
                        int size = getUserInputNum();
                        cout << "Choose value to look for:\n";
                        int val = getUserInputNum();
                        for (int i = 0; i < size; i++) {
                            heap.add(rand() % size);
                        }
                        stoper.startStoper();
                        heap.contains(val);
                        stoper.stopStoper();
                        stoper.showResult();
                        for (int i = 0; i < size; i++) {
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
        cout << "\nChoose operation: \n" + operations;

        switch (getUserInputChar()) {
            case 'r': {
                FileOperator fileOperator;
                fileOperator.readFile();
                for(int i = 0; i < fileOperator.getSize(); i ++){
                    if(!redBlackTree.contains(fileOperator.data[i])){
                        redBlackTree.add(fileOperator.data[i]);
                    }
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

            case 's': {
                cout << "Choose value to check: \n";

                if (redBlackTree.contains(getUserInputNum())){
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
                Stoper stoper;
                cout << "Choose operation to check:\n" + timeOptions << endl;

                switch (getUserInputChar()) {
                    case 'a':{
                        cout << "How much number to add?\n";
                        int size = getUserInputNum();
                        for (int i = 0; i < size; i++){
                            redBlackTree.add(rand() % size);
                        }
                        stoper.startStoper();
                        redBlackTree.add(rand() % size);
                        stoper.stopStoper();
                        stoper.showResult();
                        for (int i = 0; i < size + 1; i++){
                            redBlackTree.popRoot();
                        }
                        break;
                    }

                    case 'd':{
                        cout << "How many numbers to delete?\n";
                        int size = getUserInputNum();

                        for (int i = 0; i < size; i++){
                            redBlackTree.add(rand() % size);
                        }
                        stoper.startStoper();
                        redBlackTree.popRoot();
                        stoper.stopStoper();
                        stoper.showResult();
                        for (int i = 0; i < size - 1; i++){
                            redBlackTree.popRoot();
                        }
                        break;
                    }

                    case 's':{
                        cout << "Enter size of structure:\n";
                        int size = getUserInputNum();
                        cout << "Choose value to look for:\n";
                        int val = getUserInputNum();
                        for (int i = 0; i < size; i++) {
                            redBlackTree.add(rand() % size);
                        }
                        stoper.startStoper();
                        redBlackTree.contains(val);
                        stoper.stopStoper();
                        stoper.showResult();
                        for (int i = 0; i < size; i++) {
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
    const string structures = "a - Array\nl - List\nb - Binary Heap\nr - Red Black Tree\ng - generate numbers to file\nq - Quit\n";
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
