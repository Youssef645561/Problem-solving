#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void FillArrHardCoded(int Arr[100])
{
	Arr[0] = 10;
	Arr[1] = 20;
	Arr[2] = 30;
	Arr[4] = 30;
	Arr[5] = 20;
	Arr[6] = 10;
}

void PrintArr(int Arr[100], int ArrLength)
{
	cout << "[";

	for (int C = 0; C < ArrLength; C++)
		cout << Arr[C] << ",";

	cout << "\b]\n\n";
}

bool CheckIfArrIsPalindrome(int Arr[100], int ArrLength)
{
	for (int C = 0; C < ArrLength; C++)
	{
		if (Arr[C] != Arr[ArrLength - 1 - C])
			return false;
	}

	return true;
}

int main()
{
	int Arr1[100], ArrLength1 = 7, Arr2[100];

	FillArrHardCoded(Arr1);

	cout << "Array 1 Length : " << ArrLength1 << endl;
	cout << "Array 1 elements : ";
	PrintArr(Arr1, ArrLength1);

	cout << "Array is : ";
	if (CheckIfArrIsPalindrome(Arr1, ArrLength1))
		cout << "Palindrome." << endl;
	else
		cout << "Not Palindrome." << endl;
		
}