#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

const string ClientsDataFileName = "ClientsDataFile.txt";

//Declaration :

void ShowATMMainMenue();

void Login();

/*------------------------*/

enum enATMMainMenueOptions
{
	eQuickWithdraw = 1,
	eNormalWithdraw = 2,
	eDeposit = 3,
	eCheckBalance = 4,
	eLogout = 5,
};

struct stClientAccount
{
	string AccountNum;
	string PINCode;
};

struct stClientData
{
	stClientAccount ClientAccount;
	string Name;
	string PhoneNum;
	double AccountBalance;
};


//Global variabls :

stClientData GlobalUser;

/*------------------------*/

string Equal(int Num)
{
	string EqualText;
	for (int i = 1; i <= Num; i++)
	{
		EqualText += '=';
	}

	return EqualText;
}

string UnderScore(int Num)
{
	string UnderScoreText;

	for (int C = 1; C <= Num; C++)
	{
		UnderScoreText += '_';
	}

	return UnderScoreText;
}

string Hyphen(int Num)
{
	string HyphenText;

	for (int C = 1; C <= Num; C++)
	{
		HyphenText += '-';
	}

	return HyphenText;
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

string ReadText(string Message)
{
	string Text;

	cout << Message;
	getline(cin >> ws, Text);

	return Text;
}

void GoBackToMainMenue()
{
	cout << "\n\nPress any key to go back to main menue...";

	system("pause > 0");

	ShowATMMainMenue();
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

	ClientData.ClientAccount.AccountNum = vClientData[0];
	ClientData.ClientAccount.PINCode = vClientData[1];
	ClientData.Name = vClientData[2];
	ClientData.PhoneNum = vClientData[3];
	ClientData.AccountBalance = stod(vClientData[4]);

	return ClientData;
}

string ConvertStructClientDataToLine(stClientData& ClientData, string Delim = "##//##")
{
	string ClientDataLine;

	ClientDataLine += ClientData.ClientAccount.AccountNum + Delim;
	ClientDataLine += ClientData.ClientAccount.PINCode + Delim;
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
			Line = ConvertStructClientDataToLine(Client);

			FileOfClientsData << Line << "\n";
		}
		FileOfClientsData.close();
	}
}
vector <stClientData> vGlobalClientsData = LoadClientsDataFromFile();

bool CheckAccountNumAndPINCode(vector <stClientData>& vClientsData)
{
	for (stClientData& Client : vClientsData)
	{
		if (Client.ClientAccount.AccountNum == GlobalUser.ClientAccount.AccountNum && Client.ClientAccount.PINCode == GlobalUser.ClientAccount.PINCode)
		{
			GlobalUser = Client;
			return true;
		}

	}

	return false;
}

stClientAccount ReadAccountNumAndPIN()
{
	stClientAccount ClientAccount;

	ClientAccount.AccountNum = ReadText("\nEnter account number : ");
	ClientAccount.PINCode = ReadText("Enter PIN code : ");

	return ClientAccount;
}

int ReadDepositAndWithdrawValue(string Message)

void DepositAndWithdraw(int Transaction)
{
	for (stClientData& Client : vGlobalClientsData)
	{
		if (Client.ClientAccount.AccountNum == GlobalUser.ClientAccount.AccountNum)
		{
			Client.AccountBalance += Transaction;
			GlobalUser = Client;
		}
	}
}

short QuickWithdrawChoice(short Choice)
{
	short Arr[] = { 0,20, 50, 100, 200, 400, 600, 800, 1000 };

	return Arr[Choice];
}

short ReadQuickWithdrawChoice()
{
	short WithdrawOption;

	do
	{
		cout << "\nChoose what do you want to do [1 to 8] : ";
		WithdrawOption = ReadPossitiveValidNumber();

	} while (WithdrawOption < 1 || WithdrawOption > 9);

	return WithdrawOption;
}

char TransactionConfirmation()
{
	char YesOrNo;
	cout << "\nAre you sure you want to perform this transaction (Y/N) : ";
	cin >> YesOrNo;

	return YesOrNo;
}

void ShowQuickWithdrawScreen()
{
	short WithdrawValue, WithdrawChoice;
	bool ExceedingBalance = false;

	do
	{
		cout << Equal(30);
		cout << "\n\tQuick withdraw\n";
		cout << Equal(30);

		cout << "\n\t[1] 20\t[2] 50\n";
		cout << "\t[3] 100\t[4] 200\n";
		cout << "\t[5] 400\t[6] 600\n";
		cout << "\t[7] 800\t[8] 1000\n";
		cout << "\t[9] Exit\n";
		cout << Equal(30);
		cout << "\nYour balance is " << GlobalUser.AccountBalance << endl;

		WithdrawChoice = ReadQuickWithdrawChoice();

		WithdrawValue = QuickWithdrawChoice(WithdrawChoice);

		ExceedingBalance = WithdrawValue > GlobalUser.AccountBalance;

		if (ExceedingBalance)
		{
			cout << "\nThe amount exceeds your balance, make another choice.\n";
			cout << "\n\nPress any key to continue...";
			system("pause > 0");
			system("cls");
		}

	} while (ExceedingBalance);

	if (WithdrawChoice != 9)
	{
		char PerformTransaction = TransactionConfirmation();

		if (PerformTransaction == 'y' || PerformTransaction == 'Y')
		{
			DepositAndWithdraw(WithdrawValue * -1);

			LoadClientsDataToFile(vGlobalClientsData);

			cout << "\nDone successfully, new balance is : " << GlobalUser.AccountBalance << endl;
		}
	}
}

