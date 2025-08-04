//  Problem statement

// You are given a circular linked list having N number of nodes, where N is even. You have to split this linked list into two equal-sized circular linked lists.

// Here splitting means you have to make two separate circular linked lists, one for the first N/2 nodes and one for the last N/2 nodes.

// For Example :

// Let the circular linked list be 1, 2, 3, 4. We have to split this into two equal-sized circular linked lists.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :

// 1 <= T <= 10
// 2 <= N <= 10000, N is even
// -10 ^ 9 <= node data <= 10 ^ 9

// Where  ‘node data’ is the value of nodes of the list.

// Time limit: 1 sec

// Sample Input 1 :

// 2
// 4
// 1 2 3 4
// 2
// 1 2

// Sample Output 1 :

// 1 2
// 3 4
// 1
// 2

// Explanation for sample input 1 :

// Test Case 1: Refer to the example described above.

// Test Case 2:
//     The given circular linked list will be splitted as follows:

//     Here 1 and 2 will point to themselves as they are the only nodes in the circular linked list.

// Sample Input 2 :

// 2
// 6
// 2 4 3 5 2 1
// 4
// 1 1 1 1

// Sample Output 2 :

// 2 4 3
// 5 2 1
// 1 1
// 1 1

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

// Function to split a circular linked list into two halves
void split(Node *head, Node *&head1, Node *&head2)
{
    if (!head || head->next == head)
    {
        head1 = head;
        head2 = nullptr;
        return;
    }

    Node *slow = head;
    Node *fast = head;

    // Move slow by 1 and fast by 2 to find mid
    while (fast->next != head && fast->next->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // For even number of nodes, move fast one more step
    if (fast->next->next == head)
        fast = fast->next;

    // Set the heads of the two halves
    head1 = head;
    head2 = slow->next;

    // Break the list into two halves
    slow->next = head1;
    fast->next = head2;
}

// Function to print circular linked list
void printList(Node *head)
{
    if (!head)
        return;

    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Sample driver code
int main()
{
    Node *head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->next = new Node(-1);
    head->next->next->next->next->next->next = head;

    // 3. Print list
    printList(head);

    Node *head1 = nullptr;
    Node *head2 = nullptr;

    split(head, head1, head2);

    printList(head1);
    printList(head2);

    return 0;
}