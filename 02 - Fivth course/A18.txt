#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

string ReadText()
{
	string Text;

	cout << "Enter your name : ";
	getline(cin, Text);

	return Text;
}

string EncryptText(string &Text,short EncryptionKey)
{
	for (int C = 0; C <= Text.length(); C++)
	{
		Text[C] = char(((int)Text[C]) + EncryptionKey);
	}
	return Text;
}

string DecryptText(string &Text, short EncryptionKey)
{
	for (int C = 0; C <= Text.length(); C++)
	{
		Text[C] = char(((int)Text[C]) - EncryptionKey);
	}
	return Text;
}

int main()
{
	const short EncryptionKey = 66;

	string Name = ReadText();


	cout << "\nName before Encryption : " << Name << endl;
	cout << "\nName after Encryption : " << EncryptText(Name, EncryptionKey) << "\n" << endl;
	cout << "\nName after Decryption : " << DecryptText(Name, EncryptionKey) << "\n" << endl;
}