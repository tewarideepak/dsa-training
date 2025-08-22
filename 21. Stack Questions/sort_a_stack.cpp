//  Problem statement

// You’re given a stack consisting of 'N' integers. Your task is to sort this stack in descending order using recursion.

// We can only use the following functions on this stack S.

// is_empty(S) : Tests whether stack is empty or not.
// push(S) : Adds a new element to the stack.
// pop(S) : Removes top element from the stack.
// top(S) : Returns value of the top element. Note that this function does not remove elements from the stack.

// Note :

// 1) Use of any loop constructs like while, for..etc is not allowed.
// 2) The stack may contain duplicate integers.
// 3) The stack may contain any integer i.e it may either be negative, positive or zero.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:

// 1 <= 'T' <= 100
// 1 <=  'N' <= 100
// 1 <= |'V'| <= 10^9

// Where |V| denotes the absolute value of any stack element.

// Time limit: 1 sec

// Sample Input 1:

// 1
// 5
// 5 -2 9 -7 3

// Sample Output 1:

// 9 5 3 -2 -7

// Explanation of Sample Input 1:

// 9 Is the largest element, hence it’s present at the top. Similarly 5>3, 3>-2 and -7 being the smallest element is present at the last.

// Sample Input 2:

// 1
// 5
// -3 14 18 -5 30

// Sample Output 2:

// 30 18 14 -3 -5

// Explanation of Sample Input 2:

// 30 is the largest element, hence it’s present at the top. Similarly, 18>14, 14>-3 and -5 being the smallest element is present at the last.

#include <bits/stdc++.h>
using namespace std;

// Helper function: Insert element in sorted order (descending)
void insertSorted(stack<int> &st, int num)
{
    // If stack is empty OR num >= top, push directly
    if (st.empty() || num >= st.top())
    {
        st.push(num);
        return;
    }

    // Otherwise pop top, insert recursively, then push back
    int temp = st.top();
    st.pop();
    insertSorted(st, num);
    st.push(temp);
}

// Main function: Sort stack in descending order
void sortStack(stack<int> &st)
{
    if (st.empty())
        return;

    // Remove top
    int num = st.top();
    st.pop();

    // Recursively sort remaining stack
    sortStack(st);

    // Insert popped element in sorted order
    insertSorted(st, num);
}

// Utility function to print stack (top -> bottom)
void printStack(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

// Driver code
int main()
{
    stack<int> st;

    // Example 1
    vector<int> arr1 = {5, -2, 9, -7, 3};
    for (int x : arr1)
        st.push(x);

    sortStack(st);
    cout << "Sorted Stack (Example 1): ";
    printStack(st); // Expected: 9 5 3 -2 -7

    // Example 2
    stack<int> st2;
    vector<int> arr2 = {-3, 14, 18, -5, 30};
    for (int x : arr2)
        st2.push(x);

    sortStack(st2);
    cout << "Sorted Stack (Example 2): ";
    printStack(st2); // Expected: 30 18 14 -3 -5

    return 0;
}

// 📊 Complexity Analysis

// Time Complexity (TC):

// Each element is inserted recursively into the stack.

// Worst-case insertion takes O(N) (if smallest element goes to bottom).

// For N elements → O(N^2).

// Since N ≤ 100, this is optimal under recursion-only constraints.

// Space Complexity (SC):

// Only recursion stack is used (no extra DS).

// Max recursion depth = O(N) (for both sortStack and insertSorted).

// So SC = O(N).