void ShowNormalWithdrawScreen()
{
	bool ExceedingBalance = false;
	bool ValidWithdraw = false;
	int WithdrawValue = 0;

	do
	{
		cout << Equal(38);
		cout << "\n\tNormal withdraw screen\n";
		cout << Equal(38);

		cout << "\nYour balance is : " << GlobalUser.AccountBalance << endl;

		do
		{
			WithdrawValue = ReadDepositAndWithdrawValue("\nEnter an amount multiple of 5's : ");

		} while (WithdrawValue % 5 != 0);

		ExceedingBalance = WithdrawValue > GlobalUser.AccountBalance;

		if (ExceedingBalance)
		{
			cout << "\nThe amount exceeds your balance, make another choice.\n";
			cout << "\n\nPress any key to continue...";
			system("pause > 0");
			system("cls");
		}

	} while (ExceedingBalance);

	char PerformTransaction = TransactionConfirmation();

	if (PerformTransaction == 'y' || PerformTransaction == 'Y')
	{
		DepositAndWithdraw(WithdrawValue * -1);

		LoadClientsDataToFile(vGlobalClientsData);

		cout << "\nDone successfully, new balance is : " << GlobalUser.AccountBalance << endl;
	}
}

void ShowDepositScreen()
{
	cout << Equal(30);
	cout << "\n\tDeposit screen\n";
	cout << Equal(30);

	cout << "\nYour balance is : " << GlobalUser.AccountBalance << endl;

	int DepositValue = ReadDepositAndWithdrawValue("\nEnter the deposit amount : ");

	char PerformTransaction = TransactionConfirmation();

	if (PerformTransaction == 'y' || PerformTransaction == 'Y')
	{
		DepositAndWithdraw(DepositValue);

		LoadClientsDataToFile(vGlobalClientsData);

		cout << "\nDone successfully, new balance is : " << GlobalUser.AccountBalance << endl;
	}
}

void ShowCheckBalanceScreen()
{
	cout << Equal(36);
	cout << "\n\tCheck balance screen\n";
	cout << Equal(36);
	cout << "\nYour balance is " << GlobalUser.AccountBalance << endl;
}

void ATMMainMenueOptions(enATMMainMenueOptions ATMMainMenueOption)
{
	system("cls");

	switch (ATMMainMenueOption)
	{
	case enATMMainMenueOptions::eQuickWithdraw:

		ShowQuickWithdrawScreen();

		GoBackToMainMenue();

		break;

	case enATMMainMenueOptions::eNormalWithdraw:

		ShowNormalWithdrawScreen();

		GoBackToMainMenue();

		break;

	case enATMMainMenueOptions::eDeposit:

		ShowDepositScreen();

		GoBackToMainMenue();

		break;

	case enATMMainMenueOptions::eCheckBalance:

		ShowCheckBalanceScreen();

		GoBackToMainMenue();

		break;

	case enATMMainMenueOptions::eLogout:

		Login();

		break;
	}
}

short ReadMainMenueChoice()
{
	short Choice;

	do
	{
		cout << "\nChoose What do you want to do [1 to 5] : ";
		Choice = ReadPossitiveValidNumber();

	} while (Choice < 1 || Choice > 5);

	return Choice;
}

void ShowATMMainMenue()
{
	system("cls");

	cout << Equal(53);
	cout << "\n\t\tATM Main menue screen\n";
	cout << Equal(53);
	cout << "\n\t[1] Quick withdraw.";
	cout << "\n\t[2] Normal withdraw.";
	cout << "\n\t[3] Deposit.";
	cout << "\n\t[4] Check balance.";
	cout << "\n\t[5] Logout.\n";
	cout << Equal(53);

	ATMMainMenueOptions((enATMMainMenueOptions)ReadMainMenueChoice());
}

void LoginScreenHeader()
{
	cout << Hyphen(28);
	cout << "\n\tLogin screen\n";
	cout << Hyphen(28);
}

void Login()
{
	bool IsAccRight = false;
	vGlobalClientsData = LoadClientsDataFromFile();

	do
	{
		system("cls");

		LoginScreenHeader();

		if (IsAccRight)
		{
			cout << "\nInvalid account number/PIN code.\n";
		}

		GlobalUser.ClientAccount = ReadAccountNumAndPIN();

		IsAccRight = !CheckAccountNumAndPINCode(vGlobalClientsData);

	} while (IsAccRight);

	ShowATMMainMenue();
}

int main()
{
	Login();

}
