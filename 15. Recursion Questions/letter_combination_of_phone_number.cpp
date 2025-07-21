// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

// Example 2:

// Input: digits = ""
// Output: []

// Example 3:

// Input: digits = "2"
// Output: ["a","b","c"]

// Constraints:

//     0 <= digits.length <= 4
//     digits[i] is a digit in the range ['2', '9'].

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void backtrack(const string &digits, int index, string &current, vector<string> &result, const vector<string> &mapping)
{
    if (index == digits.size())
    {
        result.push_back(current);
        return;
    }

    string letters = mapping[digits[index] - '0'];
    for (char ch : letters)
    {
        current.push_back(ch);
        backtrack(digits, index + 1, current, result, mapping);
        current.pop_back(); // backtrack
    }
}

vector<string> letterCombinations(string digits)
{
    if (digits.empty())
        return {};

    vector<string> result;
    string current;
    vector<string> mapping = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"};

    backtrack(digits, 0, current, result, mapping);
    return result;
}

int main()
{

    string digits1 = "23";
    vector<string> result1 = letterCombinations(digits1);
    for (string s : result1)
        cout << s << " ";
    cout << endl;

    string digits2 = "3456";
    vector<string> result2 = letterCombinations(digits2);
    for (string s : result2)
        cout << s << " ";
    cout << endl;

    string digits3 = "2";
    vector<string> result3 = letterCombinations(digits3);
    for (string s : result3)
        cout << s << " ";
    cout << endl;

    return 0;
}
