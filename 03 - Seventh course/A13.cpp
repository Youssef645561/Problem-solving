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

bool CheckMatricesIdentity(int Matrix[3][3], int Rows, int Cols)
{
	for (int j = 0; j < Rows; j++)
	{
		for (int i = 0; i < Cols; i++)
		{
			if (j == i && Matrix[j][i] != 1)
			{
				return 0;
			}
			else if (j != i && Matrix[j][i] != 0)
			{
				return 0;
			}
		}
	}
	return 1;
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3];

	FillMatrixRandomly(Matrix, 3, 3);
	cout << "Matrix 1 :\n\n";
	PrintMatrix(Matrix, 3, 3);

	UnderScore(20);

	if (CheckMatricesIdentity(Matrix, 3, 3))
	{
		cout << "\n\nYes,matricses is identity.\n";
	}
	else
	{
		cout << "\n\nNo,matricses is not identity.\n";
	}
}