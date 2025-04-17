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

float CalcMonthlyPayment(float LoanAmount, float MonthsQuantity)
{
	return LoanAmount / MonthsQuantity;
}

int main()
{
	float LoanAmount = ReadNumbers("Enter loan amount : ");
	float MonthsQuantity = ReadNumbers("Enter months\' quantity : ");

	cout << "Monthly Payment = " << CalcMonthlyPayment(LoanAmount, MonthsQuantity) << " Dollar\n";
	
}