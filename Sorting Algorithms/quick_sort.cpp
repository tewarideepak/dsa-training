// ## Quick Sort

// Quick Sort is a divide-and-conquer algorithm like the Merge Sort. But unlike Merge sort, this algorithm does not use any extra array for sorting(though it uses an auxiliary stack space). So, from that perspective, Quick sort is slightly better than Merge sort.

// This algorithm is basically a repetition of two simple steps that are the following:

//     Pick a pivot and place it in its correct place in the sorted array.
//     Shift smaller elements(i.e. Smaller than the pivot) on the left of the pivot and larger ones to the right.

// Now, let’s discuss the steps in detail considering the array {4,6,2,5,7,9,1,3}:

// Step 1: The first thing is to choose the pivot. A pivot is basically a chosen element of the given array. The element or the pivot can be chosen by our choice. So, in an array a pivot can be any of the following:

//     The first element of the array
//     The last element of the array
//     Median of array
//     Any Random element of the array

// After choosing the pivot(i.e. the element), we should place it in its correct position(i.e. The place it should be after the array gets sorted) in the array. For example, if the given array is {4,6,2,5,7,9,1,3}, the correct position of 4 will be the 4th position.

// Step 2: In step 2, we will shift the smaller elements(i.e. Smaller than the pivot) to the left of the pivot and the larger ones to the right of the pivot. In the example, if the chosen pivot is 4, after performing step 2 the array will look like: {3, 2, 1, 4, 6, 5, 7, 9}. 

// From the explanation, we can see that after completing the steps, pivot 4 is in its correct position with the left and right subarray unsorted. Now we will apply these two steps on the left subarray and the right subarray recursively. And we will continue this process until the size of the unsorted part becomes 1(as an array with a single element is always sorted).

// To summarize, the main intention of this process is to place the pivot, after each recursion call, at its final position, where the pivot should be in the final sorted array.

// Approach:

// The algorithm steps are the following for the quickSort() function:

//    - Initially, the low points to the first index and the high points to the last index(as the range is n i.e. the size of the array). 
//    - After that, we will get the index(where the pivot should be placed after sorting) while shifting the smaller elements on the left and the larger ones on the right using a partition() function discussed later.
//    - Now, this index can be called the partition index as it creates a partition between the left and the right unsorted subarrays.
//    - After placing the pivot in the partition index(within the partition() function specified), we need to call the function quickSort() for the left and the right subarray recursively. So, the range of the left subarray will be [low to (partition index - 1)] and the range of the right subarray will be [(partition index + 1) to high]. 
//    - This is how the recursion will continue until the range becomes 1.

// Now, let’s understand how to implement the partition() function to get the partition index.

//    - Inside the function, we will first select the pivot(i.e. arr[low] in our case).
//    - Now, we will again take two-pointers i and j. The i pointer points to low and the j points to high.
//    - Now, the pointer i will move forward and find the first element that is greater than the pivot. Similarly, the pointer j will move backward and find the first element that is smaller than the pivot.
//    - Here, we need to add some checks like i <= high-1 and j >= low+1. Because it might happen that i is standing at high and trying to proceed or j is standing at low and trying to exceed.
//    - Once we find such elements i.e. arr[i] > pivot and arr[j] < pivot, and i < j, we will swap arr[i] and arr[j].
//    - We will continue step 3 and step 4, until j becomes smaller than i.
//    - Finally, we will swap the pivot element(i.e. arr[low]) with arr[j] and will return the index j i.e. the partition index.

// Code:

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }

        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void qs(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
}

vector<int> quickSort(vector<int> arr) {
    qs(arr, 0, arr.size() - 1);
    return arr;
}

int main()
{
    vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
    int n = arr.size();
    cout << "Before Using quick Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr = quickSort(arr);
    cout << "After Using quick sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}

// Output:
// Before Using quick Sort:
// 4 6 2 5 7 9 1 3
// After Using quick sort:
// 1 2 3 4 5 6 7 9 

// Time Complexity: O(N*logN), where N = size of the array.

// Reason: At each step, we divide the whole array, for that logN and n steps are taken for the partition() function, so overall time complexity will be N*logN.

// The following recurrence relation can be written for Quick sort : 

// F(n) = F(k) + F(n-1-k) 

// Here k is the number of elements smaller or equal to the pivot and n-1-k denotes elements greater than the pivot.

// There can be 2 cases :

// Worst Case – This case occurs when the pivot is the greatest or smallest element of the array. If the partition is done and the last element is the pivot, then the worst case would be either in the increasing order of the array or in the decreasing order of the array. 

// Recurrence:
// F(n) = F(0)+F(n-1)  or  F(n) = F(n-1) + F(0) 

// Worst Case Time complexity: O(n2) 

// Best Case – This case occurs when the pivot is the middle element or near to middle element of the array.
// Recurrence :
// F(n) = 2F(n/2)

// Time Complexity for the best and average case: O(N*logN)

// Space Complexity: O(1) + O(N) auxiliary stack space.


