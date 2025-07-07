#include <iostream>
using namespace std;

int main()
{
    int num = 5;

    // & -> addressOf operator
    cout << &num << endl;

    int *ptr = &num;

    // * -> dereference operator
    cout << *ptr << endl;

    // Always 8 irrespective of data type

    cout << "size of pointer is: " << sizeof(ptr) << endl;

    int *p = &num;

    cout << "Before: " << num << endl;

    (*p)++;

    cout << "After: " << num << endl;

    // Copying pointer

    int *q = p;

    cout << p << " - " << q << endl;

    cout << *p << " - " << *q << endl;
}