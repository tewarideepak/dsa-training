//  Problem statement

// You are given the head of a linked list containing integers, You need to find out whether the given linked list is circular or not.

// Note :

// 1. A linked list is said to be circular if it has no node having its next pointer equal to NULL and all the nodes form a circle i.e. the next pointer of last node points to the first node.
// 2. An empty linked will also be considered as circular.
// 3. All the integers in the linked list are unique.
// 4. In the input, the next pointer of a node with i’th integer is linked to the node with data (i+1)’th integer (If (i+1)’th node exists). If there is no such (i+1)’th integer then the next pointer of such node is set to NULL.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :

// 1 <= T <= 10 ^ 2
// 1 <= D <= 10 ^ 6, here D is data stored in the node.
// 0 <= N <= 10 ^ 4

// Time Limit: 1 sec

// Sample Input 1 :

// 1
// 5
// 1 2 3 4 1

// Sample Output 1 :

// True

// Explanation of sample input 1 :

// Given Linked list look like following:

// As given linked list form a circle, hence it is a Circular linked list.

// Sample Input 2 :

// 1
// 7
// 1 2 3 4 5 6 7

// Sample Output 2 :

// False

// Explanation of sample input 2 :

// Given Linked list look like following:

// In the given linked list there is a node at which this linked list terminates, hence it is not a circular linked list.

#include <iostream>
#include <unordered_set>
using namespace std;

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

class Solution
{
public:
    bool isCircular(Node *head)
    {
        if (head == nullptr)
            return true;

        Node *temp = head->next;
        while (temp != nullptr && temp != head)
        {
            temp = temp->next;
        }

        return (temp == head);
    }
};

int main()
{
    // Sample Input 1: 1 2 3 4 1 (circular)
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = head; // Creates a cycle

    Solution obj;
    cout << (obj.isCircular(head) ? "True" : "False") << endl; // Output: True

    // Sample Input 2: 1 2 3 4 5 6 7 (non-circular)
    Node *h = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);
    Node *n7 = new Node(7);

    h->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = nullptr; // Ends normally

    cout << (obj.isCircular(h) ? "True" : "False") << endl; // Output: False

    return 0;
}
