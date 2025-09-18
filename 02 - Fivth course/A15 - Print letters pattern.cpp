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

void PrintLettersPattern(int Num)
{
	cout << "\n";

	for (int i = 65; i <= (65 + Num - 1); i++)
	{
		for (int C = 1; C <= (i - 65 + 1); C++)
		{
			cout << char(i);
		}

	cout << "\n";
	}

}


int main()
{
	int Num = ReadPositiveNum("Enter a positive number : ");

	PrintLettersPattern(Num);
}
