#include <iostream>
using namespace std;

void PrintEnglishAlphabet()
{
	for (int C = 65; C <= 90; C++)
	{
		cout << char(C) << endl;
	}
}

int main()
{
	PrintEnglishAlphabet();
}