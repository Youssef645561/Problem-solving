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

void PrintMatrix(int Arr[3][3], int Rows, int Cols)
{
	for (int C = 0; C < Rows; C++)
	{
		for (int i = 0; i < Cols; i++)
		{
			printf("%02d\t", Arr[C][i]);
		}
		cout << "\n";
	}
}

void Multiply2Matrices(int Matrix1[3][3], int Matrix2[3][3], int Results[3][3])
{
	for (int C = 0; C < 3; C++)
	{
		for (int i = 0; i < 3; i++)
		{
			Results[C][i] = Matrix1[C][i] * Matrix2[C][i];
		}
	}
}
int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3], Matrix2[3][3], Results[3][3];

	FillMatrixRandomly(Matrix1, 3, 3);
	FillMatrixRandomly(Matrix2, 3, 3);

	Multiply2Matrices(Matrix1, Matrix2, Results);

	cout << "Matrix1 :\n\n";
	PrintMatrix(Matrix1, 3, 3);

	UnderScore(33);

	cout << "\nMatrix2 :\n\n";
	PrintMatrix(Matrix2, 3, 3);

	UnderScore(33);

	cout << "\nResults :\n\n";
	PrintMatrix(Results, 3, 3);

}