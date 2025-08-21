//  Problem statement

// Reverse a given stack of 'N' integers using recursion. You are required to make changes in the input parameter itself.

// Note: You are not allowed to use any extra space other than the internal stack space used due to recursion.

// Example:

// Input: [1,2,3,4,5]
// Output: [5,4,3,2,1]

// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1 :

// 3
// 2 1 3

// Sample Output 1 :

// 3 1 2

// Explanation to Sample Input 1 :

// Reverse of a give stack is 3 1 2 where first element becomes last and last becomes first.

// Sample Input 2 :

// 2
// 3 2

// Sample Output 2 :

// 2 3

// Constraints :

// 0 <= N <= 10^3
// Where 'N' is the number of elements in the given stack.

#include <bits/stdc++.h>
using namespace std;

// Helper function to insert an element at the bottom of the stack
void insertAtBottom(stack<int> &st, int x)
{
    if (st.empty())
    {
        st.push(x);
        return;
    }

    int top = st.top();
    st.pop();

    insertAtBottom(st, x);

    st.push(top);
}

// Function to reverse the stack using recursion
void reverseStack(stack<int> &st)
{
    if (st.empty())
        return;

    int top = st.top();
    st.pop();

    reverseStack(st);        // reverse the remaining stack
    insertAtBottom(st, top); // put the top element at the bottom
}

// Utility function to print stack (top to bottom)
void printStack(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n";
}

// Example usage
int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5); // Stack top = 5

    cout << "Original Stack (top to bottom): ";
    printStack(st);

    // Reverse stack
    reverseStack(st);

    cout << "Reversed Stack (top to bottom): ";
    printStack(st);

    return 0;
}

// 🔹 Complexity Analysis

// Time Complexity: O(N^2)

// Reason: insertAtBottom itself takes O(N) per call, and there are N recursive calls in reverseStack.

// Space Complexity: O(N)

// Reason: recursion call stack goes up to N for reverseStack and up to N for insertAtBottom (worst-case nested calls).