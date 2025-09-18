#include <iostream>
#include <cstdlib>
using namespace std;

enum enCharacterTypes { Digit = 1, SpecialChar, CapitalLetter, SmallLetter };

int ReadPositiveNum(string Message)
{
	int Num = 0;

	do
	{
		cout << Message;
		cin >> Num;
	} while (Num <= 0);

	return Num;
}

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
string GenerateWord(short WordLength)
{
	string Word = "";

	for (int C = 1; C <= WordLength; C++)
	{
		Word = Word + RondomChar(CapitalLetter);
	}
	return Word;
}

string GenerateKey(short WordLength, short KeyLength)
{
	string Key = "";
	for (int C = 1; C <= KeyLength; C++)
	{
		Key = Key + GenerateWord(WordLength);

		if (C != KeyLength)
		Key = Key + "-";
	}
	return Key;
}

void GenerateKeys(int Num, short WordLength,short KeyLength)
{
	for (int C = 1; C <= Num; C++)
	{
		cout << "Key[" << C << "] : " << GenerateKey(WordLength,KeyLength) << "\n";
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Num = ReadPositiveNum("Enter how many keys you want : ");
	cout << "\n";
	short WordLength = ReadPositiveNum("Enter length of words you want : ");
	cout << "\n";
	short KeyLength = ReadPositiveNum("Enter length of key you want : ");
	cout << "\n";

	GenerateKeys(Num, WordLength, KeyLength);
}
