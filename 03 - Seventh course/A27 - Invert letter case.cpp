#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>

using namespace std;

char ReadChar()
{
	char Letter;

	cout << "Enter a letter :\n";
	cin >> Letter;

	return Letter;
}

char InvertLetterCase(char Letter)
{
	return isupper(Letter) ? tolower(Letter) : toupper(Letter);
}

int main()
{
	srand((unsigned)time(NULL));

	char Letter = ReadChar();


	cout << "\nLetter after case inverting :\n";
	Letter = InvertLetterCase(Letter);

	cout << Letter << endl;
}
