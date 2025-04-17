#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "ManipulationLib.h"
#include "ArrayLib.h"

using namespace std;
using namespace nsArray;
using namespace nsManipulation;

void FillMatrixInOrder(int Arr[3][3])
{
	int Num = 0;

	for (int C = 0; C < 3; C++)
	{
		for (int i = 0; i < 3; i++)
		{
			Num++;

			Arr[C][i] = Num;
		}
	}
}

void PrintMatrix(int Arr[3][3], int Rows, int Cols)
{
	cout << "The following is a 3x3 matrix :\n";

	for (int C = 0; C < Rows; C++)
	{
		for (int i = 0; i < Cols; i++)
		{
			cout << left << setw(3) << Arr[C][i] << "\t";
		}
		cout << "\n";
	}
}

void TransposeMatrix(int Arr[3][3], int TransposedMatrix[3][3], int Rows, int Cols)
{
	for (int C = 0; C < Rows; C++)
	{
		for (int i = 0; i < Cols; i++)
		{
			TransposedMatrix[C][i] = Arr[i][C];
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Arr[3][3], TransposedMatrix[3][3];

	FillMatrixInOrder(Arr);

	PrintMatrix(Arr, 3, 3);

	UnderScore(50);

	cout << endl;

	TransposeMatrix(Arr ,TransposedMatrix , 3, 3);

	PrintMatrix(TransposedMatrix, 3, 3);
}