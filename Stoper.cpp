#include "Stoper.hpp"
#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

long long int Stoper::readQPC() {
    LARGE_INTEGER count;
    DWORD_PTR oldMask = SetThreadAffinityMask(GetCurrentThread(), 0);
    QueryPerformanceCounter(&count);
    SetThreadAffinityMask(GetCurrentThread(), oldMask);
    return((long long int)count.QuadPart);
}

long long int Stoper::startStoper() {
    QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);
    start = readQPC();
    return start;
}

long long int Stoper::stopStoper() {
    elapsed = readQPC() - start;
    return elapsed;
}

void Stoper::showResult() const {
    cout << "\nTime [s] = " << fixed << setprecision(3) << (float)elapsed / frequency << endl;
    cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) / frequency << endl;
    cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) / frequency << "\n\n";
}