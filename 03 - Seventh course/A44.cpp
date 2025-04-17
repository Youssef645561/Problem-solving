#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include "ManipulationLib.h"
#include "ArrayLib.h"
#include "MatrixLib.h"
#include <string>
#include "MathLib.h"

using namespace std;
using namespace nsArray;
using namespace nsMatrix;
using namespace nsManipulation;
using namespace nsMath;

string ReadText(string Message)
{
	string Text;

	cout << Message;
	getline(cin, Text);

	return Text;
}

string RemovePunctuation(string Text1)
{
	string Text2;

	for (short i = 0; i < Text1.length(); i++)
	{
		if (!ispunct(Text1[i]))
		{
			Text2 += Text1[i];
		}
	}
	return Text2;
}

int main()
{
	srand((unsigned)time(NULL));

	string Text = ReadText("Enter a text : ");

	cout << "\nText after removing punctuation : " << RemovePunctuation(Text);
}