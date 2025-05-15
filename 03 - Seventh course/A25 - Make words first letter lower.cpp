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

string MakeWordsFirstLetterLower(string Text)
{
	bool IsFirstLetter = true;

	for (short i = 0; i < Text.length(); i++)
	{
		if (Text[i] != ' ' && IsFirstLetter)
		{
			Text[i] = tolower(Text[i]);
		}

		IsFirstLetter = Text[i] == ' ' ? true : false;
	}

	return Text;
}

int main()
{
	srand((unsigned)time(NULL));

	string Text = ReadText();


	cout << "\n\nText after conversion first letters of words :\n";
	Text = MakeWordsFirstLetterLower(Text);
	cout << Text << endl;
}
