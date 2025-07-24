// 🔹 What is a Comparator?

// A comparator is a function or functor used to define a custom sorting or ordering logic.

// It is used with:

// sort()

// priority_queue

// set, map (custom order)

// min_element, max_element, etc.

// 🔹 Types of Comparators

// Function Pointer

// Lambda Function

// Function Object (Functor)

// ✅ Syntax: With sort()

// bool compare(int a, int b) {
// return a > b;  // descending
// }

// std::sort(v.begin(), v.end(), compare);

// Or use a lambda:

// std::sort(v.begin(), v.end(), [](int a, int b) {
// return a > b;
// });

// 🔹 Comparators with Pairs

// Example: Sort pairs by second, then first:

// bool cmp(pair<int, int> a, pair<int, int> b) {
//     if (a.second == b.second)
//         return a.first < b.first;
//     return a.second < b.second;
// }
// std::sort(v.begin(), v.end(), cmp);

// 🔹 Comparators in priority_queue
// Default (Max Heap):

// priority_queue<int> pq;

// Min Heap:

// priority_queue<int, vector<int>, greater<int>> pq;

// Custom Comparator with Struct:

// struct Compare {
//     bool operator()(int a, int b) {
//         return a > b;  // min heap
//     }
// };
// priority_queue<int, vector<int>, Compare> pq;

// 🔹 Custom Comparator in set or map

// struct Descending {
//     bool operator()(const int &a, const int &b) const {
//         return a > b;
//     }
// };

// std::set<int, Descending> s;  // Elements stored in descending order

// 🔹 Comparator Rules

// Must return a boolean.

// Must define a strict weak ordering.

// For sorting in ascending: a < b

// For descending: a > b

// 🔹 Example: Sort Structs

// struct Student {
//     string name;
//     int marks;
// };

// bool cmp(Student a, Student b) {
//     return a.marks > b.marks;
// }

// std::sort(students.begin(), students.end(), cmp);

// ✅ Summary

// Use Case	                Comparator Type
// sort()	                Function, lambda, functor
// priority_queue	        greater<>() or custom struct
// set, map custom order	Custom struct with operator()