#include <iostream>
using namespace std;

struct stInfo
{
	int Age;
	bool Driver_license;
};

stInfo Read_info()
{
	stInfo Info;
	cout << "Enter your age : ";
	cin >> Info.Age;
	cout << "\nEnter if you have a driver license (1 for Yes or 0 for NO) : ";
	cin >> Info.Driver_license;
	return Info;
}

bool Check_acception(stInfo Info)
{
	return (Info.Age > 21 && Info.Driver_license == 1);
}

void Print_status(stInfo Info)
{
	if (Check_acception(Info))
		cout << "\nYou are accepted\n";
	else
		cout << "\nYou are rejected\n";
}

int main()
{
	Print_status(Read_info());
}