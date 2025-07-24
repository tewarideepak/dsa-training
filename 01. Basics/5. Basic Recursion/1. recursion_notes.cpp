// ✅ Definition:

// Recursion is a programming technique where a function calls itself directly or indirectly to solve a problem.

// 🧠 Key Idea:

// Break a large problem into smaller sub-problems of the same type.

// 📦 Types of Recursion:

//     Direct Recursion: Function calls itself directly.

//     Indirect Recursion: Function A calls Function B, and Function B calls Function A.

// 🔁 Structure of a Recursive Function:

// return_type function_name(parameters) {
//     if (base_condition) {
//         return base_value;
//     } else {
//          Recursive case
//         return function_name(smaller_problem);
//     }
// }

// 🧱 Components:

//     Base Case: Condition to stop recursion (prevents infinite loop).

//     Recursive Case: Function calls itself with a simpler/smaller input.

// 🧮 Example – Factorial Function:

// int factorial(int n) {
//     if (n == 0) return 1;           // base case
//     return n * factorial(n - 1);    // recursive case
// }

// 🔍 How It Works (factorial(3)):

// factorial(3)
// → 3 * factorial(2)
// → 3 * (2 * factorial(1))
// → 3 * (2 * (1 * factorial(0)))
// → 3 * 2 * 1 * 1 = 6

// 🛑 Important Notes:

//     Each recursive call has its own stack frame.

//     Too deep recursion can lead to stack overflow.

//     Always define a base case to terminate recursion.

// ⚡ Advantages:

//     Clean and elegant solutions for problems like:

//         Factorial

//         Fibonacci series

//         Tree traversals

//         Tower of Hanoi

//         Backtracking (N-Queens, Sudoku)

// ⚠️ Disadvantages:

//     Overhead due to multiple function calls.

//     Less efficient than loops in some cases.

//     Memory intensive (stack usage).

// 🔁 Recursion vs Iteration:

// | Feature     | Recursion             | Iteration         |
// | ----------- | --------------------- | ----------------- |
// | Use         | Function calls itself | Loop (for/while)  |
// | Termination | Base case             | Loop condition    |
// | Memory      | Uses call stack       | Less memory usage |
// | Performance | Can be slower         | Usually faster    |
