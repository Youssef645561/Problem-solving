#include <iostream>
using namespace std;

enum enMonthOfYears
{
	January = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};

int ReadNumberInRange(string Message, int From, int To)
{
	int Num = 0;

	do
	{
		cout << Message;
		cin >> Num;
	} while (Num < From || Num > To);

	return Num;
}

enMonthOfYears ReadMonthNumber()
{
	return (enMonthOfYears)ReadNumberInRange("Enter the number of the month between 1 and 12 : ", 1, 12);
}

string MonthNumberChecker(enMonthOfYears MonthNumber)
{
	switch (MonthNumber)
	{
	case enMonthOfYears::January :
		return "January";

	case enMonthOfYears::February:
		return "February";

	case enMonthOfYears::March:
		return "March";

	case enMonthOfYears::April:
		return "April";

	case enMonthOfYears::May:
		return "May";

	case enMonthOfYears::June:
		return "June";

	case enMonthOfYears::July:
		return "July";

	case enMonthOfYears::August:
		return "August";

	case enMonthOfYears::September:
		return "September";

	case enMonthOfYears::October:
		return "October";

	case enMonthOfYears::November:
		return "November";

	case enMonthOfYears::December:
		return "December";

	default :
		return "Wrong number";
	}
}

int main()
{
	cout << "\nThe month is : " << MonthNumberChecker(ReadMonthNumber()) << endl;
}