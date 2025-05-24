// A
// B B
// C C C
// D D D D
// E E E E E

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        char ch = 'A' + i - 1;
        for (char c = 'A'; c < 'A' + i; c++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
    return 0;
}