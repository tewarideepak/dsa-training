Shell Sort is an optimization of the Insertion Sort algorithm. It works by sorting elements that are far apart from each other and progressively reducing the gap between them. The main idea is to allow elements to move faster towards their correct positions.
How Shell Sort Works

- Select an initial gap (typically, half the array size).
- Compare elements that are separated by this gap and swap if necessary.
- Reduce the gap and repeat the process until the gap is 1, at which point it behaves like Insertion Sort.


#include <bits/stdc++.h>
using namespace std;

// Function to perform Shell Sort
void shellSort(vector<int>& arr, int n) {
    for(int gap = n/2; gap>0; gap /= 2){
        for(int i=gap; i<= n-1; i++){
            int j = i;
            while(j>=gap && arr[j-gap] > arr[j]){
                swap(arr[j-gap], arr[j]);
                j -= gap;
            }
        }
    }
}

// Function to print an array
void printArray(vector<int> arr, int size) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function to test the algorithm
int main() {
    vector<int> arr = {12, 34, 54, 2, 3};
    int n = arr.size();

    cout << "Original array: ";
    printArray(arr, n);

    shellSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}



Explanation

    The function shellSort starts with a large gap (initially n/2).
    It performs gapped insertion sort, ensuring elements move towards their correct positions faster.
    The gap is repeatedly reduced (gap /= 2) until it reaches 1.
    Finally, the array is fully sorted.

Time Complexity

    Best Case: O(nlog⁡n) (depends on the gap sequence)   where log n is the number of iterations and n is the shifting of elements
    Average Case: Between O(n3/2) and O(nlog⁡n)   when gap is taken as prime number
    Worst Case: O(n2) (for some gap sequences)   reverse sorting and when all elements are same

Advantages of Shell Sort

    Faster than Insertion Sort for large datasets.
    Simple to implement.
    Works well for medium-sized datasets.



Case Where j >= gap is Necessary (Preventing Out-of-Bounds Access)

Let's consider an example where not using j >= gap would cause an error.
Given Array

int a[] = {5, 3, 8, 6, 2};
int n = 5;

If we run Shell Sort without the j >= gap condition, we might run into an issue.
Let's Analyze a Faulty Case
1st Iteration (gap = 2)

    The loop starts with gap = 2, so elements gap apart are compared.

Index	0	1	2	3	4
Array	5	3	8	6	2

    The for loop starts at i = 2, so we set j = 2.

Checking a[j - gap] > a[j]

    First comparison: a[0] (5) vs. a[2] (8) → No swap needed.

    Move to i = 3, so j = 3.
        Compare a[1] (3) vs. a[3] (6) → No swap needed.

    Move to i = 4, so j = 4.

        Compare a[2] (8) vs. a[4] (2).

        Since 8 > 2, we swap:

Array: [5, 3, 2, 6, 8]

Now, j = 2, and without j >= gap, the while condition would continue:

        while (a[j - gap] > a[j]) {  // Incorrect because j-gap might be negative
            swap(a[j - gap], a[j]);
            j -= gap;  // Moves further back
        }

        Since gap = 2, now j = 0. This means j - gap = -2, which is out of bounds!

What Happens Without j >= gap?

    The program tries to access a[-2], which is invalid memory.
    This could result in:
        Segmentation fault (crash)
        Undefined behavior (random values may be accessed)

Fixing It With j >= gap

while (j >= gap && a[j - gap] > a[j]) {

    Prevents j - gap from being negative.
    Ensures only valid elements are compared and swapped.

Conclusion

    The issue happens when gap-based swaps move an element to an index smaller than gap.
    Without j >= gap, j - gap can become negative, leading to crashes.
    Always include j >= gap to prevent invalid memory access.