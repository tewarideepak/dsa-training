// Homework

// Sum of all array elemnts

#include <bits/stdc++.h>
using namespace std;

int sumArray(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    return sum;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    int size = 5;

    int sum = sumArray(arr, size);

    cout << "The sum is: " << sum << endl;
}