#include <iostream>
#include <cstdlib>
using namespace std;

int RandomNumInRange(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

void FillArrRandomly(int Arr[100],int& ArrLength)
{
	cout << "Enter the number of elements you want : ";
	cin >> ArrLength;

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

		if (C != ArrLength - 1)
			cout << ",";
	}

	cout << "]\n\n";
}

void CloneArrFromArr(int Arr1[100], int Arr2[100], int Arr1Length)
{
	for (int C = 0; C < Arr1Length; C++)
		Arr2[C] = Arr1[C];
}

int main()
{
	srand((unsigned)time(NULL));
	
	int Arr1[100], Arr2[100], ArrLength;
	
	FillArrRandomly(Arr1, ArrLength);
	
	CloneArrFromArr(Arr1, Arr2, ArrLength);
	
	cout << "\n\nArray 1 elements : ";
	PrintArr(Arr1, ArrLength);
	
	cout << "\nArray 2 elements cloned from Array 1 : ";
	PrintArr(Arr2, ArrLength);


}
