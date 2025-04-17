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

vector <string> MySplit(string Text, string Delim)
{
	vector <string> vWords;
	string Word;
	short Pos;

	while ((Pos = Text.find(Delim)) != std::string::npos)
	{
		Word = Text.substr(0, Pos);

		if (!Word.empty())
		{
			vWords.push_back(Word);
		}

		Text.erase(0, Pos + Delim.length());
	}

	if (!Text.empty())
	{
		vWords.push_back(Text);
	}

	return vWords;
}

stClientData ConvertLineToStruct(string& Text, string Delim = "#//#")
{
	stClientData ClientData;
	vector <string> vClientData = MySplit(Text, Delim);

	ClientData.AccountNum = vClientData[0];
	ClientData.PINCode = vClientData[1];
	ClientData.Name = vClientData[2];
	ClientData.PhoneNum = vClientData[3];
	ClientData.AccountBalance = stof(vClientData[4]);

	return ClientData;
}

void PrintClientRecord(stClientData& ClientData)
{
	cout << "\n\nThe following is the extracted client record :\n\n";
	cout << "Account number : " << ClientData.AccountNum << "\n";
	cout << "PIN code : " << ClientData.PINCode << "\n";
	cout << "Name : " << ClientData.Name << "\n";
	cout << "Phone number : " << ClientData.PhoneNum << "\n";
	cout << "Account balance : " << ClientData.AccountBalance << endl;
}

int main()
{
	srand((unsigned)time(NULL));

	string Text = "A150#//#1234#//#Mohammed Abu-Hadhoud#//#079999#//#5270.000000";
	cout << "Line record is :\n" << Text;

	stClientData ClientData = ConvertLineToStruct(Text, "#//#");

	PrintClientRecord(ClientData);
}