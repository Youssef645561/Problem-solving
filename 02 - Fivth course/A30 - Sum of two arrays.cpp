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
	return rand() % (To - From + 1) + From;
}

void FillArrRandomly(int Arr[100],int ArrLength)
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

void SumOfTwoArrays(int Arr1[100], int Arr2[100], int SumArrays[100], int ArraysLength)
{
	for (int C = 0; C < ArraysLength; C++)
	{
		SumArrays[C] = Arr1[C] + Arr2[C];
	}
}

int main()
{
	srand((unsigned)time(NULL));
	
	int SumArrays[100];

	int Arr1[100],
	ArrLength = ReadPositiveNum("Enter the number of elements you want : ");

	FillArrRandomly(Arr1, ArrLength);
	
	int Arr2[100];
	FillArrRandomly(Arr2,ArrLength);
		

	cout << "\n\nArray 1 elements : ";
	PrintArr(Arr1, ArrLength);
	
	cout << "\n\nArray 2 elements : ";
	PrintArr(Arr2, ArrLength);

	SumOfTwoArrays(Arr1, Arr2, SumArrays, ArrLength);

	cout << "\n\nSummision of 2 Arrays : ";
	PrintArr(SumArrays, ArrLength);



}
