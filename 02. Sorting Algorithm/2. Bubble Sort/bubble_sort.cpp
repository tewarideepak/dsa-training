// 🎯 Goal

// Sort an array by repeatedly swapping adjacent elements if they are in the wrong order.
// 🧠 How It Works

// Compare each pair of adjacent elements.

// If the left element is greater than the right one, swap them.

// After each pass, the largest element bubbles up to the correct position at the end.

// 🔁 Steps

// For array of size n:

// for i from 0 to n-1:
//  for j from 0 to n-i-1:
//      if arr[j] > arr[j+1]:
//          swap arr[j] and arr[j+1]

// 💻 C++ Code

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // Optimization: stop if already sorted
        if (!swapped)
            break;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// 🧪 Example
// Input:

// int arr[] = {5, 1, 4, 2, 8};

// Passes:

// [1, 5, 4, 2, 8]

// [1, 4, 2, 5, 8]

// [1, 2, 4, 5, 8]

// Output:

// 1 2 4 5 8

// ✅ Properties of Bubble Sort
// Feature	Detail
// Time Complexity	O(n²) worst and average
// Best Case (sorted)	O(n) with optimization
// Space Complexity	O(1) (In-place)
// Stable	✅ Yes
// In-place	✅ Yes
// ⚙️ Why Bubble Sort is Stable

// It only swaps adjacent elements, so equal elements stay in the same relative order.
// 🚫 When Not to Use

// Inefficient for large datasets

// Consider Merge Sort or Quick Sort instead

// ⚙️ What Does "Adaptive" Mean in Sorting Algorithms?

// A sorting algorithm is called adaptive if it takes advantage of existing order in the input.
// ✅ In Simple Terms:

// If the input array is already partially sorted, an adaptive algorithm performs faster than its worst-case time.
// 🧠 Is Insertion Sort Adaptive?

// 👉 Yes!

// Insertion Sort is adaptive because:

//     It skips unnecessary comparisons and shifts if elements are already in the correct order.

//     For nearly sorted arrays, it runs in linear time: O(n)

// 📊 Example

// For this nearly sorted array:

// int arr[] = {1, 2, 3, 5, 4, 6, 7};

//     Only one element (4) is out of place.

//     Insertion Sort quickly places it, doing minimal work.

// ➡️ Much faster than the usual O(n²)
// ❌ Is Bubble Sort Adaptive?

//     Yes, if it's implemented with a flag to detect if swaps happened in a pass.

//     Otherwise, plain Bubble Sort without that flag is not adaptive.

// ✅ Summary
// Algorithm	Adaptive?	Why
// Insertion Sort	✅ Yes	Skips over already sorted parts
// Bubble Sort	✅ Yes (with flag)	Stops early if no swaps
// Selection Sort	❌ No	Always scans full unsorted part