#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

short ReadYear()
{
	short Num;

	cout << "Enter a year : ";
	cin >> Num;

	while (cin.fail()) //true or false
	{
		cin.clear();

		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "\nWrong input,\nPLease enter a valid number : ";
		cin >> Num;
	}

	return Num;

}

bool IsLeapYear(int Num)
{
	if (Num % 400 == 0)
	{
		return true;
	}
	else if (Num % 4 != 0)
	{
		return false;
	}
	else if (Num % 100 == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int main()
{
	short Year = ReadYear();

	if (IsLeapYear(Year))
	{
		cout << "\nYes, year " << Year << " is a leap year." << endl;
	}
	else
	{
		cout << "\nNo, year " << Year << " is not a leap year." << endl;
	}
}
