#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num = 512, count = 0;

    count = (int)log10(num) + 1;

    cout << count << endl;

    count = 0;

    while (num != 0)
    {
        count++;
        num /= 10;
    }

    cout << "Answer:" << count;
}
