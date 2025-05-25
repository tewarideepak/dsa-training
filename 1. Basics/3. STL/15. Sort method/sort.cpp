// 🔹 What is sort()?

// sort() is an STL algorithm used to sort elements in containers like arrays and vectors.

// It belongs to the <algorithm> header.

// By default, it sorts in ascending order.

// 🔹 Header File

// #include <algorithm>

// 🔹 Syntax

// sort(start_iterator, end_iterator);                    // Ascending
// sort(start_iterator, end_iterator, comparator_func);   // Custom

// start_iterator: Beginning of range

// end_iterator: One-past-the-end of range (exclusive)

// comparator_func: Optional function or lambda for custom sorting

// 🔹 Default Sorting (Ascending)

// std::vector<int> v = {4, 1, 5, 2};
// std::sort(v.begin(), v.end());  // [1, 2, 4, 5]

// 🔹 Descending Order

// Using greater<int>:

// std::sort(v.begin(), v.end(), std::greater<int>());

// Using custom lambda:

// std::sort(v.begin(), v.end(), [](int a, int b) {
//     return a > b;
// });

// 🔹 Sorting Array

// int arr[] = {5, 2, 9, 1};
// std::sort(arr, arr + 4);  // sorts from arr[0] to arr[3]

// 🔹 Custom Comparator for Pairs

// Sort by second element, then first:

// std::vector<std::pair<int, int>> vp = {{1, 5}, {2, 3}, {1, 2}};

// std::sort(vp.begin(), vp.end(), [](auto &a, auto &b) {
//     if (a.second == b.second)
//         return a.first < b.first;
//     return a.second < b.second;
// });

// 🔹 Time Complexity

// Case	                Complexity
// Best/Average/Worst	    O(n log n)

// sort() uses a hybrid algorithm: IntroSort (QuickSort + HeapSort + InsertionSort)

// 🔹 Container Compatibility

// Container	Can Use sort()?	        Why / Why Not?
// vector	        ✅ Yes	        Supports random access iterators
// array	        ✅ Yes	        Random access iterators
// deque	        ✅ Yes	        Random access iterators
// list	            ❌ No	        Use list.sort() instead (has its own)
// set, map	        ❌ No	        Already sorted, and keys are immutable

// ✅ Summary

// sort() sorts random-access containers in O(n log n) time.

// Default: ascending; use greater<>() or lambdas for custom sort.

// For list, use list.sort() instead of std::sort().