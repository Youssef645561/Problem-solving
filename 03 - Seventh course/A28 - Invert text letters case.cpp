#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>

using namespace std;

string ReadText()
{
	string Text = "";

	cout << "Enter a text :\n";
	getline(cin >> ws, Text);


	return Text;
}

char InvertLetterCase(char Letter)
{
	return isupper(Letter) ? tolower(Letter) : toupper(Letter);
}

string InvertAllLettersCase(string Text)
{
	for (short i = 0; i < Text.length(); i++)
	{
		Text[i] = InvertLetterCase(Text[i]);
	}

	return Text;
}

int main()
{
	srand((unsigned)time(NULL));

	string Text = ReadText();


	cout << "\nText after case inverting :\n";
	Text = InvertAllLettersCase(Text);

	cout << Text << endl;
}
