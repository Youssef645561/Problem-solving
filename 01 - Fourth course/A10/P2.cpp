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

float CalcMonthQuantity(float LoanAmount, float MonthlyPayment)
{
	return LoanAmount / MonthlyPayment;
}

int main()
{
	float LoanAmount = ReadNumbers("Enter loan amount : ");
	float MonthlyPayment = ReadNumbers("Enter monthly payment : ");

	cout << "Months\' quantity = " << CalcMonthQuantity(LoanAmount, MonthlyPayment) << " Months\n";

}