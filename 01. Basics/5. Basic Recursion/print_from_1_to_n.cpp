#include <bits/stdc++.h>
using namespace std;

void print_num(int n)
{
    if (n == 0)
        return;
    print_num(n - 1);
    cout << n << endl;
}

int main()
{
    int n = 5;
    print_num(n);

    return 0;
}