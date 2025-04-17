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

void InvertLetterCase(char& Letter)
{
	Letter = isupper(Letter) ? tolower(Letter) : toupper(Letter);
}

void InverAllLettersCase(string& Text)
{
	for (int i = 0; i < Text.length(); i++)
	{
		InvertLetterCase(Text[i]);
	}
}

int main()
{
	srand((unsigned)time(NULL));

	string Text = ReadText("Enter your string : ");

	InverAllLettersCase(Text);

	cout << "\nText after inverting :\n\n";
	cout << Text;
	cout << endl;

}