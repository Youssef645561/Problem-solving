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

string ReverseWordsInText(string& Text1)
{
	vector <string> vWords;
	vector <string>::iterator vIter;
	string Text2 = "";

	vWords = MySplit(Text1);

	vIter = vWords.end();

	while (vIter != vWords.begin())
	{
		vIter--;

		Text2 += *vIter + " ";
	}
	return Text2.substr(0, Text2.length() - 1);
}

int main()
{
	srand((unsigned)time(NULL));

	string Text = ReadText("Enter a text : ");

	cout << ReverseWordsInText(Text);

}