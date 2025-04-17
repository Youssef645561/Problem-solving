#include <iostream>
using namespace std;

float ReadSquareSide()
{
	float Side;
	cout << "Enter side of the square inscribting the sircle : ";
	cin >> Side;
	return Side;
}

float CalcCircleArea(float Side)
{
	const float PI = 3.14159;
	return PI * pow((Side / 2), 2);
}

void PrintCircleArea(float Area)
{
	cout << "Circle area = " << Area << endl;
}

int main()
{
	PrintCircleArea(CalcCircleArea(ReadSquareSide()));
}