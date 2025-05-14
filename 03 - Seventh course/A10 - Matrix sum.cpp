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

int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3];


	FillMatrixWithRandomNums(Matrix, 3, 3);
	cout << "Matrix :\n";
	PrintMatrix(Matrix, 3, 3);


	cout << "Sum of matrix = " << MatrixSum(Matrix, 3, 3) << endl;
}
