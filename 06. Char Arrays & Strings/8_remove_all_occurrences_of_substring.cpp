// Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

//     Find the leftmost occurrence of the substring part and remove it from s.

// Return s after removing all occurrences of part.

// A substring is a contiguous sequence of characters in a string.

// Example 1:

// Input: s = "daabcbaabcbc", part = "abc"
// Output: "dab"
// Explanation: The following operations are done:
// - s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
// - s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
// - s = "dababc", remove "abc" starting at index 3, so s = "dab".
// Now s has no occurrences of "abc".

// Example 2:

// Input: s = "axxxxyyyyb", part = "xy"
// Output: "ab"
// Explanation: The following operations are done:
// - s = "axxxxyyyyb", remove "xy" starting at index 4 so s = "axxxyyyb".
// - s = "axxxyyyb", remove "xy" starting at index 3 so s = "axxyyb".
// - s = "axxyyb", remove "xy" starting at index 2 so s = "axyb".
// - s = "axyb", remove "xy" starting at index 1 so s = "ab".
// Now s has no occurrences of "xy".

// Constraints:

//     1 <= s.length <= 1000
//     1 <= part.length <= 1000
//     s​​​​​​ and part consists of lowercase English letters.

#include <iostream>
#include <string>
using namespace std;

// string removeOccurrences(string s, string part) {
//     while(s.length() != 0 && s.find(part) != string::npos){
//         s.erase(s.find(part), part.length());
//     }

//     return s;
// }

string removeOccurrences(string s, string part)
{
    size_t index = s.find(part);
    while (index != string::npos)
    {
        s.erase(index, part.length());
        index = s.find(part);
    }
    return s;
}

// string removeOccurrences(string s, string part)
// {
//     string result;
//     int partLen = part.length();

//     for (char ch : s)
//     {
//         result += ch;

//         // If the end of result matches the part, remove it
//         if (result.size() >= partLen &&
//             result.substr(result.size() - partLen) == part)
//         {
//             result.erase(result.end() - partLen, result.end());
//         }
//     }

//     return result;
// }

int main()
{
    string s, part;

    // Take input
    cout << "Enter the main string: ";
    getline(cin, s);
    cout << "Enter the part to remove: ";
    cin >> part;

    // Get the result
    string result = removeOccurrences(s, part);

    // Output the final string
    cout << "Result after removing all occurrences: " << result << endl;

    return 0;
}
