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

int MinNumInMatrix(int Matrix[3][3], int Rows, int Cols)
{
	int Min = Matrix[0][0];

	for (int j = 0; j < Rows; j++)
	{
		for (int i = 0; i < Cols; i++)
		{
			if (Min > Matrix[j][i])
			{
				Min = Matrix[j][i];
			}
		}
	}
	return Min;
}

int MaxNumInMatrix(int Matrix[3][3], int Rows, int Cols)
{
	int Max = Matrix[0][0];

	for (int j = 0; j < Rows; j++)
	{
		for (int i = 0; i < Cols; i++)
		{
			if (Max < Matrix[j][i])
			{
				Max = Matrix[j][i];
			}
		}
	}
	return Max;
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3] = { {77,5,12} , {22,20,6} , {14,3,9} };

	cout << "Matrix :\n";
	PrintMatrix(Matrix, 3, 3);

	UnderScore(20);

	cout << "\nMinimum number in the matrix = " << MinNumInMatrix(Matrix,3,3) << endl;
	cout << "Maximum number in the matrix = " << MaxNumInMatrix(Matrix,3,3) << endl;
}