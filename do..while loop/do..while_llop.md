✅ Definition

    A do...while loop executes the loop body at least once, then checks the condition.

    It's a post-test (exit-controlled) loop.

🔧 Syntax

do {
// code to execute
} while (condition);

📌 Example

int i = 0;
do {
std::cout << i << " ";
i++;
} while (i < 5);

Output: 0 1 2 3 4

🧠 Flow of Execution

    Execute the loop body once.

    Check the condition.

    If true, repeat the loop body.

    Stop when the condition becomes false.

⚠️ Key Feature

    Loop body is always executed at least once, even if the condition is initially false.

int i = 10;
do {
std::cout << i << " ";
} while (i < 5);

Output: 10

🔄 Common Use Case

    Menus and user input:

char choice;
do {
std::cout << "Enter Y to continue: ";
std::cin >> choice;
} while (choice == 'Y' || choice == 'y');

🆚 while vs do...while

Feature | while Loop | do...while Loop
Condition | checked Before loop body | After loop body
Minimum iterations | 0 | 1
Use case | When condition may never be true | When loop must run at least once
