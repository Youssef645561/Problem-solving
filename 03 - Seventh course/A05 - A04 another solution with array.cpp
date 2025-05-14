#include <iostream>
#include <iomanip>

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
			Matrix[i][C] = RandomNumInRange(1, 100);
		}
	}
}

void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short C = 0; C < Cols; C++)
		{
			cout << setw(3) << left << Matrix[i][C] << "\t";
		}
		cout << "\n";
	}

	cout << endl;
}

int SumMatrixCol(int Matrix[3][3], short Rows, short ColNum)
{
	int Sum = 0;

	for (short i = 0; i < Rows; i++)
	{
		Sum += Matrix[i][ColNum];
	}

	return Sum;
}

void SumMatrixColsInArr(int Matrix[3][3], short Rows, short Cols, int Arr[3])
{
	for (short i = 0; i < Cols; i++)
	{
		Arr[i] = SumMatrixCol(Matrix, Rows, i);
	}
}

void PrintColsSumFromArr(int Arr[3], short ArrLength)
{
	cout << "\nThe following are the sum of each col in the matrix :\n\n";

	for (short i = 0; i < ArrLength; i++)
	{
		cout << "Col " << i + 1 << " sum = " << Arr[i] << "\n";
	}

	cout << endl;
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3];
	int Arr[3];

	FillMatrixWithRandomNums(Matrix, 3, 3);

	cout << "The following is a 3x3 random matrix :\n";
	PrintMatrix(Matrix, 3, 3);

	SumMatrixColsInArr(Matrix, 3, 3, Arr);

	PrintColsSumFromArr(Arr, 3);
}
