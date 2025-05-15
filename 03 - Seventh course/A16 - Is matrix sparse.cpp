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

short CountNumInMatrix(int Matrix[3][3], short Rows, short Cols, int NumToCount)
{
	short Counter = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short C = 0; C < Cols; C++)
		{
			if (Matrix[i][C] == NumToCount)
			{
				Counter++;
			}
		}
	}

	return Counter;
}

bool IsMatrixSparse(int Matrix[3][3], short Rows, short Cols)
{
	return (CountNumInMatrix(Matrix, Rows, Cols, 0) > ((Rows * Cols) / 2));
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3];

	FillMatrixWithRandomNums(Matrix, 3, 3);
	cout << "Matrix :\n";
	PrintMatrix(Matrix, 3, 3);

	if (IsMatrixSparse(Matrix, 3, 3))
	{
		cout << "\nYes, matrix is sparse." << endl;
	}
	else
	{
		cout << "\nNo, matrix is not sparse." << endl;
	}
}
