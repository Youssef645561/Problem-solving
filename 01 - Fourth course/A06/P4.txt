#include <iostream>
using namespace std;

enum enEvenOrOdd { Even, Odd };

int ReadNumber()
{
	int Num;

	cout << "Enter a number to sum even numbers until it : ";
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
	cout << "\n---------------------------------------------------\n\n";
	cout << "For loop :\n" << endl;

	int Sum = 0;

	for (int C = 1; C <= Num; C = C++)
	{
		if (CheckEvenOrOdd(C) == enEvenOrOdd::Even)
		{
			Sum = Sum + C;
		}
	}
	
	return Sum;
}

int SumUsingWhileLoop(int Num)
{
	cout << "\n---------------------------------------------------\n\n";
	cout << "Do while loop :\n" << endl;

	int C = 1, Sum = 0;

	while (C <= Num)
	{
		if (CheckEvenOrOdd(C) == enEvenOrOdd::Even)
		{
			Sum = Sum + C;
		}

	C = C++;
	}

	return Sum;
}

int SumUsingDoWhileLoop(int Num)
{
	cout << "\n---------------------------------------------------\n\n";
	cout << "While loop :\n" << endl;

	int C = 1, Sum = 0;

	do
	{
		if (CheckEvenOrOdd(C) == enEvenOrOdd::Even)
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

	cout << SumUsingForLoop(Num);
	cout << SumUsingWhileLoop(Num);
	cout << SumUsingDoWhileLoop(Num);
	cout << "\n---------------------------------------------------\n\n";
}


Donation

#include <iostream>
using namespace std;

enum enSumNumbers { Odd = 1, Even = 2, All = 3 };

void ReadNumber(int& Num, int& Temp)
{
	cout << "Choose what you want to be summed :\n" << endl;
	cout << "[1] Odd" << endl;
	cout << "[2] Even" << endl;
	cout << "[3] All" << endl;
	cout << "\nEnter the number of the operation:\n" << endl;
	cin >> Temp;

	while (Temp != 1 && Temp != 2 && Temp != 3)
	{
		cout << "\nWrong operation number,\n\nPlease enter 1,2 or 3" << endl;
		cin >> Temp;
	}

	Temp = (enSumNumbers)Temp;

	cout << "\n\nEnter a number to sum number untill it : ";
	cin >> Num;
	cout << endl;
}

enSumNumbers CheckOddOrEven(int C)
{
	if (C % 2 == 0)
		return enSumNumbers::Even;
	else
		return enSumNumbers::Odd;
}

int SumNumbersBefore(int Num, int Temp)
{

	if (Temp == enSumNumbers::Even)
	{
		int Sum = 0;

		for (int C = 1; C <= Num; C++)
		{
			if (CheckOddOrEven(C) == enSumNumbers::Even)
			{
				Sum += C;
			}
		}
		cout << "Sum of even Numbers = ";
		return Sum;
	}

	else if (Temp == enSumNumbers::Odd)
	{
		int Sum = 0;

		for (int C = 1; C <= Num; C++)
		{
			if (CheckOddOrEven(C) == enSumNumbers::Odd)
			{
				Sum += C;
			}
		}
		cout << "Sum of odd Numbers = ";
		return Sum;
	}
	else if (Temp == enSumNumbers::All)
	{ 
		int Sum = 0;

		for (int C = 1; C <= Num; C++)
		{
			Sum += C;
		}
		cout << "Sum of all Numbers = ";
		return Sum;
	}
}


int main()
{
	int Num, Temp;

	ReadNumber(Num, Temp);

	cout << SumNumbersBefore(Num, Temp) <<endl;
}