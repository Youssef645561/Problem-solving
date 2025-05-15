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

bool IsLetterVowel(char Letter)
{
	Letter = tolower(Letter);

	return (Letter == 'a' || Letter == 'e' || Letter == 'i' || Letter == 'o' || Letter == 'u');
}

int main()
{
	srand((unsigned)time(NULL));

	char Letter = ReadChar();

	if (IsLetterVowel(Letter))
	{
		cout << "\nYes, letter \'" << Letter << "'\ is vowel." << endl;
	}
	else
	{
		cout << "\nNo, letter \'" << Letter << "'\ is not vowel." << endl;
	}
}
