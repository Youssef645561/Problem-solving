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

stDate GetSystemTime()
{
	stDate Date;

	time_t CurrentTime = time(0);

	tm* stCurrentTime = localtime(&CurrentTime);

	Date.Day = stCurrentTime->tm_mday;
	Date.Month = stCurrentTime->tm_mon + 1;
	Date.Year = stCurrentTime->tm_year + 1900;

	return Date;
}

short GetDayIndex(int Year, short Month, short Day)
{
	if (Month < 3)
	{
		Month += 12;
		Year--;
	}

	int y;
	short a, m;

	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;

	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short GetDayIndex(stDate Date)
{
	return GetDayIndex(Date.Year, Date.Month, Date.Day);
}

string GetDayName(short DayIndex)
{
	string ArrDaysNames[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

	return ArrDaysNames[DayIndex];
}

bool IsLeapYear(int Year)
{
	return (((Year % 4 == 0) && (Year % 100 != 0)) || (Year % 400 == 0));
}

short MonthDaysNum(int Year, short Month)
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
		TotalDays += MonthDaysNum(Year, i);
	}

	TotalDays += Day;

	return TotalDays;
}


bool IsDate1BeforDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) || (Date1.Year == Date2.Year && Date1.Month < Date2.Month) || ((Date1.Year == Date2.Year && Date1.Month == Date2.Month) && (Date1.Day < Date2.Day));
}

bool IsLastDayInMonth(stDate Date)
{
	return Date.Day == MonthDaysNum(Date.Month, Date.Year);
}

bool IsLastMonthInYear(short Month)
{
	return Month == 12;
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

int DifferentDaysBetweenDate1AndDate2(stDate Date1, stDate Date2, bool IncludeLastDay = false)
{
	int DifferentDays = 0;

	while (IsDate1BeforDate2(Date1, Date2))
	{
		DifferentDays++;

		Date1 = IncrementDateByOneDay(Date1);
	}


	return IncludeLastDay ? ++DifferentDays : DifferentDays;
}

bool IsEndOfWeek(stDate Date)
{
	return GetDayIndex(Date) == 6;
}

bool IsWeekend(stDate Date)
{
	short DayIndex = GetDayIndex(Date);

	return (DayIndex == 5 || DayIndex == 6);
}

bool IsBussinessDay(stDate Date)
{
	/*
	short DayIndex = GetDayIndex(Date);
	return (DayIndex != 5 && DayIndex != 6);
	*/

	return !IsWeekend(Date);
}

short DaysUntilTheEndOfWeek(stDate Date)
{
	return 6 - GetDayIndex(Date);
}

short DaysUntilTheEndOfMonth(stDate Date)
{
	/*
	return (MonthDaysNum(Date.Year, Date.Month) - Date.Day + 1);
	*/


	stDate MonthEndDate;

	MonthEndDate.Day = MonthDaysNum(Date.Year, Date.Month);
	MonthEndDate.Month = Date.Month;
	MonthEndDate.Year = Date.Year;

	return DifferentDaysBetweenDate1AndDate2(Date, MonthEndDate, true);
}

short DaysUntilTheEndOfYear(stDate Date)
{
	/*
	return IsLeapYear(Date.Year) ? 366 : 365 - GetDaysNumFromBeginningOfYear(Date.Year, Date.Month, Date.Day) + 1;
	*/


	stDate YearEndDate;

	YearEndDate.Day = 31;
	YearEndDate.Month = 12;
	YearEndDate.Year = Date.Year;

	return DifferentDaysBetweenDate1AndDate2(Date, YearEndDate, true);
}

int main()
{
	//stDate Date = GetSystemTime();

	stDate Date;

	Date.Day = 23;
	Date.Month = 9;
	Date.Year = 2022;


	short DayIndex = GetDayIndex(Date);

	string DayName = GetDayName(DayIndex);


	cout << "Today is " << DayName << " , " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	cout << "\n\nIs it end of week ?\n";
	if (IsEndOfWeek(Date))
	{
		cout << "Yes, it is the end of week.";
	}
	else
	{
		cout << "No, it is not the end of week.";
	}


	cout << "\n\n\nIs it weekend ?\n";
	if (IsWeekend(Date))
	{
		cout << "Yes, it is weekend.";
	}
	else
	{
		cout << "No, it is not weekend.";
	}


	cout << "\n\n\nIs it bussiness day ?\n";
	if (IsBussinessDay(Date))
	{
		cout << "Yes, it is a bussiness day.";
	}
	else
	{
		cout << "No, it is not a bussiness day.";
	}


	cout << "\n\n\nDays untill end of the week : " << DaysUntilTheEndOfWeek(Date) << " Day(s).";
	cout << "\nDays untill end of the month    : " << DaysUntilTheEndOfMonth(Date) << " Day(s).";
	cout << "\nDays untill end of the year     : " << DaysUntilTheEndOfYear(Date) << " Day(s)." << endl;

}
