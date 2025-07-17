#include <iostream>
using namespace std;

int power(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    else if (b == 1)
    {
        return a;
    }
    else
    {
        int ans = power(a, b / 2);

        if (b % 2 == 0)
        {
            return ans * ans;
        }
        else
        {
            return a * ans * ans;
        }
    }
}

int main()
{
    int a = 2, b = 6;

    int ans = power(a, b);

    cout << "Answer: " << ans << endl;
}

// 🔍 What is power(a, b) ?

//                        It calculates abab(i.e., "a raised to the power b").
// 🧠 Concept Behind the Recursive Solution

//   This recursive function uses Divide and Conquer to reduce the number of multiplications.Key Idea:

//                        Instead of multiplying a b times,
//     we break the problem into smaller parts :

//     If b is even : a^b = (a^(b / 2))^2

//                     If b is odd : a^b = a⋅(a^(b / 2))^2

//           This reduces time complexity from O(b) to O(log b).

// 🔁 Equivalent Iterative(Loop)
// Solution

//     Here’s how you can write the same logic using a
//     loop(also with exponentiation by squaring) :

#include <iostream>
using namespace std;

int power(int a, int b)
{
    int result = 1;

    while (b > 0)
    {
        // If b is odd, multiply a to result
        if (b % 2 == 1)
        {
            result *= a;
        }

        // Square the base
        a *= a;

        // Divide exponent by 2
        b /= 2;
    }

    return result;
}

int main()
{
    int a = 2, b = 6;

    int ans = power(a, b);

    cout << "Answer: " << ans << endl;
}

// ✅ Example for a = 2, b = 6:

// Let’s walk through the recursive steps:

//     power(2, 6) → even → power(2, 3)^2

//     power(2, 3) → odd → 2 * power(2, 1)^2

//     power(2, 1) → base case → return 2

// Then working back:

//     power(2, 3) = 2 * 2 * 2 = 8

//     power(2, 6) = 8 * 8 = 64

// Final output: 64
// ✅ Time Complexity:

//     Recursive version: O(log b)

//     Iterative version: O(log b)

// Much faster than naive O(b) approach!