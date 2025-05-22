✅ 1. Purpose

    A multi-way decision control structure.

    Selects one of many code blocks to execute based on the value of a single expression.

🔹 2. Syntax

switch (expression) {
case constant1:
// Code block
break;
case constant2:
// Code block
break;
...
default:
// Default code block (optional)
}

🔍 3. How It Works

    expression is evaluated once.

    The result is compared with each case.

    If a match is found, that case's block is executed.

    break ends the switch — without it, fall-through happens.

    default runs if no case matches (like an else).

🧠 4. Example

#include <iostream>
using namespace std;

int main() {
int day;
cout << "Enter day number (1-7): ";
cin >> day;

    switch (day) {
        case 1: cout << "Monday"; break;
        case 2: cout << "Tuesday"; break;
        case 3: cout << "Wednesday"; break;
        case 4: cout << "Thursday"; break;
        case 5: cout << "Friday"; break;
        case 6: cout << "Saturday"; break;
        case 7: cout << "Sunday"; break;
        default: cout << "Invalid day!";
    }

    return 0;

}

⚠️ 5. Important Rules

    switch expression must be integral: int, char, enum, or short (not float, double, string, etc.).

    No variables or ranges in case labels — only constants.

    break is crucial to prevent execution from "falling through" to the next case.

🔁 6. Fall-through Example

char grade = 'B';

switch (grade) {
case 'A':
case 'B':
cout << "Good job!";
break;
case 'C':
cout << "You passed.";
break;
default:
cout << "Try again.";
}

    In the above, both 'A' and 'B' print "Good job!"
