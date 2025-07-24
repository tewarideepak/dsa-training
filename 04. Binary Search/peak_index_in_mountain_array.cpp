// You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

// Return the index of the peak element.

// Your task is to solve it in O(log(n)) time complexity.

// Example 1:

// Input: arr = [0,1,0]

// Output: 1

// Example 2:

// Input: arr = [0,2,1,0]

// Output: 1

// Example 3:

// Input: arr = [0,10,5,2]

// Output: 1

// Constraints:

//     3 <= arr.length <= 105
//     0 <= arr[i] <= 106
//     arr is guaranteed to be a mountain array.

#include <bits/stdc++.h>
using namespace std;

int peakElement(vector<int> &arr, int n)
{
    int start = 0, end = n - 1;

    while (start < end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] < arr[mid + 1])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }

    return start; // or return end, both are same at this point
}

int peakIndexInMountainArray(vector<int> &arr)
{
    return peakElement(arr, arr.size());
}

int main()
{
    vector<int> arr = {0, 2, 3, 4, 5, 3, 1}; // Mountain array
    int peakIndex = peakIndexInMountainArray(arr);
    cout << "Peak element index: " << peakIndex << endl;
    cout << "Peak element value: " << arr[peakIndex] << endl;
    return 0;
}
