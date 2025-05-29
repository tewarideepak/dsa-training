// ✅ What is Merge Sort?

// Merge Sort is a divide and conquer algorithm.

// It divides the array into halves, sorts them, and merges the sorted halves.

// Stable sort and not in-place (requires extra space).

// ✅ Key Concepts

// Divide: Split the array into two halves.

// Conquer: Recursively sort both halves.

// Combine: Merge the two sorted halves into one sorted array.

// ✅ Time & Space Complexity

// | Case    | Time Complexity |
// | ------- | --------------- |
// | Best    | O(n log n)      |
// | Average | O(n log n)      |
// | Worst   | O(n log n)      |

// Space Complexity: O(n) (due to temporary arrays used in merging)

// Stable Sort: Yes (maintains relative order of equal elements)

// ✅ Merge Sort Code in C++

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;    // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1; // starting index of right half of arr

    // storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);      // left half
    mergeSort(arr, mid + 1, high); // right half
    merge(arr, low, mid, high);    // merging sorted halves
}

int main()
{

    vector<int> arr = {9, 4, 7, 6, 3, 1, 5};
    int n = 7;

    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    mergeSort(arr, 0, n - 1);
    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

// ✅ Summary

// Merge Sort is great for large datasets.

// Guarantees O(n log n) performance.

// Preferred in scenarios where stable sorting is required.

// Not space-efficient due to extra memory usage.

// ❓ Why temp[i - low] instead of just temp[i]?

// ✅ Because temp[] starts from index 0,

// but we're copying it into arr[] starting from index low.

// 🧠 Let's break it down:

// Suppose:

// low = 4;
// high = 7;

// So you're working with this subarray: arr[4], arr[5], arr[6], arr[7]

// When you merge, you typically create:

// vector<int> temp; // size = high - low + 1 = 4

// And fill it with sorted values starting at temp[0].

// Now, to copy temp[0] to arr[4], you need this mapping:

// arr[4] ← temp[0]      → temp[i - low] = temp[4 - 4]
// arr[5] ← temp[1]      → temp[5 - 4]
// arr[6] ← temp[2]      → temp[6 - 4]
// arr[7] ← temp[3]      → temp[7 - 4]

// ➡️ So i - low gives the correct index into the temp array.
// ❌ What happens if you just use temp[i]?

// temp[i] would be out of bounds or incorrect, because i is based on the original array's indices, not the temp array.