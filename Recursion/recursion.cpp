#include <iostream>
#include <std.io>
using namespace std;

class Recursion
{
    void PrintN(int);
    void PrintNR(int);
};

void Recursion::PrintN(int n)
{
    if (n > 0)
    {

        PrintN(n - 1);
        cout << " " << n;
    }
}

void PrintNR(int n)
{

    if (n > 0)
    {
        cout << " " << n;
        PrintNR(int n - 1);
    }
}

void PrintOddN(int n)
{
    if (n > 0)
    {
        PrintOddN(n - 1);
        cout << " " << 2 * n - 1;
    }
}

void PrintOddNR(int n)
{
    if (n > 0)
    {
        cout << " " << 2 * n - 1;
        PrintOddNR(n - 1);
    }
}
void PrintEvenN(int n)
{
    if (n > 0)
    {
        PrintEvenN(n - 1);
        cout << " " << 2 * n;
    }
}
void PrintEvenNR(int n)
{
    if (n > 0)
    {
        cout << " " << 2 * n;
        PrintEvenN(n - 1);
    }
}
