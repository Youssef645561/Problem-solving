#include <iostream>
using namespace std;

void Read_dimensions(float& Base, float& Highet)
{
	cout << "Enter triangle base : ";
	cin >> Base;
	cout << "Enter triangle highet : ";
	cin >> Highet;
}

float Calc_triangle_area(float Base, float Highet)
{
	return (Base * Highet) / 2;
}

void Print_area(float Area)
{
	cout << "\nTriangle area = " << Area << endl;
}

int main()
{
	float Base, Highet;
	Read_dimensions(Base, Highet);
	Print_area(Calc_triangle_area(Base, Highet));
}