#include <bits/stdc++.h>
using namespace std;

int getMax(int num[], int n)
{
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, num[i]);
        // if (num[i] > max)
        // {
        //     max = num[i];
        // }
    }

    return maxi;
}

int getMin(int num[], int n)
{
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, num[i]);
        // if (num[i] < min)
        // {
        //     min = num[i];
        // }
    }

    return mini;
}

int main()
{
    int size = 5;
    int num[100] = {1, 2, 3, 4, 5};

    // Taking Input
    // for (int i = 0; i < size; i++)
    // {
    //     cin >> num[i];
    // }

    cout << "Maximum value is: " << getMax(num, size) << endl;
    cout << "Minimum value is: " << getMin(num, size) << endl;
}