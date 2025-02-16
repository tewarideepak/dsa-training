// [0.13, 0.45, 0.12, 0.89, 0.75, 0.63, 0.85, 0.39]

// # Algorithm:

// 1. Create bucket of size n

// 2. Insert elements into buckets
//     index = arr[i] * n

// 3. Sort individual buckets

// 4. Combine all elements


#include <bits/stdc++.h>
using namespace std;

// Function to perform bucket sort
void bucketSort(vector<float>& arr, int n) {
    // Create empty buckets
    vector<vector<float>> buckets(n);

    // Insert elements into their respective buckets
    for (int i = 0; i < n; i++) {
        int index = floor(n * arr[i]);  // Bucket index
        buckets[index].push_back(arr[i]);
    }

    // Sort individual buckets
    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Merge all buckets into the original array
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (float value : buckets[i]) {
            arr[index++] = value;
        }
    }
}

int main() {
    vector<float> arr = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};
    int n = arr.size();

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    bucketSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

// Explanation:

//     Buckets Creation: We create n buckets (vectors).
//     Distribute Elements: Each element is assigned to a bucket based on index = n * arr[i].
//     Sorting: Each bucket is sorted using sort().
//     Merging: The elements are copied back to the original array.

// Time Complexity:

//     Best Case: O(n+k) (When elements are uniformly distributed) (k is the number of buckets and n is the number of elements)
//     Worst Case: O(n^2) (If all elements land in one bucket and require sorting)
//     Average Case: O(n) (If distribution is balanced)


// Space Complexity:

// The space complexity is O(n) because of the space required to store the input data in the buckets.

// When to Use Bucket Sort?

// ✔️ When elements are uniformly distributed over a range.
// ✔️ When additional memory for buckets is acceptable.
// ✔️ Works well for floating-point numbers.


// -----------------------------------------------------------------------------------------------------------------------------

// If your input array contains non-floating numbers, such as integers, you can still apply bucket sort, but you'll need to modify the approach slightly, especially for determining which bucket each element should go into.
// Key Adjustments:

//     Determine Bucket Range: For integers, you'd likely divide the range of integers into equally sized buckets based on the minimum and maximum values.
//     Sorting Method: You can still use sorting algorithms like Insertion Sort or C++'s sort() for each bucket.

// Example with Integer Array

// If the input array is of integers, here’s how you can modify the bucket sort to work with integers:

// #include <bits/>stdc++.h>
// using namespace std;

// // Function to perform bucket sort on integer array
// void bucketSort(vector<int>& arr, int n) {
//     // Step 1: Find the minimum and maximum elements in the array
//     minValue = *min_element(arr.begin(), arr.end());
//     maxValue = *max_element(arr.begin(), arr.end());

//     // Step 2: Create empty buckets
//     int bucketCount = maxValue - minValue + 1;
//     vector<vector<int>> buckets(bucketCount);  // Array of buckets

//     // Step 3: Distribute elements into corresponding buckets
//     for (int i = 0; i < n; i++) {
//         int index = arr[i] - minValue;  // Bucket index
//         buckets[index].push_back(arr[i]);
//     }

//     // Step 4: Sort each bucket
//     for (int i = 0; i < bucketCount; i++) {
//         sort(buckets[i].begin(), buckets[i].end());
//     }

//     // Step 5: Merge all buckets back into the original array
//     int index = 0;
//     for (int i = 0; i < bucketCount; i++) {
//         for (int value : buckets[i]) {
//             arr[index++] = value;
//         }
//     }
// }

// // Driver code
// int main() {
//     vector<int> arr = {42, 32, 23, 52, 25, 47, 51};
//     int n = arr.size();

//     cout << "Original array: ";
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     bucketSort(arr, n);

//     cout << "Sorted array: ";
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }


// 1. Why maxValue - minValue + 1 for the number of buckets?

// The number of buckets is determined by the range of values in the array, which is the difference between the maximum value and the minimum value.

//     Purpose: We need enough buckets to represent each distinct value (or range) in the array.
//     Range: The total number of distinct "buckets" required is the difference between the largest and smallest values in the array.

// Let's say:

//     minValue = 5
//     maxValue = 10

// The range of the numbers in the array is from 5 to 10, and the difference between 10 and 5 is 5, but you need 6 buckets (one for each of 5, 6, 7, 8, 9, 10). So, you calculate the number of buckets as:

// bucketCount = maxValue - minValue + 1;

// This ensures that:

//     If the array contains values in the range [5, 10], we have 6 buckets (for 5, 6, 7, 8, 9, 10).

// 2. Why arr[i] - minValue for calculating the bucket index?

// The idea is to map each element of the array into the corresponding bucket.

//     Bucket Index Calculation: The bucket index needs to be proportional to the relative position of each element compared to the minimum value in the array.

//     How it works:
//         We subtract the minValue from arr[i] to shift the value into a "zero-based" range.
//         This ensures that the smallest element (which is equal to minValue) maps to index 0, and the largest element maps to the last bucket.

// Let's break it down with an example:

//     arr[i] = 7
//     minValue = 5
//     The relative value (how far 7 is from minValue) is 7 - 5 = 2.

// Now:

//     The value 7 will go into the bucket at index 2 (since it's 2 units greater than minValue).
//     This ensures that the values get distributed across the buckets based on their "relative position" to minValue.

