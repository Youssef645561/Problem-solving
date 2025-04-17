#include <iostream>
using namespace std;

enum enPass_Fail { Pass, Fail };

float Read_mark()
{
    float Mark;
    cout << "Enter your mark : ";
    cin >> Mark;
    return Mark;
}

bool Check_mark(float Mark)
{
    if (Mark >= 50)
    {
        return enPass_Fail::Pass;
    }
    else
    {
        return enPass_Fail::Fail;
    }
}

void Print_status(float Mark)
{

    if (Check_mark(Mark) == enPass_Fail::Pass)
        cout << "\nYou passed\n";
    else
        cout << "\nYou failed\n";
}

int main()
{
    Print_status(Read_mark());
}