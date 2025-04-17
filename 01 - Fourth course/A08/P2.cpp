#include <iostream>
#include <string>
using namespace std;

float ReadNumbers(string Message)
{
	int Num;

	cout << Message;
	cin >> Num;

	return Num;
}

float RepeatUntill()
{
	int Sum = 0, C = 1, Num = 0;
	do
	{
		Num = ReadNumbers("Enter number [" + to_string(C) + "] : ");

		if (Num == -99)
		{
			break;
		}
		Sum += Num;
		C++;

	} while (Num != -99);

	return Sum;
}

int main()
{
	cout << "\nResult = " << RepeatUntill() << endl;
}