#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

float ReadNum(string Message)
{
	float Num = 0;

	cout << Message;
	cin >> Num;

	return Num;
}

float GetFraction(float Num)
{
	return Num - (int)Num;
}

int MyRound(float Num)
{
	float Fraction = GetFraction(Num);
	int IntegerPart = (int)Num;

	if (Num > 0)
	{
		if (Fraction >= 0.5)
			return IntegerPart + 1;
		else
			return IntegerPart;
	}
	else
	{
		if (Fraction <= -0.5)
			return IntegerPart - 1;
		else
			return IntegerPart;
	}
}

int main()
{
	float Num = ReadNum("Enter a number : ");

	cout << "C++ Round function = " << round(Num) << endl;
	cout << "My Round function = " << MyRound(Num) << endl;
}
