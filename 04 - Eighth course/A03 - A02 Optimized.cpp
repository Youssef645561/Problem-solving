#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int ReadYear()
{
	int Year;

	cout << "Enter a year : ";
	cin >> Year;

	while (cin.fail() || Year <= 0) //true or false
	{
		cin.clear();

		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "\nWrong input,\nPLease enter a valid number : ";
		cin >> Year;
	}

	return Year;
}

bool IsLeapYear(int Year)
{
	return (((Year % 4 == 0) && (Year % 100 != 0)) || (Year % 400 == 0));
}

int main()
{
	int Year = ReadYear();

	if (IsLeapYear(Year))
	{
		cout << "\nYes, " << Year << " is a leap year." << endl;
	}
	else
	{
		cout << "\nNo, " << Year << " is not a leap year." << endl;
	}
}
