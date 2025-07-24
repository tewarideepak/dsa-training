// 🎯 Goal

// Sort an array in ascending (or descending) order by repeatedly selecting the minimum (or maximum) element and moving it to its correct position.
// 🧠 How It Works

// Think of sorting cards in your hand from smallest to largest.

// In each pass:

// Find the smallest element in the unsorted part.

// Swap it with the first unsorted element.

// 🔁 Steps

// For array of size n:

// for (i = 0 to n-1):
// - assume i is the index of the minimum element
// for (j = i+1 to n-1):
// - if arr[j] < arr[min_index], update min_index
// - swap arr[i] and arr[min_index]

// 💻 C++ Code

#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        // Find the minimum in remaining array
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
                min_index = j;
        }
        // Swap the found min with current element
        swap(arr[i], arr[min_index]);
    }
}

// Utility to print array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// 🧪 Example
// Input:

// int arr[] = {64, 25, 12, 22, 11};

// Steps:

// Smallest from index 0–4 is 11 → Swap with 64

// Smallest from index 1–4 is 12 → Swap with 25

// Smallest from index 2–4 is 22 → Swap with 64

// Smallest from index 3–4 is 64 → Swap with 64

// Output:

// 11 12 22 25 64

// 🧮 Time Complexity
// Case	Time
// Best case	O(n²)
// Average case	O(n²)
// Worst case	O(n²)

// Always does n(n-1)/2 comparisons

// Only n swaps (better than bubble sort)

// ✅ When to Use

// Good for small datasets

// When memory writes should be minimized

// ❌ Not Stable

// Selection sort is not stable unless explicitly modified

// Let me know if you'd like:

// A descending order version

// A visual step-by-step table

// Sorting objects with custom comparisons

// You said:
// is it in place?
// ChatGPT said:

// Yes, Selection Sort is an in-place sorting algorithm ✅

// 📌 What Does In-Place Mean?

// An algorithm is in-place if it requires only a constant amount of extra memory (O(1)), meaning:

// It modifies the original array directly.

// It does not use extra arrays or significant additional memory.

// ✅ Why Selection Sort is In-Place:

// It just uses a few variables like i, j, min_index for looping and swapping.

// All operations happen within the original array.

// No new data structures (like temporary arrays or lists) are created.

// 🧠 Summary
// Property	Selection Sort
// In-place	✅ Yes
// Stable	❌ No (by default)
// Time Complexity	O(n²)
// Space Complexity	O(1)

// ❓ Does Selection Sort retain the order of same (equal) numbers?

// 👉 No, by default, Selection Sort is not stable.
// 🧠 What Does "Stable" Mean?

// A stable sorting algorithm keeps the relative order of equal elements the same as in the original array.
// 🔍 Example:

// Suppose we sort this array of pairs by value:

// [(10, 'a'), (10, 'b'), (5, 'x')]

// A stable sort would result in:

// [(5, 'x'), (10, 'a'), (10, 'b')]

// But Selection Sort might give:

// [(5, 'x'), (10, 'b'), (10, 'a')] ❌

// Because during swapping, it might bring a later equal element forward.
// 🔧 Can You Make Selection Sort Stable?

// Yes, but you need to avoid swapping and instead shift elements:
// 🛠️ Modified Stable Selection Sort (concept):

// for i = 0 to n-1:
// - Find the minimum element from i to n-1
// - Instead of swapping:
// - Store the minimum element
// - Shift all elements between min_index and i to the right by 1
// - Place the min element at index i

// This avoids reversing the order of equal elements.
// ✅ Summary
// Property	Selection Sort
// In-place	✅ Yes
// Stable	❌ No (not by default)
// Can be made stable?	✅ Yes (with extra effort)