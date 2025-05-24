//      *
//     ***
//    *****
//   *******
//  *********
//  *********
//   *******
//    *****
//     ***
//      *

#include <bits/stdc++.h>
using namespace std;

int main()
{
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5 - i; j++)
        {
            cout << " ";
        }

        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cout << "*";
        }

        for (int j = 1; j <= 5 - i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }

    for (int i = 5; i > 0; i--)
    {
        for (int j = 1; j <= 5 - i; j++)
        {
            cout << " ";
        }

        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cout << "*";
        }

        for (int j = 1; j <= 5 - i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }

    return 0;
}