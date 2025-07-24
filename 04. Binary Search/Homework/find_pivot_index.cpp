// Given an array of integers nums, calculate the pivot index of this array.

// The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

// If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

// Return the leftmost pivot index. If no such index exists, return -1.

// Example 1:

// Input: nums = [1,7,3,6,5,6]
// Output: 3
// Explanation:
// The pivot index is 3.
// Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
// Right sum = nums[4] + nums[5] = 5 + 6 = 11

// Example 2:

// Input: nums = [1,2,3]
// Output: -1
// Explanation:
// There is no index that satisfies the conditions in the problem statement.

// Example 3:

// Input: nums = [2,1,-1]
// Output: 0
// Explanation:
// The pivot index is 0.
// Left sum = 0 (no elements to the left of index 0)
// Right sum = nums[1] + nums[2] = 1 + -1 = 0

// Constraints:

//     1 <= nums.length <= 104
//     -1000 <= nums[i] <= 1000

#include <bits/stdc++.h>
using namespace std;

// Function to compute total sum of the array
int find_total(vector<int> &nums, int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += nums[i];
    }
    return total;
}

// Function to find pivot index
int pivotIndex(vector<int> &nums)
{
    int total = find_total(nums, nums.size());
    int left = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (left == total - left - nums[i])
        {
            return i;
        }
        left += nums[i];
    }
    return -1;
}

// Main function to test the implementation
int main()
{
    vector<int> nums1 = {1, 7, 3, 6, 5, 6};
    vector<int> nums2 = {1, 2, 3};
    vector<int> nums3 = {2, 1, -1};

    cout << "Pivot index of nums1: " << pivotIndex(nums1) << endl; // Output: 3
    cout << "Pivot index of nums2: " << pivotIndex(nums2) << endl; // Output: -1
    cout << "Pivot index of nums3: " << pivotIndex(nums3) << endl; // Output: 0

    return 0;
}
