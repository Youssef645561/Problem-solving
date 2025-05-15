#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

void PrintFibonacciSeries(int Num)
{
	int Prev1 = 0;
	int Prev2 = 0;
	int FebNum = 1;

	for (int i = 1; i <= Num; i++)
	{
		cout << FebNum << "\n";

		Prev2 = Prev1;
		Prev1 = FebNum;
		FebNum = Prev1 + Prev2;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	PrintFibonacciSeries(10);
}
