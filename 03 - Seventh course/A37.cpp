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
		Word = Text.substr(0,Pos);

		if (!Word.empty())
		{
			vWords.push_back(Word);
		}

		Text.erase(0,Pos + Delim.length());
	}

	if (!Text.empty())
	{
		vWords.push_back(Text);
	}

	return vWords;
}

int main()
{
	srand((unsigned)time(NULL));

	string Text = ReadText("Enter a text : ");
	vector <string> vWords = MySplit(Text," ");

	cout << "\nTokens = " << vWords.size();
	cout << endl;
	for (string& Word : vWords)
	{
		cout << Word << endl;
	}

}