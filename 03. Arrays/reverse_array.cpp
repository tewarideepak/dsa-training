

#include <bits/stdc++.h>
using namespace std;

void reverseArray(int arr[], int n)
{
    int left = 0, right = n - 1;
    while (left < right)
    {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};

    cout << "Original Array:" << endl;
    printArray(arr, 5);

    reverseArray(arr, 5);

    cout << "Reversed Array:" << endl;
    printArray(arr, 5);
}