#include <iostream>
#include <map>
using namespace std;

// Definition of a Node in the linked list
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

// Function to detect a loop in a linked list using a map
bool detectLoop(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return false;

    map<Node *, bool> visited;
    Node *current = head;

    while (current != nullptr)
    {
        if (visited[current])
            return true; // Loop detected
        visited[current] = true;
        current = current->next;
    }

    return false; // No loop detected
}

// Utility function to print the list (used only when no loop exists)
void printList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Test case: list with no loop
void testWithoutLoop()
{
    cout << "Test Case 1: Linked List without loop" << endl;

    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);

    head->next = second;
    second->next = third;
    third->next = fourth;

    if (detectLoop(head))
    {
        cout << "Loop detected." << endl;
    }
    else
    {
        cout << "No loop detected." << endl;
        printList(head);
    }

    // Cleanup
    delete head;
    delete second;
    delete third;
    delete fourth;
}

// Test case: list with a loop
void testWithLoop()
{
    cout << "\nTest Case 2: Linked List with a loop" << endl;

    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second; // Creates loop: 4 -> 2

    if (detectLoop(head))
    {
        cout << "Loop detected." << endl;
    }
    else
    {
        cout << "No loop detected." << endl;
    }

    // No cleanup here because of loop (to avoid infinite loop during deletion)
}

int main()
{
    testWithoutLoop();
    testWithLoop();

    return 0;
}

// 🔹 Time Complexity: O(N)

//     Each node in the linked list is visited once.

//     For N nodes:

//         Checking visited[current] is O(log N) (since std::map is implemented as a Red-Black Tree).

//         In total: N * log N.

// 🔸 So, strictly speaking,

//     Time Complexity = O(N log N) when using std::map.

// ✅ But if we use unordered_map<Node*, bool> instead (based on hash table), then:

//     Time Complexity = O(N) average case.

// 🔹 Space Complexity: O(N)

//     A map stores a boolean value for each visited node, i.e., N entries in the worst case (no loop).

//     Hence, auxiliary space grows linearly with the number of nodes.