// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

// Example 1:

// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]

// Example 2:

// Input: nums = [0]
// Output: [0]

// Constraints:

//     1 <= nums.length <= 104
//     -231 <= nums[i] <= 231 - 1

// Follow up: Could you minimize the total number of operations done?

#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int> &nums)
{
    int insertPos = 0;

    // First pass: move non-zero elements to the front
    for (int num : nums)
    {
        if (num != 0)
        {
            nums[insertPos++] = num;
        }
    }

    // Second pass: fill the rest with zeros
    while (insertPos < nums.size())
    {
        nums[insertPos++] = 0;
    }
}

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);

    cout << "Result: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
