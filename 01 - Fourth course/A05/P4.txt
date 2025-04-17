#include <iostream>
using namespace std;

int ReadAge()
{
	int Age;
	cout << "Enter your age : ";
	cin >> Age;

	return Age;
}

bool ValidateAgeBetween(int From, int Number, int To)
{
	return (Number >= From && Number <= To);
}

void PrintValidation(int Age)
{
	if (ValidateAgeBetween(18, Age, 45))
		cout << "\nYour age is valid" << endl;
	else
		cout << "\nYour age is invalid" << endl;
}

int main()
{
	PrintValidation(ReadAge());
}