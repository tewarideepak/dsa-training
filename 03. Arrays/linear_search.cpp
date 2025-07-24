

#include <bits/stdc++.h>
using namespace std;

bool linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int arr[10] = {5, 7, -2, 10, 22, -2, 0, 5, 22, 1};
    int key = 200;

    bool found = linearSearch(arr, 10, key);

    if (found)
    {
        cout << "Key " << key << " is present" << endl;
    }
    else
    {
        cout << "Key " << key << " is absent" << endl;
    }
}