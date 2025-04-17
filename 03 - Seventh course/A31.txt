#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "ManipulationLib.h"
#include "ArrayLib.h"
#include "MatrixLib.h"
#include <string>

using namespace std;
using namespace nsArray;
using namespace nsMatrix;
using namespace nsManipulation;

string ReadText(string Message)
{
	string Text;

	cout << Message;
	getline(cin, Text);

	return Text;
}

char ReadChar(string Message)
{
	char Letter;

	cout << Message;
	cin >> Letter;

	return Letter;
}

char InvertLetterCase(char& Letter)
{
	return Letter = isupper(Letter) ? tolower(Letter) : toupper(Letter);
}

short LetterFrequencyInText(string& Text, char& Letter)
{
	short Counter = 0;

	for (short j = 0; j < Text.length(); j++)
	{
		if (Text[j] == Letter)
		{
			Counter++;
		}
	}
	return Counter;
}

short LetterFrequencyInTextAllCases(string& Text, char Letter, short LetterFreqCase1)
{
	if (isupper(Letter))
	{
		Letter = tolower(Letter);
		return LetterFreqCase1 + LetterFrequencyInText(Text, Letter);
	}
	else if (islower(Letter))
	{
		Letter = toupper(Letter);
		return LetterFreqCase1 + LetterFrequencyInText(Text, Letter);
	}
}

int main()
{
	srand((unsigned)time(NULL));

	string Text = ReadText("Enter your string : ");

	char Letter = ReadChar("\nEnter a letter you want to count : ");

	short LetterFreq1 = LetterFrequencyInText(Text, Letter);
	short LetterFreq2 = LetterFrequencyInTextAllCases(Text, Letter, LetterFreq1);


	if (LetterFreq1 != 0)
	{
		cout << "\nLetter \'" << Letter << "\' count = " << LetterFreq1;
		cout << "\nLetter \'" << Letter << "\' or \'";
		cout << InvertLetterCase(Letter);
		cout << "\' count = " << LetterFreq2;
	}
	else
	{
		cout << "\nThe Letter is not exist in the text.";
	}
}