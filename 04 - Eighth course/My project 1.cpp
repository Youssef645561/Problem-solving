#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

const string ClientsDataFileName = "ClientsDataFile.txt";
const string UsersInfoFileName = "UsersInfoFile.txt";

//Declaration :

void ShowMenueScreen();

void ShowTransactionsMenueScreen();

void Login();

void ShowManageUsersScreen();

/*------------------------*/


//Global variabls :

short Permissions;

/*------------------------*/

enum enMainMenueOption
{
	eShowClientList = 1,
	eAddNewClient = 2,
	eDeleteClient = 3,
	eUpdateClientData = 4,
	eFindClient = 5,
	eTransactions = 6,
	eManageUsers = 7,
	eLogOut = 8
};

enum enTransactionsMenueOptions
{
	eDeposite = 1,
	eWithdraw = 2,
	TotalBalances = 3,
	MainMenue = 4,
};

enum enManageUsersMenueOptions
{
	eUsersList = 1,
	eAddNewUser = 2,
	eDeleteUser = 3,
	eUpdateUser = 4,
	eFindUser = 5,
	eMainMenue = 6
};

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

struct stUsersInfo
{
	string Username;
	string Password;
	short Permissions = -1;

	bool MarkToDelete = false;
	bool MarkToUpdate = false;
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

vector <string> MySplit(string Text, string& Delim)
{
	vector <string> vWords;
	short Pos;
	string Word;

	while ((Pos = Text.find(Delim)) != std::string::npos)
	{
		Word = Text.substr(0, Pos);

		if (!Word.empty())
		{
			vWords.push_back(Word);
		}
		Text.erase(0, (Pos + Delim.length()));
	}

	if (!Text.empty())
	{
		vWords.push_back(Text);
	}

	return vWords;
}

stClientData ConvertClientDataLineToStruct(string& ClientDataLine, string Delim = "##//##")
{
	stClientData ClientData;

	vector <string> vClientData = MySplit(ClientDataLine, Delim);

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

	FileOfClientsData.open(ClientsDataFileName, ios::in);

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

	FileOfClientsData.open(ClientsDataFileName, ios::out);

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

	FileOfClientsData.open(ClientsDataFileName, ios::in);

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

	FileOfClientsData.open(ClientsDataFileName, ios::out | ios::app);

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

void UpdateClientDataToNew(vector <stClientData>& vClientsData, string& AccountNum)
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

		cout << "\n\nAre you sure you want to update this client (Y/N) : ";
		cin >> ConfirmUpdate;

		if (ConfirmUpdate == 'Y' || ConfirmUpdate == 'y')
		{
			UpdateClientDataToNew(vClientsData, AccountNum);

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

void SaveClientDataUpdate(vector <stClientData>& vClientsData, stClientData& ClientData)
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

stClientData DepositAndWithdraw(stClientData& ClientData, float Transaction)
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

	return DepositAndWithdraw(ClientData, Deposit);
}

void DepositMoneyToAccount(vector <stClientData>& vClientsData, string& AccountNum)
{
	stClientData ClientDataBeingDeposit;

	if (CheckIfAccountNumExist(vClientsData, ClientDataBeingDeposit, AccountNum))
	{
		PrintClientDataIndiviually(ClientDataBeingDeposit);

		ClientDataBeingDeposit = AddMoneyToAccount(ClientDataBeingDeposit);

		SaveClientDataUpdate(vClientsData, ClientDataBeingDeposit);

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

	return DepositAndWithdraw(ClientData, Withdraw);
}

void WithdrawMoneyFromAccount(vector <stClientData>& vClientsData, string& AccountNum)
{
	stClientData ClientDataBeingWithdraw;

	if (CheckIfAccountNumExist(vClientsData, ClientDataBeingWithdraw, AccountNum))
	{
		PrintClientDataIndiviually(ClientDataBeingWithdraw);

		ClientDataBeingWithdraw = TakeMoneyFromAccount(ClientDataBeingWithdraw);

		SaveClientDataUpdate(vClientsData, ClientDataBeingWithdraw);

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

string ConvertUserInfoStructToLine(stUsersInfo UserInfo, string Delim = "##//##")
{
	string UserInfoLine;

	UserInfoLine += UserInfo.Username + Delim;
	UserInfoLine += UserInfo.Password + Delim;
	UserInfoLine += to_string(UserInfo.Permissions);

	return UserInfoLine;
}

stUsersInfo ConvertUserInfoLineToStruct(string UserInfoLine, string Delim = "##//##")
{
	vector <string> vUserInfo = MySplit(UserInfoLine, Delim);

	stUsersInfo UserInfo;

	UserInfo.Username = vUserInfo[0];
	UserInfo.Password = vUserInfo[1];
	UserInfo.Permissions = stoi(vUserInfo[2]);

	return UserInfo;
}

vector <stUsersInfo> LoadUsersInfoFromFile()
{
	vector <stUsersInfo> vUsersInfo;

	fstream UsersInfoFile;

	UsersInfoFile.open(UsersInfoFileName, ios::in);

	if (UsersInfoFile.is_open())
	{
		string UserInfoLine;

		while (getline(UsersInfoFile, UserInfoLine))
		{
			if (!UserInfoLine.empty())
			{
				vUsersInfo.push_back(ConvertUserInfoLineToStruct(UserInfoLine));
			}
		}

		UsersInfoFile.close();
	}

	return vUsersInfo;
}

void GoBackToManageUsersMenue()
{
	cout << "\n\nPress any key to go back to manage users menue...";

	system("pause > 0");

	ShowManageUsersScreen();
}

void UsersListHeader(short UsersNum)
{
	cout << "\t\t\t\tBalances list (" << UsersNum << ") Client(s).\n";

	UnderScore(97);
	cout << "\n\n| " << left << setw(10) << "Username";
	cout << "| " << left << setw(10) << "Password";
	cout << "| " << left << setw(10) << "Permissions" << endl;
	UnderScore(97);
	cout << "\n" << endl;
}

void PrintUserInfoInTable(stUsersInfo UserInfo)
{
	cout << "| " << left << setw(10) << UserInfo.Username;
	cout << "| " << left << setw(10) << UserInfo.Password;
	cout << "| " << left << setw(10) << UserInfo.Permissions << endl;
}

void ShowUsersList()
{
	vector <stUsersInfo> vUsersInfo = LoadUsersInfoFromFile();

	UsersListHeader(vUsersInfo.size());

	for (stUsersInfo& UserInfo : vUsersInfo)
	{
		PrintUserInfoInTable(UserInfo);
	}

	UnderScore(97);
}

void LoadUsersInfoToFile(vector <stUsersInfo> vUsersInfo)
{
	fstream FileOfUsersInfo;

	FileOfUsersInfo.open(UsersInfoFileName, ios::out);

	if (FileOfUsersInfo.is_open())
	{
		string Line;

		for (stUsersInfo& User : vUsersInfo)
		{
			if (User.MarkToDelete == false)
			{
				Line = ConvertUserInfoStructToLine(User);

				FileOfUsersInfo << Line << "\n";
			}
		}
		FileOfUsersInfo.close();
	}
}

bool CheckUsernameAndPassword(stUsersInfo& UserInfo, vector <stUsersInfo> vUsersInfo)
{
	for (stUsersInfo& User : vUsersInfo)
	{
		if (User.Username == UserInfo.Username && User.Password == UserInfo.Password)
		{
			UserInfo = User;

			return true;
		}
	}

	return false;
}

bool FindUser(string Username, vector <stUsersInfo> vUsersInfo)
{
	for (stUsersInfo& User : vUsersInfo)
	{
		if (User.Username == Username)
		{
			return true;
		}
	}

	return false;
}

bool FindUser(string Username, vector <stUsersInfo> vUsersInfo, stUsersInfo& UserInfo)
{
	for (stUsersInfo& User : vUsersInfo)
	{
		if (User.Username == Username)
		{
			UserInfo = User;
			return true;
		}
	}

	return false;
}

string ReadUsername(bool AddUser = false)
{
	string Username;

	cout << "\nEnter username : ";
	getline(cin >> ws, Username);

	if (AddUser)
	{
		vector <stUsersInfo> vUsersInfo = LoadUsersInfoFromFile();

		while (FindUser(Username, vUsersInfo))
		{
			cout << "\nUser with [" << Username << "] already exists, enter another username : ";
			getline(cin >> ws, Username);
		}
	}
	return Username;
}

string ReadPassword()
{
	string Password;

	cout << "Enter password : ";
	getline(cin >> ws, Password);

	return Password;
}

stUsersInfo ReadUsernameAndPassword(bool AddUser = false)
{
	stUsersInfo UserInfo;
	UserInfo.Username = ReadUsername(AddUser);
	UserInfo.Password = ReadPassword();

	return UserInfo;
}

short ReadPermissions()
{
	char GiveFullAccess;
	char GiveAccessTo;

	cout << "\nDo you want to give full access (Y/N) : ";
	cin >> GiveFullAccess;

	if (GiveFullAccess == 'Y' || GiveFullAccess == 'y')
	{
		return -1;
	}

	short Permissions = 0;

	cout << "\nDo you want to give access to :\n";

	cout << "\nShow client list (Y/N) : ";
	cin >> GiveAccessTo;
	if (GiveAccessTo == 'Y' || GiveAccessTo == 'y')
		Permissions += 1;

	cout << "\nAdd new client (Y/N) : ";
	cin >> GiveAccessTo;
	if (GiveAccessTo == 'Y' || GiveAccessTo == 'y')
		Permissions += 2;

	cout << "\nDelete client (Y/N) : ";
	cin >> GiveAccessTo;
	if (GiveAccessTo == 'Y' || GiveAccessTo == 'y')
		Permissions += 4;

	cout << "\nUpdate client data (Y/N) : ";
	cin >> GiveAccessTo;
	if (GiveAccessTo == 'Y' || GiveAccessTo == 'y')
		Permissions += 8;

	cout << "\nFind client (Y/N) : ";
	cin >> GiveAccessTo;
	if (GiveAccessTo == 'Y' || GiveAccessTo == 'y')
		Permissions += 16;

	cout << "\nTransactions (Y/N) : ";
	cin >> GiveAccessTo;
	if (GiveAccessTo == 'Y' || GiveAccessTo == 'y')
		Permissions += 32;

	cout << "\nManage users(Y/N) : ";
	cin >> GiveAccessTo;
	if (GiveAccessTo == 'Y' || GiveAccessTo == 'y')
		Permissions += 64;

	return Permissions;
}

stUsersInfo ReadNewUserInfo(bool AddUser = false)
{
	stUsersInfo NewUserInfo = ReadUsernameAndPassword(AddUser);


	NewUserInfo.Permissions = ReadPermissions();

	return NewUserInfo;
}

void AddNewUserInfoToFile(string UserInfoLine)
{
	fstream FileOfUsersInfo;

	FileOfUsersInfo.open(UsersInfoFileName, ios::out | ios::app);

	if (FileOfUsersInfo.is_open())
	{
		FileOfUsersInfo << UserInfoLine << "\n";

		FileOfUsersInfo.close();
	}
}

void AddNewUser()
{
	stUsersInfo NewUserInfo = ReadNewUserInfo(true);

	AddNewUserInfoToFile(ConvertUserInfoStructToLine(NewUserInfo));
}

void ShowAddNewUsersScreen()
{
	char AddMoreUsers;

	do
	{
		Hyphen(43);
		cout << "\n\tAdd new user screen\n";
		Hyphen(43);

		cout << "\n\nAdd user :\n\n";

		AddNewUser();

		cout << "\nUser added successfully , do you want to add more users (Y/N) : ";
		cin >> AddMoreUsers;

		if (AddMoreUsers == 'Y' || AddMoreUsers == 'y')
			system("cls");

	} while (AddMoreUsers == 'Y' || AddMoreUsers == 'y');
}

void MarkUserToDelete(vector <stUsersInfo>& vUsersInfo, string& Username)
{
	for (stUsersInfo& User : vUsersInfo)
	{
		if (User.Username == Username)
		{
			User.MarkToDelete = true;
			break;
		}
	}
}

void PrintUserInfoIndividually(stUsersInfo UserInfo)
{
	Hyphen(25);
	cout << "\nUsername    : " << UserInfo.Username;
	cout << "\nPassword    : " << UserInfo.Password;
	cout << "\nPermissions : " << UserInfo.Permissions << endl;
	Hyphen(25);
}

void DeleteUser(vector <stUsersInfo>& vUsersInfo)
{
	stUsersInfo UserInfo;
	string Username = ReadUsername();

	if (Username != "Admin")
	{
		if (FindUser(Username, vUsersInfo, UserInfo))
		{
			PrintUserInfoIndividually(UserInfo);

			char ConfirmDelete;

			cout << "\n\nAre you sure you want to delete this user (Y/N) : ";
			cin >> ConfirmDelete;

			if (ConfirmDelete == 'Y' || ConfirmDelete == 'y')
			{
				MarkUserToDelete(vUsersInfo, Username);
				LoadUsersInfoToFile(vUsersInfo);
			}
		}
		else
		{
			cout << "\nUser with username (" << UserInfo.Username << ") is not found.";
		}
	}
	else
	{ 
		cout << "You can not delete this user.\n";
	}
}

void ShowDeleteUserScreen()
{
	Hyphen(35);
	cout << "\n\tDelete users screen\n";
	Hyphen(35);

	vector <stUsersInfo> vUsersInfo = LoadUsersInfoFromFile();

	DeleteUser(vUsersInfo);

}

void UpdateUserInfoToNew(vector <stUsersInfo>& vUsersInfo, string& Username)
{
	for (stUsersInfo& User : vUsersInfo)
	{
		if (User.Username == Username)
		{
			User.MarkToUpdate = true;
			User = ReadUsernameAndPassword(true);
			User.Permissions = ReadPermissions();

			break;
		}
	}
}

void UpdateUserInfo(vector <stUsersInfo>& vUsersInfo, string& Username)
{
	stUsersInfo UserInfo;

	char ConfirmUpdate;

	if (FindUser(Username, vUsersInfo, UserInfo))
	{
		PrintUserInfoIndividually(UserInfo);

		cout << "\n\nAre you sure you want to update this user (Y/N) : ";
		cin >> ConfirmUpdate;

		if (ConfirmUpdate == 'Y' || ConfirmUpdate == 'y')
		{
			UpdateUserInfoToNew(vUsersInfo, Username);

			LoadUsersInfoToFile(vUsersInfo);
		}
	}
	else
	{
		cout << "\nUser with  username (" << Username << ") is not found.";
	}
}

void ShowUpdateUserScreen()
{
	Hyphen(46);
	cout << "\n\tUpdate user information screen\n";
	Hyphen(46);

	vector <stUsersInfo> vUsersInfo = LoadUsersInfoFromFile();
	string Username = ReadUsername();

	UpdateUserInfo(vUsersInfo, Username);
}

void ShowFindUserScreen()
{
	Hyphen(41);
	cout << "\n\tFind user data screen\n";
	Hyphen(41);

	vector <stUsersInfo> vUsersInfo = LoadUsersInfoFromFile();
	stUsersInfo UserInfo;

	string Username = ReadUsername();

	if (FindUser(Username, vUsersInfo, UserInfo))
	{
		PrintUserInfoIndividually(UserInfo);
	}
	else
	{
		cout << "\nClient with username (" << Username << ") is not found.";
	}
}

short ReadManageUsersChoice()
{
	short Choice;

	do
	{
		cout << "\nChoose What do you want to do [1 to 6] : ";
		Choice = ReadPossitiveValidNumber();

	} while (Choice < 1 || Choice > 6);

	return Choice;
}

void ManageUsersMenueOptions(enManageUsersMenueOptions Choice)
{
	system("cls");

	switch (Choice)
	{
	case enManageUsersMenueOptions::eUsersList:

		ShowUsersList();

		GoBackToManageUsersMenue();

		break;

	case enManageUsersMenueOptions::eAddNewUser:

		ShowAddNewUsersScreen();

		GoBackToManageUsersMenue();

		break;

	case enManageUsersMenueOptions::eDeleteUser:

		ShowDeleteUserScreen();

		GoBackToManageUsersMenue();

		break;

	case enManageUsersMenueOptions::eUpdateUser:

		ShowUpdateUserScreen();

		GoBackToManageUsersMenue();

		break;
	case enManageUsersMenueOptions::eFindUser:

		ShowFindUserScreen();

		GoBackToManageUsersMenue();

		break;
	case enManageUsersMenueOptions::eMainMenue:

		ShowMenueScreen();

		break;
	}
}

void ShowManageUsersScreen()
{
	system("cls");

	Equal(34);
	cout << "\n\tManage users menue\n";
	Equal(34);
	cout << "\n\t[1] Show useres list.";
	cout << "\n\t[2] Add new user.";
	cout << "\n\t[3] Delete user.";
	cout << "\n\t[4] Update user information.";
	cout << "\n\t[5] Find user.";
	cout << "\n\t[6] Main menue.\n";
	Equal(34);

	ManageUsersMenueOptions((enManageUsersMenueOptions)ReadManageUsersChoice());
}

void AccessDeniedMessage()
{
	system("cls");

	Hyphen(37);
	cout << "\nAccess denied,\n";
	cout << "You don't have permission to do this,\n";
	cout << "Please, contact your admin.\n";
	Hyphen(37);
}

void MainMenueOptions(enMainMenueOption MainMenueOption)
{
	system("cls");

	switch (MainMenueOption)
	{
	case enMainMenueOption::eShowClientList:

		if ((Permissions & 1) == 1 || Permissions == -1)
		{
			PrintClientsDataList();
		}
		else
		{
			AccessDeniedMessage();
		}

		GoBackToMainMenue();

		break;

	case enMainMenueOption::eAddNewClient:

		if ((Permissions & 2) == 2 || Permissions == -1)
		{
			ShowAddNewClientsScreen();
		}
		else
		{
			AccessDeniedMessage();
		}

		GoBackToMainMenue();

		break;

	case enMainMenueOption::eDeleteClient:

		if ((Permissions & 4) == 4 || Permissions == -1)
		{
			ShowDeleteClientScreen();
			cout << "\n\nClient was deleted successfully.";
		}
		else
		{
			AccessDeniedMessage();
		}

		GoBackToMainMenue();

		break;

	case enMainMenueOption::eUpdateClientData:

		if ((Permissions & 8) == 8 || Permissions == -1)
		{
			ShowUpdateClientDataScreen();

			cout << "\n\nClient was updated successfully.";
		}
		else
		{
			AccessDeniedMessage();
		}

		GoBackToMainMenue();

		break;

	case enMainMenueOption::eFindClient:

		if ((Permissions & 16) == 16 || Permissions == -1)
		{
			ShowFindClientData();
		}
		else
		{
			AccessDeniedMessage();
		}

		GoBackToMainMenue();

		break;

	case enMainMenueOption::eTransactions:

		if ((Permissions & 32) == 32 || Permissions == -1)
		{
			ShowTransactionsMenueScreen();
		}
		else
		{
			AccessDeniedMessage();
		}

		break;

	case enMainMenueOption::eManageUsers:

		if ((Permissions & 64) == 64 || Permissions == -1)
		{
			ShowManageUsersScreen();
		}
		else
		{
			AccessDeniedMessage();
		}

		break;

	case enMainMenueOption::eLogOut:

		Login();

		break;
	}
}

short ReadMainMenueChoice()
{
	short Choice;

	do
	{
		cout << "\nChoose What do you want to do [1 to 8] : ";
		Choice = ReadPossitiveValidNumber();

	} while (Choice < 1 || Choice > 8);

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
	cout << "\n\t[7] Manage users.";
	cout << "\n\t[8] Logout.\n";
	Equal(50);

	MainMenueOptions((enMainMenueOption)ReadMainMenueChoice());
}

void LoginScreenHeader()
{
	Hyphen(28);
	cout << "\n\tLogin screen\n";
	Hyphen(28);
}

void Login()
{
	system("cls");

	LoginScreenHeader();

	stUsersInfo UserInfo = ReadUsernameAndPassword();


	vector <stUsersInfo> vUsersInfo = LoadUsersInfoFromFile();

	while (!CheckUsernameAndPassword(UserInfo, vUsersInfo))
	{
		system("cls");

		cout << CheckUsernameAndPassword(UserInfo, vUsersInfo);

		LoginScreenHeader();
		cout << "\nInvalid username/password\n";
		UserInfo = ReadUsernameAndPassword();
	}

	Permissions = UserInfo.Permissions;

	ShowMenueScreen();
}

int main()
{
	Login();
	
}
