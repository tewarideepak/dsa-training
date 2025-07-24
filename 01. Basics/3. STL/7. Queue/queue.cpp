// 🔹 What is a queue?

// A FIFO (First In First Out) data structure.

// Elements are added at the back and removed from the front.

// Implemented as a container adapter (like stack), built on other containers (default is deque).

// 🔹 Header File

// #include <queue>

// 🔹 Declaration

// std::queue<int> q;
// std::queue<string> names;

// You can also specify the underlying container:

// std::queue<int, std::list<int>> q2;

// 🔹 Key Member Functions

// Function	        Description
// push(x)	        Adds x at the back
// pop()	        Removes the element at the front
// front()	        Accesses the front element
// back()	        Accesses the last element
// empty()	        Returns true if queue is empty
// size()	        Returns number of elements in the queue
// emplace(x)	    Constructs and inserts x at the back
// swap(q2)	        Swaps contents with another queue

// 🔹 Example: Basic Usage

#include <iostream>
#include <queue>

int main()
{
    std::queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30); // Queue: 10 (front), 20, 30 (back)

    std::cout << "Front: " << q.front() << "\n"; // 10
    std::cout << "Back: " << q.back() << "\n";   // 30

    q.pop(); // Removes 10

    std::cout << "Front after pop: " << q.front() << "\n"; // 20

    return 0;
}

// 🔹 Output

// Front: 10
// Back: 30
// Front after pop: 20

// 🔹 Internal Container Options

// Container Type	    Supported
// deque	            ✅ Default
// list	                ✅

// 🔹 Time Complexities

// Operation	    Time
// push()	        O(1)
// pop()	        O(1)
// front()	        O(1)
// back()	        O(1)

// 🔹 Applications (💡 Use Cases)

// Level-order traversal (BFS) in trees/graphs

// Job scheduling / Task queue

// Buffer handling

// Print queue, call queue

// Simulation systems

// 🔸 queue vs stack vs deque

// Feature	            stack	    queue	deque
// Insert Front	        ❌	        ❌	    ✅
// Insert Back	        ✅	        ✅	    ✅
// Remove Front	        ❌	        ✅	    ✅
// Remove Back	        ✅	        ❌	    ✅
// Random Access	    ❌	        ❌	    ✅

// ✅ Summary

// queue is a FIFO data structure.

// Only allows insertion at back, deletion from front.

// Built using deque internally.

// Useful in BFS, scheduling, streaming, and multi-threaded environments.