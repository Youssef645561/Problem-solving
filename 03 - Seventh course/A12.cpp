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

bool CheckMatricesConformity(int Matrix1[3][3], int Matrix2[3][3], int Rows, int Cols)
{
	for (int C = 0; C < Rows; C++)
	{
		for (int i = 0; i < Cols; i++)
		{
			if (Matrix1[C][i] != Matrix2[C][i])
			{
				return false;
			}
		}
	}
	return true;
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

	if (CheckMatricesConformity(Matrix1, Matrix2, 3, 3))
	{
		cout << "\n\nYes,matricses are conformable.\n";
	}
	else
	{
		cout << "\n\nNo,matricses are not conformable.\n";
	}
}