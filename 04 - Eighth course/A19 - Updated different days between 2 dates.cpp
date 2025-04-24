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

short MonthDaysNum(short Month, short Year)
{
	if (Month < 1 || Month > 12)
	{
		return 0;
	}

	short ArrDaysOfMonths[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return Month == 2 ? (IsLeapYear(Year) ? 29 : 28) : ArrDaysOfMonths[Month - 1];
}

bool IsLastDayInMonth(stDate Date)
{
	return Date.Day == MonthDaysNum(Date.Month, Date.Year);
}

bool IsLastMonthInYear(short Month)
{
	return Month == 12;
}

bool IsDate1BeforDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) || (Date1.Year == Date2.Year && Date1.Month < Date2.Month) || ((Date1.Year == Date2.Year && Date1.Month == Date2.Month) && (Date1.Day < Date2.Day));
}

stDate IncrementDateByOneDay(stDate Date)
{
	if (IsLastDayInMonth(Date))
	{

		if (IsLastMonthInYear(Date.Month))
		{
			Date.Day = 1;
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Day = 1;
			Date.Month++;
		}
	}
	else
	{
		Date.Day++;
	}

	return Date;
}

void SwapDates(stDate& Date1, stDate& Date2)
{
	stDate TempDate = Date1;

	Date1 = Date2;
	Date2 = TempDate;
}

int DifferentDaysBetweenDate1AndDate2(stDate Date1, stDate Date2, bool IncludeLastDay = false)
{
	int DifferentDays = 0;
	short SwapFlagValue = 1;

	if (!IsDate1BeforDate2(Date1, Date2))
	{
		SwapDates(Date1, Date2);
		SwapFlagValue = -1;
	}

	while (IsDate1BeforDate2(Date1, Date2))
	{
		DifferentDays++;

		Date1 = IncrementDateByOneDay(Date1);
	}

	return IncludeLastDay ? (++DifferentDays * SwapFlagValue) : (DifferentDays * SwapFlagValue);
}

int main()
{
	stDate Date1 = ReadFullDate();
	stDate Date2 = ReadFullDate();

	cout << "Different days is " << DifferentDaysBetweenDate1AndDate2(Date1, Date2);
	cout << "\nDifferent days (including last day) is " << DifferentDaysBetweenDate1AndDate2(Date1, Date2, true) << endl;
}
