#pragma warning(disable:4996)

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

struct stDate
{
	int Year = 0;
	short Month = 1;
	short Day = 0;
};

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

stDate ReadFullDate()
{
	stDate Date;

	Date.Day = ReadPositiveNum("Enter a day : ");
	Date.Month = ReadPositiveNum("Enter a month : ");
	Date.Year = ReadPositiveNum("Enter a year : ");

	cout << endl;

	return Date;
}

bool IsLeapYear(int Year)
{
	return (((Year % 4 == 0) && (Year % 100 != 0)) || (Year % 400 == 0));
}

short NumOfDaysInMonth(int Year, short Month)
{
	if (Month == 2)
	{
		return IsLeapYear(Year) ? 29 : 28;
	}

	short Arr30DaysMonth[4] = { 4,6,9,11 };

	for (short i = 0; i < 4; i++)
	{
		if (Arr30DaysMonth[i] == Month)
		{
			return 30;
		}
	}
	return 31;
}

bool IsDateValid(stDate Date)
{
	if (Date.Month < 1 || Date.Month > 12)
	{
		return false;
	}

	if (Date.Year <= 0)
	{
		return false;
	}

	if (Date.Month == 2)
	{
		if (IsLeapYear(Date.Year))
		{
			if (Date.Day > 29 || Date.Day < 1)
			{
				return false;
			}
		}
		else
		{
			if (Date.Day > 28 || Date.Day < 1)
				return false;
		}
	}

	return Date.Day >= 1 && Date.Day <= NumOfDaysInMonth(Date.Year, Date.Month);
}

int main()
{
	stDate Date = ReadFullDate();

	if (IsDateValid(Date))
	{
		cout << "\nYes, date is valid." << endl;
	}
	else
	{
		cout << "\nNo, date is not valid." << endl;
	}

}
