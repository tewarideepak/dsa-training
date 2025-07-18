// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

//     Integers in each row are sorted in ascending from left to right.
//     Integers in each column are sorted in ascending from top to bottom.

// Example 1:

// Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
// Output: true

// Example 2:

// Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
// Output: false

// Constraints:

//     m == matrix.length
//     n == matrix[i].length
//     1 <= n, m <= 300
//     -109 <= matrix[i][j] <= 109
//     All the integers in each row are sorted in ascending order.
//     All the integers in each column are sorted in ascending order.
//     -109 <= target <= 109

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = 0;
        int col = matrix[0].size() - 1;

        while (row < matrix.size() && col >= 0)
        {
            int val = matrix[row][col];
            if (val == target)
                return true;
            else if (val > target)
                col--;
            else
                row++;
        }

        return false;
    }
};

int main()
{
    Solution solution;

    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};

    int target1 = 5;
    int target2 = 20;

    cout << boolalpha;
    cout << "Searching for " << target1 << ": " << solution.searchMatrix(matrix, target1) << endl; // true
    cout << "Searching for " << target2 << ": " << solution.searchMatrix(matrix, target2) << endl; // false

    return 0;
}
