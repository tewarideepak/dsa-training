// Write a function that reverses a string. The input string is given as an array of characters s.

// You must do this by modifying the input array in-place with O(1) extra memory.

// Example 1:

// Input: s = ["h","e","l","l","o"]
// Output: ["o","l","l","e","h"]

// Example 2:

// Input: s = ["H","a","n","n","a","h"]
// Output: ["h","a","n","n","a","H"]

// Constraints:

//     1 <= s.length <= 105
//     s[i] is a printable ascii character.

#include <iostream>
#include <vector>
using namespace std;

void reverseString(vector<char> &s)
{
    int left = 0, right = s.size() - 1;

    while (left < right)
    {
        swap(s[left++], s[right--]);
    }
}

void reverse(char name[], int n)
{
    int left = 0, right = n - 1;

    while (left < right)
    {
        swap(name[left], name[right]);
        left++;
        right--;
    }
}

int getLength(char name[])
{
    int count = 0;

    for (int i = 0; name[i] != '\0'; i++)
    {
        count++;
    }

    return count;
}

int main()
{
    char name[20] = "Deepak Tewari";
    cout << name << endl;
    int length = getLength(name);
    cout << "Length: " << length << endl;

    reverse(name, length);

    cout << "Reverse: " << name << endl;

    return 0;
}