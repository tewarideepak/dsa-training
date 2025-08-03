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
    }
    else
    {
        cout << "No loop detected." << endl;
    }

    return 0;
}

// ✅ Time Complexity
// Step 1: floydDetectLoop(head) → Detect Loop

//     Uses two pointers: slow and fast

//     In a list with:

//         k nodes before the loop

//         C nodes in the cycle (loop length)

//     Worst case: the slow and fast pointers meet in at most k + C steps

//         Because after k steps, both are inside the loop

//         Within the next C steps, they'll definitely meet

// 🔸 Time: O(N) — where N is the total number of nodes (including in loop)

// Step 2: getStartOfLoop(head, meetingPoint) → Find Loop Start

//     Once the meeting point is found, we use two pointers:

//         One starting from head

//         One from the meeting point

//     Both move 1 step at a time until they meet at the start of the loop

//     Distance walked is at most k (non-loop portion)

// 🔸 Time: O(N) — worst case if the loop is near the end
// ✅ Overall Time Complexity: O(N)

// Even though we traverse the list in multiple phases, it is still linear time overall, as no phase exceeds O(N).

// ✅ Space Complexity

//     We use only a constant number of pointers (slow, fast, ptr1, ptr2)

//     No extra data structures (arrays, hash tables, recursion stacks, etc.)

// 🔸 Space: O(1) — constant space