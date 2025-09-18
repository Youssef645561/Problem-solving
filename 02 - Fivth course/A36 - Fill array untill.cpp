#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int ReadArrNum(string Message)
{
	int Num;

	cout << Message;
	cin >> Num;

	return Num;
}


void ReadArrElement(int Arr[100],int ArrLength,int Num)
{
	ArrLength++;
	Arr[ArrLength - 1] = Num;
}


void FillArrUntil(int Arr[100], int ArrLength)
{
	bool YesNo;

	do
	{
		ReadArrElement(Arr, ArrLength, ReadArrNum("Enter a number to add into the array : "));

		cout << "Do you want to add another element :\n[1]Yes.\n[0]No.\nAnswer : ";
		cin >> YesNo;
		cout << "\n\n";
	} while (YesNo == 1);
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

	int Arr[100], ArrLength = 0;

	FillArrUntil(Arr, ArrLength);

	cout << "\nArray length : " << ArrLength;
	cout << "\nArray elements : ";
	PrintArr(Arr, ArrLength);

}
