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

void PrintInvertedLettersPattern(int Num)
{
	cout << "\n";

	for (int i = Num + 65 + 1; i >= 65; i--)
	{
		for (int C = 1; C <= Num - (65 + Num - 1 - i); C++)
		{
			cout << char(i);
		}

	cout << "\n";
	}

}


int main()
{
	int Num = ReadPositiveNum("Enter a positive number : ");

	PrintInvertedLettersPattern(Num);
}