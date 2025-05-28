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

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }

        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // Partition index
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}

// 🧪 Example

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);

    for (int a : arr)
    {
        cout << a << " ";
    }
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