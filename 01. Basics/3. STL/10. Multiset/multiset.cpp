// 🔹 What is a multiset?

// A sorted associative container like set, but allows duplicate elements.

// Elements are stored in sorted order (ascending by default).

// Internally implemented as a Balanced BST (Red-Black Tree).

// 🔹 Header File

// #include <set>

// 🔹 Declaration

// std::multiset<int> ms;
// std::multiset<std::string> names;

// For descending order:

// std::multiset<int, std::greater<int>> ms_desc;

// 🔹 Key Characteristics

// Feature	            set	                multiset
// Order	            Sorted	            Sorted
// Duplicates	        ❌ Not allowed	   ✅ Allowed
// Underlying DS	    Red-Black Tree	    Red-Black Tree

// 🔹 Common Functions

// Function	            Description
// insert(x)	        Inserts x, allows duplicates
// erase(x)	            Removes all occurrences of x
// erase(iterator)	    Removes only the element at that iterator
// count(x)	            Returns the number of occurrences of x
// find(x)	            Returns iterator to first occurrence of x
// equal_range(x)	    Returns pair of iterators – range of x values
// clear()	            Removes all elements
// size()	            Number of elements
// empty()	            Returns whether multiset is empty
// begin(), end()	    Iterators to start and end

// 🔹 Example

#include <iostream>
#include <set>

int main()
{
    std::multiset<int> ms;

    ms.insert(5);
    ms.insert(1);
    ms.insert(3);
    ms.insert(3); // duplicate allowed

    for (int x : ms)
        std::cout << x << " "; // Output: 1 3 3 5

    std::cout << "\nCount of 3: " << ms.count(3); // Output: 2

    ms.erase(ms.find(3)); // Erase only one occurrence of 3

    std::cout << "\nCount after erase: " << ms.count(3); // Output: 1

    return 0;
}

// 🔹 Output

// 1 3 3 5
// Count of 3: 2
// Count after erase: 1

// 🔹 Time Complexities

// Operation	Time Complexity
// insert	    O(log n)
// erase	    O(log n)
// find	        O(log n)
// count	    O(log n)

// 🔹 Use Cases (💡 Applications)

// Counted frequencies with automatic sorting

// Priority lists where multiple identical priorities exist

// Multiset-based problems (e.g., finding min/max elements with duplicates)

// ✅ Summary

// multiset stores sorted elements with duplicates allowed.

// Use count() to check number of occurrences.

// Use erase(iterator) to remove only one occurrence.

// Internally uses a Red-Black Tree, so operations are O(log n).