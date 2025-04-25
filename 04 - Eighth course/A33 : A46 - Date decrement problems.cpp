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

stDate DecrementDateByOneDay(stDate Date)
{
	if (Date.Day == 1)
	{
		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Year--;
			Date.Day = 31;
		}
		else
		{
			Date.Month--;

			Date.Day = MonthDaysNum(Date.Month, Date.Year);
		}
	}
	else
	{
		Date.Day--;
	}

	return Date;
}

stDate DecrementDateByXDays(stDate Date, int DaysToSub)
{
	for (int i = 1; i <= DaysToSub; i++)
	{
		Date = DecrementDateByOneDay(Date);
	}

	return Date;
}

stDate DecrementDateByOneWeek(stDate Date)
{
	for (short i = 1; i <= 7; i++)
	{
		Date = DecrementDateByOneDay(Date);
	}

	return Date;
}

stDate DecrementDateByXWeeks(stDate Date, int WeeksToSub)
{
	for (int i = 1; i <= WeeksToSub; i++)
	{
		Date = DecrementDateByOneWeek(Date);
	}

	return Date;
}

stDate DecrementDateByOneMonth(stDate Date)
{
	if (Date.Month == 1)
	{
		Date.Month = 12;

		Date.Year--;
	}
	else
	{
		Date.Month--;
	}

	short MonthDays = MonthDaysNum(Date.Month, Date.Year);

	if (Date.Day > MonthDays)
	{
		Date.Day = MonthDays;
	}

	return Date;
}

stDate DecrementDateByXMonths(stDate Date, int MonthsToSub)
{
	for (int i = 1; i <= MonthsToSub; i++)
	{
		Date = DecrementDateByOneMonth(Date);
	}

	return Date;
}

stDate DecrementDateByOneYear(stDate Date)
{
	if (IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
	{
		Date.Year--;

		Date.Day--;
	}
	else
	{
		Date.Year--;
	}

	return Date;
}

stDate DecrementDateByXYears(stDate Date, int YearsToSub)
{
	for (int i = 1; i <= YearsToSub; i++)
	{
		Date = DecrementDateByOneYear(Date);
	}

	return Date;
}

stDate DecrementDateByXYearsFaster(stDate Date, int YearsToSub)
{
	if (Date.Year < YearsToSub)
	{
		Date.Year = 0;
		Date.Month = 0;
		Date.Day = 0;

		return Date;
	}

	if (IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
	{
		Date.Year -= YearsToSub;

		if (!IsLeapYear(Date.Year))
			Date.Day--;

		return Date;
	}
	else
	{
		Date.Year -= YearsToSub;

		return Date;
	}
}

stDate DecrementDateByOneDecade(stDate Date)
{
	if (IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
	{
		Date.Year -= 10;

		if (!IsLeapYear(Date.Year))
			Date.Day--;

		return Date;
	}
	else
	{
		Date.Year -= 10;

		return Date;
	}
}

stDate DecrementDateByXDecades(stDate Date, int DecadesToSub)
{
	for (int i = 1; i <= DecadesToSub; i++)
	{
		Date = DecrementDateByOneDecade(Date);
	}

	return Date;
}

stDate DecrementDateByXDecadesFaster(stDate Date, int DecadesToSub)
{
	if (IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
	{
		Date.Year -= (10 * DecadesToSub);

		if (!IsLeapYear(Date.Year))
			Date.Day--;

		return Date;
	}
	else
	{
		Date.Year -= (10 * DecadesToSub);

		return Date;
	}
}

stDate DecrementDateByOneCentury(stDate Date)
{
	if (IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
	{
		Date.Year -= 100;

		if (!IsLeapYear(Date.Year))
			Date.Day--;

		return Date;
	}
	else
	{
		Date.Year -= 100;

		return Date;
	}
}

stDate DecrementDateByOneMillennium(stDate Date)
{
	if (IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
	{
		Date.Year -= 1000;

		if (!IsLeapYear(Date.Year))
			Date.Day--;

		return Date;
	}
	else
	{
		Date.Year -= 1000;

		return Date;
	}
}

int main()
{
	stDate Date = ReadFullDate();

	/*
	while (true)
	{

		cout << "Date after :\n\n";

		Date = DecrementDateByOneMonth(Date);
		cout << "Test sub one month : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl << endl;
	}
	*/

	Date = DecrementDateByOneDay(Date);
	cout << "01 - Subtracting one day is              : " << Date.Day << "/" << Date.Month << "/" << Date.Year;


	Date = DecrementDateByXDays(Date, 10);
	cout << "\n02 - Subtracting 10 day is               : " << Date.Day << "/" << Date.Month << "/" << Date.Year;


	Date = DecrementDateByOneWeek(Date);
	cout << "\n03 - Subtracting one week is             : " << Date.Day << "/" << Date.Month << "/" << Date.Year;


	Date = DecrementDateByXWeeks(Date, 10);
	cout << "\n04 - Subtracting 10 weeks is             : " << Date.Day << "/" << Date.Month << "/" << Date.Year;


	Date = DecrementDateByOneMonth(Date);
	cout << "\n05 - Subtracting one month is            : " << Date.Day << "/" << Date.Month << "/" << Date.Year;


	Date = DecrementDateByXMonths(Date, 5);
	cout << "\n06 - Subtracting 5 months is             : " << Date.Day << "/" << Date.Month << "/" << Date.Year;


	Date = DecrementDateByOneYear(Date);
	cout << "\n07 - Subtracting one year is             : " << Date.Day << "/" << Date.Month << "/" << Date.Year;


	Date = DecrementDateByXYears(Date, 10);
	cout << "\n08 - Subtracting 10 years is             : " << Date.Day << "/" << Date.Month << "/" << Date.Year;


	Date = DecrementDateByXYearsFaster(Date, 10);
	cout << "\n09 - Subtracting 10 years (faster) is    : " << Date.Day << "/" << Date.Month << "/" << Date.Year;


	Date = DecrementDateByOneDecade(Date);
	cout << "\n10 - Subtracting one decade is           : " << Date.Day << "/" << Date.Month << "/" << Date.Year;


	Date = DecrementDateByXDecades(Date, 10);
	cout << "\n11 - Subtracting 10 decades is           : " << Date.Day << "/" << Date.Month << "/" << Date.Year;


	Date = DecrementDateByXDecadesFaster(Date, 10);
	cout << "\n12 - Subtracting 10 decades (faster) is  : " << Date.Day << "/" << Date.Month << "/" << Date.Year;


	Date = DecrementDateByOneCentury(Date);
	cout << "\n13 - Subtracting one century is          : " << Date.Day << "/" << Date.Month << "/" << Date.Year;


	Date = DecrementDateByOneMillennium(Date);
	cout << "\n14 - Subtracting one millennium is       : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
}
