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

string DayName(short DayIndex)
{
	string ArrDays[7] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };

	return ArrDays[DayIndex];
}

int main()
{
	short Year = ReadNum("Enter a year : ");
	short Month = ReadNum("\nEnter a month : ");
	short Day = ReadNum("\nEnter a day : ");

	short DayIndex = GetDayIndex(Year, Month, Day);


	cout << "\nDate : " << Day << "/" << Month << "/" << Year << endl;
	cout << "Day order : " << DayIndex;
	cout << "\nDay name : " << DayName(DayIndex) << endl;


}
