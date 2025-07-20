// Given an integer array nums of unique elements, return all possible

// (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

// Example 2:

// Input: nums = [0]
// Output: [[],[0]]

// Constraints:

//     1 <= nums.length <= 10
//     -10 <= nums[i] <= 10
//     All the numbers of nums are unique.

#include <bits/stdc++.h>
using namespace std;

void generateSubsets(vector<int> &nums, vector<int> &newSubset, int index, vector<vector<int>> &subsets)
{
    if (index >= nums.size())
    {
        subsets.push_back(newSubset);
        return;
    }

    // Exclude
    generateSubsets(nums, newSubset, index + 1, subsets);

    // Include
    newSubset.push_back(nums[index]);
    generateSubsets(nums, newSubset, index + 1, subsets);
    newSubset.pop_back(); // Backtrack
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> subsets;
    vector<int> newSubset;
    generateSubsets(nums, newSubset, 0, subsets);
    return subsets;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = subsets(nums);

    for (const auto &subset : result)
    {
        cout << "[";
        for (int num : subset)
            cout << num << " ";
        cout << "]\n";
    }

    return 0;
}
