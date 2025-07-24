// A
// A B
// A B C
// A B C D
// A B C D E

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        for (char c = 'A'; c < 'A' + i; c++)
        {
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}
