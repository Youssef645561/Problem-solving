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

short CountWordsInText(string Text)
{
	short Counter = 0;

	string Delim = " ";
	short Pos = 0;
	string Word = "";

	while ((Pos = Text.find(Delim)) != std::string::npos)
	{
		Word = Text.substr(0, Pos);

		if (!Word.empty())
		{
			Counter++;
		}
		
		Text.erase(0, (Pos + Delim.length()));
	}

	if (!Text.empty())
	{
		Counter++;
	}

	return Counter;
}

int main()
{
	srand((unsigned)time(NULL));

	string Text = ReadText();


	cout << "\nThe number of words int the text is : " << CountWordsInText(Text) << endl;
}
