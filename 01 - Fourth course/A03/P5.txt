#include <iostream>
using namespace std;

void Read_numbers(float Dimensions[2])
{
	for (int Counter = 1; Counter <= 2; Counter++)
	{
		if (Counter == 1)
		{
			cout << "Enter the length of the rectangle : ";
			cin >> Dimensions[0];
			cout << endl;
		}
		else
		{
			cout << "Enter the width of the rectangle : ";
			cin >> Dimensions[1];
		}
	}
}

float Rectangle_Area(float Dimensions[2])
{
	return Dimensions[0] * Dimensions[1];
}

void Print(float Area)
{
	cout << "\nArea of the rectangle = " << Area << endl;
}

int main()
{
	float Dimensions[2];
	Read_numbers(Dimensions);
	Print(Rectangle_Area(Dimensions));
}