#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

string ReadText()
{
	string Text = "";

	cout << "Enter a text :\n";
	getline(cin >> ws, Text);


	return Text;
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

string ReverseTextWords(string Text, string Delim = " ")
{
	vector <string> vWords = MySplitText(Text, Delim);
	vector <string>::iterator vIterator = vWords.end();

	Text = "";

	while(vIterator != vWords.begin())
	{
		vIterator--;

		Text += *vIterator + Delim;
	}
	
	return Text.substr(0, (Text.length() - Delim.length()));
}

int main()
{
	srand((unsigned)time(NULL));

	string Text = ReadText();


	cout << "\n\nText after reversing words : " << ReverseTextWords(Text) << endl;
}
