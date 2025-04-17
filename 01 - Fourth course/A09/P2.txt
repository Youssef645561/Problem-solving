#include <iostream>
using namespace std;

struct stTime 
{
	float Seconds;
	float Minutes;
	float Hours;
	float Days;
};

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

stTime ReadTaskDuration()
{
	stTime Time;
	Time.Days = ReadNumbers("Enter the number of Days : ");
	Time.Hours = ReadNumbers("Enter the number of Hours : ");
	Time.Minutes = ReadNumbers("Enter the number of Minutes : ");
	Time.Seconds = ReadNumbers("Enter the number of Seconds : ");

	return Time;
}

float TaskDurationInSeconds(stTime Time)
{
	float TotalSeconds = 0;

	TotalSeconds =  Time.Days * 24 * 60 * 60;
	TotalSeconds += Time.Hours * 60 * 60;
	TotalSeconds += Time.Minutes * 60;
	TotalSeconds += Time.Seconds;

	return TotalSeconds;
}

int main()
{
	cout << "You have worked for " << TaskDurationInSeconds(ReadTaskDuration()) << " Seconds" << endl;
}