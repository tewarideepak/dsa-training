✅ Definition

    A while loop repeats a block of code as long as a given condition is true.

    It's an entry-controlled loop, meaning the condition is checked before each iteration.

🔧 Syntax

while (condition) {
// code to execute
}

📌 Example

int i = 0;
while (i < 5) {
std::cout << i << " ";
i++;
}

Output: 0 1 2 3 4

🧠 Flow of Execution

    Check condition.

    If true, execute the loop body.

    Repeat until condition becomes false.

⚠️ Important Points

    Ensure the loop modifies something so the condition will eventually become false (to avoid infinite loop).

    Use when number of iterations is not known in advance.

🔄 Infinite while Loop

while (true) {
// runs forever unless broken using `break`
}

⛔ Common Mistake

Forgetting to update variables inside the loop:

int i = 0;
while (i < 5) {
std::cout << i << " ";
// missing i++ → leads to infinite loop
}

🎯 Use Cases

    Waiting for user input

    Reading from a file until EOF

    Looping until a condition is met (e.g., correct password)

🔁 Comparison: while vs for

Feature | while Loop | for Loop
Use When | Condition-based loop | Count-based loop
Flexibility | More flexible | More compact for fixed runs
