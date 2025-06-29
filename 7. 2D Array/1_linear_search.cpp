// why do we need to speicfy the column size while passing 2d Array in cpp
// ChatGPT said:

// In C++, when passing a 2D array to a function, you must specify the number of columns, and here’s the key reason why:
// 🧠 Reason:

// C++ needs to know how to calculate the memory offset to access elements in the 2D array. Arrays in C++ are stored in row-major order, so when you access arr[i][j], it's internally computed as:

// *(*(arr + i) + j) // or arr[i * numCols + j]

// To compute this correctly, the compiler must know the number of columns (numCols). Without it, it cannot correctly jump to the j-th column of the i-th row.
// ❌ Example That Will NOT Compile:

// void print(int arr[][]) { // ERROR: column size missing
//     // ...
// }

// ✅ Correct Way:

// void print(int arr[][3], int rows) { // column size specified
//     for (int i = 0; i < rows; ++i)
//         for (int j = 0; j < 3; ++j)
//             std::cout << arr[i][j] << " ";
// }

// ✅ Better Alternative (using pointers or vectors):

//     Using pointers (with dynamic allocation):

// void print(int* arr, int rows, int cols) {
//     for (int i = 0; i < rows; ++i)
//         for (int j = 0; j < cols; ++j)
//             std::cout << *(arr + i * cols + j) << " ";
// }

//     Using std::vector (recommended):

// void print(const std::vector<std::vector<int>>& arr) {
//     for (const auto& row : arr)
//         for (int val : row)
//             std::cout << val << " ";
// }

// ✅ Summary:

//     The column size is needed so the compiler knows how to navigate memory for arr[i][j].

//     It's a limitation of how arrays are implemented in C++.

//     Prefer std::vector for 2D arrays in modern C++ for flexibility and safety.

#include <iostream>
using namespace std;

bool linearSearch(int arr[][3], int rows, int cols, int key)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (arr[i][j] == key)
            {
                cout << "Element found at position: (" << i << ", " << j << ")" << endl;
                return true;
            }
        }
    }
    cout << "Element not found in the array." << endl;
    return false;
}

int main()
{
    const int rows = 3, cols = 3;
    int arr[rows][cols] = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}};

    int key;
    cout << "Enter the element to search: ";
    cin >> key;

    linearSearch(arr, rows, cols, key);

    return 0;
}
