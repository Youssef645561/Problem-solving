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

int GetMinNumInMatrix(int Matrix[3][3], short Rows, short Cols)
{
	int MinNum = Matrix[0][0];

	for (short i = 0; i < Rows; i++)
	{
		for (short C = 0; C < Cols; C++)
		{
			if (MinNum > Matrix[i][C])
			{
				MinNum = Matrix[i][C];
			}
		}
	}

	return MinNum;
}

int GetMaxNumInMatrix(int Matrix[3][3], short Rows, short Cols)
{
	int MaxNum = Matrix[0][0];

	for (short i = 0; i < Rows; i++)
	{
		for (short C = 0; C < Cols; C++)
		{
			if (MaxNum < Matrix[i][C])
			{
				MaxNum = Matrix[i][C];
			}
		}
	}

	return MaxNum;
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3];
	int Matrix2[3][3];

	FillMatrixWithRandomNums(Matrix, 3, 3);
	cout << "Matrix :\n";
	PrintMatrix(Matrix, 3, 3);

	cout << "\nMinimum number in the matrix is : " << GetMinNumInMatrix(Matrix, 3, 3) << endl;

	cout << "\n\nMaximum number in the matrix is : " << GetMaxNumInMatrix(Matrix, 3, 3) << endl;
}
