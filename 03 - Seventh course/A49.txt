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

vector <string> SplitClientsData(string ClientDataLine, string Delim = "##//##")
{
	vector <string> vClientData;
	string Word = "";
	short Pos;

	while ((Pos = ClientDataLine.find(Delim)) != std::string::npos)
	{
		Word = ClientDataLine.substr(0, Pos);

		if (!Word.empty())
		{
			vClientData.push_back(Word);
		}

		ClientDataLine.erase(0, (Pos + Delim.length()));
	}

	if (!ClientDataLine.empty())
	{
		vClientData.push_back(ClientDataLine);
	}

	return vClientData;
}

stClientData ConvertClientDataLineToStruct(string& ClientDataLine, string Delim = "##//##")
{
	stClientData ClientData;

	vector <string> vClientData;

	vClientData = SplitClientsData(ClientDataLine, Delim);

	ClientData.AccountNum = vClientData[0];
	ClientData.PINCode = vClientData[1];
	ClientData.Name = vClientData[2];
	ClientData.PhoneNum = vClientData[3];
	ClientData.AccountBalance = stof(vClientData[4]);

	return ClientData;
}

vector <stClientData> LoadClientsDataFromFile()
{
	fstream FileOfClientsData;

	vector <stClientData> vClientsData;

	FileOfClientsData.open(ClientsFileName, ios::in);

	if (FileOfClientsData.is_open())
	{
		string ClientDataLine;

		while (getline(FileOfClientsData, ClientDataLine))
		{
			if (!ClientDataLine.empty())
			{
				vClientsData.push_back(ConvertClientDataLineToStruct(ClientDataLine));
			}
		}
		FileOfClientsData.close();
	}

	return vClientsData;
}

bool CheckIfAccountNumInVector(string& AccountNum, stClientData& ClientData)
{
	vector <stClientData> vClientsData;

	vClientsData = LoadClientsDataFromFile();

	for (stClientData& C : vClientsData)
	{
		if (C.AccountNum == AccountNum)
		{
			ClientData = C;
			return true;
		}
	}
	return false;
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

void PrintClientData(stClientData& ClientData)
{
	cout << "\nThe following are client details :\n\n";

	cout << "Account number : " << ClientData.AccountNum;
	cout << "\nPIN code : " << ClientData.PINCode;
	cout << "\nName : " << ClientData.Name;
	cout << "\nPhone number : " << ClientData.PhoneNum;
	cout << "\nAccount balance : " << fixed << setprecision(2) << ClientData.AccountBalance << endl;
}

int main()
{
	srand((unsigned)time(NULL));

	string AccountNum = ReadText("Enter account Num : ");

	stClientData ClientData;

	if (CheckIfAccountNumInVector(AccountNum, ClientData))
	{
		PrintClientData(ClientData);
	}
	else
	{
		cout << "\nClient with account number (" << AccountNum << ") is not found !" << endl;
	}

}