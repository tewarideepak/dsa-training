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

// The Binary Representation of Powers of Two:

//     Powers of two in binary representation always have exactly one 1 bit and all other bits are 0. For example:
//         1 in binary is 00000001 (which is 2^0).
//         2 in binary is 00000010 (which is 2^1).
//         4 in binary is 00000100 (which is 2^2).
//         8 in binary is 00001000 (which is 2^3), and so on.

// Key Insight (Bitwise Operation):

//     The crucial observation is that for any number n that is a power of two, the binary representation of n has exactly one 1 bit.
//     A simple bitwise trick can check if a number has only one 1 bit:

// - If n is a power of two, then n - 1 will flip all the bits of n up to and including the lowest 1 bit. This means:

// 	n & (n - 1) will be 0 if and only if n has exactly one 1 bit.