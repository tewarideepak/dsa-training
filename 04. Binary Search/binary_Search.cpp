// 🧠 Key Points to Remember

// | Concept                   | Description                                             |
// | ------------------------- | ------------------------------------------------------- |
// | Works only on sorted data | Must sort the array first if unsorted                   |
// | Midpoint calculation      | Use `mid = start + (end - start) / 2` to avoid overflow |
// | Time complexity           | `O(log n)`                                              |
// | When to stop              | `start > end` means element not found                   |

#include <iostream>
using namespace std;

// Binary Search Function (Iterative)
int binarySearch(int arr[], int n, int target)
{
    int start = 0;
    int end = n - 1;

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

int main()
{
    int arr[] = {2, 4, 10, 15, 18, 22, 27};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 15;

    int result = binarySearch(arr, size, target);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found!" << endl;

    return 0;
}
