#include <iostream>
using namespace std;

int ReadNumber()
{
	int Number;
	cout << "Enter a number between 18 and 45 : ";
	cin >> Number;

	return Number;
}

bool CheckValidation(int From, int Number, int To)
{
	return (Number >= From && Number <= To);
}

int ReadUntilNumberBetween(int From,int To)
{
	int Number = 0;
	do
	{
		Number = ReadNumber();
	}
	while (!CheckValidation(From, Number, To));

	return Number;
}

void Print(int Number)
{
	
	cout << "\nWell done you entered a valid number [" << Number << "]\n";
}

int main()
{
	Print(ReadUntilNumberBetween(18, 45));
}




or




#include <iostream>
using namespace std;

int ReadAge()
{
	int Age;

	cout << "Enter your age (Must be between 18 and 45) : ";
	cin >> Age;
	
	return Age;
}

bool AgeValidation(int From, int Age, int To)
{
	return (Age >= From && Age <= To);
}

int RepeatUntilValidInput(int From, int Age, int To)
{
	while (!AgeValidation(From, Age, To))
	{
		cout << "\n\nInvalid age\n\nEnter your age :";
		cin >> Age;
	}
	return Age;
}

void PrintValidation(int Age)
{
	cout << "\n\nWell done you entered a valid age and it is " << Age << endl << endl;
}

int main()
{
	PrintValidation(RepeatUntilValidInput(18, ReadAge(), 45));
	
	return 0;
}