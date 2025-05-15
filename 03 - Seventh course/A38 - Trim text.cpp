#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

string MyTrimLeft(string Text)
{
	for (short i = 0; i < Text.length(); i++)
	{
		if (Text[i] != ' ')
		{
			return Text.substr(i);
		}
	}

	return "";
}

string MyTrimRight(string Text)
{
	for (short i = Text.length() - 1; i >= 0; i--)
	{
		if (Text[i] != ' ')
		{
			return Text.substr(0, i + 1);
		}
	}

	return "";
}

string MyTrim(string Text)
{
	return MyTrimRight(MyTrimLeft(Text));
}

int main()
{
	srand((unsigned)time(NULL));

	string Text = "    Youssef Ahmed    ";

	cout << "Text       = " << Text;
	cout << "\nTrim left  = " << MyTrimLeft(Text);
	cout << "\nTrim right = " << MyTrimRight(Text) << "Test";
	cout << "\nTrim       = " << MyTrim(Text) << "Test" << endl;
}
