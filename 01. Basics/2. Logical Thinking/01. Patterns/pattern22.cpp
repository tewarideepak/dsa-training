// 4444444
// 4333334
// 4322234
// 4321234
// 4322234
// 4333334
// 4444444

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 4;
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        for (int j = 1; j <= 2 * n - 1; j++)
        {
            int top = i;
            int left = j;
            int bottom = (2 * n) - i;
            int right = (2 * n) - j;

            cout << (n - min(min(top, bottom), min(left, right))) + 1;
        }
        cout << endl;
    }
    return 0;
}