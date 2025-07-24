//         A
//       A B A
//     A B C B A
//   A B C D C B A
// A B C D E D C B A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << "  ";
        }

        char ch = 'A';

        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cout << ch << " ";

            if (j >= i)
                ch--;
            else
                ch++;
        }

        for (int j = 1; j <= n - i; j++)
        {
            cout << "  ";
        }
        cout << endl;
    }
    return 0;
}