#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

enum enReplay { Yes = 1, No = 2 };
enum enChoice { Rock = 1, Paper = 2, Scissors = 3 };

short ReadSmallNumInRange(short From, short To, string Message)
{
	short Num = 0;
	do
	{
		cout << Message;
		cin >> Num;
	} while (Num > To || Num < From);

	return Num;
}

short RandomNumberInRange(short From, short To)
{
	short Choice = rand() % (To - From + 1) + From;

	return Choice;
}

short ReadSmallPositiveNum(string Message)
{
	short Num = 0;
	do
	{
		cout << Message;
		cin >> Num;
	} while (Num <= 0);

	return Num;
}

void GameResults(short Win, short Lose, short Equality)
{
	cout << "\n\n\t__________________________________________________________________________\n\n";
	cout << "\t\t\t\t+++ G a m e  O v e r +++";
	cout << "\n\t__________________________________________________________________________\n";
	cout << "\n\t_____________________________ [Game Results] _____________________________\n\n";
	cout << "\tGame rounds : " << Win + Lose + Equality << endl;
	cout << "\tPlayer winning times : " << Win << endl;
	cout << "\tComputer winning times : " << Lose << endl;
	cout << "\tDraw times : " << Equality << endl;
	cout << "\tFinal winner : ";

	if (Win == Lose)
		cout << "No winner";
	else if (Win > Lose)
		cout << "Player";
	else if (Lose > Win)
		cout << "Computer";

	cout << "\n\t__________________________________________________________________________\n\n";
}

enChoice PlayerChoice()
{
	short PlayerChoice;

	cout << "Your Choice : [1]Rock. [2]Paper. [3]Scissors.? ";
	cin >> PlayerChoice;

	return (enChoice)PlayerChoice;
}

enChoice ComputerChoice()
{
	enChoice ComputerChoice;

	ComputerChoice = (enChoice)RandomNumberInRange(1, 3);

	return ComputerChoice;
}

string WhoWon(enChoice Player, enChoice Computer)
{
	if (Player == Computer)
	{
		system("color 60");
		return "[No winner]";
	}
	else if (Player == enChoice::Rock && Computer == enChoice::Paper)
	{
		system("color 40");
		cout << "\a";
		return "[Computer]";
	}
	else if (Player == enChoice::Rock && Computer == enChoice::Scissors)
	{
		system("color 20");
		return "[Player]";
	}
	else if (Player == enChoice::Paper && Computer == enChoice::Rock)
	{
		system("color 20");
		return "[Player]";
	}
	else if (Player == enChoice::Paper && Computer == enChoice::Scissors)
	{
		system("color 40");
		cout << "\a";
		return "[Computer]";
	}
	else if (Player == enChoice::Scissors && Computer == enChoice::Rock)
	{
		system("color 40");
		cout << "\a";
		return "[Computer]";
	}
	else if (Player == enChoice::Scissors && Computer == enChoice::Paper)
	{
		system("color 20");
		return "[Player]";
	}
}

string PrintChoice(enChoice Choice)
{
	switch (Choice)
	{
	case enChoice::Rock:
		return "Rock";

	case enChoice::Paper:
		return "Paper";

	case enChoice::Scissors:
		return "Scissors";
	}
}

void WinningLosingTimes(short& Player, short& Computer, short& Equality, string Winner)
{
	if (Winner == "[No winner]")
		Equality++;
	else if (Winner == "[Player]")
		Player++;
	else if (Winner == "[Computer]")
		Computer++;
}

void RoundResult(enChoice Player, enChoice Computer, string Winner, short C)
{
	cout << "\n---------------Round [" << C << "]---------------\n";
	cout << "\nPlayer choice : " << PrintChoice(Player) << endl;
	cout << "Computer choice : " << PrintChoice(Computer) << endl;
	cout << "Round winner : " << Winner << endl;
	cout << "\n---------------------------------------\n";
}

void RoundNumber()
{
	short RoundNumber = ReadSmallNumInRange(1, 10, "How many rounds from 1 to 10 ?\n");

	short Win = 0, Lose = 0, Equality = 0;

	for (short C = 1; C <= RoundNumber; C++)
	{
		cout << "\nRound [" << C << "] begins :\n\n";
		enChoice Player = PlayerChoice();
		enChoice Computer = ComputerChoice();

		string Winner = WhoWon(Player, Computer);

		RoundResult(Player, Computer, Winner, C);

		WinningLosingTimes(Win, Lose, Equality, Winner);
	}
	GameResults(Win, Lose, Equality);
}

enReplay Replay()
{
	char Replay;

	cout << "Do you want to play again (Y / N) : ";
	cin >> Replay;

	if (Replay == 'Y')
	{
		cout << "\n";
		system("color 07");
		return enReplay::Yes;
	}
	else
	{
		cout << "\n";
		return enReplay::No;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	do
	{
		RoundNumber();
	} while (Replay() == enReplay::Yes);

}