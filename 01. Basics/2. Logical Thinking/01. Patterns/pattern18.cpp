// E
// D E
// C D E
// B C D E
// A B C D E

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        char ch = 'A' + n - i;
        for (int j = 1; j <= i; j++)
        {
            cout << char(ch + j - 1) << " ";
        }
        cout << endl;
    }
    return 0;
}