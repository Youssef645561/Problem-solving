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

void MakeFirstLettersCapital(string& Text)
{
	bool IsFirstLetter = true;

	for (int C = 0; C < Text.length(); C++)
	{
		if (Text[C] != ' ' && IsFirstLetter)
			Text[C] = toupper(Text[C]);

		IsFirstLetter = (Text[C] == ' ') ? true : false;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	string Text = ReadText("Enter your string : ");

	MakeFirstLettersCapital(Text);

	cout << "\nString after conversion :\n\n";
	cout << Text;
}