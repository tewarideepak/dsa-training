// You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

// We repeatedly make duplicate removals on s until we no longer can.

// Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

// Example 1:

// Input: s = "abbaca"
// Output: "ca"
// Explanation:
// For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

// Example 2:

// Input: s = "azxxzy"
// Output: "ay"

// Constraints:

//     1 <= s.length <= 105
//     s consists of lowercase English letters.

#include <iostream>
#include <string>
using namespace std;

string removeDuplicates(string s)
{
    string result;
    int i = 0;

    while (i < s.size())
    {
        if (!result.empty() && result.back() == s[i])
        {
            result.pop_back(); // remove duplicate
        }
        else
        {
            result.push_back(s[i]); // keep current char
        }
        i++;
    }

    return result;
}

int main()
{
    // Test Case 1
    string s1 = "abbaca";
    cout << "Input: " << s1 << "\nOutput: " << removeDuplicates(s1) << endl;

    // Test Case 2
    string s2 = "azxxzy";
    cout << "Input: " << s2 << "\nOutput: " << removeDuplicates(s2) << endl;

    // Test Case 3
    string s3 = "aabbccddeeff";
    cout << "Input: " << s3 << "\nOutput: " << removeDuplicates(s3) << endl;

    // Test Case 4
    string s4 = "abcddcba";
    cout << "Input: " << s4 << "\nOutput: " << removeDuplicates(s4) << endl;

    return 0;
}
