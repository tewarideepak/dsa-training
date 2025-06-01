#include <bits/stdc++.h>
using namespace std;

int sum_num(int n)
{
    if (n == 0)
        return 0;
    return n + sum_num(n - 1);
}

int main()
{
    int n = 5;
    int sum = sum_num(n);

    cout << "Sum: " << sum << endl;

    return 0;
}