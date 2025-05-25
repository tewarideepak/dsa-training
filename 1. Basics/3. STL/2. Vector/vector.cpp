// 🔹 What is a vector?

// A vector is a dynamic array from the Standard Template Library (STL).

// Can grow or shrink in size automatically.

// Provides random access, and efficient insertion/deletion at the end.

// 🔹 Header File

// #include <vector>

// 🔹 Declaration Syntax

// std::vector<DataType> vec_name;

// Examples:

// std::vector<int> v;              // Empty vector
// std::vector<int> v(5);           // Size 5, default initialized (0)
// std::vector<int> v(5, 10);       // Size 5, all elements 10
// std::vector<int> v2 = {1, 2, 3}; // Initializer list

// 🔹 Common Member Functions

// Function	               Description
// push_back(x)	          Adds element at the end
// pop_back()	          Removes last element
// size()	              Returns number of elements
// capacity()	          Returns allocated storage
// empty()	              Checks if vector is empty
// clear()	              Removes all elements
// resize(n)	          Resizes vector to contain n elems
// at(i)	              Safe access to element at index i
// front()	              First element
// back()	              Last element
// begin()/end()	      Iterators to start/end

// 🔹 Accessing Elements

// v[0] = 10;
// std::cout << v.at(1);

// 🔹 Iterating Over a Vector

// 1. Using Index

// for (int i = 0; i < v.size(); ++i)
//     std::cout << v[i] << " ";

// 2. Range-based for loop

// for (int x : v)
//     std::cout << x << " ";

// 3. Using Iterators

// for (auto it = v.begin(); it != v.end(); ++it)
//     std::cout << *it << " ";

// 🔹 2D Vector (Matrix)

// std::vector<std::vector<int>> matrix(3, std::vector<int>(4, 0));

// Creates a 3x4 matrix initialized with 0.

// 🔹 Example

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    for (int i : v)
        std::cout << i << " ";

    return 0;
}

// ➕ insert() Function in vector

// 🔹 Purpose

//     Adds one or more elements at a specified position in a vector.

// 🔹 Syntax

// vec.insert(iterator_position, value);                        // Insert single element
// vec.insert(iterator_position, count, value);                 // Insert multiple copies
// vec.insert(iterator_position, start_iterator, end_iterator); // Insert a range

// 🔹 Parameters

//     iterator_position: Where to insert (e.g., v.begin() + 2)

//     value: Element to insert

//     count: Number of times to insert the element

//     start_iterator, end_iterator: Range to insert from another container

// 🔹 Example 1: Insert single element

// std::vector<int> v = {10, 20, 40};
// v.insert(v.begin() + 2, 30);  // Inserts 30 at index 2

// Result: {10, 20, 30, 40}

// 🔹 Example 2: Insert multiple copies

// std::vector<int> v = {1, 2, 5};
// v.insert(v.begin() + 2, 3, 4);  // Inserts 4, 4, 4 at index 2

// Result: {1, 2, 4, 4, 4, 5}

// 🔹 Example 3: Insert range from another vector

// std::vector<int> v1 = {1, 2, 6};
// std::vector<int> v2 = {3, 4, 5};

// v1.insert(v1.begin() + 2, v2.begin(), v2.end());

// Result: {1, 2, 3, 4, 5, 6}

// 🔹 Time Complexity

//     Inserting at the end: O(1) (amortized)

//     Inserting anywhere else: O(n), due to element shifting

// 🔹 Notes

//     insert() invalidates iterators after the insertion point.

//     Useful for merging, prepending, or batch updates.

// 🧹 erase() Function in vector

// 🔹 Purpose

// Removes elements from a vector.

// Shifts subsequent elements to maintain order.

// Reduces the size of the vector.

// 🔹 Syntax

// vec.erase(position);                   // Remove one element
// vec.erase(start_iterator, end_iterator); // Remove a range

// 🔹 Parameters

// position: Iterator pointing to the element to remove.

// start_iterator, end_iterator: Range of elements [start, end) to remove.

// 🔹 Example 1: Erase a single element

// std::vector<int> v = {10, 20, 30, 40};
// v.erase(v.begin() + 2);  // Removes 30

// Result: {10, 20, 40}

// 🔹 Example 2: Erase a range of elements

// std::vector<int> v = {10, 20, 30, 40, 50};
// v.erase(v.begin() + 1, v.begin() + 4);  // Removes 20, 30, 40

// Result: {10, 50}

// 🔹 Erase by value (custom approach)

// To remove all occurrences of a value (e.g., 20):

// v.erase(std::remove(v.begin(), v.end(), 20), v.end());

// Uses the "erase-remove" idiom

// ⚠️ Important Notes

// erase() is O(n) in the worst case due to shifting.

// Always check bounds when using iterators.

// Modifying a vector while iterating can invalidate iterators.

// 🔹 Vector vs Array

// Feature	                 vector	                  array
// Size	                     Dynamic	              Static
// Bounds Check	           at() does it	                No
// Flexibility	              High	                   Low
// Memory	                  Heap	                  Stack

// Swapping:

// v1 -> {10, 20}
// v2 -> {30, 40}

// v1.swap(v2); // v1 -> {30, 40} , v2 -> {10, 20}