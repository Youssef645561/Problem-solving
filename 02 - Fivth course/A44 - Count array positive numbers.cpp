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

int CountArrPositiveNums(int Arr[100], int ArrLength)
{
	int i = 0;
	for (int C = 0; C < ArrLength; C++)
	{
		if (Arr[C] > 0)
			i++;
	}
	return i;
}

int RandomNumInRange(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

void FillArrRanomly(int Arr[100], int ArrLength)
{
	for (int C = 0; C < ArrLength; C++)
		Arr[C] = RandomNumInRange(-100, 100);
}
void PrintArr(int Arr[100], int ArrLength)
{
	cout << "[";

	for (int C = 0; C < ArrLength; C++)
		cout << Arr[C] << ",";

	cout << "\b]\n\n";
}

int main()
{
	srand((unsigned)time(NULL));

	int Arr[100], ArrLength = ReadPositiveNum("Enter the number of elements you want : ");

	FillArrRanomly(Arr,ArrLength);

	cout << "\n\nArray Length : " << ArrLength << endl;
	cout << "\nArray elements : ";
	PrintArr(Arr, ArrLength);

	cout << "The number of positive numbers = " << CountArrPositiveNums(Arr, ArrLength) << endl;
	
		
}
