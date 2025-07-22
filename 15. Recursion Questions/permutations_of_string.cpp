// Given an array nums of distinct integers, return all the possible permutations.

// You can return the answer in any order.

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]

// Example 3:

// Input: nums = [1]
// Output: [[1]]

// Constraints:

//     1 <= nums.length <= 6
//     -10 <= nums[i] <= 10
//     All the integers of nums are unique.

#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<int> &nums, int index, vector<vector<int>> &result)
{
    if (index == nums.size())
    {
        result.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); ++i)
    {
        swap(nums[index], nums[i]);         // Choose
        backtrack(nums, index + 1, result); // Explore
        swap(nums[index], nums[i]);         // Un-choose (Backtrack)
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> result;
    backtrack(nums, 0, result);
    return result;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> permutations = permute(nums);

    for (const auto &p : permutations)
    {
        for (int num : p)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
