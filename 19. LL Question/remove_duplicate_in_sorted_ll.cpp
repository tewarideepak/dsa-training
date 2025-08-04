#include <iostream>
#include <unordered_set>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// ✅ Remove duplicates from sorted linked list
Node *removeDuplicatesSorted(Node *head)
{
    Node *current = head;
    while (current && current->next)
    {
        if (current->data == current->next->data)
        {
            Node *dup = current->next;
            current->next = dup->next;
            delete dup;
        }
        else
        {
            current = current->next;
        }
    }
    return head;
}

// ✅ Remove duplicates from unsorted linked list
Node *removeDuplicatesUnsorted(Node *head)
{
    if (!head)
        return nullptr;

    unordered_set<int> seen;
    Node *current = head;
    Node *prev = nullptr;

    while (current)
    {
        if (seen.count(current->data))
        {
            prev->next = current->next;
            delete current;
            current = prev->next;
        }
        else
        {
            seen.insert(current->data);
            prev = current;
            current = current->next;
        }
    }

    return head;
}

// Print the linked list
void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Sample driver code
int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(4);

    // 2. Remove duplicates — use appropriate one
    head = removeDuplicatesSorted(head); // If sorted
    // head = removeDuplicatesUnsorted(head); // If unsorted

    // 3. Print list
    printList(head);

    return 0;
}

// ➤ Time Complexity: O(n)

//     Each node is visited once.

//     Comparison and pointer adjustments are O(1) per node.

//     So for n nodes, total time = O(n).

// ➤ Space Complexity: O(1)

//     No extra space used (modifies the list in-place).

//     Just a few pointers like current, dup.