// For a quick example:

//     If arr[i] = 5 and minValue = 5, then arr[i] - minValue = 0, meaning it goes into bucket 0.
//     If arr[i] = 10 and minValue = 5, then arr[i] - minValue = 5, meaning it goes into the last bucket (bucketCount - 1).


// Explanation of Changes:

//     Find Min and Max Values:
//     The range of the integers is determined by finding the minimum (minValue) and maximum (maxValue) values in the input array.

//     Bucket Count:
//     The number of buckets is determined by the difference between the max and min values (maxValue - minValue + 1).

//     Bucket Distribution:
//     Each element is placed into a bucket based on its value relative to the minimum (arr[i] - minValue).

//     Sorting Each Bucket:
//     After distributing the elements, each bucket is sorted individually using the sort() function.

//     Merging Buckets:
//     Finally, all the sorted elements from each bucket are merged back into the original array.

// Time Complexity:

//     Best Case: O(n+k) (When elements are uniformly distributed)
//     Worst Case: O(n2) (If many elements fall into the same bucket)
//     Average Case: O(n+k), where k is the number of buckets, assuming buckets are evenly distributed.

// When to Use Bucket Sort for Integers:

//     When the range of integers is not too large (as creating too many buckets can become inefficient).
//     When the numbers are distributed evenly across a known range.

// -----------------------------------------------------------------------------------------------------------------------------

// If your input array looks like this:

// [0.13, 0.45, 0.12, 0.89, 0.75, 0.63, 0.85, 10.39]

// It contains floating-point numbers, which requires a slight modification of the bucket sort approach. Here's what we need to change:
// Key Adjustments for Floating-Point Numbers:

//     Bucket Index Calculation:
//     Since the values are floating-point numbers between 0 and 1 (except 10.39 which is an outlier), the bucket index calculation changes. We assume all values are in the range [0, 1) and use the formula index = n * arr[i] to map the values to corresponding bucket indices.

//     Handling Outliers:
//     Values like 10.39 fall far outside the [0, 1) range. To handle this, we'll scale these values down or apply a different bucket range strategy to accommodate such outliers.

// Updated Bucket Sort for Floating-Point Numbers

// Here's how the algorithm can be adapted for this specific scenario:

// #include <bits/>stdc++.h>
// using namespace std;

// // Function to perform bucket sort on floating-point array
// void bucketSort(vector<float>& arr, int n) {
//     // Step 1: Find the minimum and maximum elements in the array
//     minValue = *min_element(arr.begin(), arr.end());
//     maxValue = *max_element(arr.begin(), arr.end());

//     // Step 2: Create empty buckets
//     int bucketCount = 10;  // Let's assume we're using 10 buckets
//     vector<vector<float>> buckets(bucketCount);  // Array of buckets

//     // Step 3: Distribute elements into corresponding buckets
//     for (int i = 0; i < n; i++) {
//         // Scaling the floating-point number into the bucket range
//         int index = (arr[i] - minValue) * bucketCount / (maxValue - minValue);
//         // Handling values greater than maxValue (like 10.39 in your example)
//         if (index >= bucketCount) index = bucketCount - 1;
//         buckets[index].push_back(arr[i]);
//     }

//     // Step 4: Sort each bucket
//     for (int i = 0; i < bucketCount; i++) {
//         sort(buckets[i].begin(), buckets[i].end());
//     }

//     // Step 5: Merge all buckets back into the original array
//     int index = 0;
//     for (int i = 0; i < bucketCount; i++) {
//         for (float value : buckets[i]) {
//             arr[index++] = value;
//         }
//     }
// }

// // Driver code
// int main() {
//     vector<float> arr = {0.13, 0.45, 0.12, 0.89, 0.75, 0.63, 0.85, 10.39};
//     int n = arr.size();

//     cout << "Original array: ";
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     bucketSort(arr, n);

//     cout << "Sorted array: ";
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }

// Explanation of Changes:

//     Scaling for Bucket Index:

// int index = (arr[i] - minValue) * bucketCount / (maxValue - minValue);

// We scale the floating-point values to fit into the range of buckets by multiplying them by bucketCount / (maxValue - minValue). This distributes the values uniformly across the buckets.

// Handling Outliers:

//     if (index >= bucketCount) index = bucketCount - 1;

//     If a value exceeds the maximum bucket range (like 10.39), it gets assigned to the last bucket. This prevents errors when values fall outside the normal range.

//     Bucket Count: I've set the bucket count to 10, but you can adjust this depending on how finely you want to divide your values.

// Expected Output:

// Original array: 0.13 0.45 0.12 0.89 0.75 0.63 0.85 10.39 
// Sorted array: 0.12 0.13 0.45 0.63 0.75 0.85 0.89 10.39

// Time Complexity:

//     Best and Average Case: O(n+k)O(n+k), where nn is the number of elements and kk is the number of buckets.
//     Worst Case: O(n2)O(n2), if all elements end up in the same bucket and we need to sort each bucket individually.

// Handling Outliers:

// This approach works well when your data has outliers or extreme values (like 10.39), but you should choose your bucket count carefully. If the outlier values are rare, this approach is fine. Otherwise, you might want to consider scaling the numbers or using a more sophisticated sorting technique for extreme values.