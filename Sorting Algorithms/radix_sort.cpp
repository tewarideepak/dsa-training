// # Sort the array using count sort, digit by digit, starting from least.

// 471 is the largest number with 3 digits

// 29, 83, 471, 36, 91, 8

// 1. 471, 91, 83, 36, 8, 29

// 2. 8, 29, 36, 471, 83, 91

// 3. 8, 29, 36, 83, 91, 471


// Radix Sort is a non-comparative sorting algorithm that sorts numbers digit by digit. It works by sorting numbers starting from the least significant digit (LSD) to the most significant digit (MSD) or vice versa. It uses a stable sub-sorting algorithm like Counting Sort to sort the numbers based on each digit. Radix Sort is efficient when dealing with large sets of data and works well when the number of digits is not large.

// Steps in Radix Sort:

//     Find the maximum number in the array. The number of digits in this maximum number determines the number of passes (iterations) for sorting.
//     For each digit (starting from the least significant digit):
//         Sort the array based on that digit using a stable sub-sorting algorithm (usually Counting Sort).
//         Move to the next digit (more significant one).
//     After the last digit is sorted, the array is fully sorted.


#include<bits/stdc++.h>
using namespace std;

void countingSort(vector<int>& arr, int exp){
    int n = arr.size();
    vector<int> count(10, 0);
    vector<int> output(n);

    for(int i=0; i<n; i++){
        count[(arr[i] / exp) % 10]++;
    }

    for(int i=1; i<10; i++){
        count[i] += count[i-1];
    }

    for(int i=n-1; i>=0; i--){
       output[count[(arr[i] / exp) % 10] - 1] = arr[i];
       count[(arr[i] / exp) % 10]--;
    }

    for(int i=0; i<n; i++){
        arr[i] = output[i];
    }
}

// Radix Sort function
void radixSort(vector<int>& arr) {
    // Find the maximum number to know the number of digits
    int max = *max_element(arr.begin(), arr.end());

    // Perform counting sort for every digit
    // The exp is 10^i where i is the current digit's position
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << "Original Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    radixSort(arr);

    cout << "Sorted Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}


// Explanation:

//     Counting Sort:
//         This function sorts the elements based on a specific digit (determined by the exp value).
//         It uses the digit (arr[i] / exp) % 10 to decide the order.
//         It stores the count of digits in an array count[], then computes their actual positions in the sorted output array.

//     Radix Sort:
//         First, we find the maximum number in the array to determine how many digits the largest number has.
//         Then, we apply counting sort for each digit starting from the least significant digit (exp = 1), and multiply exp by 10 for the next digit.
//         The loop runs until exp becomes greater than the maximum number in the array.



// Time Complexity:

//     Best, Average, Worst Case: O(n * k), where n is the number of elements in the array and k is the number of digits in the largest number. (For small integers and limited digit sizes, this can be very efficient.)

//     Space Complexity: O(n), as we need extra space for the output and count arrays in counting sort.

// When to Use Radix Sort:

//     It is most effective when you have fixed-size numbers or integers with a small number of digits.
//     It is a stable sort, which makes it useful in certain scenarios where relative order of equal elements is important.