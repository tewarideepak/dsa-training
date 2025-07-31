//  Problem statement

// You are given a linked list of 'n' nodes and an integer 'k', where 'k' is less than or equal to 'n'.

// Your task is to reverse the order of each group of 'k' consecutive nodes, if 'n' is not divisible by 'k', then the last group of nodes should remain unchanged.

// For example, if the linked list is 1->2->3->4->5, and 'k' is 3, we have to reverse the first three elements, and leave the last two elements unchanged. Thus, the final linked list being 3->2->1->4->5.

// Implement a function that performs this reversal, and returns the head of the modified linked list.

// Example:

// Input: 'list' = [1, 2, 3, 4], 'k' = 2

// Output: 2 1 4 3

// Explanation:
// We have to reverse the given list 'k' at a time, which is 2 in this case. So we reverse the first 2 elements then the next 2 elements, giving us 2->1->4->3.

// Note:

// All the node values will be distinct.

// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:

// 6
// 5 4 3 7 9 2
// 4

// Sample Output 1:

// 7 3 4 5 9 2

// Explanation of the Sample Input 1:

// For the given test case, we reverse the nodes in groups of four. But for the last 2 elements, we cannot form a group of four, so leave them as they are. The linked list becomes 7->3->4->5->9->2. Hence the output is 7 3 4 5 9 2

// Sample Input 2:

// 4
// 4 3 2 8
// 4

// Sample Output 2:

// 8 2 3 4

// Expected Time Complexity:

// Try to solve this in O(n).

// Expected Space Complexity:

// Try to solve this using O(1) extra space.

// Constraints:

// 1 <= n <= 10^4
// 1 <= k <= n

#include <iostream>
using namespace std;

// Node definition
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

// Solution class containing kReverse
class Solution
{
public:
    Node *kReverse(Node *head, int k)
    {
        if (head == nullptr || k == 1)
            return head;

        // Step 0: Check if there are at least k nodes
        Node *temp = head;
        int count = 0;
        while (temp != nullptr && count < k)
        {
            temp = temp->next;
            count++;
        }

        // If less than k nodes, return head without reversing
        if (count < k)
            return head;

        // Step 1: Reverse first k nodes
        Node *curr = head;
        Node *prev = nullptr;
        Node *next = nullptr;
        count = 0;

        while (curr != nullptr && count < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Step 2: Recursive call for the next group
        if (next != nullptr)
            head->next = kReverse(next, k);

        // Step 3: Return new head
        return prev;
    }
};

// Helper function to build a linked list from input
Node *buildList(int n)
{
    int val;
    cin >> val;
    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 1; i < n; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

// Helper function to print the linked list
void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function
int main()
{
    int n, k;
    cin >> n; // number of nodes
    Node *head = buildList(n);
    cin >> k; // size of group to reverse

    Solution sol;
    Node *result = sol.kReverse(head, k);

    printList(result);
    return 0;
}

// ✅ Time Complexity: O(n)
// Reason:

//     Every node is visited exactly once during the recursive traversal and reversal.

//     In each recursive call:

//         The function reverses k nodes → takes O(k) time.

//         There are n / k such groups → total time = O(k × n/k) = O(n)

// ✅ Conclusion:

//     Each node is processed once.

//     The reversal and linking steps are all constant-time per node.

// ✅ Space Complexity: O(n/k) due to recursion stack
// Reason:

//     This is a recursive solution, so each call reverses k nodes.

//     There are n / k recursive calls (worst-case), each with a small call stack frame.

//     Thus, recursive depth = n / k

// So:

//     SC = O(n/k) → worst case O(n) when k = 1

//     Best case = O(log n) when k is large (like n)