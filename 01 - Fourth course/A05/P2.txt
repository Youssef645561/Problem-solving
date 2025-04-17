#include <iostream>
using namespace std;

void ReadTriangleData(float& Side, float& Base)
{
	cout << "Enter the side of  triangle inscribing circle : ";
	cin >> Side;
	cout << "\nEnter the base of  triangle inscribing circle : ";
	cin >> Base;
}

float CircleAreaByITriangle(float Side, float Base)
{
	const float PI = 3.14159;
	return (PI * pow(Base, 2) * ((2 * Side) - Base)) / (4 * ((2 * Side) + Base));
}

void PrintCicleArea(float Area)
{
	cout << "\nCircle area = " << Area << endl;
}

int main()
{
	float Side, Base;

	ReadTriangleData(Side, Base);
	PrintCicleArea(CircleAreaByITriangle(Side, Base));
}