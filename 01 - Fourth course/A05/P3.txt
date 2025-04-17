#include <iostream>
using namespace std;

void ReadTriangleDimensions(float A[3])
{
	cout << "Enter triangle (contained by circle) dimensions :\n\n";
	
	for (int Counter = 1; Counter <= 3; Counter++)
	{
		cout << "Enter side [" << Counter << "] : ";
		cin >> A[Counter - 1];
	}
}

float CalcCricleAreaByATriangle(float A[3])
{
	const float PI = 3.14159;
	float a = A[0], b = A[1], c = A[2];
	float P = (a + b + c) / 2;
	float Temp = (a * b * c) / (4 * sqrt(P * (P - a) * (P - b) * (P - c)));
	return PI * (Temp * Temp);
}

void PrintCicleArea(float Area)
{
	cout << "\nCircle area = " << Area << endl;
}

int main()
{
	float A[3];
	ReadTriangleDimensions(A);
	PrintCicleArea(CalcCricleAreaByATriangle(A));
}