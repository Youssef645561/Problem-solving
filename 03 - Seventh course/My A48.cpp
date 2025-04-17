#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include "ArrayLib.h"
#include "MatrixLib.h"
#include "MathLib.h"

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

void Hyphen(short Num)
{
	cout << "\n";

	for (short C = 1; C <= Num; C++)
		cout << '-';

	cout << endl;
}

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

	AddClientDataToFile(ConvertStructToTextLine(ClientData, "##//##"));
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

vector <string> SplitClientsData(string ClientData, string Delim = "##//##")
{
	vector <string> vClientData;
	string Word = "";
	short Pos;

	while ((Pos = ClientData.find(Delim)) != std::string::npos)
	{
		Word = ClientData.substr(0, Pos);
		if (!Word.empty())
		{
			vClientData.push_back(Word);
		}
		ClientData.erase(0, Pos + Delim.length());
	}

	if (!ClientData.empty())
	{
		vClientData.push_back(ClientData);
	}

	return vClientData;
}

vector <string> ReadClientsDataLinesFromFile(string FileName = ClientsFileName)
{
	vector <string> vClientsData;

	fstream FileOfClientsData;

	FileOfClientsData.open(FileName, ios::in);

	if (FileOfClientsData.is_open())
	{
		string ClientDataLine;

		while (getline(FileOfClientsData, ClientDataLine))
		{
			if (!ClientDataLine.empty())
			{
				vClientsData.push_back(ClientDataLine);
			}
		}

		FileOfClientsData.close();
	}
	return vClientsData;
}

vector <vector <string>> RecordClientsDataIntoSplitVector()
{
	vector <vector <string>> ClientsDataVector;
	vector <string> vClientsData;

	vClientsData = ReadClientsDataLinesFromFile(ClientsFileName);

	for (short i = 0; i < vClientsData.size(); i++)
	{
		ClientsDataVector.push_back(SplitClientsData(vClientsData[i], "##//##"));
	}

	return ClientsDataVector;
}

vector <stClientData> ConvertClientsDataVectorToStructVector()
{
	vector <stClientData> stClientsDataVector;
	vector <vector <string>> ClientsDataVector;

	ClientsDataVector = RecordClientsDataIntoSplitVector();

	stClientData Client;

	for (short j = 0; j < ClientsDataVector.size(); j++)
	{
		Client.AccountNum = ClientsDataVector[j][0];
		Client.PINCode = ClientsDataVector[j][1];
		Client.Name = ClientsDataVector[j][2];
		Client.PhoneNum = ClientsDataVector[j][3];
		Client.AccountBalance = stof(ClientsDataVector[j][4]);

		stClientsDataVector.push_back(Client);
	}
	return stClientsDataVector;
}


void HeaderOfTable(short ClientNum)
{
	cout << "\t\t\tClient list (" << ClientNum << ") Client(s).";

	Hyphen(100);
	cout << "|" << setw(14) << left << "Account Number";
	cout << "|" << setw(14) << left << "PIN code";
	cout << "|" << setw(30) << left << "Client name";
	cout << "|" << setw(18) << left << "Phone";
	cout << "|" << setw(18) << left << "Balance" << "|";
	Hyphen(100);
}

void PrintClientsDataInTable()
{
	vector <stClientData> stClientsDataVector;

	stClientsDataVector = ConvertClientsDataVectorToStructVector();

	HeaderOfTable(stClientsDataVector.size());

	for (stClientData stClientData : stClientsDataVector)
	{
		cout << "|" << setw(14) << left << stClientData.AccountNum;
		cout << "|" << setw(14) << left << stClientData.PINCode;
		cout << "|" << setw(30) << left << stClientData.Name;
		cout << "|" << setw(18) << left << stClientData.PhoneNum;
		cout << "|" << setw(18) << left << fixed << setprecision(2) << stClientData.AccountBalance << "|" << endl;
	}
}


int main()
{
	srand((unsigned)time(NULL));

	//ReadAllClientsData();

	PrintClientsDataInTable();
}