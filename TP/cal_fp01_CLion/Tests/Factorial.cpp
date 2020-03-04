/*
 * Factorial.cpp
 */

#include "Factorial.h"

using namespace std;

int factorialRecurs(int n)
{
    if (n >= 1) return n*factorialRecurs(n-1);
    else return 1;
}

int factorialDinam(int n)
{
    if (n == 0 || n == 1) return 1;
    int res = 1;
    for (int i = 2; i <= n; i++)
    {
        res *= i;
    }
    return res;
}
