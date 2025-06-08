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

short ReadVacationDays()
{
	short VacationDays = 0;

	cout << "\nEnter vacation days : ";
	cin >> VacationDays;

	return VacationDays;
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

bool IsWeekend(stDate Date)
{
	short DayIndex = GetDayIndex(Date);

	return (DayIndex == 5 || DayIndex == 6);
}

bool IsBussinessDay(stDate Date)
{
	return !IsWeekend(Date);
}

stDate CalcReturnVacationDate(stDate DateFrom, short VacationDays)
{
	while (VacationDays != 0 || IsWeekend(DateFrom))
	{
		if (IsBussinessDay(DateFrom))
			VacationDays--;

		DateFrom = IncrementDateByOneDay(DateFrom);
	}

	return DateFrom;
}

int main()
{
	cout << "Vacation starts :\n";
	stDate DateFrom = ReadFullDate();

	short VacationDays = ReadVacationDays();

	stDate DateTo = CalcReturnVacationDate(DateFrom, VacationDays);

	cout << "\n\nReturn date : " << GetDayName(GetDayIndex(DateTo)) << " , " << DateTo.Day << "/" << DateTo.Month << "/" << DateTo.Year << endl;

}
