#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

short ReadNum(string Message)
{
	short Num;

	cout << Message;
	cin >> Num;

	while (cin.fail()) //true or false
	{
		cin.clear();

		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "\nWrong input,\nPLease enter a valid number : ";
		cin >> Num;
	}

	return Num;

}

bool IsLeapYear(int Num)
{
	return ((Num % 400 == 0) || ((Num % 4 == 0) && (Num % 100 != 0)));
}

short DaysInMonth(short Year, short Month)
{
	if (Month < 1 || Month > 12)
		return 0;

	if (Month == 2)
	{
		return IsLeapYear(Year) ? 29 : 28;
	}
	else
	{
		short Arr30[4] = { 4,6,9,11 };

		for (short C = 0; C < 4; C++)
		{
			if (Month == Arr30[C])
			{
				return 30;
			}
		}
		return 31;
	}
}

short HoursInMonth(short Year, short Month)
{
	return DaysInMonth(Year, Month) * 24;
}

int MinutesInMonth(short Year, short Month)
{
	return HoursInMonth(Year, Month) * 60;
}

int SecondsInMonth(short Year, short Month)
{
	return MinutesInMonth(Year, Month) * 60;
}

int main()
{
	short Year = ReadNum("Enter a year : ");
	short Month = ReadNum("\nEnter a month : ");

	cout << "\nNumber of days in month [" << Year << "] is " << DaysInMonth(Year, Month) << endl;
	cout << "Number of hours in  month [" << Year << "] is " << HoursInMonth(Year, Month) << endl;
	cout << "Number of minutes in month [" << Year << "] is " << MinutesInMonth(Year, Month) << endl;
	cout << "Number of seconds in month [" << Year << "] is " << SecondsInMonth(Year, Month) << endl;

}
