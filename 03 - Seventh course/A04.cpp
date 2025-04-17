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

void PrintMatrix(int Arr[3][3], int Rows, int Cols)
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

int SumMatrixCol(int Matrix[3][3], int Col, int Rows)
{
	int Sum = 0;
	for (int i = 0; i < Rows; i++)
	{

		Sum += Matrix[i][Col];
	}
	return Sum;
}



void PrintMatrixColSum(int Matrix[3][3], int Rows, int Cols)
{
	cout << "\nThe following is the sum of each row in the matrix :\n";

	for (int C = 0; C < Cols; C++)
	{
		cout << "Col [" << C + 1 << "] Sum = " << SumMatrixCol(Arr, C, Rows) << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3];


	FillMatrixRandomly(Arr, 3, 3);

	PrintMatrix(Arr, 3, 3);

	PrintMatrixColSum(Arr, 3, 3);

}