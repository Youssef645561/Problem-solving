#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

enum enChoice { Rock = 1, Paper = 2, Scissors = 3 };
enum enWinner { Player = 1, Computer = 2, Draw = 3 };

struct stCounters { short Winning = 0, Losing = 0, Draw = 0; };

struct stGameResults 
{
	short GameRounds;
	short PlayerWinningTimes;
	short ComputerWinningTimes;
	short DrawTimes;

	enWinner Winner;
	string WinnerName;
};

struct stRoundResult
{
	short RoundIndex;

	enChoice PlayerChoice;
	enChoice ComputerChoice;

	enWinner Winner;
	string WinnerName;
};

short HowManyrounds()
{
	short HowManyRounds;

	do
	{
		cout << "How many rounds you want to play from 1 to 10?\n";
		cin >> HowManyRounds;
	} while (HowManyRounds < 1 || HowManyRounds > 10);

	return HowManyRounds;
}

void SetScreenColor(enWinner Winner)
{
	switch (Winner)
	{
	case enWinner::Player :
		system("color 2F");
		break;

	case enWinner::Computer:
		system("color 4F");
		cout << "\a";
		break;

	case enWinner::Draw:
		system("color 6F");
		break;
	}
}

void ScreenReset()
{
	system("cls");
	system("color 0F");
}

short RandomNumInRange(short From, short To)
{
	return rand() % (To - From + 1) + From;
}

enChoice ReadPlayerChoice()
{
	short PlayerChoice;

	do
	{
		cout << "Your Choice : [1]Rock. [2]Paper. [3]Scissors.? ";
		cin >> PlayerChoice;
	} while (PlayerChoice < 1 || PlayerChoice > 3);

	return (enChoice)PlayerChoice;
}

enChoice GetComputerChoice()
{
	return (enChoice)RandomNumInRange(1, 3);
}

enWinner WhoWonTheGame(stCounters Counters)
{
	if (Counters.Winning > Counters.Losing)
		return enWinner::Player;

	else if (Counters.Winning < Counters.Losing)
		return enWinner::Computer;

	else
		return enWinner::Draw;
}

enWinner WhoWonTheRound(stRoundResult RoundInfo)
{
	if (RoundInfo.PlayerChoice == RoundInfo.ComputerChoice)
		return enWinner::Draw;


	switch (RoundInfo.PlayerChoice)
	{
	case enChoice::Rock :
		if (RoundInfo.ComputerChoice == enChoice::Scissors)
			return enWinner::Player;

	case enChoice::Paper:
		if (RoundInfo.ComputerChoice == enChoice::Rock)
			return enWinner::Player;

	case enChoice::Scissors:
		if (RoundInfo.ComputerChoice == enChoice::Paper)
			return enWinner::Player;
	}

	return enWinner::Computer;
}

string WinnerName(enWinner Winner)
{
	string ArrWinner[3] = { "Player","Computer","Draw" };

	return ArrWinner[Winner - 1];
}

string choiceName(enChoice Choice)
{
	string ArrChoice[3] = { "Rock","Paper","Scissors" };

	return ArrChoice[Choice - 1];
}

void PrintGameOver()
{
	cout << "\n\n\t__________________________________________________________________________\n\n";
	cout << "\t\t\t\t+++ G a m e  O v e r +++";
	cout << "\n\t__________________________________________________________________________\n";
}

void PrintRoundResult(stRoundResult RoundInfo)
{
	cout << "\n\n___________________Round[" << RoundInfo.RoundIndex << "]___________________\n" << endl;
	cout << "Player choice : " << choiceName(RoundInfo.PlayerChoice) << endl;
	cout << "Computer choice : " << choiceName(RoundInfo.ComputerChoice) << endl;
	cout << "Winner : " << RoundInfo.WinnerName << endl;
	cout << "______________________________________________\n";

	SetScreenColor(RoundInfo.Winner);
}

void PrintFinalResult(stGameResults GameResults)
{
	cout << "\n\t_____________________________ [Game Results] _____________________________\n\n";
	cout << "\tGame rounds : " << GameResults.GameRounds << endl;
	cout << "\tPlayer winning times : " << GameResults.PlayerWinningTimes << endl;
	cout << "\tComputer winning times : " << GameResults.ComputerWinningTimes << endl;
	cout << "\tDraw times : " << GameResults.DrawTimes << endl;
	cout << "\tFinal winner : " << GameResults.WinnerName << endl;
	cout << "\t__________________________________________________________________________\n\n";
}

stGameResults FillGameResults(short HowManyRounds, stCounters Counters)
{
	stGameResults GameResults;

	GameResults.GameRounds = HowManyRounds;
	GameResults.PlayerWinningTimes = Counters.Winning;
	GameResults.ComputerWinningTimes = Counters.Losing;
	GameResults.DrawTimes = Counters.Draw;
	GameResults.Winner = WhoWonTheGame(Counters);
	GameResults.WinnerName = WinnerName(GameResults.Winner);
	
	return GameResults;
}

stGameResults GamePlay(short HowManyRounds)
{
	stRoundResult RoundInfo;

	stCounters Counters;

	for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++)
	{
		cout << "\nRound [" << GameRound << "] begins :\n\n";

		RoundInfo.RoundIndex = GameRound;
		RoundInfo.PlayerChoice = ReadPlayerChoice();
		RoundInfo.ComputerChoice = GetComputerChoice();
		RoundInfo.Winner = WhoWonTheRound(RoundInfo);
		RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);
		

		if (RoundInfo.Winner == enWinner::Player)
		{
			Counters.Winning++;
		}
		else if (RoundInfo.Winner == enWinner::Computer)
		{
			Counters.Losing++;
		}
		else
		{
			Counters.Draw++;
		}


		PrintRoundResult(RoundInfo);
	}

	return FillGameResults(HowManyRounds, Counters);
}


void StartGame()
{
	char Replay;

	do
	{
		ScreenReset();

		stGameResults GameResults = GamePlay(HowManyrounds());

		PrintGameOver();

		PrintFinalResult(GameResults);

		cout << "Do you want to play again (Y / N) ? ";
		cin >> Replay;

	} while (Replay == 'Y' || Replay == 'y');

	system("color 0F");
}


int main()
{
	srand((unsigned)time(NULL));

	StartGame();


}