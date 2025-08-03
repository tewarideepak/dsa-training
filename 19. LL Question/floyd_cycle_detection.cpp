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

// Floyd's Cycle Detection Algorithm
bool floydDetectLoop(Node *head)
{
    if (head == nullptr)
        return false;

    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            cout << "Present at: " << slow->data << endl;
            return true; // Loop detected
        }
    }

    return false; // No loop
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

    // Connect nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Create a loop (5 -> 3)
    fifth->next = third;

    // Check for loop
    if (floydDetectLoop(head))
        cout << "Loop detected." << endl;
    else
        cout << "No loop detected." << endl;

    return 0;
}

// ✅ 1. Time Complexity: O(N)
// 🔍 Why?

//     The algorithm consists of two phases:

//         Detection Phase (Tortoise and Hare movement)

//             slow moves 1 step, fast moves 2 steps.

//             They will meet at most in O(N) steps.

//             Specifically, if the loop starts at node k, and the loop has C nodes:

//                 They meet in O(k + C) steps, which is O(N) in worst case.

//         Loop Start Finding Phase (if needed)

//             Once they meet, you move one pointer to the head and move both 1 step at a time until they meet again at the start of the loop.

//             This takes at most O(N) steps.

//     So total work is at most O(N), where N is the total number of nodes (including inside and outside the loop).

// ✅ 2. Space Complexity: O(1)
// 🔍 Why?

//     The algorithm uses only two pointers: slow and fast.

//     It does not use any extra memory structures like hash tables, arrays, or recursion stacks.