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

int MatrixSum(int Matrix[3][3], short Rows, short Cols)
{
	int Sum = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short C = 0; C < Cols; C++)
		{
			Sum += Matrix[i][C];
		}
	}

	return Sum;
}

bool CheckMatricesEquality(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
	return MatrixSum(Matrix1, Rows, Cols) == MatrixSum(Matrix2, Rows, Cols);
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3];
	int Matrix2[3][3];


	FillMatrixWithRandomNums(Matrix1, 3, 3);
	cout << "Matrix 1 :\n";
	PrintMatrix(Matrix1, 3, 3);

	FillMatrixWithRandomNums(Matrix2, 3, 3);
	cout << "Matrix 2 :\n";
	PrintMatrix(Matrix2, 3, 3);



	if (CheckMatricesEquality(Matrix1, Matrix2, 3, 3))
	{
		cout << "\nYes, matrices are equal." << endl;
	}
	else
	{
		cout << "\nNo, matrices are not equal." << endl;
	}
}
