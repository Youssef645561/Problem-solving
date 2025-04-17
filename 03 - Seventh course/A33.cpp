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

bool CheckVowelLetter(char Letter)
{
	Letter = tolower(Letter);

	return ((Letter == 'a') || (Letter == 'e') || (Letter == 'i') || (Letter == 'o') || (Letter == 'u'));
}

short HowManyVowelsInText(string& Text)
{
	short C = 0;
	for (short i = 0; i < Text.length(); i++)
	{
		if (CheckVowelLetter(Text[i]))
		{
			C++;
		}
	}
	return C;
}

int main()
{
	srand((unsigned)time(NULL));

	string Text = ReadText("Enter the letter you want to check : ");

	short VowelsNum = HowManyVowelsInText(Text);

	if (VowelsNum != 0)
	{
		cout << "\nNumber of vowels = " << VowelsNum;
	}
	else
	{
		cout << "\nThere is no vowels in the text";
	}
}