#pragma warning(disable:4996)

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

struct stDate
{
	int Year = 0;
	short Month = 1;
	short Day = 0;
};

string ReadTextDate()
{
	string DateText;

	cout << "Enter date dd/mm/yyyy : ";
	getline(cin >> ws, DateText);

	return DateText;
}

vector <string> MySplit(string Text, string Delim)
{
	vector <string> vWords;
	string Word;
	short Pos;

	while ((Pos = Text.find(Delim)) != std::string::npos)
	{
		Word = Text.substr(0, Pos);

		if (!Word.empty())
		{
			vWords.push_back(Word);
		}

		Text.erase(0, Pos + Delim.length());
	}

	if (!Text.empty())
	{
		vWords.push_back(Text);
	}

	return vWords;
}

stDate ConvertTextDateToStruct(string DateText)
{
	stDate Date;
	vector <string> vDate = MySplit(DateText, "/");

	Date.Day = stoi(vDate[0]);
	Date.Month = stoi(vDate[1]);
	Date.Year = stoi(vDate[2]);

	return Date;
}

string ConvertStrcutDateToText(stDate Date)
{
	return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

int main()
{
	string DateText = ReadTextDate();

	stDate Date = ConvertTextDateToStruct(DateText);


	cout << "\nDay : " << Date.Day;
	cout << "\nMonth : " << Date.Month;
	cout << "\nYear  : " << Date.Year << endl;

	cout << "\nYou entered : " << ConvertStrcutDateToText(Date) << endl;
}
