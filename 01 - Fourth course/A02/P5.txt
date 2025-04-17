#include <iostream>
using namespace std;

void Read_number(float Mark[3])
{
    for (int Counter = 0; Counter <= 2;Counter++)
    {
        cout << "Enter Mark [" << Counter + 1 << "] : ";
        cin >> Mark[Counter];
    }
}

float Calc_sum(float Mark[3])
{
    return (Mark[0] + Mark[1] + Mark[2]) / 3;
}

void Print_sum(float Average)
{
    cout << "\nAverage = " << Average << endl;
}

int main()
{
    float Mark[3];
    Read_number(Mark);
    Print_sum(Calc_sum(Mark));
}