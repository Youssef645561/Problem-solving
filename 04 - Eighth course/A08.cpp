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

void UnderScore(short Num)
{
	for (short C = 1; C <= Num; C++)
		cout << '_';
}

bool IsLeapYear(int Num)
{
	return ((Num % 400 == 0) || ((Num % 4 == 0) && (Num % 100 != 0)));
}

short DaysInMonth(short Year, short Month)
{
	if (Month < 1 || Month > 12)
		return 0;

	short MonthsDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? IsLeapYear(Year) ? 29 : 28 : MonthsDays[Month - 1];
}

short GetDayIndex(short Year, short Month, short Day)
{
	if (Month < 3)
	{
		Month += 12;
		Year--;
	}

	short a, y, m;

	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;

	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string MonthShortName(short MonthIndex)
{
	string ArrMonths[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun","Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

	return ArrMonths[MonthIndex - 1];
}

void HeadOfCalendar(short MonthIndex)
{
	cout << endl;

	UnderScore(15);
	cout << MonthShortName(MonthIndex);
	UnderScore(15);

	cout << "\n\n" << "Sun  " << "Mon  " << "Tue  " << "Wed  " << "Thu  " << "Fri  " << "Sat  \n";
}

void MyCalendar(short Year, short Month)
{
	HeadOfCalendar(Month);

	short NumberOfDayes = DaysInMonth(Year, Month);

	short DayIndex = GetDayIndex(Year, Month, 1);


	short j;

	cout << " ";

	for (j = 0; j < DayIndex; j++)
	{
		cout << "     ";
	}

	for (short i = 1; i <= NumberOfDayes; i++)
	{
		cout << left << setw(5) << i;

		j++;

		if (j == 7)
		{
			j = 0;

			cout << "\n ";
		}
	}
	cout << endl;
	UnderScore(33);
}

int main()
{
	short Year = ReadNum("Enter a year : ");
	short Month = ReadNum("\nEnter a month : ");

	MyCalendar(Year, Month);
}
