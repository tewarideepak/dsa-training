// Given an integer n, return the number of prime numbers that are strictly less than n.

// Example 1:

// Input: n = 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

// Example 2:

// Input: n = 0
// Output: 0

// Example 3:

// Input: n = 1
// Output: 0

// Constraints:

//     0 <= n <= 5 * 106

#include <iostream>
#include <vector>
using namespace std;

int countPrimes(int n)
{
    if (n < 2)
        return 0;

    // Step 1: Initialize isPrime array
    vector<bool> isPrime(n, true);
    isPrime[0] = isPrime[1] = false;

    // Step 2: Mark non-primes using Sieve of Eratosthenes
    for (int i = 2; i * i < n; ++i)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j < n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    // Step 3: Count all primes
    int count = 0;
    for (int i = 2; i < n; ++i)
    {
        if (isPrime[i])
            count++;
    }

    return count;
}

// Driver code
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int result = countPrimes(n);
    cout << "Number of primes less than " << n << " is: " << result << endl;
    return 0;
}

// ⏱ Time Complexity: O(n log log n)

// This is the known time complexity of the Sieve of Eratosthenes.

//     The outer loop runs up to √n.

//     The inner loop for each prime i marks multiples, and overall marking happens ~ n/2 + n/3 + n/5 + ... which converges to O(n log log n).

// 📦 Space Complexity: O(n)

//     We use a vector<bool> of size n to store whether each number is prime.