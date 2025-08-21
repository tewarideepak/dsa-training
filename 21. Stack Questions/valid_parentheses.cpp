//  Problem statement

// You're given a string 'S' consisting of "{", "}", "(", ")", "[" and "]" .

// Return true if the given string 'S' is balanced, else return false.

// For example:

// 'S' = "{}()".

// There is always an opening brace before a closing brace i.e. '{' before '}', '(' before ').
// So the 'S' is Balanced.

// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1 :

// [()]{}{[()()]()}

// Sample Output 1 :

// Balanced

// Explanation Of the Sample Input 1 :

// There is always an opening brace before a closing brace i.e. '{' before '}', '(' before '), '[' before ']'.
// So the 'S' is Balanced.

// Sample Input 2 :

// [[}[

// Sample Output 2 :

// Not Balanced

// Constraints:

// 1 <= 'N' <= 10^5

// Where 'N' is the length of the input string 'S'.

#include <bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string s)
{
    stack<char> st;

    for (char c : s)
    {
        // If opening bracket, push to stack
        if (c == '(' || c == '{' || c == '[')
        {
            st.push(c);
        }
        // If closing bracket, check stack
        else
        {
            if (st.empty())
                return false; // No matching opening

            char top = st.top();
            st.pop();

            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '['))
            {
                return false; // Mismatched pair
            }
        }
    }

    // If stack is empty, all brackets matched
    return st.empty();
}

// Example usage (no user input required)
int main()
{
    string s1 = "[()]{}{[()()]()}";
    string s2 = "[[}[";

    cout << (isValidParenthesis(s1) ? "Balanced" : "Not Balanced") << endl;
    cout << (isValidParenthesis(s2) ? "Balanced" : "Not Balanced") << endl;

    return 0;
}

// ⏱ Time Complexity (TC):

// Each character is pushed and popped at most once → O(N)

// 💾 Space Complexity (SC):

// Stack can hold at most N/2 opening brackets → O(N)