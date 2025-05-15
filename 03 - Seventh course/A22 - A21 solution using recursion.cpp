#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

void PrintFibonacciSeries(short Num, int Prev1 = 0, int Prev2 = 0, int FebNum = 1)
{
	cout << FebNum << "\n";

	Prev2 = Prev1;
	Prev1 = FebNum;
	FebNum = Prev1 + Prev2;

	if (Num > 1)
		PrintFibonacciSeries(Num - 1, Prev1, Prev2, FebNum);
}

int main()
{
	srand((unsigned)time(NULL));

	PrintFibonacciSeries(10);
}
