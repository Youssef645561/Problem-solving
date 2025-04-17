#include <iostream>
using namespace std;

enum enNumber_type { Odd = 1, Even = 2 };

int Read_number()
{
	int Num;
	cout << "Enter a number : ";
	cin >> Num;
	return Num;
}

enNumber_type Check_number_type(int Num)
{
	int Fraction = Num % 2;

	if (Fraction == 0)
		return enNumber_type::Even;
	else
		return enNumber_type::Odd;
}

void Print_Number(enNumber_type Fraction)
{
	if (Fraction == enNumber_type::Even)
		cout << "\nYour number is Even\n";
	else
		cout << "\nYour number is Odd\n";
}

int main()
{
	Print_Number(Check_number_type(Read_number()));
}
