// 🔹 What is a priority_queue?

// A container adapter that provides constant time access to the largest element.

// It behaves like a max-heap by default.

// Elements are ordered by priority (largest by default).

// 🔹 Header File

// #include <queue>

// 🔹 Declaration

// std::priority_queue<int> pq;  // max-heap by default

// 🔹 Key Functions

// Function	    Description
// push(x)	    Adds element x
// pop()	    Removes the top (highest priority) element
// top()	    Returns reference to top element
// empty()	    Checks if queue is empty
// size()	    Returns number of elements
// emplace(x)	Constructs and inserts element

// 🔹 Example: Max Heap

#include <iostream>
#include <queue>

int main()
{
    std::priority_queue<int> pq;

    pq.push(30);
    pq.push(10);
    pq.push(50);

    std::cout << "Top: " << pq.top() << "\n"; // Output: 50

    pq.pop();
    std::cout << "After pop: " << pq.top() << "\n"; // Output: 30
}

// 🔹 Output:

// Top: 50
// After pop: 30

// 🔹 Min Heap

// By default, priority_queue is a max-heap. To make it a min-heap, use:

// std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

// 📌 Example:

// std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
// pq.push(10);
// pq.push(5);
// pq.push(30);
// std::cout << pq.top();  // Output: 5 (min)

// 🔹 Custom Comparator

// For custom objects:

// struct Compare {
//     bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
//         return a.second > b.second;  // min-heap by second value
//     }
// };

// std::priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

// 🔹 Time Complexities

// Operation	Time
// push()	    O(log n)
// pop()	    O(log n)
// top()	    O(1)

// 🔹 Applications (💡 Use Cases)

// Dijkstra’s algorithm

// A* pathfinding

// Huffman encoding

// Job/task scheduling

// Top-K elements

// ✅ Summary

// priority_queue is a heap-based structure.

// Max-heap by default; use greater<> for min-heap.

// Great for problems needing fast access to max/min element.