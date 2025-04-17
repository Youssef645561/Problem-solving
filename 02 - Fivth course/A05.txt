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

void PrintReversedDigits(int Num)
{
	short Remainder;
	while (Num > 0)
	{
		Remainder = Num % 10;

		cout << Remainder << "\n";

		Num /= 10;
	}
}

int main()
{
	int Num = ReadPositiveNum("Enter a positive number : ");
	PrintReversedDigits(Num);
}