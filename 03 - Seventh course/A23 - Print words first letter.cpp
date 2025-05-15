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

void PrintWordsFirstLetter(string Text)
{
	bool IsFirstLetter = true;

	for (short i = 0; i < Text.length(); i++)
	{
		if (Text[i] != ' ' && IsFirstLetter)
		{
			cout << Text[i] << "\n";
		}

		IsFirstLetter = Text[i] == ' ' ? true : false;
	}

	cout << endl;
}

int main()
{
	srand((unsigned)time(NULL));

	string Text = ReadText();


	cout << "\n\nFirst letters of words :\n\n";
	PrintWordsFirstLetter(Text);
}
