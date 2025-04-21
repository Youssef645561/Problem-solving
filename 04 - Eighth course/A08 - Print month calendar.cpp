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

string UnderScore(short Num)
{
	string UnderScoreText = "";

	for (short C = 1; C <= Num; C++)
		UnderScoreText += '_';

	return UnderScoreText;
}

bool IsLeapYear(int Year)
{
	return (((Year % 4 == 0) && (Year % 100 != 0)) || (Year % 400 == 0));
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

string GetMonthShortName(short Month)
{
	string ArrMonthsNames[13] = { "", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

	return ArrMonthsNames[Month];
}

void HeaderOfMonthCalendar(short Month)
{
	cout << "\n  " << UnderScore(15);
	cout << GetMonthShortName(Month);
	cout << UnderScore(15);

	cout << "  \n\n" << "  Sun  " << "Mon  " << "Tue  " << "Wed  " << "Thu  " << "Fri  " << "Sat  \n   ";
}

void PrintMonthCalendar(int Year, short Month)
{
	HeaderOfMonthCalendar(Month);

	short FirstDayIndex = GetDayIndex(Year, Month, 1);

	short i;

	for (i = 0; i < FirstDayIndex; i++)
	{
		cout << "     ";
	}

	short DaysNum = NumOfDaysInMonth(Year, Month);

	for (short C = 1; C <= DaysNum; C++)
	{
		if (i == 7)
		{
			i = 0;

			cout << "\n   ";
		}

		i++;

		cout << left << setw(5) << C;
	}
	cout << "\n  " << UnderScore(33);
}

int main()
{
	int Year = ReadPositiveNum("Enter a year : ");
	short Month = ReadPositiveNum("\nEnter a month : ");

	PrintMonthCalendar(Year, Month);
}
