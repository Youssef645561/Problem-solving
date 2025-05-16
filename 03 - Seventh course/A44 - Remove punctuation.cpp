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

string RemovePunctuation(string Text)
{
	string RevisedText;

	for (char& Letter : Text)
	{
		if (!ispunct(Letter))
		{
			RevisedText += Letter;
		}
	}

	return RevisedText;
}

int main()
{
	srand((unsigned)time(NULL));

	string Text = ReadText("Enter a text with punctuation :\n");

	cout << "\nText after removing punctuation :\n";
	cout << RemovePunctuation(Text) << endl;
}
