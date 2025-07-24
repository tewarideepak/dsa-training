// 🔹 What is a pair ?

// A pair is a container from the Standard Template Library(STL).

// It stores two values(elements), which can be of different types.

// Defined in the<utility> header.

// 🔹 Syntax

// #include <utility>

// std::pair<Type1, Type2> pair_name;

// 🔹 Initialization Methods

// 1. Using constructor

// std::pair<int, std::string> p1(1, "apple");

// 2. Using make_pair()

// auto p2 = std::make_pair(2, "banana");

// 3. Assignment

// std::pair<int, char> p3;
// p3.first = 10;
// p3.second = 'A';

// 🔹 Accessing Elements

// std::cout << p1.first;  // Outputs 1
// std::cout << p1.second; // Outputs "apple"

// 🔹 Common Use Cases

// Returning two values from a function.

// Storing key - value pairs(like a simplified map).

// Used heavily in STL containers like map, set, vector<pair<>>.

// 🔹 Example

#include <iostream>
#include <utility>

int main()
{
    std::pair<int, std::string> person = std::make_pair(25, "Alice");

    std::cout << "Age: " << person.first << "\n";
    std::cout << "Name: " << person.second << "\n";
    return 0;
}

// 🔹 Comparison(Lexicographical)

// Pairs can be compared using <, >, ==, etc., based on :

// 1. first elements

// 2. If first elements are equal, then compare second

// std::pair<int, int> a = {1, 2};
// std::pair<int, int> b = {1, 3};

// std::cout << (a < b); // Outputs 1 (true)

// 🔹 Nested Pairs

// std::pair<int, std::pair<int, int>> nested = {1, {2, 3}};
// std::cout << nested.second.first; // Outputs 2

// 🔹 STL Containers of Pairs

// std::vector<std::pair<int, int>> v;
// v.push_back({1, 100});
// v.push_back(std::make_pair(2, 200));