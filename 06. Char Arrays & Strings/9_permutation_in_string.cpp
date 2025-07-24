// Given two strings s1 and s2, return true if s2 contains a

// of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.

// Example 1:

// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").

// Example 2:

// Input: s1 = "ab", s2 = "eidboaoo"
// Output: false

// Constraints:

//     1 <= s1.length, s2.length <= 104
//     s1 and s2 consist of lowercase English letters.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool checkInclusion(string s1, string s2)
{
    int m = s1.size(), n = s2.size();

    if (m > n)
        return false;

    vector<int> count1(26, 0), count2(26, 0);

    // Initialize frequency counts for s1 and the first window of s2
    for (int i = 0; i < m; i++)
    {
        count1[s1[i] - 'a']++;
        count2[s2[i] - 'a']++;
    }

    // Check if the first window matches
    if (count1 == count2)
        return true;

    // Slide the window over s2
    for (int i = m; i < n; i++)
    {
        count2[s2[i] - 'a']++;     // Add new character
        count2[s2[i - m] - 'a']--; // Remove old character

        if (count1 == count2)
            return true;
    }

    return false;
}

int main()
{
    // Example 1
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout << "Example 1: " << (checkInclusion(s1, s2) ? "true" : "false") << endl;

    // Example 2
    s1 = "ab";
    s2 = "eidboaoo";
    cout << "Example 2: " << (checkInclusion(s1, s2) ? "true" : "false") << endl;

    // Custom Example
    s1 = "ade";
    s2 = "bcadefgh";
    cout << "Custom Example: " << (checkInclusion(s1, s2) ? "true" : "false") << endl;

    return 0;
}
