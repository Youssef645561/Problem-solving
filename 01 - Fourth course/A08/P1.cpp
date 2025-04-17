#include <iostream>
using namespace std;

enum enOperationType { Add = '+', Minus = '-', Multiply = '*', Devide = '/' };

float ReadNumber(string Massage)
{ 
	int Num;
	cout << Massage;
	cin >> Num;
	cout << endl;

	return Num;
}

enOperationType ReadOpType()
{
	char OperationType;

	cout << "Please enter operation type : ";
	cin >> OperationType;

	return (enOperationType)OperationType;
}

float Calculator(int Num1, int Num2, enOperationType OperationType)
{


	switch (OperationType)
	{
	case enOperationType::Add :
		return Num1 + Num2;

	case enOperationType::Minus :
		return Num1 - Num2;

	case enOperationType::Multiply :
		return Num1 * Num2;

	case enOperationType::Devide :

		while (Num2 == 0)
		{
			ReadNumber("\n\nZero is mustn't number,\n\nPlease enter a valid number : ");
		}

		return Num1 / Num2;
	}




}

int main()
{
	int Num1 = ReadNumber("Please enter first number : "),
		Num2 = ReadNumber("Please enter second number : ");

	enOperationType OperationType = ReadOpType();


	cout << "\nResult = " << Calculator(Num1, Num2, OperationType) << endl;

}