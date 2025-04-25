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

stDate IncrementDateByXDays(stDate Date, int DaysToAdd)
{
	for (int i = 1; i <= DaysToAdd; i++)
	{
		Date = IncrementDateByOneDay(Date);
	}

	return Date;
}

stDate IncrementDateByOneWeek(stDate Date)
{
	for (short i = 1; i <= 7; i++)
	{
		Date = IncrementDateByOneDay(Date);
	}

	return Date;
}

stDate IncrementDateByXWeeks(stDate Date, int WeeksToAdd)
{
	for (int i = 1; i <= WeeksToAdd; i++)
	{
		Date = IncrementDateByOneWeek(Date);
	}

	return Date;
}

stDate IncrementDateByOneMonth(stDate Date)
{
	if (IsLastMonthInYear(Date.Month))
	{
		Date.Month = 1;
		Date.Year++;

		return Date;
	}
	else
	{
		Date.Month++;
	}

	short NumberOfDaysMonth = MonthDaysNum(Date.Month, Date.Year);
	if (Date.Day > NumberOfDaysMonth)
	{
		Date.Day = NumberOfDaysMonth;
	}

	return Date;
}

stDate IncrementDateByXMonths(stDate Date, int MonthsToAdd)
{
	for (int i = 1; i <= MonthsToAdd; i++)
	{
		Date = IncrementDateByOneMonth(Date);
	}

	return Date;
}

stDate IncrementDateByOneYear(stDate Date)
{
	if (IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
	{
		Date.Year++;

		Date.Day--;
	}
	else
	{
		Date.Year++;
	}

	return Date;
}

stDate IncrementDateByXYears(stDate Date, int YearsToAdd)
{
	for (int i = 1; i <= YearsToAdd; i++)
	{
		Date = IncrementDateByOneYear(Date);
	}

	return Date;
}

stDate IncrementDateByXYearsFaster(stDate Date, int YearsToAdd)
{
	if (IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
	{
		Date.Year += YearsToAdd;

		if (!IsLeapYear(Date.Year))
			Date.Day--;

		return Date;
	}
	else
	{
		Date.Year += YearsToAdd;

		return Date;
	}
}

stDate IncrementDateByOneDecade(stDate Date)
{
	if (IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
	{
		Date.Year += 10;

		if (!IsLeapYear(Date.Year))
			Date.Day--;

		return Date;
	}
	else
	{
		Date.Year += 10;

		return Date;
	}
}

stDate IncrementDateByXDecades(stDate Date, int DecadesToAdd)
{
	for (int i = 1;i <= DecadesToAdd;i++)
	{
		Date = IncrementDateByOneDecade(Date);
	}

	return Date;
}

stDate IncrementDateByXDecadesFaster(stDate Date, int DecadesToAdd)
{
	if (IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
	{
		Date.Year += (10 * DecadesToAdd);

		if (!IsLeapYear(Date.Year))
			Date.Day--;

		return Date;
	}
	else
	{
		Date.Year += (10 * DecadesToAdd);

		return Date;
	}
}

stDate IncrementDateByOneCentury(stDate Date)
{
	if (IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
	{
		Date.Year += 100;

		if (!IsLeapYear(Date.Year))
			Date.Day--;

		return Date;
	}
	else
	{
		Date.Year += 100;

		return Date;
	}
}

stDate IncrementDateByOneMillennium(stDate Date)
{
	if (IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
	{
		Date.Year += 1000;

		if (!IsLeapYear(Date.Year))
			Date.Day--;

		return Date;
	}
	else
	{
		Date.Year += 1000;

		return Date;
	}
}

int main()
{
	stDate Date = ReadFullDate();

	/*while (true)
	{

		cout << "Date after :\n\n";

		Date = IncrementDateByOneYear(Date);
		cout << "Test add one year : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl << endl;
	}*/

	Date = IncrementDateByOneDay(Date);
	cout << "01 - Adding one day is              : " << Date.Day << "/" << Date.Month << "/" << Date.Year;


	Date = IncrementDateByXDays(Date, 10);
	cout << "\n02 - Adding 10 day is               : " << Date.Day << "/" << Date.Month << "/" << Date.Year;


	Date = IncrementDateByOneWeek(Date);
	cout << "\n03 - Adding one week is             : " << Date.Day << "/" << Date.Month << "/" << Date.Year;


	Date = IncrementDateByXWeeks(Date, 10);
	cout << "\n04 - Adding 10 weeks is             : " << Date.Day << "/" << Date.Month << "/" << Date.Year;


	Date = IncrementDateByOneMonth(Date);
	cout << "\n05 - Adding one month is            : " << Date.Day << "/" << Date.Month << "/" << Date.Year;


	Date = IncrementDateByXMonths(Date, 5);
	cout << "\n06 - Adding 5 months is             : " << Date.Day << "/" << Date.Month << "/" << Date.Year;


	Date = IncrementDateByOneYear(Date);
	cout << "\n07 - Adding one year is             : " << Date.Day << "/" << Date.Month << "/" << Date.Year;


	Date = IncrementDateByXYears(Date, 10);
	cout << "\n08 - Adding 10 years is             : " << Date.Day << "/" << Date.Month << "/" << Date.Year;


	Date = IncrementDateByXYearsFaster(Date, 10);
	cout << "\n09 - Adding 10 years (faster) is    : " << Date.Day << "/" << Date.Month << "/" << Date.Year;


	Date = IncrementDateByOneDecade(Date);
	cout << "\n10 - Adding one decade is           : " << Date.Day << "/" << Date.Month << "/" << Date.Year;


	Date = IncrementDateByXDecades(Date, 10);
	cout << "\n11 - Adding 10 decades is           : " << Date.Day << "/" << Date.Month << "/" << Date.Year;


	Date = IncrementDateByXDecadesFaster(Date, 10);
	cout << "\n12 - Adding 10 decades (faster) is  : " << Date.Day << "/" << Date.Month << "/" << Date.Year;


	Date = IncrementDateByOneCentury(Date);
	cout << "\n13 - Adding one century is          : " << Date.Day << "/" << Date.Month << "/" << Date.Year;


	Date = IncrementDateByOneMillennium(Date);
	cout << "\n14 - Adding one millennium is       : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
}
