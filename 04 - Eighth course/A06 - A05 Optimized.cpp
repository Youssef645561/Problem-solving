#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int ReadPositiveNum(string Message)
{
	int Num;

	cout << Message;
	cin >> Num;

	while (cin.fail() || Num <= 0) //true or false
	{
		cin.clear();

		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "\nWrong input,\nPLease enter a valid number : ";
		cin >> Num;
	}

	return Num;
}

bool IsLeapYear(int Year)
{
	return (((Year % 4 == 0) && (Year % 100 != 0)) || (Year % 400 == 0));
}

short NumOfDaysInMonth(int Year, short Month)
{
	if (Month < 1 || Month > 12)
	{
		return 0;
	}

	short ArrDaysOfMonths[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return Month == 2 ? (IsLeapYear(Year) ? 29 : 28) : ArrDaysOfMonths[Month - 1];
}

short NumOfHoursInMonth(int Year, short Month)
{
	return NumOfDaysInMonth(Year, Month) * 24;
}

int NumOfMinutesInMonth(int Year, short Month)
{
	return NumOfHoursInMonth(Year, Month) * 60;
}

int NumOfSecondsInMonth(int Year, short Month)
{
	return NumOfMinutesInMonth(Year, Month) * 60;
}

int main()
{
	int Year = ReadPositiveNum("Enter a year : ");
	short Month = ReadPositiveNum("\nEnter a month : ");

	cout << "\nNumber of days    in month [" << Month << "] is " << NumOfDaysInMonth(Year, Month);
	cout << "\nNumber of hours   in month [" << Month << "] is " << NumOfHoursInMonth(Year, Month);
	cout << "\nNumber of minutes in month [" << Month << "] is " << NumOfMinutesInMonth(Year, Month);
	cout << "\nNumber of seconds in month [" << Month << "] is " << NumOfSecondsInMonth(Year, Month);
}
