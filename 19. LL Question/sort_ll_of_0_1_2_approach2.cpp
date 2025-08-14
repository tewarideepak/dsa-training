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
    if (!head || !head->next)
        return head;

    // Dummy heads and tails for 0, 1, 2 lists
    Node zeroDummy(-1), oneDummy(-1), twoDummy(-1);
    Node *zeroTail = &zeroDummy;
    Node *oneTail = &oneDummy;
    Node *twoTail = &twoDummy;

    // Distribute nodes into three lists
    Node *curr = head;
    while (curr)
    {
        if (curr->data == 0)
        {
            zeroTail->next = curr;
            zeroTail = zeroTail->next;
        }
        else if (curr->data == 1)
        {
            oneTail->next = curr;
            oneTail = oneTail->next;
        }
        else
        {
            twoTail->next = curr;
            twoTail = twoTail->next;
        }
        curr = curr->next;
    }

    // Merge the three lists
    zeroTail->next = (oneDummy.next) ? oneDummy.next : twoDummy.next;
    oneTail->next = twoDummy.next;
    twoTail->next = nullptr;

    // New head
    return (zeroDummy.next) ? zeroDummy.next : (oneDummy.next ? oneDummy.next : twoDummy.next);
}

// Helper function to create linked list from vector
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

// ✅ Time Complexity: O(N)
// ✅ Space Complexity: O(1) extra (only dummy nodes, no new list elements)
// ✅ No data replacement — only rearranges existing nodes.