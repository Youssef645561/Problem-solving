#include <iostream>
using namespace std;

enum enPrimeOrNotPrime { Prime, NotPrime };

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

enPrimeOrNotPrime CheckPrime(int Num)
{
	if (Num == 1)
	{
		return enPrimeOrNotPrime::NotPrime;
	}

	int	M = round(Num / 2);

	for (int C = 2; C <= M; C++)
	{
		if (Num % C == 0)
		{
			return enPrimeOrNotPrime::NotPrime;
		}
	}
	return enPrimeOrNotPrime::Prime;
}

void PrintResult(enPrimeOrNotPrime Result)
{
	if (Result == enPrimeOrNotPrime::Prime)
		cout << "\nThe number is prime" << endl;
	else
		cout << "\nThe number is not prime" << endl;
}

int main()
{
	PrintResult(CheckPrime(ReadPositiveNumber("Enter a positive number : ")));
}