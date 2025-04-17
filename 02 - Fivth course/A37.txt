#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int ReadPositiveNum(string Message)
{
	int Num;
	cout << Message;
	cin >> Num;

	return Num;
}

void ReadArrElement(int Arr[100],int& ArrLength,int Num)
{
	ArrLength++;
	Arr[ArrLength - 1] = Num;
}

int RandomNumInRange(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

void FillArrRandomly(int Arr[100], int ArrLength)
{
	for (int C = 0; C < ArrLength; C++)
		Arr[C] = RandomNumInRange(1, 100);
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

void CloneArrOneByOne(int Arr1[100], int ArrLength1, int Arr2[100], int ArrLength2)
{
	for (int C = 0; C < ArrLength1; C++)
		ReadArrElement(Arr2, ArrLength2, Arr1[C]);
}


int main()
{
	srand((unsigned)time(NULL));

	int Arr1[100],Arr2[100], ArrLength1 = ReadPositiveNum("Enter the number of elements : ");

	FillArrRandomly(Arr1, ArrLength1);

	int ArrLength2 = 0;

	CloneArrOneByOne(Arr1, ArrLength1, Arr2, ArrLength2);

	cout << "\nArray 1 length : " << ArrLength1;
	cout << "\nArray 1 elements : ";
	PrintArr(Arr1, ArrLength1);

	cout << "\nArray 2 length : " << ArrLength1;
	cout << "\nArray 2 elements : ";
	PrintArr(Arr2, ArrLength2);
}