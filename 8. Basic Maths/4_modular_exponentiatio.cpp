//  Problem statement

// You are given a three integers 'X', 'N', and 'M'. Your task is to find ('X' ^ 'N') % 'M'. A ^ B is defined as A raised to power B and A % C is the remainder when A is divided by C.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :

// 1 <= T <= 100
// 1 <= X, N, M <= 10^9

// Time limit: 1 sec

// Sample Input 1 :

// 2
// 3 1 2
// 4 3 10

// Sample Output 1 :

// 1
// 4

// Explanation for Sample Output 1:

// In test case 1,
// X = 3, N = 1, and M = 2
// X ^ N = 3 ^ 1 = 3
// X ^ N % M = 3 % 2 = 1.
// So the answer will be 1.

// In test case 2,
// X = 4, N = 3, and M = 10
// X ^ N = 4 ^ 3 = 64
// X ^ N % M = 64 % 10 = 4.
// So the answer will be 4.

// Sample Input 2 :

// 2
// 5 2 10
// 2 5 4

// Sample Output 2 :

// 5
// 0

// Explanation for Sample Output 2:

// In test case 1,
// X = 5, N = 2, and M = 10
// X^N = 5^2 = 25
// X^N %M = 25 % 10 = 5.
// So the answer will be 5.

// In test case 2,
// X = 2, N = 5, and M = 4
// X^N = 2^5 = 32
// X^N %M = 32 % 4 = 0.
// So the answer will be 0.

// 🚀 Concept Behind It: Modular Exponentiation

// Computing X^N % M directly is not feasible for large N because:

//     Calculating X^N directly would cause overflow.

//     It would be too slow for big N.

// Modular Exponentiation solves this using Exponentiation by Squaring, which:

//     Reduces the time complexity to O(log N).

//     Prevents overflow by taking modulo at each step.

// ✅ Key Idea

// We recursively or iteratively break down the problem:

// X^N % M =
//   if N is even: ((X^(N/2)) % M * (X^(N/2)) % M) % M
//   if N is odd:  (X % M * (X^(N-1)) % M) % M

// 🔢 Sample Dry Run

// Let’s take: X=4, N=3, M=10

// Steps:

// 4^3 % 10 = (4 * 4^2) % 10
//          = (4 * (4^2 % 10)) % 10
//          = (4 * (16 % 10)) % 10
//          = (4 * 6) % 10 = 24 % 10 = 4

// 🧠 C++ Implementation (Iterative Version)

// 🔁 Binary Exponentiation

// Instead of multiplying x with itself n times, we use divide & conquer:

//     If n is even:
//     x^n=(x^n/2)^2

//     If n is odd:
//     x^n=x⋅x^n−1

// This reduces time complexity from O(N) → O(log N).

#include <bits/stdc++.h>
using namespace std;

int modularExponentiation(int x, int n, int m)
{
    int result = 1;

    while (n > 0)
    {
        if (n & 1)
        {
            result = (1LL * result * x) % m;
            n--;
        }
        else
        {
            x = (1LL * x * x) % m;
            n = n >> 1;
        }
    }

    return result;
}

int main()
{
    int t;
    cin >> t; // Number of test cases

    while (t--)
    {
        int x, n, m;
        cin >> x >> n >> m;
        cout << modularExponentiation(x, n, m) << endl;
    }

    return 0;
}

// 🧠 Problem Recap

// You're given three integers: X, N, and M, and you need to compute:

// (X^N) % M

// But here's the challenge:

//     X, N, M can be up to 10^9, so computing X^N directly would overflow even long long.

//     We need a way to compute this efficiently and safely.

// 🔢 Naive Method (Inefficient):

// long long result = 1;
// for (int i = 0; i < N; ++i)
//     result = (result * X) % M;

//     This takes O(N) time.

//     For N = 10^9, it'll do a billion multiplications → way too slow.

// ⚡ Efficient Method: Binary Exponentiation

// Also known as Exponentiation by Squaring.
// It reduces time from O(N) to O(log N).
// 🔍 Key Idea:

// Instead of computing X^N step by step, we observe that:

// X^N = (X^(N/2)) * (X^(N/2))     if N is even
// X^N = X * (X^(N/2)) * (X^(N/2)) if N is odd

// So you keep dividing the exponent by 2, squaring the base, and multiply only when needed.
// 💻 Code Explanation (Optimized Iterative Version)

// int modularExponentiation(int x, int n, int m) {
//     int result = 1;
//     x = x % m;  // reduce base modulo m initially

//     Reduce x early so we don’t work with large numbers.

//     while (n > 0) {

//     Keep dividing n (the power) by 2 until it becomes 0.

//         if (n & 1)
//             result = (1LL * result * x) % m;

//     If n is odd, we multiply current base x with the result.

//     Why 1LL * result * x?
//     To avoid integer overflow (int * int could overflow if > 2^31).
//     Casting one operand to long long ensures full 64-bit multiplication.

//         x = (1LL * x * x) % m;
//         n >>= 1;

//     Square the base x (prepare for next power of 2).

//     Halve the exponent n.

// 🕒 Time Complexity: O(log N)

//     Every iteration halves n, so the loop runs at most log2(N) times.

// 📦 Example:

// Let's say:

// X = 3, N = 5, M = 13

// Steps:

// Initial: result = 1, x = 3

// N=5: odd → result = (1 * 3) % 13 = 3
//       x = (3 * 3) % 13 = 9
//       N = 2

// N=2: even → no result update
//       x = (9 * 9) % 13 = 3
//       N = 1

// N=1: odd → result = (3 * 3) % 13 = 9
//       x = (3 * 3) % 13 = 9
//       N = 0

// Final result: 9

// ✅ 3^5 % 13 = 243 % 13 = 9

// ✅ Summary

//     Binary Exponentiation breaks down power computation into squares.

//     Modulo at every step ensures no overflow and fits in 32/64-bit types.

//     Reduces time complexity from O(N) to O(log N) — critical for large inputs.