//  Problem statement

// You are given a positive integer ‘n’.

// Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of sqrt(n).

// Example:

// Input: ‘n’ = 7

// Output: 2

// Explanation:
// The square root of the number 7 lies between 2 and 3, so the floor value is 2.

// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:

// 6

// Sample Output 1:

// 2

// Explanation of Sample Input 1:

// The square root of the given number 6 lies between 2 and 3, so the floor value is 2.

// Sample Input 2:

// 100

// Sample Output 2:

// 10

// Explanation of Sample Output 2:

// The square root of the given number 100 is 10.

// Expected Time Complexity:

// Try solving this in O(log(n)).

// Constraints:

// 0 <= n <= 10 ^ 9

// Time Limit: 1 sec.

#include <bits/stdc++.h>
using namespace std;

long long int binarySearch(int n)
{
    int start = 0, end = n;
    int ans = -1;

    while (start <= end)
    {
        long long int mid = start + (end - start) / 2;
        long long int square = mid * mid;

        if (n == square)
        {
            return mid;
        }
        else if (square > n)
        {
            end = mid - 1;
        }
        else
        {
            ans = mid;
            start = mid + 1;
        }
    }
    return ans;
}

int floorSqrt(int n)
{
    return binarySearch(n);
}

double morePrecision(int n, int precision, int tempSol)
{
    double factor = 1;
    double ans = tempSol;

    for (int i = 1; i <= precision; i++)
    {
        factor /= 10;
        for (double j = ans; j * j < n; j += factor)
        {
            ans = j;
        }
    }

    return ans;
}

int main()
{
    int n = 6;
    int tempSol = floorSqrt(n);
    cout << "Square root of " << n << " is: " << tempSol << endl;

    double ans = morePrecision(n, 3, tempSol);

    cout << "Answer is: " << ans << endl;
}
