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
