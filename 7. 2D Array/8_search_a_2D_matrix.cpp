// You are given an m x n integer matrix matrix with the following two properties:

//     Each row is sorted in non-decreasing order.
//     The first integer of each row is greater than the last integer of the previous row.

// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.

// Example 1:

// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true

// Example 2:

// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// Output: false

// Constraints:

//     m == matrix.length
//     n == matrix[i].length
//     1 <= m, n <= 100
//     -104 <= matrix[i][j], target <= 104

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size();
        int col = matrix[0].size();

        int left = 0;
        int right = row * col - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int midValue = matrix[mid / col][mid % col];

            if (midValue == target)
            {
                return true;
            }
            else if (midValue < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return false;
    }
};

// Sample usage
int main()
{
    Solution solution;
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}};

    int target1 = 3;
    int target2 = 13;

    cout << "Searching for " << target1 << ": " << (solution.searchMatrix(matrix, target1) ? "Found" : "Not Found") << endl;
    cout << "Searching for " << target2 << ": " << (solution.searchMatrix(matrix, target2) ? "Found" : "Not Found") << endl;

    return 0;
}

// ✅ Time Complexity: O(log(m × n))

//     The matrix has m rows and n columns → total elements = m × n.

//     We are applying binary search on this virtual 1D array of length m × n.

//     Binary search has logarithmic time complexity:
//     log⁡2(m×n)
//     log2​(m×n)

//     Each binary search step takes constant time (O(1) to access the value at matrix[mid / n][mid % n]).

// ✔ So, total time complexity is:

// O(log(m × n))

// ✅ Space Complexity: O(1)

//     We are using a constant number of variables: row, col, left, right, mid, and midValue.

//     No extra space or data structures are used.

//     We are accessing elements in-place from the input matrix.

// ✔ So, space complexity is:

// O(1)

// 🔁 Summary
// Resource	Complexity
// Time Complexity	O(log(m × n))
// Space Complexity	O(1)