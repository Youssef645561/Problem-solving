#include <iostream>
#include <iomanip>
#include "ArrayLib.h"

using namespace std;
using namespace nsArray;

void FillMatrixInOrder(int Arr[3][3])
{
	int Num = 0;

	for (int C = 0; C < 3; C++)
	{
		for (int i = 0; i < 3; i++)
		{
			Num++;

			Arr[C][i] = Num;
		}
	}
}

void PrintMatrix(int Arr[3][3], int Rows, int Cols)
{
	cout << "The following is a 3x3 random matrix :\n";

	for (int C = 0; C < Rows; C++)
	{
		for (int i = 0; i < Cols; i++)
		{
			cout << left << setw(3) << Arr[C][i] << "\t";
		}
		cout << "\n";
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Arr[3][3];

	FillMatrixInOrder(Arr);

	PrintMatrix(Arr, 3, 3);
}