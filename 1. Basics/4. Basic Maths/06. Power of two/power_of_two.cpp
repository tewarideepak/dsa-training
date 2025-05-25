#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n)
{
    return (n > 0) && (n & (n - 1)) == 0;
}

int main()
{
    int num = 512, ans = 0;

    ans = isPowerOfTwo(num);

    cout << "Answer:" << ans;
}