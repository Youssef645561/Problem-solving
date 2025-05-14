#include <iostream>
#include <iomanip>

using namespace std;

void FillMatrixWithOrderedNums(int Matrix[3][3], const short& Rows, const short& Cols)
{
	short j = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short C = 0; C < Cols; C++)
		{
			j++;
			Matrix[i][C] = j;
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

void TransposeMatrix(int Matrix[3][3], short Rows, short Cols, int TransposedMatrix[3][3])
{
	for (short i = 0; i < Rows; i++)
	{
		for (short C = 0; C < Cols; C++)
		{
			TransposedMatrix[i][C] = Matrix[C][i];
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3];
	int TransposedMatrix[3][3];

	FillMatrixWithOrderedNums(Matrix, 3, 3);

	cout << "The following is a 3x3 matrix filled by ordered numbers :\n";
	PrintMatrix(Matrix, 3, 3);

	TransposeMatrix(Matrix, 3, 3, TransposedMatrix);

	cout << "The following is the matrix transposed :\n";
	PrintMatrix(TransposedMatrix, 3, 3);
}
