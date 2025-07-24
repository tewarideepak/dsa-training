// Consider a rat placed at position (0, 0) in an n x n square matrix mat[][]. The rat's goal is to reach the destination at position (n-1, n-1). The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

// The matrix contains only two possible values:

//     0: A blocked cell through which the rat cannot travel.
//     1: A free cell that the rat can pass through.

// Your task is to find all possible paths the rat can take to reach the destination, starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path. Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.
// If no path exists, return an empty list.

// Note: Return the final result vector in lexicographically smallest order.

// Examples:

// Input: mat[][] = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]
// Output: ["DDRDRR", "DRDDRR"]
// Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.

// Input: mat[][] = [[1, 0], [1, 0]]
// Output: []
// Explanation: No path exists as the destination cell is blocked.

// Input: mat = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
// Output: ["DDRR", "RRDD"]
// Explanation: The rat has two possible paths to reach the destination: 1. "DDRR" 2. "RRDD", These are returned in lexicographically sorted order.

// Constraints:
// 2 ≤ mat.size() ≤ 5
// 0 ≤ mat[i][j] ≤ 1

#include <bits/stdc++.h>
using namespace std;

void solve(int i, int j, vector<vector<int>> &maze, int n, string path, vector<string> &result, vector<vector<int>> &visited)
{
    // Base condition: destination reached
    if (i == n - 1 && j == n - 1)
    {
        result.push_back(path);
        return;
    }

    // Mark current cell as visited
    visited[i][j] = 1;

    // Move Down
    if (i + 1 < n && maze[i + 1][j] == 1 && visited[i + 1][j] == 0)
    {
        solve(i + 1, j, maze, n, path + 'D', result, visited);
    }

    // Move Left
    if (j - 1 >= 0 && maze[i][j - 1] == 1 && visited[i][j - 1] == 0)
    {
        solve(i, j - 1, maze, n, path + 'L', result, visited);
    }

    // Move Right
    if (j + 1 < n && maze[i][j + 1] == 1 && visited[i][j + 1] == 0)
    {
        solve(i, j + 1, maze, n, path + 'R', result, visited);
    }

    // Move Up
    if (i - 1 >= 0 && maze[i - 1][j] == 1 && visited[i - 1][j] == 0)
    {
        solve(i - 1, j, maze, n, path + 'U', result, visited);
    }

    // Backtrack - unmark the current cell
    visited[i][j] = 0;
}

vector<string> ratInMaze(vector<vector<int>> &maze)
{
    int n = maze.size();
    vector<string> result;

    // If starting or ending cell is blocked
    if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
        return result;

    vector<vector<int>> visited(n, vector<int>(n, 0));

    // Start the recursive exploration
    solve(0, 0, maze, n, "", result, visited);

    sort(result.begin(), result.end()); // Lexicographical order
    return result;
}

int main()
{
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};

    vector<string> paths = ratInMaze(maze);
    for (string path : paths)
    {
        cout << path << " ";
    }
    return 0;
}
