//
// Created by Michal on 20.04.2022.
//

#ifndef PROJEKTSDIZO_FILE_OPERATOR_H
#define PROJEKTSDIZO_FILE_OPERATOR_H


#pragma once
#include <string>
#include <fstream>


using namespace std;

class File_Operator {

private:
    fstream plik;
    string file_name;

public:
    File_Operator();
    ~File_Operator();
    int* read_file();
    void generate_numbers_to_file();
    void set_file_name();
    int read_quantity_of_numbers();
};

#endif //PROJEKTSDIZO_FILE_OPERATOR_H
