#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int RondomInRange(int From, int To)
{
	int Num = rand() % (To - From + 1) + From;

	return Num;
}

int main()
{
cout << endl << RondomInRange(1,6) << endl;
}