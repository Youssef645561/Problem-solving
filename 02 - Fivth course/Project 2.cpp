#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

enum enQuestionLevel { Easy = 1, Medium = 2, Hard = 3, MixedLevels = 4 };
enum enQuestionOpType { Addition = 1, Subtraction = 2, Multiplication = 3, Division = 4, MixedOpTypes };

struct stQuestion
{
	int Num1 = 0;
	int Num2 = 0;

	enQuestionLevel Level;
	enQuestionOpType OpType;

	int CorrectAnswer = 0;
	int PlayerAnswer = 0;

	bool AnswerResult = false;
};
struct stAllQuestions
{
	stQuestion QuestionsArr[100];

	enQuestionLevel GeneralLevel;
	enQuestionOpType GeneralOpType;

	short QuestionsNumber;
	short RightAnswersNum = 0;
	short WrongAnswersNum = 0;

	bool PassOrFail = false;
};

short ReadHowManyQuestions()
{
	short Num = 0;
	do
	{

		cout << "How many questions you want ? ";
		cin >> Num;

	} while (Num <= 0);

	return Num;
}

enQuestionLevel ReadQuestionsLevel()
{
	short Level = 0;

	do
	{
		cout << "\nEnter Questions Level : [1] Easy. [2] Medium. [3] Hard. [4] Mixed. ? ";
		cin >> Level;
	} while (Level < 1 || Level > 4);
	return (enQuestionLevel)Level;
}

enQuestionOpType ReadQuestionsOpType()
{
	short OpType = 0;

	do
	{
		cout << "\nEnter Questions Operation Type : [1] Addition. [2] Subtraction. [3] Multiplication. [4] Division. [5] Mixed ? ";
		cin >> OpType;
	} while (OpType < 1 || OpType > 5);

	return (enQuestionOpType)OpType;
}

