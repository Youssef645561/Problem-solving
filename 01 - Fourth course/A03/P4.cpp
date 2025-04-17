#include <iostream>
using namespace std;

void Read_numbers(float Numbers[2])
{
	for (int Counter = 1; Counter <= 2; Counter++)
	{
		cout << "Enter number [" << Counter << "] : ";
		cin >> Numbers[Counter - 1];
	}
}

void Swap(float Numbers[2])
{
	float Temp;
	Temp = Numbers[0];
	Numbers[0] = Numbers[1];
	Numbers[1] = Temp;
}

void Print(float Numbers[2])
{
	cout << "\nNumber 1 before = " << Numbers[0];
	cout << "\nNumber 2 before = " << Numbers[1] << endl;
	Swap(Numbers);
	cout << "\nNumber 1 after = " << Numbers[0];
	cout << "\nNumber 2 after = " << Numbers[1] << endl;
}

int main()
{
	float Numbers[2];
	Read_numbers(Numbers);
	Print(Numbers);
}