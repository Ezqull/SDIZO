#pragma once

class Stoper
{
public:
	long long int readQPC();
	long long int startStoper();
	long long int stopStoper();
	void showResult();

private:
	long long int frequency, start, elapsed;
};



