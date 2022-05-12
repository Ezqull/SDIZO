#pragma once

class Stoper{
public:
	static long long int readQPC();
	long long int startStoper();
	long long int stopStoper();
	void showResult();
    void averageTime();

private:
	long long int frequency, start, elapsed;
    float time;
};



