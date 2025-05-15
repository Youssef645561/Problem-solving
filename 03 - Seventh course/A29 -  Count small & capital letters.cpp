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

short CountSmallLetters(string Text)
{
	short Counter = 0;

	for (short i = 0; i < Text.length(); i++)
	{
		if (islower(Text[i]))
			Counter++;
	}

	return Counter;
}

short CountCapitalLetters(string Text)
{
	short Counter = 0;

	for (short i = 0; i < Text.length(); i++)
	{
		if (isupper(Text[i]))
			Counter++;

	}

	return Counter;
}

int main()
{
	srand((unsigned)time(NULL));

	string Text = ReadText();

	cout << "\nText length = " << Text.length();
	cout << "\nSmall letters number = " << CountSmallLetters(Text);
	cout << "\nCapital letters number = " << CountCapitalLetters(Text) << endl;
}
