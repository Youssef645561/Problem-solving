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

void PrintMatrixRow(int Matrix[3][3], int Row, int Cols)
{
	Row -= 1;

	for (int C = 0; C < Cols; C++)
	{
		printf("%02d\t", Matrix[Row][C]);
	}
}

void PrintMatrixCol(int Matrix[3][3], int Rows, int Col)
{
	Col -= 1;

	for (int C = 0; C < Rows; C++)
	{
		printf("%02d\t", Matrix[C][Col]);
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3];

	FillMatrixRandomly(Matrix, 3, 3);

	cout << "Matrix :\n\n";
	PrintMatrix(Matrix, 3, 3);

	UnderScore(20);

	cout << "\nMatrix middle row :\n\n";
	PrintMatrixRow(Matrix, 2, 3);

	cout << endl;

	UnderScore(20);

	cout << "\nMatrix middle Col :\n\n";
	PrintMatrixCol(Matrix, 3, 2);
}