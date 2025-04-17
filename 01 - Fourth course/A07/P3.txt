#include <iostream>
using namespace std;

float ReadGrade(int From, int To)
{
	int Grade;

	do
	{
		cout << "Enter your grade : ";
		cin >> Grade;
	} while (Grade < From || Grade > To);

	return Grade;
}

char CheckGrade(int Grade)
{
	if (Grade >= 90)
		return 'A';

	else if (Grade >= 80)
		return 'B';

	else if (Grade >= 70)
		return 'C';

	else if (Grade >= 60)
		return 'D';

	else if (Grade >= 50)
		return 'E';

	else
		return 'F';
}

int main()
{
	cout << endl << CheckGrade(ReadGrade(0, 100)) << endl;
}