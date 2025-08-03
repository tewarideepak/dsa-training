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

// Step 1: Floyd’s Cycle Detection Algorithm (detect loop and return meeting point)
Node *floydDetectLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            cout << "Meeting Point (inside loop): " << slow->data << endl;
            return slow; // Loop detected
        }
    }

    return nullptr; // No loop
}

// Step 2: Get start of the loop using meeting point
Node *getStartOfLoop(Node *head, Node *meetingPoint)
{
    if (meetingPoint == nullptr)
        return nullptr;

    Node *ptr1 = head;
    Node *ptr2 = meetingPoint;

    while (ptr1 != ptr2)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return ptr1; // Start of loop
}

// ✅ Step 3: Remove the loop by setting last node in loop's next to nullptr
void removeLoop(Node *loopStart)
{
    if (loopStart == nullptr)
        return;

    Node *temp = loopStart;

    // Traverse the loop until we find the node just before the start node
    while (temp->next != loopStart)
    {
        temp = temp->next;
    }

    // Break the loop
    temp->next = nullptr;

    cout << "Loop removed." << endl;
}

// Test case
int main()
{
    // Create nodes
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    Node *fifth = new Node(5);

    // Connect nodes to form a list: 1 -> 2 -> 3 -> 4 -> 5
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Create a loop: 5 -> 3
    fifth->next = third;

    // Step 1: Detect loop
    Node *meetingPoint = floydDetectLoop(head);

    // Step 2: Find start of loop
    Node *loopStart = getStartOfLoop(head, meetingPoint);

    if (loopStart != nullptr)
    {
        cout << "Loop detected." << endl;
        cout << "Start of loop is at node with value: " << loopStart->data << endl;

        // Step 3: Remove loop
        removeLoop(loopStart);
    }
    else
    {
        cout << "No loop detected." << endl;
    }

    // ✅ Print list after loop removal to confirm it's linear
    cout << "Linked list after loop removal: ";
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}

// ✅ Time Complexity

// Let’s assume:

//     k = number of nodes before the loop starts

//     C = number of nodes in the cycle (loop length)

//     N = total number of nodes in the list (N = k + C)

// 1. floydDetectLoop(head)

//     Two pointers (slow and fast) are used.

//     After k steps, both pointers are inside the loop.

//     Within the next C steps, they are guaranteed to meet.

//     So, maximum steps taken = k + C

// 🔹 Time: O(N)

// 2. getStartOfLoop(head, meetingPoint)

//     Starts two pointers: one from head and one from meeting point.

//     They move one step at a time until they meet at the start of the loop.

//     Maximum number of steps = k

// 🔹 Time: O(N)

// 3. removeLoop(head)

// (Loop removal happens by traversing the loop once and setting the last node's next to nullptr)

//     After finding the start node of the loop, we traverse the cycle until the node whose next is the loop starting node.

//     This requires traversing C nodes at most.

// 🔹 Time: O(C) ⟶ O(N)` in worst case
// ✅ Overall Time Complexity: O(N)

//     Even though there are three steps (detect, find start, remove), each takes linear time, and they are not nested.

//     So total remains linear.

// ✅ Space Complexity

//     Only a constant number of pointers are used:

//         slow, fast for detection

//         ptr1, ptr2 for loop start detection

//         Temporary pointer for loop removal

// 🔹 Space: O(1)