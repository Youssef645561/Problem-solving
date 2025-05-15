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

int ReadNumToCount()
{
	int NumToCount;

	cout << "Enter a number to count it in the matrix : ";
	cin >> NumToCount;

	while (cin.fail()) //true or false
	{
		cin.clear();

		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "\nWrong input,\nPLease enter a valid number : ";
		cin >> NumToCount;
	}

	return NumToCount;
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

int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3];

	FillMatrixWithRandomNums(Matrix, 3, 3);
	cout << "Matrix :\n";
	PrintMatrix(Matrix, 3, 3);

	int NumToCount = ReadNumToCount();

	cout << "\nCounter of number " << NumToCount << " in matrix is " << CountNumInMatrix(Matrix, 3, 3, NumToCount) << endl;
}
