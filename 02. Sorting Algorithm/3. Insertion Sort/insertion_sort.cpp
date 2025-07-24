// 🎯 Goal

// Sort an array by building a sorted part one element at a time, like sorting playing cards in your hand.
// 🧠 How It Works

// Start with the second element and compare it with elements before it.

// Insert the current element into the correct position in the sorted portion of the array (left side).

// 🔁 Steps

// For an array of size n:

// for i from 1 to n-1:
// key = arr[i]
// j = i - 1
// while j >= 0 and arr[j] > key:
//     arr[j + 1] = arr[j]
//     j = j - 1
// arr[j + 1] = key

// 💻 C++ Code

#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i]; // current element to insert
        int j = i - 1;

        // shift elements of arr[0..i-1] that are greater than key
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j]; // move element right
            j--;
        }
        arr[j + 1] = key; // insert key in correct position
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

// int arr[] = {5, 2, 4, 6, 1, 3};

// Steps:

// i=1, key=2 → Insert before 5 → [2, 5, 4, 6, 1, 3]

// i=2, key=4 → Insert before 5 → [2, 4, 5, 6, 1, 3]

// i=3, key=6 → No change

// i=4, key=1 → Insert at start → [1, 2, 4, 5, 6, 3]

// i=5, key=3 → Insert between 2 and 4 → [1, 2, 3, 4, 5, 6]

// Output:

// 1 2 3 4 5 6

// ✅ Properties of Insertion Sort
// Feature	Value
// Time Complexity	O(n²) worst & average
// Best Case (sorted)	O(n)
// Space Complexity	O(1) (in-place)
// Stable	✅ Yes
// In-place	✅ Yes
// ✅ Why It’s Stable

// Equal elements are not swapped over each other, so original order is preserved.

// 👍 When to Use

// Small arrays

// Nearly sorted arrays (best case O(n))

// When stability is important