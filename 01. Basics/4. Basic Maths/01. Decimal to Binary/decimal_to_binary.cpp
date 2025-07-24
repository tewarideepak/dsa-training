// 1st Approach:

// 1. divide by 2
// 2. store reminder
// 3. repeat above 2 steps until n!=0
// 4. reverse answer

// 2nd Approach:

// 1. num & 1 -> odd otherwise even
// 2. right shift >>

// rev -> ans = (digit * 10 ^ i) + ans

// same -> ans = ans * 10 + digit;

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 7;
    int ans = 0, i = 0;

    while (n != 0)
    {
        int digit = n & 1;
        ans = (digit * pow(10, i)) + ans;
        n = n >> 1;
        i++;
    }

    cout << "Answer:" << ans;
}