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

stClientData ConvertTextLineToStruct(string Text, string Delim = "##//##")
{
	stClientData ClientData;
	vector <string> vClientData;

	vClientData = SplitClientsData(Text, Delim);

	ClientData.AccountNum = vClientData[0];
	ClientData.PINCode = vClientData[1];
	ClientData.Name = vClientData[2];
	ClientData.PhoneNum = vClientData[3];
	ClientData.AccountBalance = stof(vClientData[4]);

	return ClientData;
}

vector <stClientData> LoadClientsDataLinesFromFile(string FileName = ClientsFileName)
{
	fstream FileOfClientsData;

	FileOfClientsData.open(FileName, ios::in);

	vector <stClientData> ClientsDataVector;

	if (FileOfClientsData.is_open())
	{
		string ClientDataLine;

		while (getline(FileOfClientsData, ClientDataLine))
		{
			if (!ClientDataLine.empty())
			{
				ClientsDataVector.push_back(ConvertTextLineToStruct(ClientDataLine));
			}
		}
		FileOfClientsData.close();
	}
	return ClientsDataVector;
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
	cout << "|" << setw(14) << left << ClientData.AccountNum;
	cout << "|" << setw(14) << left << ClientData.PINCode;
	cout << "|" << setw(30) << left << ClientData.Name;
	cout << "|" << setw(18) << left << ClientData.PhoneNum;
	cout << "|" << setw(18) << left << fixed << setprecision(2) << ClientData.AccountBalance << "|" << endl;
}

void PrintClientsDataInTable()
{
	vector <stClientData> ClientsDataVector;

	ClientsDataVector = LoadClientsDataLinesFromFile();

	HeaderOfTable(ClientsDataVector.size());

	for (stClientData& ClientData : ClientsDataVector)
	{
		PrintClientData(ClientData);
	}
}


int main()
{
	srand((unsigned)time(NULL));

	PrintClientsDataInTable();
}