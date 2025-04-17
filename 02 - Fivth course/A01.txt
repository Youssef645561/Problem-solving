#include <iostream>
#include <string>
using namespace std;

void HeaderOfTable()
{
	cout << "\t\t Multiplication Table from 1 to 10\n" << endl;
	
	for (int C = 1; C <= 10; C++)
	{
		cout << "\t" << C;
	}
	cout << "\n------------------------------------------------------------------------------------\n";
}

string Separator(int I)
{
	if (I < 10)
		return " " + to_string(I) + "   |";
	else
		return " " + to_string(I) + "  |";
}

void TheWholeTable()
{
	HeaderOfTable();

	for (int I = 1; I <= 10; I++)
	{
		cout << Separator(I) << " ";

		for (int J = 1; J <= 10; J++)
		{

			cout << "\t" << I * J;

		}
		cout << endl;
	}
}

int main()
{
	TheWholeTable();

	return 0;
}
