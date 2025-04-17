#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "ManipulationLib.h"
#include "ArrayLib.h"

using namespace std;
using namespace nsArray;
using namespace nsManipulation;

bool CheckNumExistanceInMatrix(int Matrix[3][3], int Rows, int Cols, int Num)
{
	for (int j = 0; j < Rows; j++)
	{
		for (int i = 0; i < Cols; i++)
		{
			if (Matrix[j][i] == Num)
			{
				return true;
				break;
			}
		}
	}
	return false;
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

void PrintIntersectedNums(int Matrix1[3][3], int Matrix2[3][3], int Rows, int Cols)
{
	cout << "Intersected numbers are :\n\n";

	for (int j = 0; j < Rows; j++)
	{
		for (int i = 0; i < Cols; i++)
		{
			if (CheckNumExistanceInMatrix(Matrix2,Rows,Cols,Matrix1[j][i]))
			{
				cout << setw(3) << Matrix1[j][i] << "\t";
			}
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3] = { {77,5,12} , {22,20,1} , {1,0,9} };
	int Matrix2[3][3] = { {5,80,90} , {22,77,1} , {10,8,33} };

	cout << "Matrix 1 :\n\n";
	PrintMatrix(Matrix1, 3, 3);

	UnderScore(20);

	cout << "\nMatrix 2 :\n\n";
	PrintMatrix(Matrix2, 3, 3);

	UnderScore(20);

	PrintIntersectedNums(Matrix1, Matrix2, 3, 3);
}