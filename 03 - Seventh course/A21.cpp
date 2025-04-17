#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "ManipulationLib.h"
#include "ArrayLib.h"
#include "MatrixLib.h"

using namespace std;
using namespace nsArray;
using namespace nsMatrix;
using namespace nsManipulation;


void PrintFibonacciSeriesUntill(int Untill)
{
	int Prev1 = 0;
	int Prev2 = 1;
	int Num;

	for (int C = 0; C < Untill; C++)
	{
		Num = Prev1 + Prev2;

		cout << Num << "\t";

		Prev2 = Prev1;
		Prev1 = Num;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	PrintFibonacciSeriesUntill(10);
}