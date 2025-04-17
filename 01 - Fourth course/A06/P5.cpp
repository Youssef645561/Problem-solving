#include <iostream>
using namespace std;

int ReadNumber()
{
	int Num;

	cout << "Enter a number to calculate its factorial : ";
	cin >> Num;

	return Num;
}

int FactorialUsingForLoop(int Num)
{
	int Factorial = 1;

	for (int C = Num; C >= 1; C--)
	{
		Factorial *= C;
	}
	return Factorial;
}

int FactorialUsingWhileLoop(int Num)
{
	int Factorial = 1;
	int C = Num;
	while (C >= 1)
	{
		Factorial *= C;
		C--;
	}
	return Factorial;
}

int FactorialUsingDoWhileLoop(int Num)
{
	int Factorial = 1;
	int C = Num;

	do
	{
		Factorial *= C;
		C--;
	} while (C >= 1);

	return Factorial;

}

int main()
{
	int Num = ReadNumber();

	cout << "\n\nFactorial of " << Num << " using for loop = " << FactorialUsingForLoop(Num) << endl;
	cout << "\n\nFactorial of " << Num << " using while loop = " << FactorialUsingWhileLoop(Num) << endl;
	cout << "\n\nFactorial of " << Num << " using do while loop = " << FactorialUsingDoWhileLoop(Num) << endl;
}