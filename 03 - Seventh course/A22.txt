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


void PrintFibonacciSeriesUntill(int Untill, int Prev1 = 0, int Prev2 = 1)
{

	int Num = 0;

	if (Untill != 0)
	{
		Num = Prev1 + Prev2;
		Prev2 = Prev1;
		Prev1 = Num;

		cout << Num << "\t";

		PrintFibonacciSeriesUntill(Untill - 1, Prev1, Prev2);
	}
}


int main()
{
	srand((unsigned)time(NULL));

	PrintFibonacciSeriesUntill(10);
}