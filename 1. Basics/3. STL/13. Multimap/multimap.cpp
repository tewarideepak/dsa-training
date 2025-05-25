// 🔹 What is a multimap?

// A key-value associative container like map.

// Allows duplicate keys, unlike map.

// Stores elements in sorted order of keys (ascending by default).

// Internally implemented as a Red-Black Tree.

// 🔹 Header File

// #include <map>

// 🔹 Declaration

// std::multimap<int, std::string> mm;
// std::multimap<std::string, int> freq;

// Descending order:

// std::multimap<int, int, std::greater<int>> mm_desc;

// 🔹 Key Properties

// Feature	            map	                multimap
// Key Uniqueness	    ✅ Unique	       ❌ Duplicate allowed
// Sorted by Key	    ✅ Yes	           ✅ Yes
// Internal DS	        Red-Black Tree	    Red-Black Tree
// Access by key	    O(log n)	        O(log n)

// 🔹 Common Functions

// Function	            Description
// insert({k, v})	    Inserts key-value pair (duplicates allowed)
// erase(key)	        Erases all pairs with that key
// erase(iterator)	    Erases the element at the given iterator
// find(key)	        Returns iterator to first occurrence
// count(key)	        Number of elements with that key
// equal_range(key)	    Returns a pair of iterators (range of that key)
// clear()	            Erase all elements
// size()	            Total elements (including duplicates)
// empty()	            Returns true if empty
// begin(), end()	    Iterators to first and last elements

// 🔹 Example

#include <iostream>
#include <map>

int main()
{
    std::multimap<int, std::string> mm;

    mm.insert({1, "apple"});
    mm.insert({2, "banana"});
    mm.insert({1, "apricot"}); // duplicate key allowed

    for (auto &p : mm)
        std::cout << p.first << " -> " << p.second << "\n";

    std::cout << "Count of key 1: " << mm.count(1) << "\n";

    // Get range of key 1
    auto range = mm.equal_range(1);
    for (auto it = range.first; it != range.second; ++it)
        std::cout << "Equal range -> " << it->first << ": " << it->second << "\n";

    return 0;
}

// 🔹 Output

// 1 -> apple
// 1 -> apricot
// 2 -> banana
// Count of key 1: 2
// Equal range -> 1: apple
// Equal range -> 1: apricot

// 🔹 Time Complexities

// Operation	Time Complexity
// insert	    O(log n)
// erase	    O(log n)
// find	        O(log n)
// equal_range	O(log n)

// 🔹 Use Cases (💡 Applications)

// Indexing multiple values for the same key

// Grouping records with same key (e.g., timestamps → logs)

// Storing duplicate frequencies (e.g., product ID → reviews)

// Use when you need sorted duplicate keys

// ✅ Summary

// multimap is like map, but allows duplicate keys.

// Keys are always stored in sorted order.

// Use equal_range() or count() to access duplicates.

// Internally uses a Red-Black Tree, so all major operations are O(log n).