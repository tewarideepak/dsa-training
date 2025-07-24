// A B C D E
// A B C D
// A B C
// A B
// A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    for (int i = n; i > 0; i--)
    {
        for (char c = 'A'; c < 'A' + i; c++)
        {
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}