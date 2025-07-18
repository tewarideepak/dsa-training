// ✅ What is Quick Sort?

// A Divide and Conquer sorting algorithm.

// Picks a pivot element, partitions the array around the pivot, and recursively sorts the subarrays.

// 🧠 Key Concepts

// Pivot Selection

// Can be the first, last, middle, or random element.

// Common choice: last element in the array.

// Partitioning

// Rearranges elements:

//     Elements < pivot go to left.

//     Elements > pivot go to right.

// Places pivot in its correct sorted position.

// Recursion

// Recursively apply Quick Sort to left and right subarrays.

// 🧾 Algorithm Steps

// Choose pivot (commonly last element).

// Partition the array:

// Place pivot in its correct position.

// Ensure all smaller elements are before it, larger after it.

// Recursively sort left and right subarrays.

// 🔢 C++ Code (Using Lomuto Partition Scheme)

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;

    while (true)
    {
        // Move right until we find an element >= pivot
        do
        {
            i++;
        } while (arr[i] < pivot);

        // Move left until we find an element <= pivot
        do
        {
            j--;
        } while (arr[j] > pivot);

        // If two pointers met or crossed
        if (i >= j)
            return j;

        // Swap out-of-place elements
        swap(arr[i], arr[j]);
    }
}

void quickSortHelper(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quickSortHelper(arr, low, p);
        quickSortHelper(arr, p + 1, high);
    }
}

vector<int> quickSort(vector<int> arr)
{
    quickSortHelper(arr, 0, arr.size() - 1);
    return arr;
}

// 🧪 Example

int main()
{
    vector<int> arr = {9, 9, 9, 8, 2, 3, -6};
    vector<int> sorted = quickSort(arr);

    for (int num : sorted)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// After sorting: 1 5 7 8 9 10
// ⏱️ Time Complexity
// Case	Time Complexity
// Best	O(n log n) (When pivot is middle)
// Average	O(n log n)
// Worst	O(n²) (unbalanced partitions)

// Space Complexity: O(log n) due to recursion stack

// ✅ Advantages

// Faster in practice than most O(n log n) algorithms.

// In-place (no extra memory required).

// Well-suited for large datasets.

// ❌ Disadvantages

// Unstable (doesn’t preserve relative order of equal elements).

// Worst-case is O(n²) (e.g., when array is already sorted and pivot is always smallest/largest).