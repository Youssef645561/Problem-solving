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

string MakeAllLettersLower(string Text)
{
	for (short i = 0; i < Text.length(); i++)
	{
		Text[i] = tolower(Text[i]);
	}

	return Text;
}

string MakeAllLettersUpper(string Text)
{
	for (short i = 0; i < Text.length(); i++)
	{
		Text[i] = toupper(Text[i]);
	}

	return Text;
}

int main()
{
	srand((unsigned)time(NULL));

	string Text = ReadText();


	cout << "\n\nText after lower :\n";
	Text = MakeAllLettersLower(Text);
	cout << Text << endl;


	cout << "\n\nText after upper :\n";
	Text = MakeAllLettersUpper(Text);
	cout << Text << endl;
}
