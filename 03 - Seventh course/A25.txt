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

void MakeFirstLettersSmall(string& Text)
{
	bool IsFirstLetter = true;

	for (short j = 0; j < Text.length(); j++)
	{
		if (IsFirstLetter)
		{
			Text[j] = tolower(Text[j]);
		}

		IsFirstLetter = Text[j] == ' ' ? true : false;
	}

}

int main()
{
	srand((unsigned)time(NULL));

	string Text = ReadText("Enter your string : ");

	MakeFirstLettersSmall(Text);

	cout << "\nString after conversion :\n\n";
	cout << Text;
}