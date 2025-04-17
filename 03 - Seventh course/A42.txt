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

string ReplaceWord(string& Text1, string ReplacedWord, string ReplacingWord)
{
	short Pos = 0;

	while ((Pos = Text1.find(ReplacedWord)) != std::string::npos)
	{
		Text1 = Text1.replace(Pos,ReplacedWord.length(),ReplacingWord);
	}

	return Text1;
}

int main()
{
	srand((unsigned)time(NULL));

	string Text = ReadText("Enter a text : ");

	cout << ReplaceWord(Text, "Egypt", "Poland");

}