// 🔹 What is unordered_map?

// A key-value associative container like map.

// Stores unique keys, but no specific order.

// Provides average O(1) time complexity for insertion, deletion, and access.

// Internally implemented using a Hash Table.

// 🔹 Header File

// #include <unordered_map>

// 🔹 Declaration

// std::unordered_map<int, std::string> um;
// std::unordered_map<std::string, int> freq;

// 🔹 Key Properties

// Property	                    Description
// Keys	                        ✅ Unique only
// Order	                    ❌ Not sorted (unordered)
// Access Time	                ✅ O(1) average, O(n) worst
// Underlying Structure	        Hash Table
// Duplicates Allowed	        ❌ No

// 🔹 Common Functions

// Function	            Description
// um[key] = val	    Inserts or updates key with value
// um.insert({k, v})	Inserts key-value pair (if key not already exists)
// um.erase(key)	    Removes the key-value pair
// um.find(key)	        Returns iterator to key or um.end()
// um.count(key)	    Returns 1 if key exists, 0 otherwise
// um.size()	        Number of elements
// um.clear()	        Clears the map
// um.empty()	        Checks if map is empty
// begin(), end()	    Iterators to first/last elements (no order)

// 🔹 Example

#include <iostream>
#include <unordered_map>

int main()
{
    std::unordered_map<std::string, int> um;

    um["apple"] = 4;
    um["banana"] = 2;
    um["cherry"] = 3;

    um["apple"] += 1; // apple = 5

    for (auto &p : um)
        std::cout << p.first << ": " << p.second << "\n";

    if (um.count("banana"))
        std::cout << "Banana exists\n";

    um.erase("banana");

    return 0;
}

// 🔹 Output (unordered)

// cherry: 3
// apple: 5
// banana: 2
// Banana exists

// Note: Output order may vary each run due to hash table structure.

// 🔹 Time Complexities

// Operation	Time (Avg)	    Time (Worst)
// insert	    O(1)	        O(n)
// erase	    O(1)	        O(n)
// find	        O(1)	        O(n)

// Worst-case happens when hash collisions are high.

// 🔹 Use Cases

// Fast lookup tables

// Frequency counters

// Caching (e.g., LRU Cache)

// Word count from a string

// Hash-based key-value mappings where order doesn’t matter

// 🔹 When to Use unordered_map vs map

// Feature	            map	                unordered_map
// Key order	        ✅ Sorted           ❌ Unordered
// Time Complexity	    O(log n)	        O(1) avg, O(n) worst
// Underlying DS	    Red-Black Tree	    Hash Table
// Duplicates	        ❌ Not allowed	   ❌ Not allowed
// Use When	            Order matters	    Performance matters

// ✅ Summary

// unordered_map offers fast access with unique keys, no sorting.

// Backed by hash tables, average time is O(1).

// Ideal when key ordering is not important and you need maximum speed.