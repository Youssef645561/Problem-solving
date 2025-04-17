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

enum enWhatToCount { SmallLetters = 1, CapitalLetters = 2, AllLetters = 3 };

string ReadText(string Message)
{
	string Text;

	cout << Message;
	getline(cin, Text);

	return Text;
}

short LettersCounter(string& Text, enWhatToCount WhatToCount = enWhatToCount::AllLetters)
{
	if (WhatToCount == enWhatToCount::AllLetters)
		return Text.length();

	short Counter = 0;

	for (short j = 0; j < Text.length(); j++)
	{
		if (WhatToCount == enWhatToCount::CapitalLetters && isupper(Text[j]))
			Counter++;

		else if (WhatToCount == enWhatToCount::SmallLetters && islower(Text[j]))
			Counter++;
	}
	return Counter;
}

int main()
{
	srand((unsigned)time(NULL));

	string Text = ReadText("Enter your string : ");

	cout << "\nString length = ";
	cout << LettersCounter(Text, enWhatToCount::AllLetters);

	cout << "\nCapital letters count = ";
	cout << LettersCounter(Text, enWhatToCount::CapitalLetters);

	cout << "\nSmall letters count = ";
	cout << LettersCounter(Text, enWhatToCount::SmallLetters);
}