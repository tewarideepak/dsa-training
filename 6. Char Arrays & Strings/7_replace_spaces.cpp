//  Problem statement

// You have been given a string 'STR' of words. You need to replace all the spaces between words with “@40”.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:

// 1 <= T <= 50
// 0 <= |STR| <= 100

// Where ‘|STR|’ is the length of a particular string including spaces.

// Time limit: 1 sec

// Sample Input 1:

// 2
// Coding Ninjas Is A Coding Platform
// Hello World

// Sample Output 1:

// Coding@40Ninjas@40Is@40A@40Coding@40Platform
// Hello@40World

// Explanation of Sample Output 1:

// In test case 1, After replacing the spaces with “@40” string is:

// Coding@40Ninjas@40Is@40A@40Coding@40Platform

// In test case 2, After replacing the spaces with “@40” string is:

// Hello@40World

// Sample Input 2:

// 3
// Hello
// I love coding
// Coding Ninjas India

// Sample Output 2:

// Hello
// I@40love@40coding
// Coding@40Ninjas@40India

// Explanation for Sample Output 2:

// In test case 1, After replacing the spaces with “@40” string is:

// Hello

// In test case 2, After replacing the spaces with “@40” string is:

// I@40love@40coding

// In test case 3, After replacing the spaces with “@40” string is:

// Coding@40Ninjas@40India

#include <iostream>
#include <string>
using namespace std;

string replaceSpaces(string &str)
{
    int spaceCount = 0;
    int originalLength = str.length();

    // Count spaces
    for (char ch : str)
    {
        if (ch == ' ')
            spaceCount++;
    }

    // No spaces? Return early
    if (spaceCount == 0)
        return str;

    // Resize string to accommodate extra characters (@40 = 3 chars)
    int newLength = originalLength + 2 * spaceCount;
    str.resize(newLength);

    // i = index of original string (from end)
    // j = index of new resized string (from end)
    int i = originalLength - 1;
    int j = newLength - 1;

    // Traverse backwards and fill characters
    while (i >= 0)
    {
        if (str[i] == ' ')
        {
            str[j--] = '0';
            str[j--] = '4';
            str[j--] = '@';
        }
        else
        {
            str[j--] = str[i];
        }
        i--;
    }

    return str;
}

// string replaceSpaces(string &str)
// {
//     string result;
//     for (char ch : str)
//     {
//         if (ch == ' ')
//             result += "@40";
//         else
//             result += ch;
//     }
//     return result;
// }

int main()
{
    int T;
    cin >> T;
    cin.ignore(); // To consume the newline after reading T

    while (T--)
    {
        string str;
        getline(cin, str); // Read the entire line including spaces
        cout << replaceSpaces(str) << endl;
    }

    return 0;
}
