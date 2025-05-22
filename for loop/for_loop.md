✅ Definition

    A for loop is a control flow statement used to repeat a block of code a fixed number of times.

🔧 Syntax

for (initialization; condition; increment) {
// code to execute
}

📌 Example

for (int i = 0; i < 5; i++) {
std::cout << i << " ";
}

Output: 0 1 2 3 4
🧠 Parts Explained

    Initialization – Runs once before the loop starts (e.g., int i = 0)

    Condition – Checked before each iteration (loop runs if true)

    Increment/Decrement – Runs after each iteration (e.g., i++)

🔁 Reverse Loop

for (int i = 5; i > 0; i--) {
std::cout << i << " ";
}

💡 Loop without Initialization or Increment

You can skip parts if needed:

int i = 0;
for (; i < 5; ) {
std::cout << i << " ";
i++;
}

🔄 Nested for Loops

for (int i = 1; i <= 3; i++) {
for (int j = 1; j <= 2; j++) {
std::cout << i << "," << j << " ";
}
}

⚠️ Infinite for Loop

for (;;) {
// runs forever unless broken
}
