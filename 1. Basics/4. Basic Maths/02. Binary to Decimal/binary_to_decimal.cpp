#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 111;
    int ans = 0, i = 0;

    while (n != 0)
    {
        int digit = n % 10;
        ans = pow(2, i) + ans;
        n = n / 10;
        i++;
    }

    cout << "Answer:" << ans;
}