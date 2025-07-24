// 🔹 What is a stack?

// A LIFO (Last In First Out) data structure.

// Elements are added and removed only from the top.

// STL provides it as a container adapter (built on other containers like deque or vector).

// 🔹 Header File

// #include <stack>

// 🔹 Declaration

// std::stack<int> s;
// std::stack<string> names;

// You can also specify the underlying container (default is deque):

// std::stack<int, std::vector<int>> s2;

// 🔹 Basic Operations (Member Functions)

// Function	        Description
// push(x)	        Pushes element x on top
// pop()	        Removes the top element
// top()	        Returns reference to top element
// empty()	        Checks if stack is empty (returns bool)
// size()	        Returns number of elements in stack
// swap(s2)	        Swaps content with another stack
// emplace(x)	    Constructs and inserts element on top

// 🔹 Example: Basic Usage

#include <iostream>
#include <stack>

int main()
{
    std::stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30); // Top is now 30

    std::cout << "Top: " << s.top() << "\n"; // Output: 30

    s.pop(); // Removes 30

    std::cout << "Top after pop: " << s.top(); // Output: 20

    return 0;
}

// 🔹 Output:

// Top: 30
// Top after pop: 20

// 🔹 Internal Container Options

// Container Type	    Supported
// deque	            ✅ Default
// vector	            ✅
// list	                ✅

// std::stack<int, std::list<int>> s3;  // stack using list

// 🔹 Stack Applications (💡 Use Cases)

// Reversing a string

// Expression evaluation (postfix/infix)

// Undo operations

// Backtracking algorithms

// Balanced parentheses check

// 🔹 Time Complexities

// Operation	Time Complexity
// push	        O(1)
// pop	        O(1)
// top	        O(1)

// ✅ Summary

// stack is a LIFO structure with O(1) top operations.

// It’s ideal for scenarios requiring last-added-first-removed behavior.

// Internally uses deque by default, but can use vector or list.