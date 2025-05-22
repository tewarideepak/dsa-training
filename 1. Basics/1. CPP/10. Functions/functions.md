✅ Definition

    A function is a reusable block of code that performs a specific task.

    It can accept inputs (parameters) and optionally return a value.

📌 Syntax

return_type function_name(parameter_list) {
// function body
}

Example:

int add(int a, int b) {
return a + b;
}

📤 Parameter Passing in C++

1️⃣ Pass by Value

🔧 Syntax

void modify(int x) {
x = x + 10;
}

🔍 How It Works

    A copy of the variable is passed.

    Changes do not affect the original variable.

🧪 Example

int a = 5;
modify(a);
// a is still 5

2️⃣ Pass by Reference

🔧 Syntax

void modify(int &x) {
x = x + 10;
}

🔍 How It Works

    A reference (alias) to the original variable is passed.

    Changes do affect the original variable.

🧪 Example

int a = 5;
modify(a);
// a is now 15

🔄 Pass by Pointer (Alternative way to reference)

<!-- void modify(int* x) {
*x = *x + 10;
} -->

int a = 5;
modify(&a); // a becomes 15

🆚 Summary: Pass by Value vs Reference

Feature | Pass by Value | Pass by Reference
Data copied? | ✅ Yes | ❌ No (alias used)
Affects original? | ❌ No | ✅ Yes
Safer (accidental change)? | ✅ Yes | ❌ No
Performance (large data) | Slower (copies) | Faster (no copies)
