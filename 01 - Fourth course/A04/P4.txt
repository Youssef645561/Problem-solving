#include <iostream>
using namespace std;

float ReadDiameter()
{
	float Diameter;
	cout << "Enter circle diameter: ";
	cin >> Diameter;
	return Diameter;
}

float CalcCircleArea(float Diameter)
{
	const float PI = 3.14159;
	return (PI * pow(Diameter, 2)) / 4;
}

void PrintArea(float Area)
{
	cout << "\nCircle area = " << Area << endl;
}

int main()
{	
	PrintArea(CalcCircleArea(ReadDiameter()));
}