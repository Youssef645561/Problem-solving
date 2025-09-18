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

void CheckNumExistance(int Position, int SearchingNum)
{
	if (Position != -1)
	{
		cout << "\nThe number you are looking for is " << SearchingNum;
		cout << "\nThe number found at position : " << Position << endl;
		cout << "\nThe number found in order : " << Position + 1 << endl;
	}
	else
	{
		cout << "\nThe number you are looking for is " << SearchingNum;
		cout << "\n\nThe number is not found :-(" << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Arr[100],SearchingNum;

	int ArrLength = ReadPositiveNum("Enter the number of elements you want : ");

	FillArrRanomly(Arr, ArrLength);
	
	cout << "\nArray elements : ";
	PrintArr(Arr, ArrLength);

	SearchingNum = ReadPositiveNum("Enter a number to search for in array elements : ");

	int Position = FindNumPositiom(Arr, ArrLength, SearchingNum);
	
	CheckNumExistance(Position, SearchingNum);
}
