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

int main()
{
	short Day = ReadPositiveNum("Enter a day : ");
	short Month = ReadPositiveNum("\nEnter a month : ");
	int Year = ReadPositiveNum("\nEnter a year : ");

	cout << "\nNumber of days from the beginning of the year is " << GetDaysNumFromBeginningOfYear(Year, Month, Day) << endl;
}
