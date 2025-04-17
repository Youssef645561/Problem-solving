#include <iostream>
#include <cstdlib>
using namespace std;

enum enCharacterTypes { Digit = 1, SpecialChar, CapitalLetter, SmallLetter };

int RondomNumInRange(int From, int To)
{
	int Num = rand() % (To - From + 1) + From;

	return Num;
}

char RondomChar(enCharacterTypes Character)
{
	switch (Character)
	{
	case enCharacterTypes::CapitalLetter :
		return char(RondomNumInRange(65, 90));

	case enCharacterTypes::SmallLetter :
		return char(RondomNumInRange(97, 122));

	case enCharacterTypes::Digit :
		return char(RondomNumInRange(48, 57));

	case enCharacterTypes::SpecialChar :
		return char(RondomNumInRange(33, 47));
	}
}

int main()
{
	srand((unsigned)time(NULL));

	cout << RondomChar(enCharacterTypes::CapitalLetter) << endl;
	cout << RondomChar(enCharacterTypes::SmallLetter) << endl;
	cout << RondomChar(enCharacterTypes::SpecialChar) << endl;
	cout << RondomChar(enCharacterTypes::Digit) << endl;
}