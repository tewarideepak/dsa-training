// 🔹 What is list?

//     A list is a doubly linked list provided by the STL.

//     Unlike vector, it allows fast insertion and deletion anywhere but no random access.

//     Each element points to both the next and previous element.

// 🔹 Header File

// #include <list>

// 🔹 Declaration

// std::list<int> l;
// std::list<string> names;

// 🔹 Initialization Examples

// std::list<int> l1 = {10, 20, 30};
// std::list<int> l2(5);          // 5 default-initialized elements (0)
// std::list<int> l3(3, 100);     // 3 elements, all 100

// 🔹 Key Features
// Feature	                        Description
// Fast insertion/deletion	        O(1) at any position
// No random access	                No [] or .at(i)
// Bi-directional iterator	        Traverse forward and backward
// Doubly linked	                Nodes connected in both directions

// 🔹 Important Member Functions

// Function	                    Description
// push_back(val)	            Add element at end
// push_front(val)	            Add element at front
// pop_back()	                Remove last element
// pop_front()	                Remove first element
// insert(pos, val)	            Insert before iterator pos
// erase(pos)	                Erase element at iterator pos
// remove(val)	                Remove all occurrences of val
// clear()	                    Remove all elements
// size()	                    Number of elements
// empty()	                    Check if list is empty
// front(), back()	            Access first/last element
// sort()	                    Sorts the list (must be homogeneous type)
// reverse()	                Reverses the list
// unique()	                    Removes consecutive duplicates only
// merge(l2)	                Merges another sorted list into this list

// 🔹 Iterating a List

// std::list<int> l = {1, 2, 3};

// for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
//     std::cout << *it << " ";

// 🔸 With auto:

// for (auto it = l.begin(); it != l.end(); ++it)
//     std::cout << *it << " ";

// 🔸 Range-based loop:

// for (int x : l)
//     std::cout << x << " ";

// 🔹 Example: Basic Operations

#include <iostream>
#include <list>

int main()
{
    std::list<int> l = {10, 20, 30};

    l.push_front(5); // {5, 10, 20, 30}
    l.push_back(40); // {5, 10, 20, 30, 40}
    l.pop_front();   // {10, 20, 30, 40}
    l.remove(20);    // {10, 30, 40}

    for (int x : l)
        std::cout << x << " ";

    return 0;
}

// 🔹 list vs vector

// Feature	                    vector	                list
// Underlying	                Dynamic array	        Doubly linked list
// Random Access	            ✅ Yes	               ❌ No
// Insertion (middle)	        ❌ Slow (O(n))	       ✅ Fast (O(1))
// Memory Overhead	            Less	                More (due to pointers)
// Cache Friendly	            ✅ Yes	                ❌ No

// 🔹 When to Use list?

// ✅ Prefer list when:

//     Frequent insertions/deletions not at the end

//     No need for random access

//     You want stable iterators (they don't get invalidated easily)