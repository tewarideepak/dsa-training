#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 2, b = 5, c = 2, d = 5;

    if ((a == b && c == d) || (a == c && b == d) || (a == d && b == c))
    {
        cout << "Yes";
        return 0;
    }
    cout << "No";
}