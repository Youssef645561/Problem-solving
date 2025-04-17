#include <iostream>
#include <iomanip>
#include "ArrayLib.h"

using namespace std;
using namespace nsArray;

void FillMatrixRandomly(int Arr[3][3], int Rows, int Cols)
{		for (int C = 0; C < Rows; C++)
	{
		for (int i = 0; i < Cols; i++)
		{
			Arr[C][i] = RandomNumInRange(1, 100);
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

int SumMatrixRow(int Matrix[3][3], int Row, int Cols)
{
	int Sum = 0;
		for (int i = 0; i < Cols; i++)
		{
			
			Sum += Matrix[Row][i];
		}
		return Sum;
}



void PrintMatrixRowSum(int Matrix[3][3], int Rows, int Cols)
{
	cout << "\nThe following is the sum of each row in the matrix :\n";

	for (int C = 0; C < Rows; C++)
	{
		cout << "Row [" << C + 1 << "] Sum = " << SumMatrixRow(Matrix,C,Cols) << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3];

	FillMatrixRandomly(Matrix, 3, 3);

	PrintMatrix(Matrix, 3, 3);

	PrintMatrixRowSum(Matrix, 3, 3);
}