// ✅ 1. Purpose

// Used for decision making in programs.

// Executes different code blocks based on conditions.

// 🔹 2. Syntax
// ➤ Basic if statement:

if (condition) {
    // Code to execute if condition is true
}

// ➤ if-else statement:

if (condition) {
    // Code if true
} else {
    // Code if false
}

// ➤ if-else if-else ladder:

if (condition1) {
    // Code if condition1 is true
} else if (condition2) {
    // Code if condition2 is true
} else {
    // Code if none are true
}

// 🧠 3. Example

#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (num > 0) {
        cout << "Positive number";
    } else if (num < 0) {
        cout << "Negative number";
    } else {
        cout << "Zero";
    }

    return 0;
}

// ⚠️ 4. Important Notes

// Condition must return a boolean (true or false).

// Use curly braces {} for multiple lines (optional for one-line blocks, but recommended).

// Logical operators (&&, ||, !) can combine conditions.

// 🔄 5. Nested if

// You can place one if inside another:

if (x > 0) {
    if (x % 2 == 0) {
        cout << "Positive even";
    } else {
        cout << "Positive odd";
    }
}

// 🔍 6. Ternary Operator (Short form)

// Alternative to simple if-else:

int a = 5, b = 10;
int max = (a > b) ? a : b;  // Ternary operator