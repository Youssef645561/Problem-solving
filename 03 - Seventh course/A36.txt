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

short CountWordsInText(string Text)
{
	string Delim = " ";
	short Counter = 0;
	short Pos;

	while ((Pos = Text.find(Delim)) != (std::string::npos))
	{

		if (Text.substr(0, Pos) != "")
		{
			Counter++;
		}
		Text.erase(0, Pos + Delim.length());
	}

	if (Text != "")
	{
		Counter++;
	}
	return Counter;
}

int main()
{
	srand((unsigned)time(NULL));

	string Text = ReadText("Enter a text : ");

	cout << "\nNumber of text words : ";
	cout << CountWordsInText(Text);

}