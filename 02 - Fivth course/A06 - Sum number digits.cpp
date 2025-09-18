#include <iostream>
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

int SumNumberDigits(int Num)
{
	short Remainder, Sum = 0;
	while (Num > 0)
	{
		Remainder = Num % 10;

		Sum += Remainder;

		Num /= 10;
	}
	return Sum;
}

int main()
{
	int Num = ReadPositiveNum("Enter a positive number : ");
	
	cout << "\nSum of number digits = " << SumNumberDigits(Num) << endl;
}
