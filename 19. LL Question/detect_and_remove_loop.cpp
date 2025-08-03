//  Problem statement

// Given a singly linked list, you have to detect the loop and remove the loop from the linked list, if present. You have to make changes in the given linked list itself and return the updated linked list.

// Expected Complexity: Try doing it in O(n) time complexity and O(1) space complexity. Here, n is the number of nodes in the linked list.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:

// 1 <= N <= 100000.
// 1 <= ‘VAL’ <= 1000 .

// Time limit: 1 sec

// Sample Input:

// 6 2
// 1 2 3 4 5 6

// Sample Output:

// 1 2 3 4 5 6

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
        this->next = NULL;
    }
};

// Floyd’s Cycle Detection Algorithm
Node *floydDetectLoop(Node *head)
{
    if (head == nullptr)
        return nullptr;

    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return slow;
    }

    return nullptr;
}

// Get the starting node of the loop
Node *getStartOfLoop(Node *head, Node *meetingPoint)
{
    if (meetingPoint == nullptr)
        return nullptr;

    Node *p1 = head;
    Node *p2 = meetingPoint;

    while (p1 != p2)
    {
        p1 = p1->next;
        p2 = p2->next;
    }

    return p1;
}

// Remove the loop
Node *removeLoop(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *meetingPoint = floydDetectLoop(head);

    if (meetingPoint == nullptr)
        return head;

    Node *loopStart = getStartOfLoop(head, meetingPoint);

    Node *temp = loopStart;
    while (temp->next != loopStart)
    {
        temp = temp->next;
    }

    temp->next = nullptr;

    return head;
}

// Print the linked list (for testing)
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
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Creating a loop: 5 -> 3
    head->next->next->next->next->next = head->next->next;

    // Remove the loop
    head = removeLoop(head);

    // Print the linked list
    printList(head);

    return 0;
}
