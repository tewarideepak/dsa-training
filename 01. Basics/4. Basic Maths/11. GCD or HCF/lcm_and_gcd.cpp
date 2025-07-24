// 1. LCM

// Listing Multiples for 10 and 20

//     Multiples of 10: 10, 20, 30, 40, …

//     Multiples of 20: 20, 40, 60, …

// The smallest common multiple is:
// 20
// 20​
// Final Answer:
// LCM(10,20)=20
// LCM(10,20)=20

// lcm = (num1*num2)/hcf;

// 2. GCD or HCF

// There will always be a factor of two numbers i.e. 1

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num1 = 10, num2 = 20;

    for (int i = min(10, 20); i > 0; i--)
    {
        if (num1 % i == 0 && num2 % i == 0)
        {
            cout << "Answer:" << i << endl;
            break;
        }
    }

    while (num1 > 0 && num2 > 0)
    {
        if (num1 > num2)
            num1 = num1 % num2;
        else
            num2 = num2 % num1;
    }

    if (num1 == 0)
        cout << num2;
    else
        cout << num1;
}

// Euclidean Algo

// gcd(n1, n2) = gcd(n1 - n2, n2)  n1 > n2

// gcd(n1, n2) = gcd(n1 % n2, n2)  n1 > n2

// if one of them is zero, the other is gcd