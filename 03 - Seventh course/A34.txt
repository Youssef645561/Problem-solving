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

void PrintAllVowelsInText(string& Text)
{
	for (short i = 0; i < Text.length(); i++)
	{
		if (CheckVowelLetter(Text[i]))
		{
			cout << Text[i] << "\t";
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));

	string Text = ReadText("Enter the letter you want to check : ");

	cout << "Vowels in the text is : ";
	PrintAllVowelsInText(Text);
}