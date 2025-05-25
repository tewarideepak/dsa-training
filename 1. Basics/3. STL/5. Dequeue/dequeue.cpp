// 🔹 What is deque?

// deque stands for Double Ended Queue.

// It allows insertion and deletion from both ends (front and back) in O(1) time.

// Internally implemented as a dynamic array of fixed-size arrays.

// 🔹 Header File

// #include <deque>

// 🔹 Declaration

// std::deque<int> dq;
// std::deque<string> names;

// 🔹 Initialization Examples

// std::deque<int> dq1 = {10, 20, 30};
// std::deque<int> dq2(5);         // 5 default-initialized elements
// std::deque<int> dq3(3, 100);    // 3 elements with value 100

// 🔹 Key Features

// Feature	                        Description
// Fast at both ends	            O(1) insertion/deletion at front/back
// Random access	                ✅ Supported (like vector)
// Middle insert/erase	            Slower (O(n))
// Doubly-ended	                True double-ended queue

// 🔹 Important Member Functions

// Function	                Description
// push_back(val)	            Add to end
// push_front(val)	            Add to front
// pop_back()	                Remove from end
// pop_front()	                Remove from front
// front(), back()	            Access front/back element
// insert(pos, val)	        Insert before iterator pos
// erase(pos)	                Remove element at iterator pos
// size()	                    Get number of elements
// empty()	                    Check if empty
// clear()	                    Removes all elements
// at(index) / [i]	            Random access
// begin(), end()	            Iterators

// 🔹 Iterating a Deque

// std::deque<int> dq = {10, 20, 30};

// for (auto it = dq.begin(); it != dq.end(); ++it)
//     std::cout << *it << " ";

// Or:

// for (int x : dq)
//     std::cout << x << " ";

// 🔹 Example: Basic Operations

#include <iostream>
#include <deque>

int main()
{
    std::deque<int> dq;

    dq.push_back(10); // {10}
    dq.push_front(5); // {5, 10}
    dq.push_back(20); // {5, 10, 20}

    dq.pop_front(); // {10, 20}
    dq.pop_back();  // {10}

    std::cout << dq.front(); // 10
}

// 🔹 deque vs vector vs list

// Feature	                deque	          vector  	    list
// Insert Front	            ✅ Fast	        ❌ Slow	    ✅ Fast
// Insert Back	            ✅ Fast	        ✅ Fast	    ✅ Fast
// Insert Middle	        ❌ Slow	        ❌ Slow	    ✅ Fast
// Random Access	        ✅ Yes	        ✅ Yes	    ❌ No
// Cache Performance	    ⚠️ Medium	     ✅ Good	     ❌ Poor
// Iterator Stability	    ❌ Limited	    ❌ Limited	✅ Stable

// 🔹 When to Use deque?

// ✅ Use deque when:

// You need fast insertion/deletion from both ends.

// You still want random access like arrays.

// You don't want the overhead of list, but need more flexibility than vector.