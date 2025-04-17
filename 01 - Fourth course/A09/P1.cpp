#include <iostream>
using namespace std;

float ReadNumbers(string Message)
{
	float Num;
	do
	{
		cout << Message;
		cin >> Num;
		cout << endl;
	} while (Num < 0);

	return Num;
}

float HoursToDays(float Hours)
{
	return Hours / 24;
}

float HoursToWeeks(float Hours)
{
	return Hours / 24 / 7;
}

float DaysToWeeks(float Days)
{
	return Days / 7;
}


void PrintResult()
{
	float Hours = ReadNumbers("Enter the number of hours : ");
	float Days = HoursToDays(Hours);
	float Weeks = HoursToWeeks(Hours);

	cout << "\nTotal Hours = " << Hours << " Hour" << endl;
	cout << "\nTotal Days = " << Days << " Day" << endl;
	cout << "\nTotal Weeks = " << Weeks << " Week" << endl;
}

int main()
{
	PrintResult();
}