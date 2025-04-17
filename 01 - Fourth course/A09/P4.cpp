#include <iostream>
#include <cmath>
using namespace std;

enum enDaysOfWeek
{
	Sunday = 1,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday
};

int ReadNumberInRange(string Message,int From,int To)
{
	int Num;
	do
	{
		cout << Message;
		cin >> Num;
		cout << endl;
	} while (Num < From || Num > To);

	return Num;
}

enDaysOfWeek ReadDayNumber()
{
	return (enDaysOfWeek)ReadNumberInRange("Enter the number of the day from 1 to 7 : ", 1, 7);
}

string DayNumberChecker(enDaysOfWeek NumberOfDay)
{
	switch (NumberOfDay)
	{
	case enDaysOfWeek::Sunday:
		return "Sunday";

	case enDaysOfWeek::Monday:
		return "Monday";

	case enDaysOfWeek::Tuesday:
		return "Tuesday";

	case enDaysOfWeek::Wednesday:
		return "Wednesday";

	case enDaysOfWeek::Thursday:
		return "Thursday";

	case enDaysOfWeek::Friday:
		return "Friday";

	case enDaysOfWeek::Saturday:
		return "Saturday";
	
	default:
		return "Wrong Number";
	}
}


int main()
{
	cout << "The day is " << DayNumberChecker(ReadDayNumber()) << endl;
	return 0;
}