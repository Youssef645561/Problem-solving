#include <iostream>
using namespace std;

int ReadTotalSales()
{
	int TotalSales;

	cout << "Enter your total sales : ";
	cin >> TotalSales;

	return TotalSales;
}

float PercentageTotalSales(int TotalSales)
{
		if (TotalSales >= 1000000)
			return 0.01;

		else if (TotalSales >= 500000)
			return 0.02;

		else if (TotalSales >= 100000)
			return 0.03;

		else if (TotalSales >= 50000)
			return 0.05;

		else
			return 0.00;
}

float CalcCommissionTotalSales(int TotalSales)
{
	return TotalSales * PercentageTotalSales(TotalSales);
}

int main()
{
	int TotalSales = ReadTotalSales();

	cout << "\nYour percentage in total sales = " << PercentageTotalSales(TotalSales) << endl;
	cout << "Your commission total sales = " << CalcCommissionTotalSales(TotalSales) << endl;
}