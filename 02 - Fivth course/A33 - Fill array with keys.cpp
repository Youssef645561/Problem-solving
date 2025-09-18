#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

enum enCharType { CapitalLetter, SmallLetter, Digit, SpecialChar };

int ReadPositiveNum(string Message)
{
	int Num;
	do
	{
		cout << Message;
		cin >> Num;
	} while (Num <= 0);

	return Num;
}

int RandomNumInRange(int From, int To)
{
	return rand() % (To - From - 1) + From;
}

char TypeOfChar(enCharType Type)
{
	switch (Type)
	{
	case enCharType::CapitalLetter:
		return RandomNumInRange(65, 90);

	case enCharType::SmallLetter:
		return RandomNumInRange(97, 122);

	case enCharType::Digit:
		return RandomNumInRange(48, 57);

	case enCharType::SpecialChar:
		return RandomNumInRange(33, 47);
	}
}

string WordGenerator(int WordLength)
{
	string Word = "";

	for (int C = 0; C < WordLength; C++)
	{
		Word += TypeOfChar(CapitalLetter);
	}
	return Word;
}

string KeyGenerator(int WordLength, int KeyLength)
{
	string Key = "";

	for (int C = 0; C < KeyLength; C++)
	{
		if (C != KeyLength - 1)
			Key = Key + WordGenerator(WordLength) + "-";
		else
			Key = Key + WordGenerator(WordLength);
	}

	return Key;
}

void FillKeyArray(string Arr[100], int ArrLength)
{
	for (int C = 0; C < ArrLength; C++)
		Arr[C] = KeyGenerator(4, 4);
}

void PrintArr(string Arr[100], int ArrLength)
{
	for (int C = 0; C < ArrLength; C++)
	{
		cout << "\nArray [" << C << "] : " << Arr[C] << "\n";

	}
}

int main()
{
	srand((unsigned)time(NULL));

	string KeyArray[100];

	int ArrLength = ReadPositiveNum("Enter the number of elements you want : ");

	FillKeyArray(KeyArray,ArrLength);

	cout << "Array of keys :\n";
	PrintArr(KeyArray, ArrLength);
}
