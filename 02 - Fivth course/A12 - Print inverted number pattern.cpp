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

void PrintInvertedNumberPattern(int Num)
{
	cout << "\n";

	for (int i = Num; i >= 1; i--)
	{
		for (int C = i; C >= 1; C--)
		{
			cout << i;
		}
		cout << "\n";
	}
}


int main()
{
	int Num = ReadPositiveNum("Enter a positive number : ");

	PrintInvertedNumberPattern(Num);
}
