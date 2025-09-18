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

int MyFloor(float Num)
{
	if (Num > 0)
		return (int)Num;
	else
		return (int)Num - 1;
}

int main()
{
	float Num = ReadNum("Enter a number : ");

	cout << "C++ Floor function = " << floor(Num) << endl;
	cout << "My Floor function = " << MyFloor(Num) << endl;
}
