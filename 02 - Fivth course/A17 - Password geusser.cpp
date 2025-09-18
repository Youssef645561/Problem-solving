#include <iostream>
using namespace std;

string ReadWord(string Message)
{
	string Word;
	cout << Message;
	cin >> Word;
	return Word;
}

bool PasswordGeusser(string Password)
{
	int K = 0;
	string Word = "";

	for (int J = 65; J <= 90; J++)
	{

		for (int i = 65; i <= 90; i++)
		{

			for (int C = 65; C <= 90; C++)
			{
				K++;
				Word = Word + char(J);
				Word = Word + char(i);
				Word = Word + char(C);

				cout << "Trial [" << K << "] : " << Word << "\n";


				if (Word == Password)
				{
					cout << "\n\nPassword is " << Word << "\n\nFound after " << K << " Tiral(s).\n";
					return true;
				}
				Word = "";
			}
		}
	}
	return false;
}

int main()
{
	string Password = ReadWord("Enter a trial capital word : ");
	PasswordGeusser(Password);

}
