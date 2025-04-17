#include <iostream>
using namespace std;

int ReadNumber()
{
	int Num;

	cout << "Enter a number : ";
	cin >> Num;

	return Num;
}

void Power_2_3_4(int Num)
{
	cout << Num << "^2 = " << Num * Num << endl;
	cout << Num << "^3 = " << Num * Num * Num << endl;
	cout << Num << "^4 = " << Num * Num * Num * Num << endl;
}

int main()
{
	Power_2_3_4(ReadNumber());

}