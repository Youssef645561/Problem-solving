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

string ReadText(string Message)
{
	string Text;

	cout << Message;
	getline(cin, Text);

	return Text;
}

void PrintWordsLineByLine(string Text)
{
	string Delim = " "; //Delimiter
	string Word = "";
	short Pos = 0;

	while((Pos = Text.find(Delim)) != Text.npos)
	{
		Word = Text.substr(0, Pos);

		if (Word != "")
		{
			cout << Word << "\n";
		}

		Text.erase(0,Pos + Delim.length());
	}

	if (Text != "")
	{
		cout << Text << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	string Text = ReadText("Enter a text : ");

	cout << "\nYour text words are :\n\n";

	PrintWordsLineByLine(Text);
}