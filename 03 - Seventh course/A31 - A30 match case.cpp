#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>

using namespace std;

string ReadText()
{
	string Text = "";

	cout << "Enter a text :\n";
	getline(cin >> ws, Text);


	return Text;
}

char ReadChar()
{
	char Letter;

	cout << "\nEnter a letter :\n";
	cin >> Letter;

	return Letter;
}

char InvertLetterCase(char Letter)
{
	return isupper(Letter) ? tolower(Letter) : toupper(Letter);
}

short CountLetterRepition(string Text, char LetterToCount, bool MatchCase = true)
{
	short Counter = 0;

	for (short i = 0; i < Text.length(); i++)
	{
		if (MatchCase)
		{
			if (Text[i] == LetterToCount)
			{
				Counter++;
			}
		}
		else
		{
			if (tolower(Text[i]) == tolower(LetterToCount))
			{
				Counter++;
			}
		}
	}

	return Counter;
}

int main()
{
	srand((unsigned)time(NULL));

	string Text = ReadText();
	char LetterToCount = ReadChar();


	cout << "\nLetter \'" << LetterToCount << "\' counter = " << CountLetterRepition(Text, LetterToCount);
	cout << "\nLetter \'" << LetterToCount << "\' or \'" << InvertLetterCase(LetterToCount) << "\' counter = " << CountLetterRepition(Text, LetterToCount, false) << endl;
}
