// Given a string s of lowercase alphabets. The task is to find the maximum occurring character in the string s. If more than one character occurs the maximum number of times then print the lexicographically smaller character.

// Examples:

// Input: s = "testsample"
// Output: 'e'
// Explanation: e is the character which is having the highest frequency.

// Input: s = "output"
// Output: 't'
// Explanation:  t and u are the characters with the same frequency, but t is lexicographically smaller.

// Constraints:
// 1 ≤ |s| ≤ 100

#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

char getMaxOccuringChar(string &s)
{
    vector<int> freq(128, 0); // ASCII characters range from 0 to 127

    // Count frequency of each character
    for (char ch : s)
    {
        freq[ch]++;
    }

    int maxFreq = INT_MIN;
    char ans = 0;

    // Check uppercase characters first (A-Z)
    for (char ch = 'A'; ch <= 'Z'; ch++)
    {
        if (freq[ch] > maxFreq || (freq[ch] == maxFreq && ch < ans))
        {
            maxFreq = freq[ch];
            ans = ch;
        }
    }

    // Check lowercase characters (a-z)
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        if (freq[ch] > maxFreq || (freq[ch] == maxFreq && ch < ans))
        {
            maxFreq = freq[ch];
            ans = ch;
        }
    }

    return ans;
}

// Main function to test the logic
int main()
{
    string s;
    cout << "Enter a string of lowercase or uppercase letters: ";
    cin >> s;

    char result = getMaxOccuringChar(s);
    cout << "Maximum occurring character: " << result << endl;

    return 0;
}
