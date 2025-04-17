#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void FillArrHardCoded(int Arr[100])
{
	Arr[0] = 10;
	Arr[1] = 10;
	Arr[2] = 10;
	Arr[3] = 50;
	Arr[4] = 70;
	Arr[5] = 70;
	Arr[6] = 70;
	Arr[7] = 70;
	Arr[8] = 90;
}

void PrintArr(int Arr[100], int ArrLength)
{
	cout << "[";

	for (int C = 0; C < ArrLength; C++)
		cout << Arr[C] << ",";

	cout << "\b]\n\n";
}

int FindNumPosition(int Arr[100], int ArrLength, int Num)
{
	for (int C = 0; C < ArrLength; C++)
	{
		if (Num == Arr[C])
			return C;
	}
	return -1;
}

bool CheckIfNumExist(int Arr[100], int& ArrLength, int Num)
{
	return FindNumPosition(Arr, ArrLength, Num) == -1;
}

void CloneWithoutRepeating(int Arr2[100], int& ArrLength2, int Num)
{
	if (CheckIfNumExist(Arr2, ArrLength2, Num))
	{
		ArrLength2++;

		Arr2[ArrLength2 - 1] = Num;
	}
}

void CloneNumElementByElement(int Arr1[100], int ArrLength1, int Arr2[100], int& ArrLength2)
{
	for (int C = 0; C < ArrLength1; C++)
	{
		CloneWithoutRepeating(Arr2, ArrLength2, Arr1[C]);
	}
}

int main()
{
	int Arr1[100], ArrLength1 = 9, Arr2[100], ArrLength2 = 0;

	FillArrHardCoded(Arr1);

	CloneNumElementByElement(Arr1, ArrLength1, Arr2, ArrLength2);

	cout << "Array 1 Length : " << ArrLength1 << endl;
	cout << "Array 1 elements : ";
	PrintArr(Arr1, ArrLength1);

	cout << "\nArray 2 Length : " << ArrLength2 << endl;
	cout << "Array 2 elements : ";
	PrintArr(Arr2, ArrLength2);

}