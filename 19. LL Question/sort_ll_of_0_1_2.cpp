//  Problem statement

// Given a linked list of 'N' nodes, where each node has an integer value that can be 0, 1, or 2. You need to sort the linked list in non-decreasing order and the return the head of the sorted list.

// Example:

// Given linked list is 1 -> 0 -> 2 -> 1 -> 2.
// The sorted list for the given linked list will be 0 -> 1 -> 1 -> 2 -> 2.

// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:

// 7
// 1 0 2 1 0 2 1

// Sample Output 1:

// 0 0 1 1 1 2 2

// Explanation Of Sample Input 1:

// Input: 1 -> 0 -> 2 -> 1 -> 0 -> 2 -> 1

// Output: 0 -> 0 -> 1 -> 1 -> 1 -> 2 -> 2

// Explanation:
// In this example, the original linked list contains two 0s, three 1s, and two 2s. The sorted linked list has all the 0s at the beginning, followed by all the 1s, and finally, all the 2s at the end.

// Sample Input 2:

// 8
// 2 1 0 2 1 0 0 2

// Sample Output 2:

// 0 0 0 1 1 2 2 2

// Follow Up:

// Can you solve this without updating the Nodes of the given linked list?

// Constraints :

// 1 <= N <= 10^3
// 0 <= data <= 2

// Where 'N' is the length of the linked list.

#include <bits/stdc++.h>
using namespace std;

// Node class
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

Node *sortList(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    int count0 = 0, count1 = 0, count2 = 0;

    Node *curr = head;

    while (curr != nullptr)
    {
        if (curr->data == 0)
            count0++;
        else if (curr->data == 1)
            count1++;
        else
            count2++;

        curr = curr->next;
    }

    curr = head;

    while (count0--)
    {
        curr->data = 0;
        curr = curr->next;
    }

    while (count1--)
    {
        curr->data = 1;
        curr = curr->next;
    }

    while (count2--)
    {
        curr->data = 2;
        curr = curr->next;
    }

    return head;
}

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

void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Example usage
int main()
{
    vector<int> arr = {1, 0, 2, 1, 0, 2, 1};

    Node *head = createLinkedList(arr);

    cout << "Original list: ";
    printList(head);

    head = sortList(head);

    cout << "Sorted list:   ";
    printList(head);

    return 0;
}

// Complexity

// Time: O(N) → one pass for counting, one pass for refilling.

// Space: O(1) → only 3 integer counters.