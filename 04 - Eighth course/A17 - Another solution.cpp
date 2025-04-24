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

short NumOfDaysInMonth(short Month, short Year)
{
	if (Month < 1 || Month > 12)
	{
		return 0;
	}

	short ArrDaysOfMonths[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return Month == 2 ? (IsLeapYear(Year) ? 29 : 28) : ArrDaysOfMonths[Month - 1];
}

bool IsDate1BeforDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) || (Date1.Year == Date2.Year && Date1.Month < Date2.Month) || ((Date1.Year == Date2.Year && Date1.Month == Date2.Month) && (Date1.Day < Date2.Day));
}

short NumOfDaysFromYearBeginning(short Day, short Month, int Year)
{
	short TotalDays = Day;

	for (short i = 1; i < Month; i++)
	{
		TotalDays += NumOfDaysInMonth(i, Year);
	}

	return TotalDays;
}

int DifferentDaysBetweenDate1AndDate2(stDate Date1, stDate Date2, bool IncludeLastDay = false)
{
	short DateDays1 = NumOfDaysFromYearBeginning(Date1.Day, Date1.Month, Date1.Year);
	short DateDays2 = NumOfDaysFromYearBeginning(Date2.Day, Date2.Month, Date2.Year);

	int DifferentDays = 0;

	for (Date1.Year; Date1.Year < Date2.Year; Date1.Year++)
	{
		DifferentDays += IsLeapYear(Date1.Year) ? 366 : 365;
	}

	DifferentDays += DateDays2 - DateDays1;

	return IncludeLastDay ? DifferentDays + 1 : DifferentDays;
}

int main()
{

	stDate Date1 = ReadFullDate();
	stDate Date2 = ReadFullDate();

	while (!IsDate1BeforDate2(Date1, Date2))
	{
		cout << "\n\nWrong dates, Date1 is not less than Date2";

		cout << "\n\nPress any key to enter dates again  ... ";

		system("pause > 0");
		system("cls");

		Date1 = ReadFullDate();
		Date2 = ReadFullDate();
	}

	cout << "Different days is " << DifferentDaysBetweenDate1AndDate2(Date1, Date2);
	cout << "\nDifferent days (including last day) is " << DifferentDaysBetweenDate1AndDate2(Date1, Date2, true) << endl;
}
