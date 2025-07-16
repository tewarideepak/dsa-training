#include <iostream>
using namespace std;

int binarySearch(int arr[], int s, int e, int key)
{
    if (s > e)
    {
        return false;
    }

    int mid = s + (e - s) / 2;

    if (arr[mid] == key)
    {
        return true;
    }
    else if (arr[mid] < key)
    {
        return binarySearch(arr, mid + 1, e, key);
    }
    else
    {
        return binarySearch(arr, s, mid - 1, key);
    }
}

int main()
{
    int arr[] = {2, 4, 6, 10, 14, 16};
    int size = 6, key = 18;

    bool ans = binarySearch(arr, 0, size - 1, key);
    cout << "Found: " << ans << endl;
}