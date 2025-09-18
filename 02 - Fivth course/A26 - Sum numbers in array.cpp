#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int RondomNumInRange(int From, int To)
{
	int Num = rand() % (To - From + 1) + From;

	return Num;
}

void FillArrayRandomly(int Arr[100], short& ArrLength)
{
	cout << "Enter the number of elements : ";
	cin >> ArrLength;


	for (int C = 0; C < ArrLength; C++)
		Arr[C] = RondomNumInRange(1, 100);

	cout << "\n";
}

void PrintArr(int Arr[100], short ArrLength)
{
	cout << "[";

	for (int C = 0; C < ArrLength; C++)
	{
		cout << Arr[C];

		if (C != ArrLength - 1)
			cout << ",";
	}

	cout << "]";
}

int SumNumsInArr(int Arr[100], short ArrLength)
{
	int Sum = 0;

	for (int C = 0; C < ArrLength; C++)
	{
		Sum += Arr[C];
	}
	return Sum;
}

int main()
{
	srand((unsigned)time(NULL));

	int Arr[100];
	short ArrLength;

	FillArrayRandomly(Arr, ArrLength);

	cout << "Array elements : ";
	PrintArr(Arr, ArrLength);

	cout << "\n\nNumbers sum is : " << SumNumsInArr(Arr,ArrLength) << endl;
}
