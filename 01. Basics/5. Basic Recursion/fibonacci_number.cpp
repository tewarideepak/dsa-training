// 🔢 What is the Fibonacci Sequence?

// A sequence where:

// F(0) = 0
// F(1) = 1
// F(n) = F(n - 1) + F(n - 2)  for n ≥ 2

// Example:

// 0, 1, 1, 2, 3, 5, 8, 13, ...

// 🧠 Recursive Approach

// Break the problem into smaller subproblems using:

// fib(n) = fib(n - 1) + fib(n - 2)

// Base cases:

// fib(0) = 0

// fib(1) = 1

#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n)
{
    if (n == 0)
        return 0; // 🧱 Base case 1
    if (n == 1)
        return 1; // 🧱 Base case 2

    // 🔁 Recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n = 6;
    cout << "Fibonacci number at position " << n << " is: " << fibonacci(n) << endl;
    return 0;
}

// 🕒 Time & Space Complexity

// | Metric           | Value                    |
// | ---------------- | ------------------------ |
// | Time Complexity  | O(2ⁿ) (very inefficient) |
// | Space Complexity | O(n) (due to call stack) |

// ⚠️ Why is this inefficient?

// Many values are recomputed.

// Example: fibonacci(5) calls fibonacci(4) and fibonacci(3), but fibonacci(4) again calls fibonacci(3)...

// 💡 Better Alternatives

// Memoization (top-down): Store previously computed results.

// Dynamic Programming (bottom-up): Use iteration and arrays.

// Formula (Binet's formula): For direct computation (rarely used in practice due to precision issues).