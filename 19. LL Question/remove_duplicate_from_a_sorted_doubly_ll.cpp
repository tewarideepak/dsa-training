//  Problem statement

// A doubly-linked list is a data structure that consists of sequentially linked nodes, and the nodes have reference to both the previous and the next nodes in the sequence of nodes.

// You are given a sorted doubly linked list of size 'n'.

// Remove all the duplicate nodes present in the linked list.

// Example :

// Input: Linked List: 1 <-> 2 <-> 2 <-> 2 <-> 3

// Output: Modified Linked List: 1 <-> 2 <-> 3

// Explanation: We will delete the duplicate values ‘2’ present in the linked list.

// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1 :

// 5
// 1 2 2 2 3

// Sample Output 1 :

// 1 2 3

// Explanation For Sample Input 1 :

// We will delete the duplicate values ‘2’ present in the linked list.

// Sample Input 2 :

// 4
// 1 2 3 4

// Sample Output 2 :

// 1 2 3 4

// Explanation For Sample Input 2 :

// The list contains no duplicates, so the final list is unchanged.

// Expected time complexity :

// The expected time complexity is O('n').

// Constraints :

// 1 <= 'n' <= 10^5
// 1 <= 'data' in any node <= 10^6

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

// ✅ Remove duplicates from a **sorted doubly linked list**
Node *removeDuplicates(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *curr = head;

    while (curr != nullptr && curr->next != nullptr)
    {
        if (curr->data == curr->next->data)
        {
            Node *dup = curr->next;
            curr->next = dup->next;

            if (dup->next != nullptr)
            {
                dup->next->prev = curr;
            }

            delete dup;
        }
        else
        {
            curr = curr->next;
        }
    }

    return head;
}

// ✅ Print the doubly linked list
void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// ✅ Sample driver code
int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(2);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(3);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->prev = head->next->next->next;

    // Remove duplicates
    head = removeDuplicates(head);

    // Print list
    printList(head);

    return 0;
}

// ➤ Time Complexity: O(n)

//     Each node is visited once.

//     Comparisons and pointer adjustments take constant time O(1).

//     So, total time for n nodes = O(n).

// ➤ Space Complexity: O(1)

//     No extra space is used.

//     Only a few pointers like curr and dup.