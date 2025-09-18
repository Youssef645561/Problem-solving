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

int MyCeil(float Num)
{
	if (GetFraction(Num) != 0)
	{
		if (Num > 0)
			return (int)Num + 1;
		else
			return (int)Num;
	}
	else
		return Num;
}

int main()
{
	float Num = ReadNum("Enter a number : ");

	cout << "C++ Ceil function = " << ceil(Num) << endl;
	cout << "My Ceil function = " << MyCeil(Num) << endl;
}
