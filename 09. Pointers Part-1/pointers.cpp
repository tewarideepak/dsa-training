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

    int arr[10] = {2, 5, 6};

    cout << *arr << endl;

    int i = 2;

    cout << i[arr] << endl; //  *(i+arr)

    int temp[10] = {1, 2};
    cout << sizeof(temp) << endl;
    cout << " 1st " << sizeof(*temp) << endl;
    cout << " 2nd " << sizeof(&temp) << endl;

    int *pt = &temp[0];
    cout << sizeof(pt) << endl;
    cout << sizeof(*pt) << endl;
    cout << sizeof(&pt) << endl;

    cout << pt << endl;
    cout << *pt << endl;
    cout << &pt << endl;
}