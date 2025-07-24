//  Problem statement

// You have been given a sorted array/list 'arr' consisting of ‘n’ elements. You are also given an integer ‘k’.

// Now the array is rotated at some pivot point unknown to you.

// For example, if 'arr' = [ 1, 3, 5, 7, 8], then after rotating 'arr' at index 3, the array will be 'arr' = [7, 8, 1, 3, 5].

// Now, your task is to find the index at which ‘k’ is present in 'arr'.

// Note :

// 1. If ‘k’ is not present in 'arr', then print -1.
// 2. There are no duplicate elements present in 'arr'.
// 3. 'arr' can be rotated only in the right direction.

// Example:

// Input: 'arr' = [12, 15, 18, 2, 4] , 'k' = 2

// Output: 3

// Explanation:
// If 'arr' = [12, 15, 18, 2, 4] and 'k' = 2, then the position at which 'k' is present in the array is 3 (0-indexed).

// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:

// 4 3
// 8 9 4 5

// Sample output 1:

// -1

// Explanation of Sample Output 1:

// For the test case, 3 is not present in the array. Hence the output will be -1.

// Sample Input 2:

// 4 3
// 2 3 5 8

// Sample output 2:

// 1

// Expected Time Complexity:

// Try to do this in O(log(n)).

// Constraints:

// 1 <= n <= 10^5
// 0 <= k <= 10^9
// 0 <= arr[i] <= 10^9

// Time Limit: 1 second

#include <bits/stdc++.h>
using namespace std;

int searchAnother(vector<int> &arr, int n, int k)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        // if mid points the target
        if (arr[mid] == k)
            return mid;

        // if left part is sorted:
        if (arr[low] <= arr[mid])
        {
            if (arr[low] <= k && k <= arr[mid])
            {
                // element exists:
                high = mid - 1;
            }
            else
            {
                // element does not exist:
                low = mid + 1;
            }
        }
        else
        { // if right part is sorted:
            if (arr[mid] <= k && k <= arr[high])
            {
                // element exists:
                low = mid + 1;
            }
            else
            {
                // element does not exist:
                high = mid - 1;
            }
        }
    }
    return -1;
}

int binarySearch(vector<int> &arr, int s, int e, int target)
{
    int start = s;
    int end = e;

    while (start <= end)
    {
        // Find the middle index
        int mid = start + (end - start) / 2;

        // Check if mid is the target
        if (arr[mid] == target)
            return mid;

        // If target is greater, ignore left half
        else if (arr[mid] < target)
            start = mid + 1;

        // If target is smaller, ignore right half
        else
            end = mid - 1;
    }

    // Target not found
    return -1;
}

int getPivot(vector<int> &arr, int n)
{
    int start = 0, end = n - 1;

    while (start < end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] >= arr[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }

    return start;
}

int search(vector<int> &arr, int n, int k)
{
    int pivot = getPivot(arr, n);

    if (arr[pivot] <= k && k <= arr[n - 1])
    {
        return binarySearch(arr, pivot, n - 1, k);
    }
    else
    {
        return binarySearch(arr, 0, pivot - 1, k);
    }
}

int main()
{
    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int n = 9, k = 1;
    int ans = search(arr, n, k);
    int ans2 = searchAnother(arr, n, k);
    if (ans == -1)
        cout << "Target is not present.\n";
    else
        cout << "The index is: " << ans << "\n";

    if (ans2 == -1)
        cout << "Target is not present.\n";
    else
        cout << "The index is: " << ans2 << "\n";

    return 0;
}
