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

string GetDayName(short DayIndex)
{
	string ArrDaysNames[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

	return ArrDaysNames[DayIndex];
}

int main()
{
	int Year = ReadPositiveNum("Enter a year : ");
	short Month = ReadPositiveNum("\nEnter a month : ");
	short Day = ReadPositiveNum("\nEnter a day : ");

	short DayIndex = GetDayIndex(Year, Month, Day);

	cout << "\nDate      : " << Day << "/" << Month << "/" << Year;
	cout << "\nDay order : " << DayIndex;
	cout << "\nDay name  : " << GetDayName(DayIndex) << endl;
}
