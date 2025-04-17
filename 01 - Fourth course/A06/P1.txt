#include <iostream>
using namespace std;

int ReadNumber()
{
	int Num;

	cout << "Enter a number to count to it : ";
	cin >> Num;
	cout << endl;

	return Num;
}

void CounterForLoop(int Num)
{
	cout << "\n---------------------------------------------------\n\n";
	cout << "For loop :\n" << endl;

	for (int C = 1; C <= Num; C++)
	{
		cout << C << endl;
	}
}

void CounterWhileLoop(int Num)
{
	cout << "\n---------------------------------------------------\n\n";
	cout << "While loop :\n" << endl;

	int C = 1;

	while (C <= Num)
	{
		cout << C << endl;
		C++;
	}
}

void CounterDoWhileLoop(int Num)
{
	cout << "\n---------------------------------------------------\n\n";
	cout << "Do while loop:\n" << endl;


	int C = 1;

	do
	{
		cout << C << endl;
		C++;
	} while (C <= Num);

	cout << "\n---------------------------------------------------\n";
}

int main()
{
	int Num = ReadNumber();

	CounterForLoop(Num);
	CounterWhileLoop(Num);
	CounterDoWhileLoop(Num);
}