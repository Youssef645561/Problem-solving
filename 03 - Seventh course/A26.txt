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

void MakeAllLettersCapital(string& Text)
{
	for (int i = 0; i < Text.length(); i++)
	{
		Text[i] = toupper(Text[i]);
	}
}

void MakeAllLettersSmall(string& Text)
{
	for (short j = 0; j < Text.length(); j++)
	{
		Text[j] = tolower(Text[j]);
	}
}

int main()
{
	srand((unsigned)time(NULL));

	string Text = ReadText("Enter your string : ");

	MakeAllLettersCapital(Text);

	cout << "\nString after upper :\n\n";
	cout << Text;


	MakeAllLettersSmall(Text);

	cout << "\n\nString after lower :\n\n";
	cout << Text;
}