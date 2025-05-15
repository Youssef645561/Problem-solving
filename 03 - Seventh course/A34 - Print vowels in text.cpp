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

bool IsLetterVowel(char Letter)
{
	Letter = tolower(Letter);

	return (Letter == 'a' || Letter == 'e' || Letter == 'i' || Letter == 'o' || Letter == 'u');
}

void PrintVowelsInText(string Text)
{
	short Counter = 0;

	for (short i = 0; i < Text.length(); i++)
	{
		if (IsLetterVowel(Text[i]))
		{
			cout << Text[i] << "\t";
		}
	}

	cout << endl;
}

int main()
{
	srand((unsigned)time(NULL));

	string Text = ReadText();


	cout << "\nVowels in the text are :\n";
	PrintVowelsInText(Text);
}
