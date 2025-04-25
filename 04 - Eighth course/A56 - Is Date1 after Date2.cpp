#pragma warning(disable:4996)

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <string>
#include <ctime>

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

bool IsDate1BeforDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) || (Date1.Year == Date2.Year && Date1.Month < Date2.Month) || ((Date1.Year == Date2.Year && Date1.Month == Date2.Month) && (Date1.Day < Date2.Day));
}

bool AreDateAnd1Date2Equal(stDate Date1, stDate Date2)
{
	return (Date1.Year == Date2.Year) ? (Date1.Month == Date2.Month) ? (Date1.Day == Date2.Day) : false : false;
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
	return !IsDate1BeforDate2(Date1, Date2) && !AreDateAnd1Date2Equal(Date1, Date2);
}

int main()
{
	cout << "Enter date 1 :\n";
	stDate Date1 = ReadFullDate();

	cout << "Enter date 2 :\n";
	stDate Date2 = ReadFullDate();

	if (IsDate1AfterDate2(Date1, Date2))
	{
		cout << "\nYes, Date1 is after Date2.";
	}
	else
	{
		cout << "\nNo, Date1 is not after Date2.";
	}




}
