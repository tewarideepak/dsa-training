
#include <bits/stdc++.h>
using namespace std;

// Printing the Array through Function

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    // Declaration

    int number[15];

    // Accessing

    cout << "Value at 15 index " << number[14] << endl;

    // cout << "Value at 20 index " << number[19] << endl; // error

    // Initializing

    int second[3] = {5, 7, 11};

    int third[15] = {2, 7}; // Rest location will be initialized with zero

    int fourth[10] = {0}; // Each will be zero

    // Printing

    // for (int x : second)
    // {
    //     cout << x << endl;
    // }

    printArray(fourth, 10);

    int fifth[10] = {1};

    int fifthSize = sizeof(fifth) / sizeof(int);

    cout << "Size of Fifth is: " << fifthSize << endl;

    char ch[5] = {'a', 'b', 'c', 'd'};

    return 0;
}

// Homework

// 1. Initialize an array with any value like int arr[5] = {0}

void init()
{
    int arr[5];
    std::fill_n(arr, 5, 7); // All elements set to 7

    for (int num : arr)
    {
        cout << num << endl;
    }
}