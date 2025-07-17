#include <iostream>
using namespace std;

bool checkPalindrome(string s, int left, int right)
{
    if (left > right)
    {
        return true;
    }
    else if (s[left] != s[right])
    {
        return false;
    }
    else
    {
        return checkPalindrome(s, left + 1, right - 1);
    }
}

int main()
{
    string name = "naman";

    bool isPalindrome = checkPalindrome(name, 0, name.size() - 1);

    cout << "Palindrome: " << isPalindrome << endl;
}
