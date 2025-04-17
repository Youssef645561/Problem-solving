#include <iostream>
using namespace std;

void Read_number(int Num[3])
{
    for (int Counter = 0; Counter <= 2;Counter++)
    {
        cout << "Enter Number [" << Counter + 1 << "] : ";
        cin >> Num[Counter];
    }
}

int Calc_sum(int Num[3])
{
    return Num[0] + Num[1] + Num[2];
}

void Print_sum(int Sum)
{
    cout << "\nSum = " << Sum << endl;
}

int main()
{
    int Num[3];
    Read_number(Num);
    Print_sum(Calc_sum(Num));
}