//  Problem statement

// Given a singly linked list of integers. Your task is to return the head of the reversed linked list.
// For example:

// The given linked list is 1 -> 2 -> 3 -> 4-> NULL. Then the reverse linked list is 4 -> 3 -> 2 -> 1 -> NULL and the head of the reversed linked list will be 4.

// Follow Up :

// Can you solve this problem in O(N) time and O(1) space complexity?

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :

// 1 <= T <= 5
// 0 <= L <= 10^5
// 1 <= data <= 10^9 and data != -1

// Time Limit: 1 sec

// Sample Input 1 :

// 1
// 1 2 3 4 5 6 -1

// Sample Output 1 :

// 6 5 4 3 2 1 -1

// Explanation For Sample Input 1 :

// For the first test case,  After changing the next pointer of each node to the previous node, The given linked list is reversed.

// Sample Input 2 :

// 1
// 10 21 3 2 4 -1

// Sample Output 2 :

// 4 2 3 21 10 -1

#include <iostream>
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

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    // Add node at the end
    void append(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    // Print the list
    void print()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Iterative reversal
    void reverseIterative()
    {
        Node *prev = nullptr;
        Node *curr = head;
        Node *next = nullptr;

        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }

    // Recursive reversal
    Node *reverseRecursiveUtil(Node *node)
    {
        if (!node || !node->next)
            return node;

        Node *newHead = reverseRecursiveUtil(node->next);
        node->next->next = node;
        node->next = nullptr;
        return newHead;
    }

    void reverseRecursive()
    {
        head = reverseRecursiveUtil(head);
    }
};

int main()
{
    LinkedList list;

    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);

    cout << "Original list: ";
    list.print();

    list.reverseIterative();
    cout << "Reversed list (iterative): ";
    list.print();

    list.reverseRecursive();
    cout << "Reversed list again (recursive): ";
    list.print();

    return 0;
}
