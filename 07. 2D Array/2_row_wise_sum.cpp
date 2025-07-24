#include <iostream>
using namespace std;

int main()
{
    const int rows = 3, cols = 4;
    int arr[rows][cols] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    cout << "Row-wise sums:\n";
    for (int i = 0; i < rows; ++i)
    {
        int rowSum = 0;
        for (int j = 0; j < cols; ++j)
        {
            rowSum += arr[i][j];
        }
        cout << "Sum of row " << i << ": " << rowSum << endl;
    }

    return 0;
}
