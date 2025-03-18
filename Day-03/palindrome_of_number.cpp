
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int x) {
    int rev = 0, num = x, rem = 0;

    if(x < 0) return 0;

    while(x){
        rem = x % 10;
        if(rev > INT_MAX / 10) return 0;
        rev = rev * 10 + rem;
        x /= 10;
    }

    if(rev == num) return 1;
    else return 0;
}


#include <iostream>
using namespace std;

bool isPalindrome(int num) {
    // Negative numbers and numbers ending with 0 (except 0 itself) can't be palindromes
    if (num < 0 || (num != 0 && num % 10 == 0)) {
        return false;
    }

    int reversedHalf = 0;
    // Reverse only half of the number to save time
    while (num > reversedHalf) {
        reversedHalf = reversedHalf * 10 + num % 10;
        num /= 10;
    }

    // Check if the original first half equals the reversed second half
    // For even-length numbers -> num == reversedHalf
    // For odd-length numbers -> num == reversedHalf / 10 (middle digit ignored)
    return (num == reversedHalf || num == reversedHalf / 10);
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isPalindrome(num)) {
        cout << num << " is a palindrome." << endl;
    } else {
        cout << num << " is not a palindrome." << endl;
    }

    return 0;
}
