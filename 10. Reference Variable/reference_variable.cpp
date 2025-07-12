#include <iostream>
using namespace std;

// Bad Practice

int &func(int a)
{
    int num = a;
    int &ans = num;
    return ans;
}

int *fun(int a)
{
    int *ptr = &a;
    return ptr;
}

void update1(int n)
{
    n++;
}

void update2(int &n)
{
    n++;
}

int main()
{
    int i = 5;

    // create a ref variable

    int &j = i;

    cout << i << endl;
    i++;
    cout << i << endl;
    j++;
    cout << i << endl;

    int n = 5;

    cout << "Before: " << n << endl;
    update1(n);
    cout << "After: " << n << endl;

    cout << endl;

    cout << "Before: " << n << endl;
    update2(n);
    cout << "After: " << n << endl;

    cout << func(n) << endl;
    cout << fun(n) << endl;
}