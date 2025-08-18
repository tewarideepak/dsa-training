//  Problem statement

// For a given Singly Linked List of integers, sort the list using the 'Merge Sort' algorithm.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :

// 1 <= N <= 10^5
// 1 <= DATA <= 10^9

// Where 'DATA' denotes the value of node of Linked List.

// Time Limit: 1sec

// Sample Input 1 :

// 1 4 5 2 -1

// Sample Output 1 :

// 1 2 4 5

// Sample Input 2 :

// 10 9 8 7 6 5 4 -1

// Sample Output 2 :

// 4 5 6 7 8 9 10

#include <iostream>
using namespace std;

/********************************************************************
    Singly Linked List Node definition
********************************************************************/
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

/********************************************************************
    Merge two sorted linked lists
********************************************************************/
node *mergeTwoLists(node *head1, node *head2)
{
    if (!head1)
        return head2;
    if (!head2)
        return head1;

    node *mergedHead = nullptr;
    node *mergedTail = nullptr;

    // Initialize mergedHead with smaller head
    if (head1->data <= head2->data)
    {
        mergedHead = mergedTail = head1;
        head1 = head1->next;
    }
    else
    {
        mergedHead = mergedTail = head2;
        head2 = head2->next;
    }

    // Merge remaining nodes
    while (head1 && head2)
    {
        if (head1->data <= head2->data)
        {
            mergedTail->next = head1;
            mergedTail = head1;
            head1 = head1->next;
        }
        else
        {
            mergedTail->next = head2;
            mergedTail = head2;
            head2 = head2->next;
        }
    }

    // Attach leftover nodes
    if (head1)
        mergedTail->next = head1;
    else
        mergedTail->next = head2;

    return mergedHead;
}

/********************************************************************
    Find middle of linked list (slow/fast pointer method)
********************************************************************/
node *getMiddle(node *head)
{
    if (!head || !head->next)
        return head;

    node *slow = head;
    node *fast = head->next;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow; // slow = middle node
}

/********************************************************************
    Merge Sort main function
********************************************************************/
node *mergeSort(node *head)
{
    if (!head || !head->next)
        return head; // base case

    // Split into two halves
    node *mid = getMiddle(head);
    node *half2 = mid->next;
    mid->next = nullptr; // break the list

    // Recursive sort
    node *left = mergeSort(head);
    node *right = mergeSort(half2);

    // Merge sorted halves
    return mergeTwoLists(left, right);
}

int main()
{
    // Example: 10 -> 9 -> 8 -> 7 -> 6 -> 5 -> 4
    node *head = new node(10);
    head->next = new node(9);
    head->next->next = new node(8);
    head->next->next->next = new node(7);
    head->next->next->next->next = new node(6);
    head->next->next->next->next->next = new node(5);
    head->next->next->next->next->next->next = new node(4);

    head = mergeSort(head);

    // Print sorted list
    node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}

// Uses O(N log N) time, O(1) extra space (excluding recursion stack).

// Does not replace data (only pointer rearrangement).