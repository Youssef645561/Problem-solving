#include <iostream>
#include <cmath>
using namespace std;

struct stTime
{
	float Seconds;
	float Minutes;
	float Hours;
	float Days;
};

int ReadNumbers(string Message)
{
	int Num;
	do
	{
		cout << Message;
		cin >> Num;
		cout << endl;
	} while (Num < 0);

	return Num;
}

stTime TaskDuration(int SecondsNumber)
{
	stTime Time;
	const int SecondsPerDay = 24 * 60 * 60;
	const int SecondsPerHour = 60 * 60;
	const int SecondsPerMinute = 60;

	Time.Days = floor(SecondsNumber / SecondsPerDay);
	int Remainder = SecondsNumber % SecondsPerDay;

	Time.Hours = floor(Remainder / SecondsPerHour);
	Remainder = Remainder % SecondsPerHour;

	Time.Minutes = floor(Remainder / SecondsPerMinute);
	Remainder = Remainder % SecondsPerMinute;

	Time.Seconds = Remainder;

	return Time;
}

void PrintResult(stTime Time)
{
	cout << Time.Days << ":" << Time.Hours << ":" << Time.Minutes << ":" << Time.Seconds << endl;
}

int main()
{
	int SecondsNumber = ReadNumbers("Enter the number of seconds : ");

	PrintResult(TaskDuration(SecondsNumber));

	return 0;
}