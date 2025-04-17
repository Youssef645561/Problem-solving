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

float CalcRemainder(float TotalBill, float CashPaid)
{
	return CashPaid - TotalBill;
}

int main()
{
	float TotalBill = ReadNumbers("Please enter total bill value : ");
	float CashPaid = ReadNumbers("Please enter cash paid value : ");

	cout << endl;
	cout << "Total bill = " << TotalBill << endl;
	cout << "\nCash paid = " << CashPaid << endl;
	cout << "**********************" << endl;
	cout << "\nRemainder = " << CalcRemainder(TotalBill, CashPaid) << endl;
}