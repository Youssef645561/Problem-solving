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

void InvertLetter(char& Letter)
{
	Letter = isupper(Letter) ? tolower(Letter) : toupper(Letter);
}

int main()
{
	srand((unsigned)time(NULL));

	char Letter = ReadChar("Enter your letter : ");

	InvertLetter(Letter);

	cout << "\nLetter after inverting :\n\n";
	cout << Letter;
	cout << endl;

}