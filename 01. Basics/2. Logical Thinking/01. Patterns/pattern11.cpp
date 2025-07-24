// 1
// 0 1
// 1 0 1
// 0 1 0 1
// 1 0 1 0 1

#include <bits/stdc++.h>
using namespace std;

int main()
{
    for (int i = 1; i <= 5; i++)
    {
        int bit = i % 2 == 0 ? 0 : 1;
        for (int j = 1; j <= i; j++)
        {
            cout << bit << " ";
            bit = bit ^ 1;
        }
        cout << endl;
    }
    return 0;
}
