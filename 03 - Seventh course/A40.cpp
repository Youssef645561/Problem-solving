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

string MyJoinString(vector <string>& vWords, string Delim = " ")
{
	string Text = "";
	for (string& Element : vWords)
	{
		Text = Text + Element + Delim;
	}
	return Text.substr(0, Text.length() - Delim.length());
}

string MyJoinString(string Arrwords[5], short ArrLength, string Delim = " ")
{
	string Text = "";
	for (short i = 0; i < ArrLength; i++)
	{
		Text = Text + Arrwords[i] + Delim;
	}
	return Text.substr(0, Text.length() - Delim.length());
}

int main()
{
	srand((unsigned)time(NULL));

	//string Text = ReadText("Enter a text : ");

	vector <string> vWords;

	string ArrWords[4] = { {"Hello"},{"Bye"},{"Test"},{"Try"} };

	vWords.push_back("Hello");
	vWords.push_back("Bye");
	vWords.push_back("Test");
	vWords.push_back("Try");

	cout << "Vector after join :\n" << MyJoinString(vWords, "ZZZ");

	cout << "\n\nArray after join :\n" << MyJoinString(ArrWords, 4,"nn");

}