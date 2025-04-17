#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include "ArrayLib.h"
#include "MatrixLib.h"
#include "MathLib.h"

#include <limits>

using namespace std;
using namespace nsArray;
using namespace nsMatrix;
using namespace nsMath;

struct stClientData
{
	string AccountNum;
	string PINCode;
	string Name;
	string PhoneNum;
	float AccountBalance;
};

const string ClientsFileName = "ClientsDataFile.txt";

string ReadText(string Message)
{
	string Text;

	cout << Message;
	getline(cin >> ws, Text);

	return Text;
}

float ReadValidNum(string Message)
{
	float Num;

	cout << Message;
	cin >> Num;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "Error , enter a valid number : ";
		cin >> Num;
	}
	return Num;
}

stClientData ReadClientData(stClientData& ClientData)
{
	ClientData.AccountNum = ReadText("Enter account number : ");
	ClientData.PINCode = ReadText("Enter PIN code : ");
	ClientData.Name = ReadText("Enter name : ");
	ClientData.PhoneNum = ReadText("Enter phone number : ");
	ClientData.AccountBalance = ReadValidNum("Enter account balance : ");

	return ClientData;
}

string ConvertStructToTextLine(stClientData ClientData, string Delim = "##//##")
{
	string Text = "";

	Text += ClientData.AccountNum + Delim;
	Text += ClientData.PINCode + Delim;
	Text += ClientData.Name + Delim;
	Text += ClientData.PhoneNum + Delim;
	Text += to_string(ClientData.AccountBalance);

	return Text;
}

void AddClientDataToFile(string ClientDataLine, string FileName = ClientsFileName)
{
	fstream FileOfClientsData;

	FileOfClientsData.open(FileName, ios::out | ios::app); //Append mode

	if (FileOfClientsData.is_open())
	{
		FileOfClientsData << ClientDataLine << "\n";

		FileOfClientsData.close();
	}
}

void AddNewClient()
{
	cout << "Add new client :\n\n";

	stClientData ClientData;
	
	ClientData = ReadClientData(ClientData);

	AddClientDataToFile(ConvertStructToTextLine(ClientData));
}


void ReadAllClientsData()
{
	char AddMoreClients = 'Y';

	while (AddMoreClients == 'Y' || AddMoreClients == 'y')
	{
		system("cls");

		AddNewClient();

		cout << "\n\nClient was added successfully, do you want to add more clients (Y / N) ? ";
		cin >> AddMoreClients;
	}

}

int main()
{
	srand((unsigned)time(NULL));

	ReadAllClientsData();
}