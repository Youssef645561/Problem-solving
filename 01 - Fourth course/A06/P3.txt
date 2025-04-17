#include <iostream>
using namespace std;

enum enEvenOrOdd { Even, Odd };

int ReadNumber()
{
	int Num;

	cout << "Enter a number to sum odd numbers until it : ";
	cin >> Num;

	return Num;
}

enEvenOrOdd CheckEvenOrOdd(int C)
{
	if (C % 2 == enEvenOrOdd::Even)
		return enEvenOrOdd::Even;
	else
		return enEvenOrOdd::Odd;
}

int SumUsingForLoop(int Num)
{	
	int Sum = 0;

	for (int C = 1; C <= Num; C = C++)
	{
		if (CheckEvenOrOdd(C) == enEvenOrOdd::Odd)
		{
			Sum = Sum + C;
		}
	}
	
	return Sum;
}

int SumUsingWhileLoop(int Num)
{
	int C = 1, Sum = 0;

	while (C <= Num)
	{
		if (CheckEvenOrOdd(C) == enEvenOrOdd::Odd)
		{
			Sum = Sum + C;
		}

	C = C++;
	}

	return Sum;
}

int SumUsingDoWhileLoop(int Num)
{
	int C = 1, Sum = 0;

	do
	{
		if (CheckEvenOrOdd(C) == enEvenOrOdd::Odd)
		{
			Sum = C + Sum;
		}

	C = C++;

	} while (C <= Num);

	return Sum;
}


int main()
{
	int Num = ReadNumber();

	cout << "\n---------------------------------------------------\n\n";
	cout << "For loop :\n" << endl;
	cout << SumUsingForLoop(Num);
	cout << "\n---------------------------------------------------\n\n";
	cout << "Do while loop :\n" << endl;
	cout << SumUsingWhileLoop(Num);
	cout << "\n---------------------------------------------------\n\n";
	cout << "While loop :\n" << endl;
	cout << SumUsingDoWhileLoop(Num);
	cout << "\n---------------------------------------------------\n\n";
}