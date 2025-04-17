#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

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

int MySqrt(int Num)
{
	return pow(Num, 0.5);
}

int main()
{
	int Num = ReadPositiveNum("Enter a positive number : ");

	cout << "C++ Square Root function = " << sqrt(Num) << endl;
	cout << "My Square Root function = " << MySqrt(Num) << endl;
}