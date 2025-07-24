#include <bits/stdc++.h>
using namespace std;

int mySqrt(int x)
{
    int n = 0;
    // Keep squaring n until n*n exceeds x
    while ((long long)n * n <= x)
    {
        n++;
    }
    return n - 1; // n went one step too far, so we return n - 1
}
