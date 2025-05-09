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

int ReverseNumber(int Num)
{
	short Remainder; 
	int ReversedNumber = 0;
	while (Num > 0)
	{
		Remainder = Num % 10;

		ReversedNumber = ReversedNumber * 10 + Remainder;

		Num /= 10;
	}
	return ReversedNumber;
}

int main()
{
	int Num = ReadPositiveNum("Enter a positive number : ");
	
	cout << "\nReversed number = " << ReverseNumber(Num) << endl;
}