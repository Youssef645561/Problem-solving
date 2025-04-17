#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

const string FileName = "ClientsDataFile.txt";

//Declaration :

void ShowMenueScreen();

/*------------------------*/

enum enMainMenueOption
{
	ShowClientList = 1,
	enAddNewClient = 2,
	DeleteClient = 3,
	UpdateClientData = 4,
	FindClient = 5,
	Exit = 6
};

void Equal(int Num)
{
	for (int i = 1; i <= Num; i++)
	{
		cout << '=';
	}
}

void UnderScore(int Num)
{
	for (int C = 1; C <= Num; C++)
	{
		cout << '_';
	}
}

void Hyphen(int Num)
{
	for (int C = 1; C <= Num; C++)
	{
		cout << '-';
	}
}

float ReadValidNumber()
{
	float Num;

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

struct stClientData
{
	string AccountNum;
	string PINCode;
	string Name;
	string PhoneNum;
	double AccountBalance;

	bool MarkToDelete = false;
	bool MarkToUpdate = false;
};

vector <string> SplitClientDataLine(string& ClientDataLine, string& Delim)
{
	vector <string> vClientData;
	short Pos;
	string Word;

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

	vector <string> vClientData = SplitClientDataLine(ClientDataLine, Delim);

	ClientData.AccountNum = vClientData[0];
	ClientData.PINCode = vClientData[1];
	ClientData.Name = vClientData[2];
	ClientData.PhoneNum = vClientData[3];
	ClientData.AccountBalance = stod(vClientData[4]);

	return ClientData;
}

string ConvertStructClientDataToLine(stClientData& ClientData, string Delim = "##//##")
{
	string ClientDataLine;

	ClientDataLine += ClientData.AccountNum + Delim;
	ClientDataLine += ClientData.PINCode + Delim;
	ClientDataLine += ClientData.Name + Delim;
	ClientDataLine += ClientData.PhoneNum + Delim;
	ClientDataLine += to_string(ClientData.AccountBalance);

	return ClientDataLine;
}

vector <stClientData> LoadClientsDataFromFile()
{
	vector <stClientData> vClientsData;

	fstream FileOfClientsData;

	FileOfClientsData.open(FileName, ios::in);

	if (FileOfClientsData.is_open())
	{
		string ClientDataLine;

		while (getline(FileOfClientsData, ClientDataLine))
		{
			if (!ClientDataLine.empty())
			{
				vClientsData.push_back(ConvertClientDataLineToStruct(ClientDataLine, "##//##"));
			}
		}
		FileOfClientsData.close();
	}
	return vClientsData;
}

void LoadClientsDataToFile(vector <stClientData> vClientsData)
{
	fstream FileOfClientsData;

	FileOfClientsData.open(FileName, ios::out);

	if (FileOfClientsData.is_open())
	{
		string Line;

		for (stClientData& Client : vClientsData)
		{
			if (Client.MarkToDelete == false)
			{
				Line = ConvertStructClientDataToLine(Client);

				FileOfClientsData << Line << "\n";
			}
		}
		FileOfClientsData.close();
	}
}

void PrintClientDataIndiviually(stClientData& ClientData)
{
	cout << "\nThe following are client details :\n";

	Hyphen(35);
	cout << "\nAccount number" << setw(4) << ": " << ClientData.AccountNum;
	cout << "\nPIN code" << setw(10) << ": " << ClientData.PINCode;
	cout << "\nClient name" << setw(7) << ": " << ClientData.Name;
	cout << "\nPhone number" << setw(6) << ": " << ClientData.PhoneNum;
	cout << "\nAccount balance : " << ClientData.AccountBalance << endl;
	Hyphen(35);
}

void HeaderOfClientsDataTable(int ClientsNum)
{
	cout << "\t\t\tClient list (" << ClientsNum << ") Client(s).\n";

	UnderScore(106);
	cout << "\n\n| " << setw(14) << left << "Account Number ";
	cout << "| " << setw(14) << left << "PIN code";
	cout << "| " << setw(30) << left << "Client name";
	cout << "| " << setw(18) << left << "Phone";
	cout << "| " << setw(18) << left << "Balance" << "|\n";
	UnderScore(106);
	cout << "\n" << endl;
}

void PrintClientDataInTable(stClientData& ClientData)
{
	cout << "| " << setw(14) << left << ClientData.AccountNum;
	cout << " | " << setw(14) << left << ClientData.PINCode;
	cout << "| " << setw(30) << left << ClientData.Name;
	cout << "| " << setw(18) << left << ClientData.PhoneNum;
	cout << "| " << setw(18) << left << ClientData.AccountBalance << "|\n";
}

void PrintClientsDataList()
{
	vector <stClientData> vClientsData = LoadClientsDataFromFile();

	HeaderOfClientsDataTable(vClientsData.size());

	for (stClientData& ClientData : vClientsData)
	{
		PrintClientDataInTable(ClientData);
	}
	UnderScore(106);
}

bool CheckIfAccountNumExist(vector <stClientData>& vClientsData, stClientData& ClientData, string& AccountNum)
{
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

bool CheckIfAccountNumExist(string& AccountNum)
{
	vector <stClientData> vClientsData = LoadClientsDataFromFile();

	for (stClientData& C : vClientsData)
	{
		if (C.AccountNum == AccountNum)
		{
			return true;
		}
	}
	return false;
}

stClientData ReadClientData(stClientData& NewClientData)
{
	if (NewClientData.MarkToUpdate == false)
	{
		cout << "Enter account number : ";
		getline(cin >> ws, NewClientData.AccountNum);

		while (CheckIfAccountNumExist(NewClientData.AccountNum))
		{
			cout << "Client with [" << NewClientData.AccountNum << "] already exists , enter another account number : ";
			getline(cin >> ws, NewClientData.AccountNum);
		}
	}

	cout << "\n\nEnter PIN code : ";
	getline(cin >> ws, NewClientData.PINCode);

	cout << "Enter name : ";
	getline(cin >> ws, NewClientData.Name);

	cout << "Enter phone number : ";
	getline(cin >> ws, NewClientData.PhoneNum);

	cout << "Enter account balance : ";
	NewClientData.AccountBalance = ReadValidNumber();

	return NewClientData;
}

void AddNewClientsDataToFile(string ClientData)
{
	fstream FileOfClientsData;

	FileOfClientsData.open(FileName, ios::out | ios::app);

	if (FileOfClientsData.is_open())
	{
		FileOfClientsData << ClientData << "\n";

		FileOfClientsData.close();
	}
}

void AddNewClient()
{
	char AddMoreClients;

	do
	{
		cout << "Add new client :\n\n";

		stClientData NewClientData;
		NewClientData = ReadClientData(NewClientData);

		AddNewClientsDataToFile(ConvertStructClientDataToLine(NewClientData));

		cout << "\nClient added successfully , do you want to add more clients (Y/N) : ";
		cin >> AddMoreClients;

		if (AddMoreClients == 'Y' || AddMoreClients == 'y')
			system("cls");

	} while (AddMoreClients == 'Y' || AddMoreClients == 'y');
}

void MarkClientToDelete(vector <stClientData>& vClientsData, string& AccountNum)
{
	for (stClientData& ClientData : vClientsData)
	{
		if (ClientData.AccountNum == AccountNum)
		{
			ClientData.MarkToDelete = true;
			break;
		}
	}
}

void UpdateToNewData(vector <stClientData>& vClientsData, string& AccountNum)
{
	for (stClientData& ClientData : vClientsData)
	{
		if (ClientData.AccountNum == AccountNum)
		{
			ClientData.MarkToUpdate = true;
			ClientData = ReadClientData(ClientData);
			break;
		}
	}
}

void DeleteClientScreen()
{
	Hyphen(43);
	cout << "\n\tDelete client data screen\n";
	Hyphen(43);

	vector <stClientData> vClientsData = LoadClientsDataFromFile();
	stClientData ClientDataBeingDeleted;
	string AccountNum;
	char ConfirmDelete;

	cout << "\n\nEnter account number : ";
	getline(cin >> ws, AccountNum);


	if (CheckIfAccountNumExist(vClientsData, ClientDataBeingDeleted, AccountNum))
	{
		PrintClientDataIndiviually(ClientDataBeingDeleted);

		cout << "\n\nAre you sure you want to delete his client (Y/N) : ";
		cin >> ConfirmDelete;

		if (ConfirmDelete == 'Y' || ConfirmDelete == 'y')
		{
			MarkClientToDelete(vClientsData, AccountNum);
			LoadClientsDataToFile(vClientsData);

			vClientsData = LoadClientsDataFromFile();
		}
	}
	else
	{
		cout << "\nClient with account number (" << AccountNum << ") is not found.";
	}

}

void UpdateClientDataScreen()
{
	Hyphen(43);
	cout << "\n\tUpdate client data screen\n";
	Hyphen(43);

	vector <stClientData> vClientsData = LoadClientsDataFromFile();
	stClientData ClientDataBeingUpdated;
	string AccountNum;
	char ConfirmUpdate;

	cout << "\n\nEnter account number : ";
	getline(cin >> ws, AccountNum);

	if (CheckIfAccountNumExist(vClientsData, ClientDataBeingUpdated, AccountNum))
	{
		PrintClientDataIndiviually(ClientDataBeingUpdated);

		cout << "\n\nAre you sure you want to update his client (Y/N) : ";
		cin >> ConfirmUpdate;

		if (ConfirmUpdate == 'Y' || ConfirmUpdate == 'y')
		{
			UpdateToNewData(vClientsData, AccountNum);

			LoadClientsDataToFile(vClientsData);
		}
	}
	else
	{
		cout << "\nClient with account number (" << AccountNum << ") is not found.";
	}
}

void FindClientData()
{
	Hyphen(43);
	cout << "\n\tFind client data screen\n";
	Hyphen(43);

	vector <stClientData> vClientsData = LoadClientsDataFromFile();
	stClientData ClientData;
	string AccountNum;

	cout << "\n\nEnter account number : ";
	getline(cin >> ws, AccountNum);

	if (CheckIfAccountNumExist(vClientsData, ClientData, AccountNum))
	{
		PrintClientDataIndiviually(ClientData);
	}
	else
	{
		cout << "\nClient with account number (" << AccountNum << ") is not found.";
	}
}

void MainMenueOptions(enMainMenueOption MainMenueOption)
{
	system("cls");

	switch (MainMenueOption)
	{
	case enMainMenueOption::ShowClientList:

		PrintClientsDataList();

		cout << "\n\nPress any key to go back to main menue...";

		system("pause > 0");

		system("cls");

		ShowMenueScreen();

		break;

	case enMainMenueOption::enAddNewClient:

		AddNewClient();

		cout << "\n\nPress any key to go back to main menue...";

		system("pause > 0");

		system("cls");

		ShowMenueScreen();

		break;

	case enMainMenueOption::DeleteClient:

		DeleteClientScreen();

		cout << "\n\nClient was deleted successfully.";

		cout << "\n\nPress any key to go back to main menue...";

		system("pause > 0");

		system("cls");

		ShowMenueScreen();

		break;

	case enMainMenueOption::UpdateClientData:

		UpdateClientDataScreen();

		cout << "\n\nClient was updated successfully.";

		cout << "\n\nPress any key to go back to main menue...";

		system("pause > 0");

		system("cls");

		ShowMenueScreen();

		break;

	case enMainMenueOption::FindClient:

		FindClientData();

		cout << "\n\nPress any key to go back to main menue...";

		system("pause > 0");

		system("cls");

		ShowMenueScreen();

		break;

	case enMainMenueOption::Exit:

		system("cls");

		Hyphen(43);
		cout << "\n\tProgram has ended :-)\n";
		Hyphen(43);

		break;
	}

}

short ReadMainMenueChoice()
{
	short Choice;

	do
	{
		cout << "\nChoose What do you want to do [1 to 6] : ";
		Choice = ReadValidNumber();

	} while (Choice < 1 || Choice > 6);

	return Choice;
}

void ShowMenueScreen()
{

	Equal(50);
	cout << "\n\t[1] Show client list.";
	cout << "\n\t[2] Add new client.";
	cout << "\n\t[3] Delete client.";
	cout << "\n\t[4] Update client data.";
	cout << "\n\t[5] Find client.";
	cout << "\n\t[6] Exit.\n";
	Equal(50);

	MainMenueOptions((enMainMenueOption)ReadMainMenueChoice());
}

int main()
{
	ShowMenueScreen();
}