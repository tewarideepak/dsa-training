#include <bits/stdc++.h>
using namespace std;

int main()
{
    int year = 2004;

    if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
    {
        cout << "Leap Year";
    }
    else
    {
        cout << "Not a Leap Year";
    }
}