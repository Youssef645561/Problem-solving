#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int ReadYear()
{
	int Num;

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

int main()
{
	int Year = ReadYear();

	if (IsLeapYear(Year))
	{
		cout << "\nYes, year " << Year << " is a leap year." << endl;
	}
	else
	{
		cout << "\nNo, year " << Year << " is not a leap year." << endl;
	}
}
