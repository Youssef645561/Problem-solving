#include <iostream>
using namespace std;

enum enPass_Fail { Fail, Pass };

void Read_marks(float &Mark1, float &Mark2, float &Mark3)
{
	cout << "Enter mark [1] : ";
	cin >> Mark1;
	cout << "\nEnter mark [2] : ";
	cin >> Mark2;
	cout << "\nEnter mark [3] : ";
	cin >> Mark3;
}

float Sum(float Mark1, float Mark2, float Mark3)
{
	return Mark1 + Mark2 + Mark3;
}

float Average(float Mark1, float Mark2, float Mark3)
{
	return Sum(Mark1, Mark2, Mark3) / 3;
}

enPass_Fail Pass_Fail(float Average)
{
	if (Average >= 50)
		return enPass_Fail::Pass;
	else
		return enPass_Fail::Fail;
}

void Print_average(float Average)
{
	cout << "\nYour average = " << Average << endl;
	if (Pass_Fail(Average))
		cout << "\nYou Passed" << endl;
	else
		cout << "\nYou failed" << endl;
}

int main()
{
	float Mark1, Mark2, Mark3;

	Read_marks(Mark1, Mark2, Mark3);

	Print_average(Average(Mark1, Mark2, Mark3));

	return 0;
}