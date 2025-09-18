#include <iostream>
#include <string>
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

void ReadArray(short& ArrLength, int Arr[100])
{
	cout << "Enter the number of elements : ";
	cin >> ArrLength;

	cout << "\nEnter Array elements :\n\n";

	for (int C = 0; C < ArrLength; C++)
	{
		cout << "Element [" << C + 1 << "] : ";
		cin >> Arr[C];
		cout << "\n";
	}
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

short DigitFrequencyInArr(int Arr[100], short Digit, short ArrLength)
{
	short C = 0;

	for (short i = 0; i <= ArrLength - 1; i++)
	{

		if (Arr[i] == Digit)
			C++;
	}
	cout << endl << "\n";
	return C;
}


int main()
{
	int Arr[100];
	short ArrLength;

	ReadArray(ArrLength, Arr);

	short Digit = ReadPositiveNum("Enter the number you want to check : ");

	cout << "\nOriginal Array : ";

	PrintArr(Arr, ArrLength);

	cout << Digit << " is repeated " << DigitFrequencyInArr(Arr, Digit, ArrLength) << " Time(s).\n\n";

}
