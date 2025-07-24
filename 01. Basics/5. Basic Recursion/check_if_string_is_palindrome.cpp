// 🔁 Definition

// A palindrome is a string that reads the same forward and backward.

// Example: "madam", "racecar" → Palindrome

// "hello" → Not a palindrome

// 🧠 Approach (Recursive)

// Use two indices: start (beginning) and end (end).

// Base case:

// If start >= end → return true (all characters matched).

// Recursive case:

// If s[start] != s[end] → return false.

// Otherwise, recurse with start + 1 and end - 1.

#include <iostream>
using namespace std;

bool isPalindrome(string s, int start, int end)
{
    if (start >= end)
        return true; // 🧱 Base case

    if (s[start] != s[end])
        return false; // ❌ Mismatch

    return isPalindrome(s, start + 1, end - 1); // 🔁 Recurse on substring
}

int main()
{
    string s = "racecar";

    if (isPalindrome(s, 0, s.length() - 1))
        cout << s << " is a palindrome." << endl;
    else
        cout << s << " is not a palindrome." << endl;

    return 0;
}

// 🕒 Time & Space Complexity

// | Metric           | Value                                 |
// | ---------------- | ------------------------------------- |
// | Time Complexity  | O(n)                                  |
// | Space Complexity | O(n) (recursion stack for n/2 levels) |
