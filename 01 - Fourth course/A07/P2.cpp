#include <iostream>
using namespace std;

int ReadNumber()
{
	int Num;

	cout << "Enter a number : ";
	cin >> Num;

	return Num;
}

int ReadPower()
{
	int Power;

	cout << "\n\nEnter a power : ";
	cin >> Power;

	return Power;
}

int MyPow(int Num, int Power)
{
	if (Power == 0)
	{
		return 1;
	}

	int MultiPly = 1;

	for (int C = 1; C <= Power; C++)
	{
		MultiPly *= Num;
	}
	return MultiPly;
}

int main()
{
	int Num = ReadNumber(), Power = ReadPower();
	cout << endl << Num << "^" << Power << " = " << MyPow(Num, Power) << endl;
}