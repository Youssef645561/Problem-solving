#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "ManipulationLib.h"
#include "ArrayLib.h"

using namespace std;
using namespace nsArray;
using namespace nsManipulation;

void FillMatrixRandomly(int Matrix[3][3], int Rows, int Cols)
{
	for (int C = 0; C < Rows; C++)
	{
		for (int i = 0; i < Cols; i++)
		{
			Matrix[C][i] = RandomNumInRange(1, 10);
		}
	}
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

int SumMatrixElements(int Matrix[3][3], int Rows, int Cols)
{
	int Sum = 0;

	for (int C = 0; C < Rows; C++)
	{
		for (int i = 0; i < Cols; i++)
		{
			Sum += Matrix[C][i];
		}
	}
	return Sum;
}

short NumFrequencyInMatrix(int Matrix[3][3], int Rows, int Cols, int Num)
{
	short C = 0;

	for (int j = 0; j < Rows; j++)
	{
		for (int i = 0; i < Cols; i++)
		{
			if (Matrix[j][i] == Num)
				C++;
		}
	}
	return C;
}

int ReadNumFromUser()
{
	int Num;

	cout << "\n\nEnter a number to count in matrix : ";
	cin >> Num;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "\nInvalid number, Enter a correct number : ";
		cin >> Num;
	}

	return Num;
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3];

	FillMatrixRandomly(Matrix, 3, 3);
	cout << "Matrix 1 :\n\n";
	PrintMatrix(Matrix, 3, 3);

	UnderScore(20);

	int Num = ReadNumFromUser();

	cout << "\nNumber " << Num << " frequency in matrix is " << NumFrequencyInMatrix(Matrix, 3, 3, Num) << " Time(s)." << endl;

}