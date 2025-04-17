#include <iostream>
using namespace std;

float ReadRadius()
{
	float r;
	cout << "Enter circle radius : ";
	cin >> r;
	return r;
}

float CalcCircleArea(float r)
{
	const float PI = 3.14159;
	return PI * pow(r, 2);
}

void PrintArea(float Area)
{
	cout << "\nCircle area = " << Area << endl;
}

int main()
{	
	PrintArea(CalcCircleArea(ReadRadius()));
}