#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "ManipulationLib.h"
#include "ArrayLib.h"
#include "MatrixLib.h"

using namespace std;
using namespace nsArray;
using namespace nsMatrix;
using namespace nsManipulation;

bool IsPalindromeMatrix(int Matrix[3][3], int Rows, int Cols)
{
	int Col = Cols - 1;
	int Limit = Cols / 2;
	for (int j = 0; j < Rows; j++)
	{
		for (int i = 0; i < Limit; i++)
		{
			if (Matrix[j][i] != Matrix[j][Col - i])
				return 0;
		}
	}
	return 1;
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3] = { {1,2,1} , {5,8,5} , {7,3,7} };

	cout << "Matrix :\n";
	PrintMatrix(Matrix, 3, 3);

	UnderScore(20);

	if (IsPalindromeMatrix(Matrix, 3, 3))
	{
		cout << "\nYes,matrix is palindrome";
	}
	else
	{
		cout << "\nNo,matrix is not palindrome";
	}
}