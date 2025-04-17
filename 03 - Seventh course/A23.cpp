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

void PrintWordsFirstLetter(string Text)
{
	bool IsFirstLetter = true;

	cout << "\nFirst letters of this string :\n\n";

	for (int C = 0; C < Text.length(); C++)
	{
		if (Text[C] != ' ' && IsFirstLetter)
			cout << Text[C] << "\n";

		IsFirstLetter = (Text[C] == ' ') ? true : false;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	PrintWordsFirstLetter(ReadText("Enter your string : "));
}