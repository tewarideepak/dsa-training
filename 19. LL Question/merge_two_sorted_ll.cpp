//  Problem statement

// You are given two sorted linked lists. You have to merge them to produce a combined sorted linked list. You need to return the head of the final linked list.

// Note:

// The given linked lists may or may not be null.

// For example:

// If the first list is: 1 -> 4 -> 5 -> NULL and the second list is: 2 -> 3 -> 5 -> NULL

// The final list would be: 1 -> 2 -> 3 -> 4 -> 5 -> 5 -> NULL

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:

// 1 <= L <= 10^5
// 1 ≤ data ≤ 10^6 and data != -1

// Where L is the number of nodes in either of the two Linked List.

// Time Limit: 1 sec

// Follow-up:

// Try to solve this problem in linear time complexity and constant space complexity.

// Sample Input 1:

// 7 8 -1
// 1 3 4 6 -1

// Sample Output 1:

// 1 3 4 6 7 8 -1

// Explanation of Input 1:

// In this testcase, the first list is: 7 -> 8 -> NULL
// The second list is: 1 -> 3 -> 4 -> 6 -> NULL
// The final list would be: 1 -> 3 -> 4 -> 6 -> 7 -> 8 -> NULL

// Sample Input 2:

// 5 -1
// 1 3 6 10 -1

// Sample Output 2

// 1 3 5 6 10 -1

#include <bits/stdc++.h>
using namespace std;

// Node structure
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

// Function to merge two sorted linked lists
Node *sortTwoLists(Node *first, Node *second)
{
    if (!first)
        return second; // If first list is empty
    if (!second)
        return first; // If second list is empty

    Node *head = nullptr;
    Node *tail = nullptr;

    // Choose the first node
    if (first->data <= second->data)
    {
        head = tail = first;
        first = first->next;
    }
    else
    {
        head = tail = second;
        second = second->next;
    }

    // Merge the lists
    while (first && second)
    {
        if (first->data <= second->data)
        {
            tail->next = first;
            first = first->next;
        }
        else
        {
            tail->next = second;
            second = second->next;
        }
        tail = tail->next;
    }

    // Attach the remaining nodes
    if (first)
        tail->next = first;
    if (second)
        tail->next = second;

    return head;
}

// Helper function to create a linked list from vector
Node *createLinkedList(const vector<int> &arr)
{
    if (arr.empty())
        return NULL;
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}

// Helper function to print linked list
void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "-1\n"; // End marker
}

// Example usage
int main()
{
    vector<int> list1 = {1, 4, 5};
    vector<int> list2 = {2, 3, 5};

    Node *first = createLinkedList(list1);
    Node *second = createLinkedList(list2);

    cout << "First List: ";
    printList(first);

    cout << "Second List: ";
    printList(second);

    Node *merged = sortTwoLists(first, second);

    cout << "Merged List: ";
    printList(merged);

    // Cleanup
    delete merged;

    return 0;
}

// This runs in O(N + M) time and O(1) space, modifying only pointers and not creating extra nodes.