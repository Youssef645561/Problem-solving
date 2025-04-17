#include <iostream>
using namespace std;

void Read_numbers(float& Num1, float& Num2)
{
	cout << "Enter number 1 : ";
	cin >> Num1;
	cout << "\nEnter number 2 : ";
	cin >> Num2;
}

float Check_greater(float Num1, float Num2)
{
	if (Num1 > Num2)
		return Num1;
	else
		return Num2;
}

void Print(float Greater)
{
	cout << "\n" << Greater << " is greater" << endl;
}

int main()
{
	float Num1, Num2;
	Read_numbers(Num1, Num2);
	Print(Check_greater(Num1, Num2));

	return 0;
}