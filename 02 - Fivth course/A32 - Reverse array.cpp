#include <iostream>
#include <cstdlib>
using namespace std;

int ReadPositiveNum(string Message)
{
	int Num = 0;

	do
	{
		cout << Message;
		cin >> Num;
	} while (Num <= 0);

	return Num;
}

int RandomNumInRange(int From, int To)
{
	int Num = rand() % (To - From + 1) + From;

	return Num;
}

void FillArrayRandomly(int Arr[100], int ArrLength)
{
	for (int C = 0; C < ArrLength; C++)
	{
		Arr[C] = RandomNumInRange(1, 100);
	}
}

void PrintArr(int Arr[100], int ArrLength)
{
	cout << "[";

	for (int C = 0; C < ArrLength; C++)
	{
		cout << Arr[C];

		cout << ",";
	}

	cout << "\b]\n\n";
}

void ReverseArray(int Arr[100], int ArrLength, int TempArr[100])
{
	for (int C = 0; C < ArrLength; C++)
	{
		TempArr[C] = Arr[ArrLength - 1 - C];
	}
	
}

int main()
{
	srand((unsigned)time(NULL));

	int Arr[100], TempArr[100], ArrLength = ReadPositiveNum("Enter the number of elements you want : ");

	FillArrayRandomly(Arr, ArrLength);

	cout << "\nArray elements before Revsersing : ";
	PrintArr(Arr, ArrLength);

	ReverseArray(Arr, ArrLength, TempArr);

	cout << "\nArray elements aftrer Reversing : ";
	PrintArr(TempArr, ArrLength);
}
