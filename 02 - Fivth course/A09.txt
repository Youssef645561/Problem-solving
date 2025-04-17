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

short DigitFrequency(int Num, short Digit)
{
	short Remainder, C = 0;

	while (Num > 0)
	{
		Remainder = Num % 10;

		if (Remainder == Digit)
			C++;

		Num /= 10;
	}
	return C;
}

void PrintAllDigitsFrequency(int Num)
{
	for (short Digit = 0; Digit <= 9; Digit++)
	{
		short C = DigitFrequency(Num,Digit);

		if (C != 0)
			cout << "\nDigit " << Digit << " Frequency is " << C << " Time(s).\n";
	}
}

int main()
{
	int Num = ReadPositiveNum("Enter a positive number : ");


	PrintAllDigitsFrequency(Num);
}