#include <iostream>
#include <string>
using namespace std;

struct stFull_name
{
	string First_name;
	string Last_name;
};

stFull_name Read_name()
{
	stFull_name Full_name;
	cout << "Enter your first name : ";
	getline(cin, Full_name.First_name);
	cout << "\nEnter you last name : ";
	getline(cin, Full_name.Last_name);
	return Full_name;
}

string Combine_full_name(stFull_name Full_name)
{
	string Combination = Full_name.First_name + " " + Full_name.Last_name;
	return Combination;
}
void Print_name(string Combination)
{
	cout << "\nYour name is " << Combination << endl;
}

int main()
{
	Print_name(Combine_full_name(Read_name()));
}




Edit




#include <iostream>
#include <string>
using namespace std;

struct stFull_name
{
	string First_name;
	string Last_name;
};

stFull_name Read_name()
{
	stFull_name Full_name;
	cout << "Enter your first name : ";
	getline(cin, Full_name.First_name);
	cout << "\nEnter you last name : ";
	getline(cin, Full_name.Last_name);
	return Full_name;
}

string Combine_full_name(stFull_name Full_name, bool Reversed)
{
	string Combination;

	if (Reversed == true)
	{
		Combination = Full_name.Last_name + " " + Full_name.First_name;
		return Combination;
	}
	else
	{
		Combination = Full_name.First_name + " " + Full_name.Last_name;
		return Combination;
	}
}
void Print_name(string Combination)
{
	cout << "\nYour name is " << Combination << endl;
}

int main()
{
	Print_name(Combine_full_name(Read_name(),true));
}





