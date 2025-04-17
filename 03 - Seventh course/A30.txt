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

int main()
{
	srand((unsigned)time(NULL));

	string Text = ReadText("Enter your string : ");

	char Letter = ReadChar("\nEnter a letter you want to count : ");

	short LetterFreq = LetterFrequencyInText(Text, Letter);

	if (LetterFreq != 0)
	{
		cout << "\nLetter \'" << Letter << "\' count = " << LetterFreq;
	}
	else
	{
		cout << "\nThe Letter is not exist in the text.";
	}
}