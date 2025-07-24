#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int x)
{
    int rev = 0, num = x, rem = 0;

    if (x < 0)
        return 0;

    while (x)
    {
        rem = x % 10;
        if (rev > INT_MAX / 10)
            return 0;
        rev = rev * 10 + rem;
        x /= 10;
    }

    if (rev == num)
        return 1;
    else
        return 0;
}

int main()
{
    int num = 12321;

    if (isPalindrome(num))
    {
        cout << num << " is a palindrome." << endl;
    }
    else
    {
        cout << num << " is not a palindrome." << endl;
    }

    return 0;
}