#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>

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

short GetDaysNumFromBeginningOfYear(int Year, short Month, short Day)
{
	short TotalDays = 0;

	for (short i = 1; i < Month; i++)
	{
		TotalDays += NumOfDaysInMonth(Year, i);
	}

	TotalDays += Day;

	return TotalDays;
}

stDate ReadFullDate()
{
	stDate Date;

	Date.Day = ReadPositiveNum("Enter a day : ");
	Date.Month = ReadPositiveNum("\nEnter a month : ");
	Date.Year = ReadPositiveNum("\nEnter a year : ");

	return Date;
}

stDate AddDaysToDate(stDate Date, short DaysToAdd)
{
	while (DaysToAdd >= 365)
	{
		if (IsLeapYear(Date.Year))
		{
			Date.Year++;

			DaysToAdd -= 366;

			continue;
		}
		else
		{
			Date.Year++;

			DaysToAdd -= 365;
		}
	}

	short MonthDays;

	Date.Day += DaysToAdd;

	while (Date.Day >= (MonthDays = NumOfDaysInMonth(Date.Year, Date.Month)))
	{
		if (Date.Month == 12)
		{
			Date.Year++;
			Date.Month = 0;
		}

		Date.Month++;

		Date.Day -= MonthDays;
	}

	return Date;
}

int main()
{
	stDate Date = ReadFullDate();

	short DaysToAdd = ReadPositiveNum("\nEnter how many days you want to add : ");

	Date = AddDaysToDate(Date, DaysToAdd);

	cout << "\n\nDate after adding [" << DaysToAdd << "] days is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
}
