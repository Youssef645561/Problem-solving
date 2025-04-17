#include <iostream>
#include <string>
using namespace std;

string ReadPINCode(string Message)
{
	string Code;
	cout << Message;
	cin >> Code;

	return Code;
}

bool Login()
{
	string Code;

	do
	{

		Code = ReadPINCode("Enter PIN code : ");
		
		if (Code == "1234")
		{
			return 1;
		}
		else
		{
			system("color 4F");
			cout << "\nWrong PIN code." << endl;
		}

	} while (Code != "1234");

	system("color 4F");
	return 0;
}

int main()
{
	if (Login() == 1)
	{
		system("color 2F");
		cout << "\nTrue PIN code.\n" << endl;
		cout << "Your balance = 7500 Dollars" << endl;
	}
}