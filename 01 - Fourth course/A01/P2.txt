#include <iostream>
#include <string>
using namespace std;

string Read_name()
{
	string Name;
	cout << "Enter your name : " << endl;
	getline(cin, Name);
	return Name;
}

void Print_name(string Name)
{
	cout << "\nYour name is : " << Name << endl;
}

int main()
{

	Print_name(Read_name());
}