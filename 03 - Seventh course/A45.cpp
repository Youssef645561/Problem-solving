#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include "ManipulationLib.h"
#include "ArrayLib.h"
#include "MatrixLib.h"
#include <string>
#include "MathLib.h"

using namespace std;
using namespace nsArray;
using namespace nsMatrix;
using namespace nsManipulation;
using namespace nsMath;

struct stClientData
{
	string AccountNum;
	string PINCode;
	string Name;
	string PhoneNum;
	float AccountBalance;
};

float ReadValidNumber(string Message)
{
	float Num;

	cout << Message;
	cin >> Num;

	while (cin.fail()) //true or false
	{
		cin.clear();

		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "\nWrong input,\nPLease enter a valid number : ";
		cin >> Num;
	}

	return Num;

}

string ReadText(string Message)
{
	string Text;

	cout << Message;
	getline(cin, Text);

	return Text;
}

stClientData ReadClientData(stClientData& ClientData)
{
	ClientData.AccountNum = ReadText("Enter account number : ");
	ClientData.PINCode = ReadText("Enter PIN code : ");
	ClientData.Name = ReadText("Enter name : ");
	ClientData.PhoneNum = ReadText("Enter phone number : ");
	ClientData.AccountBalance = ReadValidNumber("Enter account balance : ");

	return ClientData;
}

string MyJoinString(vector <string>& vWords,string Delim = "")
{
	string Text;

	for (string& Element : vWords)
	{
		Text += Element + Delim;
	}
	return Text.substr(0,Text.length() - Delim.length());
}

string ConvertStructToLine(stClientData& ClientData,string Delim = "|OOO|")
{
	string Text;
	Text += ClientData.AccountNum + Delim;
	Text += ClientData.PINCode + Delim;
	Text += ClientData.Name + Delim;
	Text += ClientData.PhoneNum + Delim;
	Text += to_string(ClientData.AccountBalance);

	return Text;
}

int main()
{
	srand((unsigned)time(NULL));
	stClientData ClientData;

	cout << "Please enter client data :\n\n";

	ClientData = ReadClientData(ClientData);

	cout << "\nClient data for saving is :\n";
	cout << ConvertStructToLine(ClientData,"#//#") << endl;
	
}