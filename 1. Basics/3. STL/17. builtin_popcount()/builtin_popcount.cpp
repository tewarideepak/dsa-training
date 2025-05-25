// 🔹 What is __builtin_popcount()?

// A GCC/Clang compiler-provided built-in function to count the number of set bits (1s) in the binary representation of an integer.

// 🔹 Syntax

// int __builtin_popcount(unsigned int x);

// Counts number of 1-bits in x

// Argument must be unsigned

// 🔹 Example

#include <iostream>
using namespace std;

int main()
{
    int n = 29;                    // Binary: 11101
    cout << __builtin_popcount(n); // Output: 4
    return 0;
}

// 🔹 Variants

// Function	                Input Type	            Description
// __builtin_popcount()	    unsigned int	        32-bit unsigned
// __builtin_popcountl()	unsigned long	        32/64-bit (platform-dependent)
// __builtin_popcountll()	unsigned long long	    64-bit guaranteed

// 🔹 Time Complexity

// ⚡ Very fast: Usually O(1) due to hardware instruction (like POPCNT on x86 CPUs)

// 🔹 Use Cases

// Bit counting (e.g., Hamming weight)

// Subset generation

// Bitmask DP

// Parity checks

// Finding sparse values in masks

// 🔹 Notes

// Available only in GCC/Clang

// Not available in standard C++ header (compiler extension)

// For portable C++, use custom function or bitset.count()

// 🔹 Alternative (C++20)

// #include <bit>
// std::popcount(x);  // C++20 standard equivalent

// ✅ Summary

// __builtin_popcount(n) → counts the number of set bits (1s) in n

// Use when performance matters and compiler supports it

// Replaced by std::popcount() in C++20