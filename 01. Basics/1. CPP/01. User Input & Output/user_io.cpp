// 1. 📤 Output in C++

//     Used to display information on the screen.

//     Handled using the cout object from the iostream library.

// ➤ Syntax:

// #include <iostream>
// using namespace std;

// cout << "Hello, World!";

// ➤ Notes:

//     << is the insertion operator (inserts data into the output stream).

//     Multiple values can be output using chained <<.

// int a = 5;
// cout << "Value of a: " << a << endl;

// 2. 📥 Input in C++

//     Used to take data from the user.

//     Handled using the cin object from the iostream library.

// ➤ Syntax:

// #include <iostream>
// using namespace std;

// int x;
// cin >> x;

// ➤ Notes:

//     >> is the extraction operator (extracts input from the stream).

//     You can read multiple inputs in one line:

// int a, b;
// cin >> a >> b;

// 3. 🧠 Common Input/Output Functions
// Function	Description
// cout	Standard output stream
// cin	Standard input stream
// endl	Ends the line (like \n)
// getline(cin, str)	Reads an entire line including spaces
// 4. ⚠️ Important Notes

//     cin stops at space or newline; use getline for full line input.

//     cout is used for debugging, messages, and results display.

// 5. 📌 Example: Basic Input/Output

#include <iostream>
using namespace std;

int main() {
    string name;
    int age;

    cout << "Enter your name: ";
    getline(cin, name);  // reads full line

    cout << "Enter your age: ";
    cin >> age;

    cout << "Hello, " << name << "! You are " << age << " years old." << endl;

    return 0;
}