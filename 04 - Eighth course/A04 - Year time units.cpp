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

short NumOfDaysInYear(int Year)
{
	return IsLeapYear(Year) ? 366 : 365;
}

short NumOfHoursInYear(int Year)
{
	return NumOfDaysInYear(Year) * 24;
}

int NumOfMinutesInYear(int Year)
{
	return NumOfHoursInYear(Year) * 60;
}

int NumOfSecondsInYear(int Year)
{
	return NumOfMinutesInYear(Year) * 60;
}

int main()
{
	int Year = ReadYear();

	cout << "\nNumber of days    in year [" << Year << "] is " << NumOfDaysInYear(Year);
	cout << "\nNumber of hours   in year [" << Year << "] is " << NumOfHoursInYear(Year);
	cout << "\nNumber of minutes in year [" << Year << "] is " << NumOfMinutesInYear(Year);
	cout << "\nNumber of seconds in year [" << Year << "] is " << NumOfSecondsInYear(Year);
}
