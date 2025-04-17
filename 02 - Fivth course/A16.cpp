#include <iostream>
using namespace std;

void PrintFromAAAToZZZ()
{
	string Word = "";

	for (int J = 65; J <= 90; J++)
	{

		for (int i = 65; i <= 90; i++)
		{

			for (int C = 65; C <= 90; C++)
			{
				Word = Word + char(J);
				Word = Word + char(i);
				Word = Word + char(C);

				cout << Word << "\n";

				Word = "";
			}
		}
	}
}

int main()
{

	PrintFromAAAToZZZ();

}