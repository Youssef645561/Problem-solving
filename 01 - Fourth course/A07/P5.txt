#include <iostream>
using namespace std;

struct stCoinsAndNotes { int Penny, Nickal, Dime, Quarter, Dollar; };

stCoinsAndNotes ReadCoinsAndNotes()
{
	stCoinsAndNotes Coins;

	cout << "Enter how many pennies : ";
	cin >> Coins.Penny;
	cout << "\nEnter how many nickals : ";
	cin >> Coins.Nickal;
	cout << "\nEnter how many dims : ";
	cin >> Coins.Dime;
	cout << "\nEnter how many quarters : ";
	cin >> Coins.Quarter;
	cout << "\nEnter how many dollars : ";
	cin >> Coins.Dollar;

	return Coins;
}

int CalcPennies(stCoinsAndNotes Coins)
{
	int TotalPennies = Coins.Penny + Coins.Nickal * 5 + Coins.Dime * 10 + Coins.Quarter * 25 + Coins.Dollar * 100;

	return TotalPennies;
}

int main()
{
	int TotalPennies = CalcPennies(ReadCoinsAndNotes());
	

	cout << "\nTotal pennies = " << TotalPennies << endl;
	cout << "\nTotal dollars = " << (float)TotalPennies / 100 << endl;

}

