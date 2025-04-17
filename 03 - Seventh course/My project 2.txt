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

void ShowTransactionsMenueScreen();
/*------------------------*/

enum enMainMenueOption
{
	eShowClientList = 1,
	eAddNewClient = 2,
	eDeleteClient = 3,
	eUpdateClientData = 4,
	eFindClient = 5,
	eTransactions = 6,
	eExit = 7
};

enum enTransactionsMenueOptions
{
	eDeposite = 1,
	eWithdraw = 2,
	TotalBalances = 3,
	MainMenue = 4,

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

float ReadPossitiveValidNumber()
{
	float Num;

	cin >> Num;

	while (cin.fail() || Num < 0) //true or false
	{
		cin.clear();

		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "\nWrong input,\nPlease enter a valid number : ";
		cin >> Num;
	}

	return Num;
}

string ReadAccountNumber()
{
	string AccountNum;

	cout << "\n\nEnter account number : ";
	getline(cin >> ws, AccountNum);

	return AccountNum;
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
	cout << "\t\t\t\tClient list (" << ClientsNum << ") Client(s).\n";

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
	fstream FileOfClientsData;

	FileOfClientsData.open(FileName, ios::in);

	if (FileOfClientsData.is_open())
	{
		stClientData ClientData;
		string ClientDataLine;

		while (getline(FileOfClientsData, ClientDataLine))
		{
			if (!ClientDataLine.empty())
			{
				ClientData = ConvertClientDataLineToStruct(ClientDataLine, "##//##");

				if (ClientData.AccountNum == AccountNum)
				{
					FileOfClientsData.close();
					return true;
				}

			}
		}
		FileOfClientsData.close();
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
	NewClientData.AccountBalance = ReadPossitiveValidNumber();

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
	stClientData NewClientData;
	NewClientData = ReadClientData(NewClientData);

	AddNewClientsDataToFile(ConvertStructClientDataToLine(NewClientData));
}

void ShowAddNewClientsScreen()
{
	char AddMoreClients;

	do
	{
		Hyphen(43);
		cout << "\n\tAdd new clients screen\n";
		Hyphen(43);

		cout << "\n\nAdd new client :\n\n";

		AddNewClient();

		cout << "\nClient added successfully , do you want to add more clients (Y/N) : ";
		cin >> AddMoreClients;

		if (AddMoreClients == 'Y' || AddMoreClients == 'y')
			system("cls");

	} while (AddMoreClients == 'Y' || AddMoreClients == 'y');
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

void DeleteClientByAccountNum(vector <stClientData>& vClientsData)
{
	stClientData ClientDataBeingDeleted;
	string AccountNum = ReadAccountNumber();
	char ConfirmDelete;

	if (CheckIfAccountNumExist(vClientsData, ClientDataBeingDeleted, AccountNum))
	{
		PrintClientDataIndiviually(ClientDataBeingDeleted);

		cout << "\n\nAre you sure you want to delete his client (Y/N) : ";
		cin >> ConfirmDelete;

		if (ConfirmDelete == 'Y' || ConfirmDelete == 'y')
		{
			MarkClientToDelete(vClientsData, AccountNum);
			LoadClientsDataToFile(vClientsData);
		}
	}
	else
	{
		cout << "\nClient with account number (" << AccountNum << ") is not found.";
	}
}

void ShowDeleteClientScreen()
{
	Hyphen(43);
	cout << "\n\tDelete client data screen\n";
	Hyphen(43);

	vector <stClientData> vClientsData = LoadClientsDataFromFile();

	DeleteClientByAccountNum(vClientsData);
}

void UpdateClientByAccountNum(vector <stClientData>& vClientsData, string& AccountNum)
{
	stClientData ClientDataBeingUpdated;

	char ConfirmUpdate;

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

void ShowUpdateClientDataScreen()
{
	Hyphen(43);
	cout << "\n\tUpdate client data screen\n";
	Hyphen(43);

	vector <stClientData> vClientsData = LoadClientsDataFromFile();
	string AccountNum = ReadAccountNumber();
	UpdateClientByAccountNum(vClientsData, AccountNum);
}

void ShowFindClientData()
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

void GoBackToMainMenue()
{
	cout << "\n\nPress any key to go back to main menue...";

	system("pause > 0");

	ShowMenueScreen();
}

void ShowEndScreen()
{
	Hyphen(43);
	cout << "\n\tProgram has ended :-)\n";
	Hyphen(43);
}

void SaveNewChanges(vector <stClientData>& vClientsData, stClientData& ClientData)
{
	for (stClientData& C : vClientsData)
	{
		if (C.AccountNum == ClientData.AccountNum)
		{
			C = ClientData;

			LoadClientsDataToFile(vClientsData);

			break;
		}
	}
}

void GoBackToTransactionsMenue()
{
	cout << "\n\nPress any key to go back to transactions menue...";

	system("pause > 0");

	system("cls");

	ShowTransactionsMenueScreen();
}

stClientData DeppsitAndWithdraw(stClientData& ClientData, float Transaction)
{
	char ConfirmTransaction;

	cout << "\nAre you sure you want to perform this transaction (Y/N) ?";
	cin >> ConfirmTransaction;

	if (ConfirmTransaction == 'Y' || ConfirmTransaction == 'y')
	{
		ClientData.AccountBalance += Transaction;
		return ClientData;
	}
	else
	{
		GoBackToTransactionsMenue();
	}
}

stClientData AddMoneyToAccount(stClientData& ClientData)
{
	float Deposit;

	cout << "\n\nEnter deposit amount : ";
	Deposit = ReadPossitiveValidNumber();

	return DeppsitAndWithdraw(ClientData, Deposit);
}

void DepositMoneyToAccount(vector <stClientData>& vClientsData, string& AccountNum)
{
	stClientData ClientDataBeingDeposit;

	if (CheckIfAccountNumExist(vClientsData, ClientDataBeingDeposit, AccountNum))
	{
		PrintClientDataIndiviually(ClientDataBeingDeposit);

		ClientDataBeingDeposit = AddMoneyToAccount(ClientDataBeingDeposit);

		SaveNewChanges(vClientsData, ClientDataBeingDeposit);

		cout << "\nDeposit successfully and new balance = " << ClientDataBeingDeposit.AccountBalance;

	}
	else
	{
		cout << "\nClient with account number (" << AccountNum << ") is not found.\n";

		AccountNum = ReadAccountNumber();

		DepositMoneyToAccount(vClientsData, AccountNum);
	}
}

void ShowDepositeScreen()
{
	Hyphen(43);
	cout << "\n\t\tDeposit screen\n";
	Hyphen(43);

	string AccountNum = ReadAccountNumber();
	vector <stClientData> vClientsData = LoadClientsDataFromFile();

	DepositMoneyToAccount(vClientsData, AccountNum);

}

stClientData TakeMoneyFromAccount(stClientData& ClientData)
{
	float Withdraw;

	cout << "\n\nEnter deposit amount : ";
	Withdraw = ReadPossitiveValidNumber();

	Withdraw *= -1;

	return DeppsitAndWithdraw(ClientData, Withdraw);
}

void WithdrawMoneyFromAccount(vector <stClientData>& vClientsData, string& AccountNum)
{
	stClientData ClientDataBeingWithdraw;

	if (CheckIfAccountNumExist(vClientsData, ClientDataBeingWithdraw, AccountNum))
	{
		PrintClientDataIndiviually(ClientDataBeingWithdraw);

		ClientDataBeingWithdraw = TakeMoneyFromAccount(ClientDataBeingWithdraw);

		SaveNewChanges(vClientsData, ClientDataBeingWithdraw);

		cout << "\nWithdraw successfully and new balance = " << ClientDataBeingWithdraw.AccountBalance;

	}
	else
	{
		cout << "\nClient with account number (" << AccountNum << ") is not found.\n";

		AccountNum = ReadAccountNumber();

		WithdrawMoneyFromAccount(vClientsData, AccountNum);
	}


}

void ShowWithdrawScreen()
{
	Hyphen(43);
	cout << "\n\t\tWithdraw screen\n";
	Hyphen(43);

	string AccountNum = ReadAccountNumber();
	vector <stClientData> vClientsData = LoadClientsDataFromFile();

	WithdrawMoneyFromAccount(vClientsData, AccountNum);
}

void HeaderOfTotalBalancesTable(int ClientsNum)
{
	cout << "\t\tBalances list (" << ClientsNum << ") Client(s).\n";

	UnderScore(97);
	cout << "\n\n| " << left << setw(20) << "Account number";
	cout << "| " << left << setw(50) << "Client name";
	cout << "| " << left << setw(25) << "Balance" << endl;
	UnderScore(97);
	cout << "\n" << endl;
}

void PrintClientAccountData(stClientData& ClientData)
{
	cout << "| " << left << setw(20) << ClientData.AccountNum;
	cout << "| " << left << setw(50) << ClientData.Name;
	cout << "| " << left << setw(25) << ClientData.AccountBalance << endl;
}

float PrintAcountBalancesTableBody(vector <stClientData>& vClientsData)
{
	float TotalBalances = 0;

	for (stClientData& ClientData : vClientsData)
	{
		PrintClientAccountData(ClientData);

		TotalBalances += ClientData.AccountBalance;
	}

	UnderScore(97);

	return TotalBalances;
}

void ShowTotalBalancesScreen()
{
	vector <stClientData> vClientsData = LoadClientsDataFromFile();

	HeaderOfTotalBalancesTable(vClientsData.size());

	cout << "\n\n\t\t\t\tTotal balances = " << PrintAcountBalancesTableBody(vClientsData);
	
}

void TransactionsMenueOptions(enTransactionsMenueOptions TransactionsOption)
{
	system("cls");

	switch (TransactionsOption)
	{
	case enTransactionsMenueOptions::eDeposite:
		ShowDepositeScreen();

		GoBackToTransactionsMenue();

		break;
	case enTransactionsMenueOptions::eWithdraw:
		ShowWithdrawScreen();

		GoBackToTransactionsMenue();

		break;
	case enTransactionsMenueOptions::TotalBalances:
		ShowTotalBalancesScreen();

		GoBackToTransactionsMenue();

		break;
	case enTransactionsMenueOptions::MainMenue:
		ShowMenueScreen();
	}
}

short ReadTransactionsMenueChoice()
{
	short TransactionOption;

	do
	{
		cout << "\nChoose what do you want to do [1 to 4] : ";
		TransactionOption = ReadPossitiveValidNumber();

	} while (TransactionOption < 1 || TransactionOption > 4);

	return TransactionOption;
}

void ShowTransactionsMenueScreen()
{
	Equal(43);
	cout << "\n\tTransaction menue screen\n";
	Equal(43);

	cout << "\n\t[1] Deposite.";
	cout << "\n\t[2] Withdraw.";
	cout << "\n\t[3] Total balances.";
	cout << "\n\t[4] Main menue." << endl;

	Equal(43);
	TransactionsMenueOptions((enTransactionsMenueOptions)ReadTransactionsMenueChoice());


}

void MainMenueOptions(enMainMenueOption MainMenueOption)
{
	system("cls");

	switch (MainMenueOption)
	{
	case enMainMenueOption::eShowClientList:

		PrintClientsDataList();

		GoBackToMainMenue();

		break;

	case enMainMenueOption::eAddNewClient:

		ShowAddNewClientsScreen();

		GoBackToMainMenue();

		break;

	case enMainMenueOption::eDeleteClient:

		ShowDeleteClientScreen();

		cout << "\n\nClient was deleted successfully.";

		GoBackToMainMenue();

		break;

	case enMainMenueOption::eUpdateClientData:

		ShowUpdateClientDataScreen();

		cout << "\n\nClient was updated successfully.";

		GoBackToMainMenue();

		break;

	case enMainMenueOption::eFindClient:

		ShowFindClientData();

		GoBackToMainMenue();

		break;


	case enMainMenueOption::eTransactions:

		ShowTransactionsMenueScreen();

		break;

	case enMainMenueOption::eExit:

		ShowEndScreen();

		break;
	}
}

short ReadMainMenueChoice()
{
	short Choice;

	do
	{
		cout << "\nChoose What do you want to do [1 to 7] : ";
		Choice = ReadPossitiveValidNumber();

	} while (Choice < 1 || Choice > 7);

	return Choice;
}

void ShowMenueScreen()
{
	system("cls");

	Equal(50);
	cout << "\n\t\tMain menue screen\n";
	Equal(50);
	cout << "\n\t[1] Show client list.";
	cout << "\n\t[2] Add new client.";
	cout << "\n\t[3] Delete client.";
	cout << "\n\t[4] Update client data.";
	cout << "\n\t[5] Find client.";
	cout << "\n\t[6] Transactions.";
	cout << "\n\t[7] Exit.\n";
	Equal(50);

	MainMenueOptions((enMainMenueOption)ReadMainMenueChoice());
}

int main()
{
	ShowMenueScreen();
}