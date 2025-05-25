// 🔹 What is a set?

// A container that stores unique elements in sorted order.

// Implemented as a Balanced Binary Search Tree (usually Red-Black Tree).

// Elements are automatically sorted in ascending order.

// 🔹 Header File

// #include <set>

// 🔹 Declaration

// std::set<int> s;
// std::set<std::string> names;

// You can also use custom sort:

// std::set<int, std::greater<int>> s_desc;  // Descending order

// 🔹 Key Properties

// Property	                Description
// Elements	                Always unique
// Order	                Sorted (ascending by default)
// Duplicates	            ❌ Not allowed
// Internal Structure	    Balanced BST (Red-Black Tree)

// 🔹 Common Member Functions

// Function	            Description
// insert(x)	        Inserts x (if not already present)
// erase(x)	            Removes x from the set
// find(x)	            Returns iterator to x, or s.end() if not found
// count(x)	            Returns 1 if x is present, else 0
// clear()	            Removes all elements
// size()	            Returns number of elements
// empty()	            Checks if set is empty
// begin(), end()	    Iterators to start and end
// lower_bound(x)	    Returns iterator to first element ≥ x
// upper_bound(x)	    Returns iterator to first element > x

// 🔹 Example

#include <iostream>
#include <set>

int main()
{
    std::set<int> s;

    s.insert(5);
    s.insert(1);
    s.insert(3);
    s.insert(3); // duplicate, ignored

    for (int x : s)
        std::cout << x << " "; // Output: 1 3 5

    s.erase(3); // remove element 3

    std::cout << "\nContains 3? " << s.count(3); // Output: 0

    return 0;
}

// 🔹 Output

// 1 3 5
// Contains 3? 0

// 🔹 Time Complexities

// Operation	Time Complexity
// insert	    O(log n)
// erase	    O(log n)
// find	        O(log n)
// count	    O(log n)

// 🔹 Variants of Set

// Type	            Description
// set	            Unique, sorted elements (ascending by default)
// multiset	        Allows duplicates, sorted
// unordered_set	Hash-based, no ordering, faster avg operations

// 🔹 Use Cases (💡 Applications)

// Removing duplicates

// Maintaining sorted elements

// Fast search, insert, delete (log n)

// Custom sorting (with comparator)

// ✅ Summary

// set stores unique, sorted elements.

// Backed by Red-Black Tree (self-balancing BST).

// Use unordered_set for faster operations (if no ordering needed).

// Use multiset if duplicates are allowed.