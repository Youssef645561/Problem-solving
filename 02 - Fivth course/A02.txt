#include <iostream>
using namespace std;

enum enPrimeNotPrime { Prime, NotPrime };

int ReadPositiveNumber(string Message)
{
	int Num = 0;
	do
	{
		cout << Message;
		cin >> Num;
	} while (Num <= 0);

	return Num;
}

enPrimeNotPrime CheckPrimeOrNotPrime(int Num)
{ 
	if (Num == 1)
		return enPrimeNotPrime::NotPrime;

	int M = sqrt(Num);

	for (int C = 2; C <= M; C++)
	{
		if ((Num % C) == 0)
			return enPrimeNotPrime::NotPrime;
	}
	return enPrimeNotPrime::Prime;
}

void PrintPrimeNumberUntillNum(int Num)
{

	cout << "\n\Prime numbers from 1 to " << Num << " :\n" << endl;

	for (int C = 2; C <= Num; C++)
	{
		if (CheckPrimeOrNotPrime(C) == enPrimeNotPrime::Prime)
			cout << C << endl;
	}

}

int main()
{
		
		int Num = ReadPositiveNumber("Enter a positive number : ");
		
		PrintPrimeNumberUntillNum(Num);




}
