#include <iostream>
#include <iomanip>

using namespace std;

int RandomNumInRange(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

void FillMatrixWithRandomNums(int Matrix[3][3],const short& Rows,const short& Cols)
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
			cout  << setw(3) << left << Matrix[i][C] << "\t";
		}
		cout << "\n";
	}

	cout << endl;
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3];

	FillMatrixWithRandomNums(Matrix, 3, 3);

	cout << "The following is a 3x3 random matrix :\n";
	PrintMatrix(Matrix, 3, 3);
}
