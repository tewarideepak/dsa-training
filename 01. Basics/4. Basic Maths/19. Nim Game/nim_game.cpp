#include <iostream>
using namespace std;

bool canWinNim(int n)
{
    return n % 4 != 0;
}

int main()
{
    int n = 5;
    cout << canWinNim(n) << endl;
    return 0;
}