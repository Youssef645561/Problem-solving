#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

enum enOpType { Add = 1, Sub = 2, Mul = 3, Dev = 4 ,Mix = 5};

enum enLevels { Easy = 1, Med = 2, Hard = 3, Mixed = 4};

struct stFinalResults
{
	short QuestionsNumber;
	
	enLevels QuestionsLevel;	
	enOpType QuestionsOptType;

	short Right = 0;
	short Wrong = 0;
};

enOpType ReadOpType()
{
	short OpType;

	do
	{
		cout << "Enter operation type : [1] Addition [2] Subtraction [3] Multiply [4] Devide [5] Mixed ? ";
		cin >> OpType;
	} while (OpType < 1 || OpType > 5);

	return (enOpType)OpType;
}

enLevels ReadQuestionLevel()
{
	short QuizzLevel;

	do
	{
		cout << "Enter question level : [1] Easy. [2] Med. [3] Hard. [4] Mix. ? ";
		cin >> QuizzLevel;
	} while (QuizzLevel < 1 || QuizzLevel > 4);

	return (enLevels)QuizzLevel;
}

short RandomNumInRange(short From, short To)
{
	return rand() % (To - From + 1) + From;
}

short HowManyQuestions()
{
	short Num;

	do
	{
		cout << "How many questions you want ? ";
		cin >> Num;
	} while (Num <= 0);

	return Num;
}

string OpTypeMath(enOpType OpType)
{
	string ArrOpType[5] = { " + "," - "," x "," / ","Mixed"};

	return ArrOpType[OpType - 1];
}

string OpTypeText(enOpType OpType)
{
	string ArrOpType[5] = { " Addition "," Subtraction "," Multiply "," Devide ","Mixed" };

	return ArrOpType[OpType - 1];
}

string LevelText(enLevels Level)
{
	string ArrLevels[4] = { "Easy","Medium","Hard","Mixed" };

	return ArrLevels[Level - 1];
}

short Calculator(short Num1,short Num2,enOpType OpType)
{
	switch (OpType)
	{
	case enOpType::Add :
		return Num1 + Num2;

	case enOpType::Sub:
		return Num1 - Num2;

	case enOpType::Mul :
		return Num1 * Num2;

	case enOpType::Dev :
		return Num1 / Num2;
	}
}

short Quizz(enLevels Level, enOpType OpType)
{
	short From, To;

	switch (Level)
	{
	case enLevels::Easy :
		From = 1, To = 10;
		break;

	case enLevels::Med:
		From = 10, To = 20;
		break;

	case enLevels::Hard:
		From = 20, To = 100;
		break;
	}

	short Num1 = RandomNumInRange(From, To);
	short Num2 = RandomNumInRange(From, To);

	cout << "\n" << Num1 << "\n" << Num2;
	cout << " " << OpTypeMath(OpType);
	cout << "\n________\n";

	return Calculator(Num1, Num2, OpType);
}

short ReadPlayerAnswer()
{
	short Answer;

	cin >> Answer;

	return Answer;
}

bool CheckAnswer(short ComputerAnswer, short PlayerAnswer)
{
	return ComputerAnswer == PlayerAnswer;
}

void SetScreenColors(bool Result, short ComputerAnswer)
{
	if (Result)
	{
		system("color 2F");
		cout << "Right Answer :-)\n" << endl;
	}
	else
	{
		system("color 4F");
		cout << "\aWrong Answer :-(" << endl;
		cout << "\nThe right answer is : " << ComputerAnswer << endl;
	}
}

void ScreenReset()
{
	system("cls");
	system("color 0F");
}

bool IsMixedLevels(enLevels Level)
{
	return Level == enLevels::Mixed;
}

bool IsMixedOpTypes(enOpType OpType)
{
	return OpType == enOpType::Mix;
}

void IfMixed(enLevels& Level, bool MixedLevelsTest, enOpType& OpType, bool MixedOpTypesTest)
{
	if (MixedLevelsTest && MixedOpTypesTest)
	{
		Level = (enLevels)RandomNumInRange(1, 3);
		OpType = (enOpType)RandomNumInRange(1, 4);

	}
	else if (MixedLevelsTest)
	{
		Level = (enLevels)RandomNumInRange(1, 3);
	}
	else if (MixedOpTypesTest) {
		OpType = (enOpType)RandomNumInRange(1, 4);
	}

}

void PassOrFail(short Right, short Wrong)
{
	if (Right > Wrong)
	{
		cout << "PASS :-)";
		system("color 2F");
	}
	else
	{
		cout << "\aFail :-(";
		system("color 4F");
	}
}

void PrintFinalTableHead(short Right, short Wrong)
{
	cout << "\n_______________________________\n";
	cout << "\nFinal Results is ";
	PassOrFail(Right, Wrong);
	cout << "\n_______________________________\n";
}

void PrintFinalResults(stFinalResults FinalResults)
{
	PrintFinalTableHead(FinalResults.Right, FinalResults.Wrong);

	cout << "\nNumber of questions     : " << FinalResults.QuestionsNumber;
	cout << "\nQuestions level         : " << LevelText(FinalResults.QuestionsLevel);
	cout << "\nOperation type          : " << OpTypeText(FinalResults.QuestionsOptType);
	cout << "\nNumber of Right Answers : " << FinalResults.Right << endl;
	cout << "Number of Wrong Answers : " << FinalResults.Wrong << endl;
	cout << "_______________________________\n";
}


stFinalResults PrintQuestions(short HowManyQuestions, enLevels Level, enOpType OpType)
{
	stFinalResults FinalResults;

	FinalResults.QuestionsLevel = Level;
	FinalResults.QuestionsOptType = OpType;
	FinalResults.QuestionsNumber = HowManyQuestions;

	bool MixedLevelsTest = IsMixedLevels(Level);
	bool MixedOpTypesTest = IsMixedOpTypes(OpType);

	for (short QuestionNum = 1; QuestionNum <= HowManyQuestions; QuestionNum++)
	{

		IfMixed(Level, MixedLevelsTest, OpType, MixedOpTypesTest);

		cout << "\nQuestion [" << QuestionNum << "/" << HowManyQuestions << "]\n";

		short ComputerAnswer = Quizz(Level, OpType);

		short PlayerAnswer = ReadPlayerAnswer();

		bool Result = CheckAnswer(ComputerAnswer, PlayerAnswer);

		SetScreenColors(Result, ComputerAnswer);

		if (Result)
			FinalResults.Right++;
		else
			FinalResults.Wrong++;
	}
	return FinalResults;
}

void GamePlay()
{
	char Replay;

	do
	{
		ScreenReset();

		short NumberOfQuestions = HowManyQuestions();

		enLevels Level = ReadQuestionLevel();

		enOpType OpType = ReadOpType();

		PrintFinalResults(PrintQuestions(NumberOfQuestions, Level, OpType));

		cout << "\n\nDo you want to play again Y / N : ";
		cin >> Replay;
	} while (Replay == 'Y' || Replay == 'y');

	system("color 0F");
}

int main()
{
	srand((unsigned)time(NULL));

	GamePlay();
}