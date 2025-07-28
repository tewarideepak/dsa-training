//  Problem statement

// Given a singly linked list of 'N' nodes. The objective is to determine the middle node of a singly linked list. However, if the list has an even number of nodes, we return the second middle node.
// Note:

// 1. If the list is empty, the function immediately returns None because there is no middle node to find.
// 2. If the list has only one node, then the only node in the list is trivially the middle node, and the function returns that node.

// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1 :

// 5
// 1 2 3 4 5

// Sample Output 1 :

// 3 4 5

// Explanation Of Sample Input 1 :

// We can clearly see that there are 5 elements in the linked list therefore the middle node is the node with value '3'.

// Sample Input 2 :

// 6
// 1 2 3 4 5 6

// Sample Output 2 :

// 4 5 6

// Explanation Of Sample Input 2 :

// We can clearly see that there are 6 elements in the linked list and the middle nodes are  nodes with values 3 and 4 hence we return a second middle node having value '4'.

// Constraints :

// 1 <= 'N' <= 10^4
// 0 <= 'data' <= 10^3

// Where 'N' is the length of the linked list.

#include <iostream>
using namespace std;

// Node class definition
class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = nullptr;
    }

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }

    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

// Append a new node at the end of the list
void append(Node *&head, int value)
{
    Node *newNode = new Node(value);
    if (!head)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to find the middle node (second middle if even)
Node *findMiddle(Node *head)
{
    if (!head || !head->next)
    {
        return head;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Print the linked list from a given node
void printFromNode(Node *node)
{
    while (node != nullptr)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Main function
int main()
{
    int n;
    cin >> n;

    Node *head = nullptr;
    for (int i = 0; i < n; ++i)
    {
        int value;
        cin >> value;
        append(head, value);
    }

    Node *middle = findMiddle(head);
    printFromNode(middle);

    return 0;
}
