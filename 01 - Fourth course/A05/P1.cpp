#include <iostream>
using namespace std;

float ReadCircleCircumference()
{
	float L;
	cout << "Enter circle circumference : ";
	cin >> L;
	return L;
}

float CalcCircleArea(float L)
{
	const float PI = 3.14159;
	return pow(L, 2) / (4 * PI);
}

void PrintCircleArea(float Area)
{
	cout << "\nCircle area = " << Area << endl;
}

int main()
{
	PrintCircleArea(CalcCircleArea(ReadCircleCircumference()));
}