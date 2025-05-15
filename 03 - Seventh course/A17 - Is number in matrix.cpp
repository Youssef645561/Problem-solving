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

int ReadNumToCheckExistance()
{
	int NumToCheck;

	cout << "Enter a number to check its existance in the matrix : ";
	cin >> NumToCheck;

	while (cin.fail()) //true or false
	{
		cin.clear();

		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "\nWrong input,\nPLease enter a valid number : ";
		cin >> NumToCheck;
	}

	return NumToCheck;
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

int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3];

	FillMatrixWithRandomNums(Matrix, 3, 3);
	cout << "Matrix :\n";
	PrintMatrix(Matrix, 3, 3);


	int NumToCheck = ReadNumToCheckExistance();

	if (IsNumInMatrix(Matrix, 3, 3, NumToCheck))
	{
		cout << "\nYes, number is in the matrix." << endl;
	}
	else
	{
		cout << "\nNo, number is not in the matrix." << endl;
	}
}
