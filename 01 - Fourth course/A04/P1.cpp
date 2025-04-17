#include <iostream>
#include <cmath>

using namespace std;

void Read_numbers(float& Side, float& Diagnal)
{
			cout << "Enter the diagnal of the rectangle : ";
			cin >> Diagnal;
			cout << endl;
			cout << "Enter the side of the rectangle : ";
			cin >> Side;

			while (Diagnal < Side)
			{
				cout << "\nWrong input\nDiagnal of rectangle must be greater than its side" << endl;
				cout << "\nEnter the diagnal of the rectangle : ";
				cin >> Diagnal;
				cout << endl;
				cout << "Enter the side of the rectangle : ";
				cin >> Side;
			}
}

float Rectangle_Area(float Side, float Diagnal)
{
	return Side * sqrt(pow(Diagnal, 2) - pow(Side, 2));
}

void Print(float Area)
{
	cout << "\nArea of the rectangle = " << Area << endl;
}

int main()
{
	float Side,Diagnal;
	Read_numbers(Side,Diagnal);
	Print(Rectangle_Area(Side,Diagnal));
	return 0;
}