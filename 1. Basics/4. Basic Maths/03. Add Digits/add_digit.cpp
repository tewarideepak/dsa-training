#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num = 635;

    while (num > 9)
    {
        int rem, ans = 0;
        while (num != 0)
        {
            rem = num % 10;
            num /= 10;
            ans = ans + rem;
        }

        num = ans;
    }

    cout << num;
}

// Example: 27 = 2 + 7 = 9

// 249 = 2 + 4 + 9 = 17 = 1 + 7 = 8

// Given an integer num, the goal is to repeatedly add its digits until the result is a single digit.

// Concept: Digital Root and Modulo 9

// The solution uses a concept called the digital root of a number, which is the result of repeatedly summing the digits until a single digit remains. This process has a direct relationship with modulo 9 arithmetic. Here's the key property:

// 1. The digital root of a number is equivalent to the number modulo 9, with a special exception for numbers that are multiples of 9.
// 2. If num == 0, the result is 0 (digital root of zero is 0).
// 3. If num % 9 == 0 and num != 0, the result is 9 (because any non-zero multiple of 9 has a digital root of 9).
// 4. Otherwise, the result is simply num % 9.

class Solution
{
public:
    int addDigits(int num)
    {
        if (num == 0)
            return 0;

        return num % 9 == 0 ? 9 : num % 9;
    }
};