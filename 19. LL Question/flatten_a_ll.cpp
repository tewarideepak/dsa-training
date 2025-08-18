//  Problem statement

// You are given a linked list containing 'n' 'head' nodes, where every node in the linked list contains two pointers:

// (1) ‘next’ which points to the next node in the list

// (2) ‘child’ pointer to a linked list where the current node is the head.

// Each of these child linked lists is in sorted order and connected by 'child' pointer.

// Your task is to flatten this linked such that all nodes appear in a single layer or level in a 'sorted order'.

// Example:

// Input: Given linked list is:

// Output:
// 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8 → 9 → 12 → 20 → null.

// Explanation:
// The returned linked list should be in a sorted order. All the elements in this returned linked list are connected by 'child' pointers and 'next' pointers point to null.

// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1 :

// 4
// 3
// 1 2 3
// 3
// 8 10 15
// 2
// 18 22
// 1
// 29

// Sample Output 1 :

// 1 2 3 8 10 15 18 22 29

// Explanation For Sample Input 1:

// The given linked list is

// Therefore after flattening the list will become-
// 1 -> 2 -> 3 -> 8 -> 10 -> 15 -> 18 -> 22 -> 29 ->null

// Sample Input 2 :

// 5
// 2
// 4 6
// 2
// 5 71
// 3
// 7 8 9
// 3
// 11 12 19
// 3
// 14 15 17

// Sample Output 2 :

// 4 5 6 7 8 9 11 12 14 15 17 19 71

// Expected Time Complexity:

// Try solving this in O(n*n*k), where ‘n’ denotes the number of head nodes and ‘k’ is the average number of child nodes in all 'n' sub-lists.

// Expected Space Complexity:

// Try solving this without using any extra space.

// Constraints:

// 1 <= n <= 100
// 1 <= k <= 20
// 1 <= Node.data <= 10^9

// Merges two linked lists in a particular
// order based on the data value

#include <bits/stdc++.h>
using namespace std;

// Definition for linked list node
class Node
{
public:
    int data;
    Node *next;
    Node *child;

    Node(int x) : data(x), next(nullptr), child(nullptr) {}
};

// Function to merge two sorted linked lists (using child pointer)
Node *mergeTwoLists(Node *first, Node *second)
{
    Node dummyNode(-1); // stack-allocated dummy node
    Node *res = &dummyNode;

    while (first != nullptr && second != nullptr)
    {
        if (first->data <= second->data)
        {
            res->child = first;
            res = first;
            first = first->child;
        }
        else
        {
            res->child = second;
            res = second;
            second = second->child;
        }
        res->next = nullptr; // break stale 'next' pointer
    }

    if (first != nullptr)
        res->child = first;
    else if (second != nullptr)
        res->child = second;

    // Ensure no 'next' pointers remain in merged chain
    Node *tail = dummyNode.child;
    while (tail != nullptr)
    {
        tail->next = nullptr;
        tail = tail->child;
    }

    return dummyNode.child;
}

// Function to flatten the linked list
Node *flattenLinkedList(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    // Recursively flatten the rest of the list
    Node *mergedHead = flattenLinkedList(head->next);

    // Merge current list with flattened right part
    head = mergeTwoLists(head, mergedHead);
    return head;
}

// Helper function to print flattened list
void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->child;
    }
    cout << "\n";
}

// Example driver code
int main()
{
    /*
       Example structure:
       5 -> 10 -> 19 -> 28
       |    |     |     |
       7    22    35    40
       |          |     |
       8          50    45
    */

    Node *head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(19);
    head->next->next->next = new Node(28);

    head->child = new Node(7);
    head->child->child = new Node(8);

    head->next->child = new Node(22);

    head->next->next->child = new Node(35);
    head->next->next->child->child = new Node(50);

    head->next->next->next->child = new Node(40);
    head->next->next->next->child->child = new Node(45);

    // Flatten the list
    Node *flatHead = flattenLinkedList(head);

    // Print flattened list
    printList(flatHead);

    return 0;
}

// ✅ Explanation of the Code

// mergeTwoLists:
// Merges two sorted lists connected by child.
// Uses a dummy node to simplify handling of the head.
// Ensures all next pointers are broken.

// flattenLinkedList:

// Base case: if there’s no next, return head.

// Recursive step: flatten the rest of the list (head->next), then merge it with current list using mergeTwoLists.

// Driver Code:
// Constructs the classic sample structure.
// Calls flattenLinkedList and prints the flattened list.

// ✅ Output for Example

// 5 7 8 10 19 22 28 35 40 45 50

// ✅ Time Complexity (TC)

// Each merge operation (mergeTwoLists) takes O(m + n) where m and n are lengths of the two lists being merged.

// flattenLinkedList does recursive merging across k lists (where k is the number of top-level nodes connected via next).

// Total complexity = O(N * k) in worst case (if each merge is big).
// But since every node is visited once during merging, overall complexity is O(N log k) (similar to merging k sorted lists using divide & conquer).

// 👉 Final TC = O(N log k)
// Where N = total number of nodes, k = number of top-level lists.

// ✅ Space Complexity (SC)

// We use only:

// A few pointers,

// Stack frames due to recursion (flattenLinkedList can go k levels deep).

// So extra space = O(k) (recursion depth).

// 👉 Final SC = O(k)