// 🔹 What is a map?

// A key-value associative container.

// Stores unique keys in sorted order (ascending by default).

// Each key maps to a single value.

// Internally implemented as a Red-Black Tree (self-balancing BST).

// 🔹 Header File

// #include <map>

// 🔹 Declaration

// std::map<int, std::string> m;
// std::map<std::string, int> freq;

// You can also sort in descending order:

// std::map<int, int, std::greater<int>> m_desc;

// 🔹 Key Properties

// Property	        Description
// Unique Keys	    ✅ Yes
// Sorted Order	    ✅ Ascending (by default)
// Duplicate Keys	❌ No
// Access Time	    O(log n)
// Underlying DS	Red-Black Tree

// 🔹 Common Member Functions

// Function	            Description
// m[key] = val	        Inserts or updates the value for a key
// m.insert({k, v})	    Inserts key-value pair if key doesn't exist
// m.erase(key)	        Removes element with given key
// m.find(key)	        Returns iterator to key or m.end() if not found
// m.count(key)	        Returns 1 if key exists, else 0
// m.clear()	        Removes all key-value pairs
// m.size()	            Number of elements
// m.empty()	        Checks if map is empty
// begin(), end()	    Iterators to start/end of map

// 🔹 Example

#include <iostream>
#include <map>

int main()
{
    std::map<std::string, int> m;

    m["apple"] = 3;
    m["banana"] = 5;
    m["cherry"] = 2;

    m["apple"] += 2; // apple = 5

    for (auto &pair : m)
        std::cout << pair.first << ": " << pair.second << "\n";

    if (m.count("banana"))
        std::cout << "Banana exists.\n";

    m.erase("banana");

    return 0;
}

// 🔹 Output

// apple: 5
// banana: 5
// cherry: 2
// Banana exists.

// 🔹 Time Complexities

// Operation	Time Complexity
// insert	    O(log n)
// erase	    O(log n)
// find	        O(log n)
// [] operator	O(log n)

// 🔹 Use Cases (💡 Applications)

// Frequency counting

// Key-based lookup (like a dictionary)

// Mapping values to keys (e.g., roll number → student name)

// Storing records where order of keys is required

// 🔹 When to Use map vs unordered_map

// Feature	            map	                unordered_map
// Order	            ✅ Sorted	       ❌ No order
// Time Complexity	    O(log n)	        O(1) average
// Internals	        Red-Black Tree	    Hash Table
// Duplicates	        ❌ Not allowed	   ❌ Not allowed

// ✅ Summary

// map stores unique keys in sorted order with key-value pairs.

// Great for ordered lookup, frequency maps, and indexed storage.

// Use unordered_map for faster access when order is not important.