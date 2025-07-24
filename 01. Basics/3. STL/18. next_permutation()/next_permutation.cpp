// 🔹 What is it?

// next_permutation() rearranges elements in the lexicographically next greater permutation.

// If such permutation does not exist (i.e., it's the last permutation), it returns to the smallest (sorted) permutation.

// 🔹 Header File

// #include <algorithm>

// 🔹 Syntax

// bool next_permutation(start_iterator, end_iterator);

// Returns true if the permutation was changed to the next permutation.

// Returns false if it was the last permutation and resets the sequence to the first permutation (sorted order).

// 🔹 Example

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3};

    do
    {
        for (int x : v)
            cout << x << " ";
        cout << "\n";
    } while (next_permutation(v.begin(), v.end()));

    return 0;
}

// ✅ Output:

// 1 2 3
// 1 3 2
// 2 1 3
// 2 3 1
// 3 1 2
// 3 2 1

// 🔹 Works with

// vector

// array

// string

// Any random-access iterator container

// 🔹 Important: Initial Sorting

// To generate all permutations, start from sorted order (smallest lexicographic):

// sort(v.begin(), v.end());

// 🔹 Use with prev_permutation()

// prev_permutation(v.begin(), v.end());

// Gives lexicographically previous permutation

// Returns false when it's the first (smallest) permutation

// 🔹 Use Case Examples

// Generating all permutations of a string

// Brute-force for small input

// Finding next lexicographical arrangement

// Solving combinatorial problems like the Traveling Salesman Problem (TSP)

// ✅ Summary

// Feature	                    Description
// Function	                    next_permutation(begin, end)
// Return type	                bool (true if next permutation exists)
// Time complexity	            O(n)
// Use with containers like	    vector, array, string
// Common usage	                Generating permutations, brute force search