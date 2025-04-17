#include <iostream>
#include <iomanip>
#include "ArrayLib.h"

using namespace std;
using namespace nsArray;

void FillMatrixRandomly(int Matrix[3][3], int Rows, int Cols)
{
	for (int C = 0; C < Rows; C++)
	{
		for (int i = 0; i < Cols; i++)
		{
			Matrix[C][i] = RandomNumInRange(1, 100);
		}
	}
}

void PrintMatrix(int Matrix[3][3], int Rows, int Cols)
{
	cout << "The following is a random matrix :\n";

	for (int C = 0; C < Rows; C++)
	{
		for (int i = 0; i < Cols; i++)
		{
			cout << left << setw(3) << Matrix[C][i] << "\t";
		}
		cout << "\n";
	}
}

int* SumMatrixRows(int Matrix[3][3], int Rows, int Cols)
{
	int* SumMatrix;


	SumMatrix = new int[Rows];


	for (int C = 0; C < Rows; C++)
	{
		int Sum = 0;

		for (int i = 0; i < Cols; i++)
		{
			Sum += Matrix[C][i];
		}
		SumMatrix[C] = Sum;
	}

	return SumMatrix;
}

void PrintDynamicArr(int* SumMatrix, int ArrLength)
{
	cout << "\nThe following is the sum of each row in the matrix :\n";

	for (int C = 0; C < ArrLength; C++)
	{
		cout << "Row [" << C + 1 << "] Sum = " << SumMatrix[C] << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3];


	FillMatrixRandomly(Arr, 3, 3);

	PrintMatrix(Arr, 3, 3);

	int* SumMatrix = SumMatrixRows(Arr, 3, 3);

	PrintDynamicArr(SumArr, 3);

	delete[] SumMatrix;
}