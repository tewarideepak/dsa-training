// Rules:

// 1. For the outer loop, count the number of lines

// 2. For the inner loop, focus on the columns and connect them somehow to the rows

// 3. Print the '*' inside the inner loop

// 4. Observe symmetry [optional]

// ****
// ****
// ****
// ****

// 1st:

// for(i=0; i<5; i++)

// 2nd:

// 0 -> 4
// 1 -> 4
// 2 -> 4
// 3 -> 4

// for(i=0; i<4; i++)
// for(j=0; j< 4; j++)

// 3rd:

// for(i=0; i<4; i++){
// for(j=0; j< 4; j++){
// cout<<"*";
// }
// cout<<endl;    // For moving to next line after printing a row
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}
