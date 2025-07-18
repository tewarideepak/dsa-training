//  Problem statement

// For a given integer array/list 'ARR' of size 'N' containing all distinct values, find the total number of 'Inversions' that may exist.

// An inversion is defined for a pair of integers in the array/list when the following two conditions are met.

// A pair ('ARR[i]', 'ARR[j]') is said to be an inversion when:

// 1. 'ARR[i] > 'ARR[j]'
// 2. 'i' < 'j'

// Where 'i' and 'j' denote the indices ranging from [0, 'N').

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :

// 1 <= N <= 10^5
// 1 <= ARR[i] <= 10^9

// Where 'ARR[i]' denotes the array element at 'ith' index.

// Time Limit: 1 sec

// Sample Input 1 :

// 3
// 3 2 1

// Sample Output 1 :

// 3

// Explanation of Sample Output 1:

// We have a total of 3 pairs which satisfy the condition of inversion. (3, 2), (2, 1) and (3, 1).

// Sample Input 2 :

// 5
// 2 5 1 3 4

// Sample Output 2 :

// 4

// Explanation of Sample Output 1:

// We have a total of 4 pairs which satisfy the condition of inversion. (2, 1), (5, 1), (5, 3) and (5, 4).

// Hints:

// 1. Start with the brute force approach.
// 2. Use a modified merge sort.
// 3. Iterate through the elements in sorted order and use a Fenwick tree to track the inversions.

#include <bits/stdc++.h>
using namespace std;

long long merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    long long count = 0;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left++]);
        }
        else
        {
            temp.push_back(arr[right++]);
            count += mid - left + 1;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; ++i)
    {
        arr[i] = temp[i - low];
    }

    return count;
}

long long mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return 0;
    long long count = 0;
    int mid = low + (high - low) / 2;
    count += mergeSort(arr, low, mid);
    count += mergeSort(arr, mid + 1, high);
    count += merge(arr, low, mid, high);
    return count;
}

long long getInversions(long long *arr, int n)
{
    vector<int> a(arr, arr + n);
    return mergeSort(a, 0, n - 1);
}

int main()
{
    long long arr[] = {2, 4, 1, 3, 5};
    int n = 5;

    cout << "Number of inversions: " << getInversions(arr, n) << endl;
    return 0;
}