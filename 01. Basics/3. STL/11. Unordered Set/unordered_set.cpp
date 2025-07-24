// 🔹 What is an unordered_set?

// A hash-based associative container that stores unique elements.

// Elements are not stored in any specific order.

// Internally uses a hash table, so operations are generally faster than set.

// 🔹 Header File

// #include <unordered_set>

// 🔹 Declaration

// std::unordered_set<int> us;
// std::unordered_set<std::string> names;

// 🔹 Key Properties

// Feature	                unordered_set
// Duplicate elements	    ❌ Not allowed
// Order	                ❌ No particular order (unordered)
// Search/Insert/Delete	    ✅ Average O(1), Worst O(n)
// Underlying DS	        Hash Table

// 🔹 Common Functions

// Function	        Description
// insert(x)	    Inserts x (if not already present)
// erase(x)	        Removes x if it exists
// find(x)	        Returns iterator to x, or end() if not found
// count(x)	        Returns 1 if x exists, otherwise 0
// size()	        Number of elements
// clear()	        Removes all elements
// empty()	        Checks if set is empty
// begin(), end()	Iterators for traversal (unordered)

// 🔹 Example

#include <iostream>
#include <unordered_set>

int main()
{
    std::unordered_set<int> us;

    us.insert(10);
    us.insert(20);
    us.insert(30);
    us.insert(20); // duplicate, ignored

    for (int x : us)
        std::cout << x << " "; // Order is NOT guaranteed

    std::cout << "\nContains 30? " << us.count(30); // Output: 1
    us.erase(30);
    std::cout << "\nContains 30 after erase? " << us.count(30); // Output: 0

    return 0;
}

// 🔹 Output (Example, order may vary):

// 30 10 20
// Contains 30? 1
// Contains 30 after erase? 0

// 🔹 Time Complexities

// Operation	Average Case	Worst Case
// insert	    O(1)	        O(n)
// erase	    O(1)	        O(n)
// find	        O(1)	        O(n)
// count	    O(1)	        O(n)

// Worst case occurs if many elements hash to the same bucket (hash collisions).

// 🔹 Use Cases (💡 Applications)

// Fast lookup of unique elements

// Hash-based frequency filtering

// Useful in competitive programming for O(1) operations

// Set operations when order does not matter

// 🔹 When to Use unordered_set vs set

// Feature	            set (RB Tree)	unordered_set (Hash Table)
// Ordered?	            ✅ Yes	        ❌ No
// Duplicate allowed?	❌ No	        ❌ No
// Lookup Speed	        O(log n)	     O(1) avg
// Use if	            Need order	     Need speed

// ✅ Summary

// unordered_set stores unique, unordered elements.

// Offers faster average performance than set using a hash table.

// Use when order doesn't matter but speed does.