short RandomNumInRange(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

int SimpleCalculator(int Num1, int Num2, enQuestionOpType OpType)
{
	switch (OpType)
	{
	case enQuestionOpType::Addition:
		return Num1 + Num2;
	case enQuestionOpType::Subtraction:
		return Num1 - Num2;
	case enQuestionOpType::Multiplication:
		return Num1 * Num2;
	case enQuestionOpType::Division:
		return (Num2 != 0) ? (Num1 / Num2) : 0;
	}
}

stQuestion GenerateSingleQuestion(enQuestionLevel GeneralLevel, enQuestionOpType GeneralOpType)
{
	stQuestion Question;

	if (GeneralLevel == enQuestionLevel::MixedLevels)
	{
		GeneralLevel = (enQuestionLevel)RandomNumInRange(1, 3);
	}

	if (GeneralOpType == enQuestionOpType::MixedOpTypes)
	{
		GeneralOpType = (enQuestionOpType)RandomNumInRange(1, 4);
	}

	Question.Level = GeneralLevel;
	Question.OpType = GeneralOpType;

	switch (Question.Level)
	{
	case enQuestionLevel::Easy:
		Question.Num1 = RandomNumInRange(1, 10);
		Question.Num2 = RandomNumInRange(1, 10);

		Question.CorrectAnswer = SimpleCalculator(Question.Num1, Question.Num2, Question.OpType);
		return Question;

	case enQuestionLevel::Medium:
		Question.Num1 = RandomNumInRange(10, 20);
		Question.Num2 = RandomNumInRange(1, 10);

		Question.CorrectAnswer = SimpleCalculator(Question.Num1, Question.Num2, Question.OpType);
		return Question;

	case enQuestionLevel::Hard:
		Question.Num1 = RandomNumInRange(50, 100);
		Question.Num2 = RandomNumInRange(50, 100);

		Question.CorrectAnswer = SimpleCalculator(Question.Num1, Question.Num2, Question.OpType);
		return Question;

	}
}

void GenerateAllQuestions(stAllQuestions& AllQuestions)
{
	for (short Question = 0; Question <= AllQuestions.QuestionsNumber; Question++)
	{
		AllQuestions.QuestionsArr[Question] = GenerateSingleQuestion(AllQuestions.GeneralLevel, AllQuestions.GeneralOpType);
	}

}

string TextOpType(enQuestionOpType OpType)
{
	string OpTypeArr[5] = { "+","-","X", "/", "Mixed"};

	return OpTypeArr[OpType - 1];
}

string TextLevel(enQuestionLevel Level)
{
	string LevelArr[4] = { "Easy","Medium","Hard","Mixed" };

	return LevelArr[Level - 1];
}

void PrintQuestion(stAllQuestions AllQuestions, short Question)
{
	cout << "\nQuestion [" << Question + 1 << "/" << AllQuestions.QuestionsNumber << "] \n\n";
	cout << AllQuestions.QuestionsArr[Question].Num1 << "\n";
	cout << AllQuestions.QuestionsArr[Question].Num2 << "  ";
	cout << TextOpType(AllQuestions.QuestionsArr[Question].OpType);
	cout << "\n_______\n";
}

int ReadPlayerAnswer()
{
	int Answer = 0;

	cin >> Answer;

	return Answer;
}

void AnswerCorrector(stAllQuestions& AllQuestions, short QuestionNum)
{
	if (AllQuestions.QuestionsArr[QuestionNum].PlayerAnswer == AllQuestions.QuestionsArr[QuestionNum].CorrectAnswer)
	{
		AllQuestions.QuestionsArr[QuestionNum].AnswerResult = true;
		AllQuestions.RightAnswersNum++;
		system("color 2F");
		cout << "Right Answer :-)\n";
	}
	else
	{
		AllQuestions.QuestionsArr[QuestionNum].AnswerResult = false;
		AllQuestions.WrongAnswersNum++;
		system("color 4F");
		cout << "Wrong Answer :-(\n";
		cout << "The right answer is : ";
		cout << AllQuestions.QuestionsArr[QuestionNum].CorrectAnswer << "\n";
	}
}

void AskPlayerCorrectAnswers(stAllQuestions& AllQuestions)
{
	for (short Question = 0; Question < AllQuestions.QuestionsNumber; Question++)
	{
		PrintQuestion(AllQuestions, Question);

		AllQuestions.QuestionsArr[Question].PlayerAnswer = ReadPlayerAnswer();

		AnswerCorrector(AllQuestions, Question);
	}

	AllQuestions.PassOrFail = (AllQuestions.RightAnswersNum >= AllQuestions.WrongAnswersNum);
}

string PassedOrFailed(bool PassedOrFailed)
{
	if (PassedOrFailed)
		return "Passed :-)";
	else
		return "Passed :-(";
}

void PrintFinalResults(stAllQuestions AllQuestions)
{
	cout << "\n_____________________________\n\n";
	cout << " Final Results is " << PassedOrFailed(AllQuestions.PassOrFail);
	cout << "\n_____________________________\n\n";

	cout << "Number of questions : " << AllQuestions.QuestionsNumber << endl;
	cout << "\nQuestions level : " << TextLevel(AllQuestions.GeneralLevel) << endl;
	cout << "\nQuestions level : " << TextOpType(AllQuestions.GeneralOpType) << endl;
	cout << "\nNumber of Right Answers : " << AllQuestions.RightAnswersNum << endl;
	cout << "\nNumber of Wrong Answers : " << AllQuestions.WrongAnswersNum  << endl;
	cout << "\n_____________________________\n\n";
}

void PlayGame()
{
	stAllQuestions AllQuestions;

	AllQuestions.QuestionsNumber = ReadHowManyQuestions();
	AllQuestions.GeneralLevel = ReadQuestionsLevel();
	AllQuestions.GeneralOpType = ReadQuestionsOpType();

	GenerateAllQuestions(AllQuestions);

	AskPlayerCorrectAnswers(AllQuestions);

	PrintFinalResults(AllQuestions);
}

void ScreenReset()
{
	system("color 0F");
	system("cls");
}

void StartGame()
{
	char Replay;

	do
	{
		ScreenReset();

		PlayGame();

		cout << endl << "Do you want to play again (Y / N) : ";
		cin >> Replay;

	} while (Replay == 'Y' || Replay == 'y');
}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();
}