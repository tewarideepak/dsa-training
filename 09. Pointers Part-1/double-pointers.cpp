#include <iostream>
using namespace std;

void update(int **p2)
{
    // p2 = p2 + 1;  // No change

    // *p2 = *p2 + 1;

    **p2 = **p2 + 1;
}

int main()
{
    int i = 5;
    int *p = &i;
    int **p2 = &p;

    cout << " Printing P: " << p << endl;
    cout << "Address of p: " << &p << endl;
    cout << *p2 << endl;

    cout << endl;

    cout << i << endl;
    cout << *p << endl;
    cout << **p2 << endl;

    cout << endl;

    cout << &i << endl;
    cout << p << endl;
    cout << *p2 << endl;

    cout << endl;

    cout << &p << endl;
    cout << p2 << endl;

    cout << endl;

    cout << "before: " << i << endl;
    cout << "before: " << p << endl;
    cout << "before: " << p2 << endl;
    update(p2);
    cout << endl;
    cout << "after: " << i << endl;
    cout << "after: " << p << endl;
    cout << "after: " << p2 << endl;
    cout << endl;
}
