#include <iostream>
#include <std.io>
using namespace std;

class Recursion
{
    void PrintN(int);
    void PrintNR(int);
    void PrintOddN(int);
    void PrintOddNR(int);
};

void Recursion::PrintN(int n)
{
    if (n > 0)
    {

        PrintN(n - 1);
        cout << " " << n;
    }
}

void Recursion::PrintNR(int n)
{

    if (n > 0)
    {
        cout << " " << n;
        PrintNR(int n - 1);
    }
}

void Recursion::PrintOddN(int n)
{
    if (n > 0)
    {
        PrintOddN(n - 1);
        cout << " " << 2 * n - 1;
    }
}

void Recursion::PrintOddNR(int n)
{
    if (n > 0)
    {
        cout << " " << 2 * n - 1;
        PrintOddNR(n - 1);
    }
}
void Recursion::PrintEvenN(int n)
{
    if (n > 0)
    {
        PrintEvenN(n - 1);
        cout << " " << 2 * n;
    }
}
void Recursion::PrintEvenNR(int n)
{
    if (n > 0)
    {
        cout << " " << 2 * n;
        PrintEvenN(n - 1);
    }
}

void Recursion::PrintSqn(int n)
{
    if (n > 0)
    {
        PrintSqn(n - 1);
        cout << " " << n * n;
    }
}

void Recursion::PrintSqnR(int n)
{
    if (n > 0)
    {
        cout << " " << n * n;
        PrintSqnR(n - 1);
    }
}

void Recursion::Printcube(int n)
{
    if (n > 0)
    {

        Printcube(n - 1);
        cout << " " << n * n * n;
    }
}
void Recursion::PrintcubeR(int n)
{
    if (n > 0)
    {
        cout << " " << n * n * n;
        PrintcubeR(n - 1);
    }
}

int SumofSq(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return sumofSq(n - 1) + n * n;
}

int SumofNodd(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return SumofNodd(n - 1) + 2 * n - 1;
}

int SumofNeven(int n)
{
    if (n == 1)
    {
        return 2;
    }
    return SumofNeven(n - 1) * 2 * n;
}

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return factorial(n - 1) * n;
}

int sumofdigits(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return sumofdigits(n / 10) + (n % 10);
    }
}

void dtob(int n)
{
    if (n > 0)
    {
        dtob(n / 2);

        printf("%d", n % 2);
    }
}

int fib(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int hcf(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    if (b == 0)
    {
        return a;
    }
    if (a > 0)
    {
        return hcf(a % b, b);
    }
    if (b > 0)
    {
        return hcf(a, b % a);
    }
}