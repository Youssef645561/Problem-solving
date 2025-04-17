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

float MyAbs(float Num)
{
	if (Num < 0)
		return Num * -1;
	else
		return Num;
}

int main()
{
	float Num = ReadNum("Enter a number : ");

	cout << "C++ Absolute function = " << abs(Num) << endl;
	cout << "My Absolute function = " << MyAbs(Num) << endl;
}