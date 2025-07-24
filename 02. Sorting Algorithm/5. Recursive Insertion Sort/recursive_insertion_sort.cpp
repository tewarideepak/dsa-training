#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{
    if (n <= 1)
        return;

    insertionSort(arr, n - 1);

    int key = arr[n - 1];
    int j = n - 2;

    while (j >= 0 && arr[j] > key)
    {
        arr[j + 1] = arr[j];
        j--;
    }

    arr[j + 1] = key;
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);

    for (int a : arr)
    {
        cout << a << " ";
    }
}