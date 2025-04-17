#include <iostream>
#include <cstdlib>
using namespace std;

void FillArrInOrderToNum(int Arr[100],int& ArrLength)
{
	cout << "Enter the number of elements you want : ";
	cin >> ArrLength;

	for (int C = 0; C < ArrLength; C++)
	{
		Arr[C] = C + 1;
	}
}

int RondomNumInRange(int From, int To)
{
	int Num = rand() % (To - From + 1) + From;

	return Num;
}

void Swap(int& Num1, int& Num2)
{
	int Temp = Num1;

	Num1 = Num2;
	Num2 = Temp;
}

void ShuffleArrRandomly(int Arr[100],int ArrLength)
{
	for (int C = 0; C < ArrLength; C++)
	{
		int Index1 = RondomNumInRange(1, ArrLength) - 1;
		int Index2 = RondomNumInRange(1, ArrLength- 1);

		Swap(Arr[Index1],Arr[Index2]);
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


int main()
{
	srand((unsigned)time(NULL));

	int Arr[100], ArrLength;

	FillArrInOrderToNum(Arr, ArrLength);

	cout << "\nArray elements before shuffling : ";
	PrintArr(Arr, ArrLength);

	ShuffleArrRandomly(Arr, ArrLength);


	cout << "\nArray elements aftrer shuffling : ";
	PrintArr(Arr, ArrLength);
}