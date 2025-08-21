#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string str = "naman";

    stack<char> s;

    for (char c : str)
    {
        s.push(c);
    }
    string reversedStr = "";
    while (!s.empty())
    {
        reversedStr += s.top();
        s.pop();
    }
    cout << "Reversed string: " << reversedStr << endl;
    return 0;
}