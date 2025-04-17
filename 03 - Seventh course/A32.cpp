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

char ReadChar(string Message)
{
	char Letter;

	cout << Message;
	cin >> Letter;

	return Letter;
}

bool CheckVowelLetter(char Letter)
{
	Letter = tolower(Letter);

	return ((Letter == 'a') || (Letter == 'e') || (Letter == 'i') || (Letter == 'o') || (Letter == 'u'));
}

int main()
{
	srand((unsigned)time(NULL));

	char Letter = ReadChar("Enter the letter you want to check : ");

	if (CheckVowelLetter(Letter))
	{
		cout << "\nYes,letter \'" << Letter << "\' is a vowel.";
	}
	else
	{
		cout << "\nNo,letter \'" << Letter << "\' is not a vowel.";
	}
}