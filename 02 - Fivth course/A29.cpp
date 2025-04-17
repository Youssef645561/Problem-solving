#include <iostream>
#include <cstdlib>
using namespace std;

enum enPrimeOrNotPrime { NotPrime, Prime };

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

		cout << ",";
	}

	cout << "\b]\n\n";
}

enPrimeOrNotPrime CheckPrimeOrNotPrime(int Num)
{
	if (Num == 0 || Num == 1)
		return enPrimeOrNotPrime::NotPrime;

	else if (Num == 2 || Num == 3 || Num == 5 || Num == 7)
		return enPrimeOrNotPrime::Prime;

	else if (Num % 2 == 0 || Num < 2)
		return enPrimeOrNotPrime::NotPrime;

	int NumSquarRoot = sqrt(Num);

	for (int C = 3; C <= NumSquarRoot; C += 2)
	{
		if (Num % C == 0)
			return enPrimeOrNotPrime::NotPrime;
	}
	return enPrimeOrNotPrime::Prime;
}

void ExArrPrimeNums(int Arr[100], int ArrLength, int ArrPrime[100], int &ArrPrimeLength)
{
	for (int C = 0; C < ArrLength; C++)
	{
		if (CheckPrimeOrNotPrime(Arr[C]) == enPrimeOrNotPrime::Prime)
		{
			ArrPrime[ArrPrimeLength] = Arr[C];

			ArrPrimeLength++;
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));
	
	int Arr[100], ArrLength;
	FillArrRandomly(Arr, ArrLength);
	
	int ArrPrime[100], ArrPrimeLength = 0;
	ExArrPrimeNums(Arr, ArrLength, ArrPrime, ArrPrimeLength);
		
	cout << "\n\nArray elements : ";
	PrintArr(Arr, ArrLength);
	
	cout << "\nPrime number in Array : ";
	PrintArr(ArrPrime, ArrPrimeLength);
}