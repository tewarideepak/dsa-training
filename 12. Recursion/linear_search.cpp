#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int key)
{
    if (size == 0)
    {
        return false;
    }
    else if (arr[0] == key)
    {
        return true;
    }
    else
    {
        return linearSearch(arr + 1, size - 1, key);
    }
}

int main()
{
    int arr[] = {3, 2, 5, 1, 6};
    int size = 5, key = 2;

    bool ans = linearSearch(arr, size, key);

    cout << "Found: " << ans << endl;
}