#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

short ReadYear()
{
	short Num;

	cout << "Enter a year : ";
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

short DaysInYear(short Year)
{
	return IsLeapYear(Year) ? 366 : 355;
}

short HoursInYear(short Year)
{
	return DaysInYear(Year) * 24;
}

int MinutesInYear(short Year)
{
	return HoursInYear(Year) * 60;
}

int SecondsInYear(short Year)
{
	return MinutesInYear(Year) * 60;
}

int main()
{
	short Year = ReadYear();

	cout << "\nNumber of days in year [" << Year << "] is " << DaysInYear(Year) << endl;
	cout << "Number of hours in year [" << Year << "] is " << HoursInYear(Year) << endl;
	cout << "Number of minutes in year [" << Year << "] is " << MinutesInYear(Year) << endl;
	cout << "Number of seconds in year [" << Year << "] is " << SecondsInYear(Year) << endl;

}
