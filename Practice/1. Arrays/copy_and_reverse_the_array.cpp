// Problem statement

// You are given an array 'ARR' consisting of 'N' non-negative integers, your task is to copy the elements of 'ARR' into another array 'COPY_ARR' in reverse order.

// For example:

// If 'ARR' contains the following elements [ 1, 2, 3, 4, 5 ], then you should return another array that is equal to [ 5, 4, 3, 2, 1].

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :

// 1 <= T <= 10^2
// 1 <= N <= 10^4
// 0 <= ARR[i] <= 10^9

// Time Limit: 1 sec

// Sample Input 1 :

// 2
// 5
// 1 2 3 4 5
// 4
// 5 8 2 1

// Sample Output 1 :

// 5 4 3 2 1
// 1 2 8 5

// Explanation For Sample Input 1 :

// The reverse of [1, 2, 3, 4, 5] is [5, 4, 3, 2,1]
// The reverse of [5, 8, 2, 1] is [1, 2, 8, 5].

// Sample Input 2 :

// 3
// 3
// 3 2 1
// 4
// 8  6 2 4
// 5
// 1 3 5 4 2

// Sample Output 2 :

// 1 2 3
// 4 2 6 8
// 2 4 5 3 1

// Explanation For Sample Input 2 :

// The reverse of [3, 2, 1] is [1, 2, 3].
// The reverse of [8, 6, 2, 4] is [4, 2, 6, 8].
// The reverse of [1, 3, 5, 4, 2] is [2, 4, 5, 3, 1].

#include <bits/stdc++.h>
using namespace std;

vector<int> copyAndReverse(vector<int> arr, int n)
{
    vector<int> copy_arr;

    for (int i = n - 1; i >= 0; i--)
    {
        copy_arr.push_back(arr[i]);
    }

    return copy_arr;
}

int main()
{
    vector<int> input = {1, 2, 3, 4, 5};
    int n = input.size();

    vector<int> reversed = copyAndReverse(input, n);

    cout << "Original array: ";
    for (int val : input)
    {
        cout << val << " ";
    }
    cout << endl;

    cout << "Reversed copy: ";
    for (int val : reversed)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
