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

void PrintEachWordInText(string Text)
{
	string Delim = " ";
	short Pos = 0;
	string Word = "";

	while ((Pos = Text.find(Delim)) != std::string::npos)
	{
		Word = Text.substr(0, Pos);

		if (!Word.empty())
		{
			cout << Word << "\n";
		}
		
		Text.erase(0, (Pos + Delim.length()));
	}

	if (!Text.empty())
	{
		cout << Text << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	string Text = ReadText();


	cout << "\nText words are :\n";
	PrintEachWordInText(Text);

}
