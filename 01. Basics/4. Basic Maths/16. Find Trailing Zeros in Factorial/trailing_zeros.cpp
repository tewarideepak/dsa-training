// ❓ What are Trailing Zeros?

// Zeros at the end of a number.

// Example:

// 120 → 1 trailing zero

// 100! ends with multiple zeros

// 🤔 Why Do Trailing Zeros Occur in Factorials?

// Factorial (n!) = n × (n-1) × (n-2) × ... × 1

// A trailing zero is created by a multiple of 10

// 10 = 2 × 5

// In n!, there are more multiples of 2 than of 5.

// So, count the number of 5s in the prime factors of numbers from 1 to n.

// ✅ Key Insight

// The number of trailing zeros in n! =
// ⌊n/5⌋ + ⌊n/25⌋ + ⌊n/125⌋ + ... until n/5^k is 0

// 💻 C++ Code

#include <iostream>
using namespace std;

int countTrailingZeros(int n)
{
    int count = 0;
    for (int i = 5; n / i >= 1; i *= 5)
    {
        count += n / i;
    }
    return count;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Trailing zeros in " << n << "! = " << countTrailingZeros(n) << endl;
    return 0;
}

// 🧠 Explanation

// n / 5 → counts numbers divisible by 5

// n / 25 → counts additional multiples of 25 (which have two 5s)

// Continue with n / 125, etc.

// 📈 Time Complexity

// O(log₅ n) – because we divide n by powers of 5

// 🧪 Example

// n = 100

// 100/5   = 20
// 100/25  = 4
// 100/125 = 0 → stop

// Total = 20 + 4 = 24 trailing zeros