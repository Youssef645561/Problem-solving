#include <iostream>
#include <string>
using namespace std;

int Read_number()
{
	int Number;
	cout << "Enter a number : ";
	cin >> Number;
	return Number;
}

float Calc_half(int Number)
{
	return float(Number) / 2;
}

void Print_number_half(int Number)
{
	string Result = "Half of " + to_string(Number) + " = " + to_string(Calc_half(Number));
	cout << endl << Result << endl;
}

int main()
{
	Print_number_half(Read_number());
}