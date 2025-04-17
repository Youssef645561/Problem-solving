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

int ReadNumFromUser()
{
	int Num;

	cout << "\n\nEnter a number to check in matrix : ";
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

int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3];

	FillMatrixRandomly(Matrix, 3, 3);
	cout << "Matrix :\n\n";
	PrintMatrix(Matrix, 3, 3);

	UnderScore(20);

	if (CheckNumExistanceInMatrix(Matrix, 3, 3,ReadNumFromUser()))
	{
		cout << "\nYes,number is exist.\n";
	}
	else
	{
		cout << "\nNo,number is not exist.\n";
	}

}