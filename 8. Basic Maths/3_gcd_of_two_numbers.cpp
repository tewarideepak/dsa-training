#include <iostream>
using namespace std;

int gcd2(int a, int b)
{
    if (a == 0)
        return b;
    else if (b == 0)
        return a;

    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }

    return a;
}

// Euclidean Algorithm for GCD
int gcd(int a, int b)
{
    // Ensure a and b are non-negative
    a = abs(a);
    b = abs(b);

    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    int result = gcd(a, b);
    cout << "GCD of " << a << " and " << b << " is: " << result << endl;
    return 0;
}

// 📊 Time Complexity: O(log(min(a, b)))

//     Every iteration reduces the problem size significantly (like halving), so the number of iterations is logarithmic in the smaller of the two numbers.

// 📦 Space Complexity: O(1) (Constant space)

//     No extra space used apart from a few variables.