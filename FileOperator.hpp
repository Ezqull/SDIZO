#include <string>
#include <fstream>


using namespace std;

class FileOperator {

private:
    fstream file;
    string fileName;
    int size;

public:
    int* data;
    FileOperator();
    ~FileOperator();
    void readFile();
    void generateNumbersToFile();
    int getSize();
};
