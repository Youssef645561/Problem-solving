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

void PrintMiddleMatrixRow(int Matrix[3][3], short Rows, short Cols)
{
	short MiddleRow = Rows / 2;

	for (short i = 0; i < Cols; i++)
	{
		printf("%02d\t", Matrix[MiddleRow][i]);
	}

	cout << endl;
}

void PrintMiddleMatrixCol(int Matrix[3][3], short Rows, short Cols)
{
	short MiddleCol = Rows / 2;

	for (short i = 0; i < Rows; i++)
	{
		printf("%02d\t", Matrix[i][MiddleCol]);
	}

	cout << endl;
}



int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3];


	FillMatrixWithRandomNums(Matrix, 3, 3);
	cout << "Matrix :\n";
	PrintMatrix(Matrix, 3, 3);


	cout << "Middle row of the matrix :\n";
	PrintMiddleMatrixRow(Matrix, 3, 3);

	cout << "\nMiddle col of the matrix :\n";
	PrintMiddleMatrixCol(Matrix, 3, 3);

}
