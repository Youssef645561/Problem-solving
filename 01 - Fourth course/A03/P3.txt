#include <iostream>
using namespace std;

void Read_numbers(float Numbers[3])
{
	for (int Counter = 1; Counter <= 3; Counter++)
	{
		cout << "Enter number [" << Counter << "] : ";
		cin >> Numbers[Counter - 1];
	}
}

float Check_greater_number(float Number[3])
{
	if (Number[0] > Number[1])
	
	{

		if (Number[0] > Number[2])
		{
			return Number[0];
		}
		else
			return Number[2];
	}

	else 

	{
		if (Number[1] > Number[2])
		{
			return Number[1];
		}
		else
		{
			return Number[2];
		}
	}
}

void Print(float Greatest)
{
	cout << "\n" << Greatest << " is the greatest" << endl;
}

int main()
{
	float Numbers[3];
	Read_numbers(Numbers);
	Print(Check_greater_number(Numbers));
}