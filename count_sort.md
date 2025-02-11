Counting Sort is a non-comparative sorting algorithm that is efficient when the range of input values is known and not very large. Instead of comparing elements directly, Counting Sort calculates the frequency of each unique element and uses that to determine their sorted position. This algorithm is most effective when the input consists of integers or items that can be mapped to integers.
Steps of Counting Sort:

    - Find the Range: Determine the range of the input values (the largest value).
    - Create a Count Array: Create an auxiliary array (count[]) that stores the frequency of each element.
    - Cumulative Count: Modify the count[] array to store the cumulative sum of counts.
    - Place Elements: Place each element from the input array into the correct position in the output array based on the cumulative counts.
    - Copy to Original: Copy the sorted elements back into the original array.


#include<bits/stdc++.h>
using namespace std;

void countingSort(vector<int>& arr) {
    int n = arr.size();
    
    // Find the maximum value in the array
    int maxVal = *max_element(arr.begin(), arr.end());
    
    // Create a count array with size maxVal + 1 (to include 0)
    vector<int> count(maxVal + 1, 0);
    
    // Count the frequency of each element
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    
    // Modify the count array by adding cumulative counts
    for (int i = 1; i <= maxVal; i++) {
        count[i] += count[i - 1];
    }
    
    // Output array to store sorted elements
    vector<int> output(n);
    
    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;  // Decrease count
    }
    
    // Copy the sorted output array back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    
    cout << "Original Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    countingSort(arr);
    
    cout << "Sorted Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}


Time Complexity:

Best, Average, and Worst: O(n+k), where:

    - n is the number of elements in the input array.
    - k is the range of the input (i.e., the maximum element in the array).

Space complexity:

O(n+k), where:

    - n is the number of elements in the input array.
    - k is the range of the input values.



When to Use Counting Sort:

    - Counting Sort is ideal when:
        - The range of numbers (k) is small or comparable to the number of elements (n).
        - You are working with integers or categorical data (non-comparative).

However, if the range is very large, the space complexity can be a concern, and other sorting algorithms like Quick Sort or Merge Sort might be more efficient.