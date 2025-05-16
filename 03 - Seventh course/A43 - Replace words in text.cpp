#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

string ReadText(string Message)
{
	string Text = "";

	cout << Message;
	getline(cin >> ws, Text);


	return Text;
}

char ReadChar(string Message)
{
	char Letter;

	cout << Message;
	cin >> Letter;

	return Letter;
}

vector <string> MySplitText(string Text, string Delim = " ")
{
	vector <string> vWords;

	short Pos = 0;
	string Word = "";

	while ((Pos = Text.find(Delim)) != std::string::npos)
	{
		Word = Text.substr(0, Pos);

		if (!Word.empty())
		{
			vWords.push_back(Word);
		}

		Text.erase(0, (Pos + Delim.length()));
	}

	if (!Text.empty())
	{
		vWords.push_back(Text);
	}

	return vWords;
}

string MyJoinText(vector <string> vWords, string Delim = " ")
{
	string Text;

	for (string& Element : vWords)
	{
		Text += Element + Delim;
	}

	return Text.substr(0, (Text.length() - Delim.length()));
}

string MakeAllLettersLower(string Text)
{
	for (short i = 0; i < Text.length(); i++)
	{
		Text[i] = tolower(Text[i]);
	}

	return Text;
}

string ReplaceWords(string Text, string WordToRemove, string WordToAppend, char MatchCase = 'N')
{
	vector <string> vWords = MySplitText(Text);

	for (string& Element : vWords)
	{
		if ((MakeAllLettersLower(Element) == MakeAllLettersLower(WordToRemove) && (MatchCase == 'N' || MatchCase == 'n')) || (Element == WordToRemove && (MatchCase == 'Y' || MatchCase == 'y')))
		{
			Element = WordToAppend;
		}
	}

	return MyJoinText(vWords);
}

int main()
{
	srand((unsigned)time(NULL));

	string Text = ReadText("Enter a text :\n");
	string WordToRemove = ReadText("\nEnter a word to be replaced :\n");
	string WordToAppend = ReadText("Enter a word to replace :\n");

	char MatchCase = ReadChar("\nDo you want to enable match case (Y / N) : ");

	cout << "\nText after replace words :\n" << ReplaceWords(Text, WordToRemove, WordToAppend, MatchCase) << endl;

}
