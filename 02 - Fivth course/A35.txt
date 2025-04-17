#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int ReadPositiveNum(string Message)
{
	int Num;
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

void FillArrRanomly(int Arr[100],int ArrLength)
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

int FindNumPositiom(int Arr[100], int ArrLength, int Num)
{
	for (int C = 0; C < ArrLength; C++)
	{
		if (Arr[C] == Num)
			return C;
	}
	return -1;
}

bool CheckIfNumInArr(int Arr[100], int ArrLength, int SearchingNum)
{
	return FindNumPositiom(Arr, ArrLength, SearchingNum) != -1;
}

int main()
{
	srand((unsigned)time(NULL));

	int Arr[100], SearchingNum;

	int ArrLength = ReadPositiveNum("Enter the number of elements you want : ");

	FillArrRanomly(Arr, ArrLength);

	cout << "\nArray elements : ";
	PrintArr(Arr, ArrLength);

	SearchingNum = ReadPositiveNum("Enter a number to search for in array elements : ");

	cout << "\n\nThe number you are looking for is " << SearchingNum;

	if (!CheckIfNumInArr(Arr, ArrLength, SearchingNum))
	{
		cout << "\n\nYes,the number is not found :-(" << endl;
	}
	else
	{
		cout << "\n\nYes,the number is found :-)" << endl;
	}
}