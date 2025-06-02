// 🎯 Goal

//     Reverse an array arr[] of size n using recursion.

// 🧠 Key Idea

//     Swap elements from the beginning and end of the array:

//         arr[start] ↔ arr[end]

//     Recursively reverse the inner subarray: start + 1 to end - 1

// 🧩 Base Case

//     When start >= end, stop recursion.

#include <bits/stdc++.h>
using namespace std;

void reverseArray(int arr[], int start, int end)
{
    if (start >= end)
        return; // 🧱 Base case

    // 🔄 Swap elements at start and end
    swap(arr[start], arr[end]);

    // 🔁 Recurse for the rest
    reverseArray(arr, start + 1, end - 1);
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    reverseArray(arr, 0, n - 1); // Call recursion

    cout << "Reversed array: ";
    printArray(arr, n);

    return 0;
}

// 🔍 Time & Space Complexity

// Time: O(n)

// Space: O(n) due to recursive call stack