// 🔹 What are they?

// std::max_element() finds the iterator to the largest element in a range.

// std::min_element() finds the iterator to the smallest element in a range.

// 🔹 Header File

// #include <algorithm>

// 🔹 Syntax

// auto it = std::max_element(start_iterator, end_iterator);
// auto it = std::min_element(start_iterator, end_iterator);

// Returns an iterator to the max/min element.

// Use *it to get the actual value.

// 🔹 Example

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v = {10, 20, 5, 23, 42, 15};

    auto max_it = max_element(v.begin(), v.end());
    auto min_it = min_element(v.begin(), v.end());

    cout << "Max: " << *max_it << "\n"; // 42
    cout << "Min: " << *min_it << "\n"; // 5

    return 0;
}

// 🔹 With Custom Comparator

// You can also provide a comparator to change the logic:

// auto max_by_second = max_element(vp.begin(), vp.end(), [](auto &a, auto &b) {
//     return a.second < b.second;
// });

// 🔹 Time Complexity

// O(n) — Linear scan through the range.

// 🔹 Works With

// Any container with random/sequential access iterators: vector, array, deque, list, string

// 🔹 Common Pitfalls

// Issue	                            Example Fix
// Dereferencing without checking	    Ensure the container is not empty before using *it
// Using with wrong types	            Works only with iterators, not raw containers

// ✅ Summary
// Function	            Purpose	                        Returns
// max_element()	    Iterator to largest element	    iterator
// min_element()	    Iterator to smallest element	iterator
// Time Complexity	    O(n)
// Custom Compare	    ✅ Supported