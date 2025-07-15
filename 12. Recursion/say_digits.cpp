// I/P -> 412
// O/P -> Four One Two

#include <bits/stdc++.h>
using namespace std;

void sayDigit(int n, string arr[])
{
    if (n == 0)
    {
        return;
    }

    int digit = n % 10;
    n = n / 10;

    sayDigit(n, arr);          // Recurse first
    cout << arr[digit] << " "; // Then print the digit (in correct order)
}

int main()
{
    int number = 412;

    if (number == 0)
    {
        cout << "zero";
    }
    else
    {
        string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        sayDigit(number, arr);
    }

    return 0;
}
