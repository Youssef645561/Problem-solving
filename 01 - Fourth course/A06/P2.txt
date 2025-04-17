#include <iostream>
using namespace std;

int ReadNumber()
{
	int Num;

	cout << "Enter a number to count from it to 1 : ";
	cin >> Num;
	cout << endl;

	return Num;
}

void CounterForLoop(int Num)
{
	cout << "\n---------------------------------------------------\n\n";
	cout << "For loop :\n" << endl;

	for (Num; Num >= 1; Num--)
	{
		cout << Num << endl;
	}
}

void CounterWhileLoop(int Num)
{
	cout << "\n---------------------------------------------------\n\n";
	cout << "While loop :\n" << endl;

	while (Num >= 1)
	{
		cout << Num << endl;
		Num--;
	}
}

void CounterDoWhileLoop(int Num)
{
	cout << "\n---------------------------------------------------\n\n";
	cout << "Do while loop:\n" << endl;

	do
	{
		cout << Num << endl;

		Num--;
	} while (Num >= 1);

	cout << "\n---------------------------------------------------\n";
}

int main()
{
	int Num = ReadNumber();

	CounterForLoop(Num);
	CounterWhileLoop(Num);
	CounterDoWhileLoop(Num);
}