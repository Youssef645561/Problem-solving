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

string MyRightTrim(string& Text)
{
	for (short Pos = Text.length() - 1; Pos >= 0; Pos--)
	{
		if (Text[Pos] != ' ')
		{
			return Text.substr(0, Pos + 1);
		}
	}
	return "";
}

string MyLeftTrim(string& Text)
{
	for (short Pos = 0; Pos < Text.length(); Pos++)
	{
		if (Text[Pos] != ' ')
		{
			return Text.substr(Pos);
		}
	}
	return "";
}

string MyTrim(string& Text)
{
	string S = MyRightTrim(Text);
	return MyLeftTrim(S);
}

int main()
{
	srand((unsigned)time(NULL));

	string Text = ReadText("Enter a text : ");


	cout << "\nLeft trim : " << MyLeftTrim(Text) << "Test" << endl;
	cout << "Right trim : " << MyRightTrim(Text) << "Test" << endl;
	cout << "All trim : " << MyTrim(Text) << "Test" << endl;




}