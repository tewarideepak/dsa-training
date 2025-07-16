#include <iostream>
using namespace std;

bool isSorted(int arr[], int size)
{
    if (size == 1 || size == 0)
    {
        return true;
    }
    else if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        return isSorted(arr + 1, size - 1);
    }
}

int main()
{
    int arr[] = {2, 4, 6, 8, 9};
    int size = 5;

    cout << "Is Sorted: " << isSorted(arr, size) << endl;
}