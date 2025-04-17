#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "ManipulationLib.h"
#include "ArrayLib.h"

using namespace std;
using namespace nsArray;
using namespace nsManipulation;

void FillMatrixRandomly(int Matrix[3][3], int Rows, int Cols)
{
	for (int C = 0; C < Rows; C++)
	{
		for (int i = 0; i < Cols; i++)
		{
			Matrix[C][i] = RandomNumInRange(1, 10);
		}
	}
}

void PrintMatrix(int Matrix[3][3], int Rows, int Cols)
{
	for (int C = 0; C < Rows; C++)
	{
		for (int i = 0; i < Cols; i++)
		{
			printf("%02d\t", Matrix[C][i]);
		}
		cout << "\n";
	}
}

int SumMatrixElements(int Matrix[3][3], int Rows, int Cols)
{
	int Sum = 0;

	for (int C = 0; C < Rows; C++)
	{
		for (int i = 0; i < Cols; i++)
		{
			Sum += Matrix[C][i];
		}
	}
	return Sum;
}

bool CheckMatricesEquality(int Matrix1[3][3], int Matrix2[3][3], int Rows, int Cols)
{
	return (SumMatrixElements(Matrix1, Rows, Cols) == SumMatrixElements(Matrix2, Rows, Cols));
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3],Matrix2[3][3];

	FillMatrixRandomly(Matrix1, 3, 3);
	cout << "Matrix 1 :\n\n";
	PrintMatrix(Matrix1, 3, 3);

	UnderScore(20);

	FillMatrixRandomly(Matrix2, 3, 3);
	cout << "\nMatrix 2 :\n\n";
	PrintMatrix(Matrix2, 3, 3);

	if (CheckMatricesEquality(Matrix1, Matrix2, 3, 3))
	{
		cout << "\n\nYes,matricses are equal.\n";
	}
	else
	{
		cout << "\n\nNo,matricses are not equal.\n";
	}
}