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

int main()
{
	int Num = ReadPositiveNum("Enter a positive number : ");
	short Digit = ReadPositiveNum("Enter a digit : ");
	
	cout << "\nDigit " << Digit << " Frequency is " << DigitFrequency(Num, Digit) << " Time(s).\n";
}
