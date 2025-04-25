#pragma warning(disable:4996)

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

enum enCompareResult { Before = -1, Equal = 0, After = 1 };

struct stDate
{
	int Year = 0;
	short Month = 1;
	short Day = 0;
};

struct stPeriod
{
	stDate StartDate;
	stDate EndDate;
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

stPeriod ReadPeriod()
{
	stPeriod Period;

	cout << "Enter start date :\n\n";
	Period.StartDate = ReadFullDate();

	cout << "\nEnter end date :\n\n";
	Period.EndDate = ReadFullDate();

	return Period;
}

bool IsDate1BeforDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) || (Date1.Year == Date2.Year && Date1.Month < Date2.Month) || ((Date1.Year == Date2.Year && Date1.Month == Date2.Month) && (Date1.Day < Date2.Day));
}

bool AreDateAnd1Date2Equal(stDate Date1, stDate Date2)
{
	return (Date1.Year == Date2.Year) ? (Date1.Month == Date2.Month) ? (Date1.Day == Date2.Day) : false : false;
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
	return !IsDate1BeforDate2(Date1, Date2) && !AreDateAnd1Date2Equal(Date1, Date2);
}

enCompareResult CompareDate1ToDate2(stDate Date1, stDate Date2)
{
	return IsDate1AfterDate2(Date1, Date2) ? enCompareResult::After : IsDate1BeforDate2(Date1, Date2) ? enCompareResult::Before : enCompareResult::Equal;
}

bool IsDateWithinPeriod(stPeriod Period, stDate Date)
{
	return
			!(CompareDate1ToDate2(Date, Period.StartDate) == enCompareResult::Before
		||
			CompareDate1ToDate2(Date, Period.EndDate) == enCompareResult::After);
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

bool ArePeriodsOverlap(stPeriod Period1, stPeriod Period2)
{
	return !(CompareDate1ToDate2(Period2.EndDate, Period1.StartDate) == enCompareResult::Before || CompareDate1ToDate2(Period2.StartDate, Period1.EndDate) == enCompareResult::After);
}

void SwapPeriods(stPeriod& Period1, stPeriod& Period2)
{
	stPeriod TempPeriod = Period1;

	Period1 = Period2;

	Period2 = TempPeriod;
}

int CountOverlapedDays(stPeriod Period1, stPeriod Period2)
{
	int DaysCounter = 0;

	if (Period1.EndDate.Year - Period1.StartDate.Year > Period2.EndDate.Year - Period2.StartDate.Year)
	{
		SwapPeriods(Period1, Period2);
	}

	while (CompareDate1ToDate2(Period1.StartDate, Period1.EndDate) == enCompareResult::Before)
	{
		if (IsDateWithinPeriod(Period2, Period1.StartDate))
		{
			DaysCounter++;
		}
		
		Period1.StartDate = IncrementDateByOneDay(Period1.StartDate);


		if (!ArePeriodsOverlap(Period1, Period2))
		{
			break;
		}
	}

	return DaysCounter;
}

int main()
{
	cout << "Enter period 1 :\n";
	stPeriod Period1 = ReadPeriod();

	cout << "\n\nEnter period 2 :\n";
	stPeriod Period2 = ReadPeriod();
	


	cout << "\nOverlaped days number is : " << CountOverlapedDays(Period1, Period2) << endl;
}
