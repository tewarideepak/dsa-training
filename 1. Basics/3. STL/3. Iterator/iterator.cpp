// 🔹 What are Iterators?

// Iterators are objects that point to elements in STL containers (like vector, map, set, etc.).

// They work like pointers and allow you to traverse containers.

// Defined in the <iterator> or respective container headers (e.g., <vector>, <map>).

// 🔹 Types of Iterators

// Iterator Type	   Description
// Input Iterator	   Read data in a single pass (e.g., istream_iterator)
// Output Iterator	   Write data in a single pass (e.g., ostream_iterator)
// Forward Iterator    Read/write multiple passes (e.g., forward_list)
// Bidirectional	   Move forward & backward (e.g., list, set)
// Random Access	   Direct jump (e.g., vector, deque)

// 🔹 Syntax

// std::vector<int>::iterator it;

// 🔹 Basic Iterator Operations

// Operation	        Description
// it = v.begin()	    Points to the first element
// it = v.end()	        Points past the last element
// *it	                Access value pointed to
// it++ / ++it	        Move to next element
// it-- / --it	        Move to previous (for bidirectional)

// 🔹 Example with vector

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v = {10, 20, 30};

    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        std::cout << *it << " ";
    }

    return 0;
}

// 🔹 Using auto (C++11+)

// for (auto it = v.begin(); it != v.end(); ++it)
//     std::cout << *it << " ";

// 🔹 Range-Based Loop (Simpler Alternative)

// for (int x : v)
//     std::cout << x << " ";

// 🔹 Const Iterator

// std::vector<int>::const_iterator cit = v.begin();
// *cit = 5;  // ❌ Not allowed – read-only

// 🔹 Reverse Iterator

// for (auto rit = v.rbegin(); rit != v.rend(); ++rit)
//     std::cout << *rit << " ";

// 🔹 Iterator with Other Containers

// Set:

// std::set<int> s = {1, 2, 3};
// for (auto it = s.begin(); it != s.end(); ++it)
//     std::cout << *it << " ";

// Map:

// std::map<int, std::string> m = {{1, "one"}, {2, "two"}};
// for (auto it = m.begin(); it != m.end(); ++it)
//     std::cout << it->first << ": " << it->second << "\n";

// 🔹 STL Algorithms with Iterators

// Iterators are used with algorithms like:

// std::sort(v.begin(), v.end());
// std::find(v.begin(), v.end(), 20);
// std::reverse(v.begin(), v.end());

// 🔹 Summary

// Iterators generalize pointers for STL containers.

// Allow traversal, insertion, deletion, and modification.

// Work with all STL algorithms.

// Use auto for simpler syntax (especially with long types like map<int, string>::iterator).