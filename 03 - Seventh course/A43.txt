#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include "ManipulationLib.h"
#include "ArrayLib.h"
#include "MatrixLib.h"
#include <string>
#include "MathLib.h"

using namespace std;
using namespace nsArray;
using namespace nsMatrix;
using namespace nsManipulation;
using namespace nsMath;

enum enMatchCase { Enable = 1, Disable = 2 };

string ReadText(string Message)
{
	string Text;

	cout << Message;
	getline(cin, Text);

	return Text;
}

string MakeAllLettersSmall(string Text)
{
	for (short j = 0; j < Text.length(); j++)
	{
		Text[j] = tolower(Text[j]);
	}
	return Text;
}

vector <string> MySplit(string Text, string Delim = " ")
{
	vector <string> vWords;

	string Word = "";
	short Pos = 0;

	while ((Pos = Text.find(Delim)) != std::string::npos)
	{
		Word = Text.substr(0, Pos);

		if (!Word.empty())
		{
			vWords.push_back(Word);
		}

		Text.erase(0, Pos + Delim.length());
	}

	if (!Text.empty())
	{
		vWords.push_back(Text);
	}

	return vWords;
}

string MyJoinString(vector <string>& vWords, string Delim = " ")
{
	string Text = "";
	for (string& Element : vWords)
	{
		Text = Text + Element + Delim;
	}
	return Text.substr(0, Text.length() - Delim.length());
}

string ReplaceWord(string Text, string ReplacedWord, string ReplacingWord, enMatchCase MatchCase)
{
	vector <string> vWords = MySplit(Text);


	for (string& Element : vWords)
	{
		if (MatchCase == enMatchCase::Enable)
		{
			if (Element == ReplacedWord)
			{
				Element = ReplacingWord;
			}
			continue;
		}
		else
		{
			if (MakeAllLettersSmall(Element) == MakeAllLettersSmall(ReplacedWord))
			{
				Element = ReplacingWord;
			}
		}
	}
	return MyJoinString(vWords);
}

int main()
{
	srand((unsigned)time(NULL));

	string Text = ReadText("Enter a text : ");

	cout << "\nReplace with match case :\n" << ReplaceWord(Text, "Jordan", "USA", enMatchCase::Enable);
	cout << "\n\nReplace with no match case :\n" << ReplaceWord(Text, "Jordan", "USA", enMatchCase::Disable);

}