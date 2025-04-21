#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

long long ReadNum()
{
	long long Num;

	cout << "Enter a number : ";
	cin >> Num;

	while (cin.fail()) //true or false
	{
		cin.clear();

		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "\nWrong input,\nPLease enter a valid number : ";
		cin >> Num;
	}

	return Num;

}

string ConvertNumToText(long long Num, bool Zero = true)
{
	if (Num == 0)
	{
		return Zero ? "Zero" : "";
	}


	if (Num >= 1 && Num <= 19)
	{
		string ArrOneToNinteen[] = { "","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

		return ArrOneToNinteen[Num];
	}
	else if (Num >= 20 && Num <= 99)
	{
		string ArrTwentyToNinety[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };

		return ArrTwentyToNinety[Num / 10] + " " + ConvertNumToText(Num % 10, false);
	}
	else if (Num >= 100 && Num <= 999)
	{
		string ArrOneToNinteen[] = { "","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

		return ArrOneToNinteen[Num / 100] + " Hundred " + ConvertNumToText(Num % 100, false);
	}
	else if (Num >= 1000 && Num <= 999999)
	{
		return ConvertNumToText(Num / 1000, false) + " Thousand " + ConvertNumToText(Num % 1000, false);
	}
	else if (Num >= 1000000 && Num <= 999999999)
	{
		return ConvertNumToText(Num / 1000000, false) + " Million " + ConvertNumToText(Num % 1000000, false);
	}
	else if (Num >= 1000000000 && Num <= 999999999999)
	{
		return ConvertNumToText(Num / 1000000000, false) + " Billion " + ConvertNumToText(Num % 1000000000, false);
	}
	else if (Num >= 1000000000000 && Num <= 999999999999999)
	{
		return ConvertNumToText(Num / 1000000000000, false) + " Trillion " + ConvertNumToText(Num % 1000000000000, false);
	}
	else
	{
		return "Out of the range.";
	}
}

int main()
{
	long long Num = ReadNum();

	cout << "\n";

	cout << ConvertNumToText(Num) << endl;

}
