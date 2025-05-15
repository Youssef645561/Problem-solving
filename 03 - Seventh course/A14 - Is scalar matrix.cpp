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

bool CheckScalarMatrix(int Matrix[3][3], short Rows, short Cols)
{
	int DiagFirstNum = Matrix[0][0];

	for (short i = 0; i < Rows; i++)
	{
		for (short C = 0; C < Cols; C++)
		{
			if ((i == C && Matrix[i][C] != DiagFirstNum) || (i != C && Matrix[i][C] != 0))
			{
				return false;
			}
		}
	}

	return true;
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3];

	FillMatrixWithRandomNums(Matrix, 3, 3);
	cout << "Matrix :\n";
	PrintMatrix(Matrix, 3, 3);

/*
	int ScalarMatrix[3][3] =
	{
		{Num, 0, 0},
		{0, Num, 0},
		{0, 0, Num}
	};
*/

	if (CheckScalarMatrix(Matrix, 3, 3))
	{
		cout << "\nYes, matrix is scalar." << endl;
	}
	else
	{
		cout << "\nNo, matrix is not scalar." << endl;
	}
}
