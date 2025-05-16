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

string ReplaceWords(string Text, string WordToRemove, string WordToAppend)
{
	short Pos = 0;

	while ((Pos = Text.find(WordToRemove)) != std::string::npos)
	{
		Text = Text.replace(Pos, (WordToRemove.length()), WordToAppend);
	}

	return Text;
}

int main()
{
	srand((unsigned)time(NULL));

	string Text = ReadText("Enter a text :\n");
	string WordToRemove = ReadText("\nEnter a word to be replaced :\n");
	string WordToAppend = ReadText("Enter a word to replace :\n");

	cout << "\nText after replace words :\n" << ReplaceWords(Text, WordToRemove, WordToAppend) << endl;

}
