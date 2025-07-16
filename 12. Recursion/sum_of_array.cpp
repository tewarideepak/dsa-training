#include <iostream>
using namespace std;

int sum(int arr[], int size)
{
    if (size == 0)
    {
        return 0;
    }
    else
    {
        return arr[0] + sum(arr + 1, size - 1);
    }
}

int main()
{
    int arr[] = {3, 2, 5, 1, 6};
    int size = 5;

    cout << "Sum: " << sum(arr, size) << endl;
}