#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

int RandomNumInRange(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

void FillMatrixWithRandomNums(int Matrix[3][3], const short& Rows, const short& Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short C = 0; C < Cols; C++)
		{
			Matrix[i][C] = RandomNumInRange(1, 10);
		}
	}
}

void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short C = 0; C < Cols; C++)
		{
			printf("%02d\t", Matrix[i][C]);
		}
		printf("\n");
	}

	cout << endl;
}

bool IsNumInMatrix(int Matrix[3][3], short Rows, short Cols, int NumToCheck)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short C = 0; C < Cols; C++)
		{
			if (Matrix[i][C] == NumToCheck)
			{
				return true;
			}
		}
	}

	return false;
}

void PrintMatricesIntersectedNums(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short C = 0; C < Cols; C++)
		{
			if (IsNumInMatrix(Matrix2, Rows, Cols, Matrix1[i][C]))
			{
				cout << setw(3) << left << Matrix1[i][C] << "\t";
			}
		}
	}

	cout << endl;
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3];
	int Matrix2[3][3];

	FillMatrixWithRandomNums(Matrix1, 3, 3);
	cout << "Matrix :\n";
	PrintMatrix(Matrix1, 3, 3);


	FillMatrixWithRandomNums(Matrix2, 3, 3);
	cout << "Matrix :\n";
	PrintMatrix(Matrix2, 3, 3);


	cout << "\nIntersected numbers are :\n\n";
	PrintMatricesIntersectedNums(Matrix1, Matrix2, 3, 3);
}
