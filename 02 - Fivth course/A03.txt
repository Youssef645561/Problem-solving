#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
	int Num = 0;
	do
	{
		cout << Message;
		cin >> Num;
	} while (Num <= 0);
	return Num;
}

bool CheckPerfectOrNotPerfect(int Num)
{ 
	int M = Num / 2, Sum = 0;

	for (int C = 1; C <= M; C++)
	{
		if ((Num % C) == 0)
			Sum += C;
	}
	return Sum == Num;
}

void PrintPerfectOrNotPerfect(int Num)
{
	if (CheckPerfectOrNotPerfect(Num))
		cout << endl << Num << " is a pefect number.\n\n";
	else
		cout << endl << Num << " is not a pefect number.\n\n";
}

int main()
{
		int Num = ReadPositiveNumber("Enter a positive number : ");

		PrintPerfectOrNotPerfect(Num);
}