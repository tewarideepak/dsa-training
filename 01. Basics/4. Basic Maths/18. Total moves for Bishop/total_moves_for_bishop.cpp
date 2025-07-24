// 🎯 Objective

// Given the position (A, B) of a bishop on a standard 8x8 chessboard, count how many squares it can reach in one move.
// 📚 Key Concepts

// Bishop moves diagonally in four directions:

// Top-Left

// Top-Right

// Bottom-Left

// Bottom-Right

// A bishop can move any number of squares diagonally, as long as it stays within bounds.

// 🧠 Logic

// For position (A, B):

// Count how many squares are available in each diagonal direction:

// Top-left: min(A-1, B-1)

// Top-right: min(A-1, 8-B)

// Bottom-left: min(8-A, B-1)

// Bottom-right: min(8-A, 8-B)

// 💻 C++ Code

#include <iostream>
using namespace std;

int bishopMoves(int A, int B)
{
    int topLeft = min(A - 1, B - 1);
    int topRight = min(A - 1, 8 - B);
    int bottomLeft = min(8 - A, B - 1);
    int bottomRight = min(8 - A, 8 - B);

    return topLeft + topRight + bottomLeft + bottomRight;
}

int main()
{
    int A, B;
    cin >> A >> B;
    cout << bishopMoves(A, B) << endl;
    return 0;
}

// 🧪 Example
// Input:

// A = 4, B = 4

// Output:

// 13

// Why?

// Top-left: min(3, 3) = 3

// Top-right: min(3, 4) = 3

// Bottom-left: min(4, 3) = 3

// Bottom-right: min(4, 4) = 4
// Total = 3 + 3 + 3 + 4 = 13

// ✅ Time Complexity

// O(1) (only arithmetic operations)