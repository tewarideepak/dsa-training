// Given an m x n matrix, return all elements of the matrix in spiral order.

// Example 1:

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]

// Example 2:

// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]

// Constraints:

//     m == matrix.length
//     n == matrix[i].length
//     1 <= m, n <= 10
//     -100 <= matrix[i][j] <= 100

#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> result;
    int top = 0, bottom = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; ++i)
            result.push_back(matrix[top][i]);
        ++top;

        for (int i = top; i <= bottom; ++i)
            result.push_back(matrix[i][right]);
        --right;

        if (top <= bottom)
        {
            for (int i = right; i >= left; --i)
                result.push_back(matrix[bottom][i]);
            --bottom;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; --i)
                result.push_back(matrix[i][left]);
            ++left;
        }
    }

    return result;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<int> result = spiralOrder(matrix);
    for (int num : result)
        cout << num << " ";
    return 0;
}

// ⏱ Time Complexity: O(m * n)

//     Every element in the matrix is visited exactly once.

//     There are m * n elements.

//     All operations inside the loop are constant time (O(1)), and each element is pushed into the result vector once.

// ✅ So total time: O(m * n)
// 🧠 Space Complexity:
// ✅ Auxiliary Space: O(1)

//     We only use a few integer variables: top, bottom, left, right, and loop counters.

//     No extra data structures are used (like stacks, queues, maps, etc.)

// ✅ Result Storage: O(m * n)

//     The result vector holds all elements of the matrix.

//     This is required output space, so it’s usually not counted as "extra" or "auxiliary".