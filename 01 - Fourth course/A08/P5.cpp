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

float CalcTotalBill(float BillValue)
{
	BillValue *= 1.1;
	BillValue *= 1.16;

	return BillValue;
}

int main()
{
	float TotalBill = ReadNumbers("Please enter bill value : ");

	cout << "Total Bill = " << TotalBill << endl;
	cout << "\nTotal Bill after service and sales tax = " << CalcTotalBill(TotalBill) << endl;
}