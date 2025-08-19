// You are given a special linked list with n nodes where each node has two pointers a next pointer that points to the next node of the singly linked list, and a random pointer that points to the random node of the linked list.

// Construct a copy of this linked list. The copy should consist of the same number of new nodes, where each new node has the value corresponding to its original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list, such that it also represent the same list state. None of the pointers in the new list should point to nodes in the original list.

// Return the head of the copied linked list.

// NOTE : Original linked list should remain unchanged.

// Examples:

// Input: head = [[1, 3], [3, 3], [5, NULL], [9, 3]]

// Output: head = [[1, 3], [3, 3], [5, NULL], [9, 3]]
// Explanation:
// Node 1 points to Node 2 as its NEXT and Node 3 as its RANDOM.
// Node 2 points to Node 3 as its NEXT and Node 3 as its RANDOM.
// Node 3 points to Node 4 as its NEXT and NULL as its RANDOM.
// Node 4 points to NULL as its NEXT and Node 3 as its RANDOM.

// Input: head = [[1, 3], [2, 1], [3, 5], [4, 3], [5, 2]]

// Output: head = [[1, 3], [2, 1], [3, 5], [4, 3], [5, 2]]
// Explanation:
// Node 1 points to Node 2 as its NEXT and Node 3 as its RANDOM.
// Node 2 points to Node 3 as its NEXT and Node 1 as its RANDOM.
// Node 3 points to Node 4 as its NEXT and Node 5 as its RANDOM.
// Node 4 points to Node 5 as its NEXT and Node 3 as its RANDOM.
// Node 5 points to NULL as its NEXT and Node 2 as its RANDOM.

// Input: head = [[7, NULL], [7, NULL]]
// Output: head = [[7, NULL], [7, NULL]]
// Explanation:
// Node 1 points to Node 2 as its NEXT and NULL as its RANDOM.
// Node 2 points to NULL as its NEXT and NULL as its RANDOM.

// Constraints:
// 1 ≤ n ≤ 100
// 0 ≤ node->data ≤ 1000

#include <bits/stdc++.h>
using namespace std;

// Definition for Node
class Node
{
public:
    int data;
    Node *next;
    Node *random;

    Node(int x)
    {
        data = x;
        next = NULL;
        random = NULL;
    }
};

// Solution class using HashMap approach
class Solution
{
public:
    Node *cloneLinkedList(Node *head)
    {
        if (!head)
            return NULL;

        // Step 1: Create mapping from original to copy
        unordered_map<Node *, Node *> mp;
        Node *curr = head;
        while (curr)
        {
            mp[curr] = new Node(curr->data);
            curr = curr->next;
        }

        // Step 2: Assign next and random using map
        curr = head;
        while (curr)
        {
            mp[curr]->next = mp[curr->next];
            mp[curr]->random = mp[curr->random];
            curr = curr->next;
        }

        return mp[head];
    }
};

// Helper function to print list along with random pointers
void printList(Node *head)
{
    Node *curr = head;
    while (curr)
    {
        cout << "Node data: " << curr->data << ", Random data: ";
        if (curr->random)
            cout << curr->random->data;
        else
            cout << "NULL";
        cout << endl;
        curr = curr->next;
    }
}

int main()
{
    // Creating list: 1 -> 2 -> 3
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    // Setting random pointers
    head->random = head->next->next; // 1 -> 3
    head->next->random = head;       // 2 -> 1
    head->next->next->random = NULL; // 3 -> NULL

    cout << "Original list:" << endl;
    printList(head);

    Solution sol;
    Node *clonedHead = sol.cloneLinkedList(head);

    cout << "\nCloned list:" << endl;
    printList(clonedHead);

    return 0;
}

// ⏱️ Time: O(n)
// 💾 Space: O(n) (hash map)

// Optimal Weaving Approach (O(1) extra space)

// We divide the algorithm into three steps.

// Step 1: Insert cloned nodes next to original nodes
// Idea:

// For every node curr in the original list, we create a copy node copy and insert it right after curr.

// This “weaves” the original and cloned nodes together.

// Code:

// Node* curr = head;
// while (curr) {
//     Node* copy = new Node(curr->data);
//     copy->next = curr->next;
//     curr->next = copy;
//     curr = copy->next;
// }

// Example:

// Original list:

// 1 -> 2 -> 3 -> NULL

// After Step 1 (weaving):

// 1 -> 1' -> 2 -> 2' -> 3 -> 3' -> NULL

// 1', 2', 3' are new cloned nodes.

// next pointers temporarily connect original → clone → original → clone.

// Original random pointers are unchanged.

// Why this helps:
// Now, the copy of any node curr is always curr->next, so we don’t need a map.

// Step 2: Set random pointers for cloned nodes
// Idea:

// For each original node curr, if it has curr->random:

// The clone’s random pointer should point to the clone of curr->random.

// Since every clone is right after its original, the clone of curr->random is curr->random->next.

// Code:

// curr = head;
// while (curr) {
//     if (curr->random)
//         curr->next->random = curr->random->next;
//     curr = curr->next->next; // move to next original node

// Visual Example:

// Original list (random pointers shown by arrows ↷):

// 1 -> 2 -> 3
// 1.random -> 3
// 2.random -> 1
// 3.random -> NULL

// Step 1 (weaved list):

// 1 -> 1' -> 2 -> 2' -> 3 -> 3'

// Step 2 sets random pointers of cloned nodes:

// 1'.random -> 3'   (1.random->next)
// 2'.random -> 1'   (2.random->next)
// 3'.random -> NULL

// Key insight:

// Each original node’s clone is always next to it.

// So curr->next->random = curr->random->next automatically points clone → clone.

// Step 3: Separate original and cloned lists
// Idea:

// Now we have a weaved list:

// 1 -> 1' -> 2 -> 2' -> 3 -> 3'

// We need to restore the original list and extract the cloned list.

// Code:

// curr = head;
// Node* dummy = new Node(0);  // placeholder for cloned list
// Node* copyCurr = dummy;

// while (curr) {
//     Node* copy = curr->next;
//     curr->next = copy->next;        // restore original list
//     copyCurr->next = copy;          // add to cloned list
//     copyCurr = copy;
//     curr = curr->next;
// }

// Step-by-Step:

// copy = curr->next → the cloned node.

// curr->next = copy->next → skip cloned node to restore original list.

// copyCurr->next = copy → append clone to new list.

// Move both pointers forward:

// curr = curr->next → next original

// copyCurr = copyCurr->next → next clone

// Result:

// Original list restored:

// 1 -> 2 -> 3

// Cloned list:

// 1' -> 2' -> 3'

// next and random of cloned nodes are fully correct.

// Why this is optimal

// | Aspect        | Complexity                                                                                         |
// | ------------- | -------------------------------------------------------------------------------------------------- |
// | **Time**      | O(n) → 3 traversals of the list                                                                    |
// | **Space**     | O(1) → No extra hashmap used                                                                       |
// | **Intuition** | We “weave” cloned nodes in place so we can access the clone of any node in O(1) using `node->next` |

#include <bits/stdc++.h>
using namespace std;

// Definition for Node
class Node
{
public:
    int data;
    Node *next;
    Node *random;

    Node(int x)
    {
        data = x;
        next = NULL;
        random = NULL;
    }
};

// Solution class using optimal weaving approach
class Solution
{
public:
    Node *cloneLinkedList(Node *head)
    {
        if (!head)
            return NULL;

        Node *curr = head;

        // Step 1: Insert cloned nodes after each original node
        while (curr)
        {
            Node *copy = new Node(curr->data);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        // Step 2: Assign random pointers for cloned nodes
        curr = head;
        while (curr)
        {
            if (curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        // Step 3: Separate original list and cloned list
        curr = head;
        Node *dummy = new Node(0);
        Node *copyCurr = dummy;

        while (curr)
        {
            Node *copy = curr->next;
            curr->next = copy->next; // restore original list
            copyCurr->next = copy;   // build cloned list
            copyCurr = copy;
            curr = curr->next;
        }

        return dummy->next;
    }
};

// Helper function to print list along with random pointers
void printList(Node *head)
{
    Node *curr = head;
    while (curr)
    {
        cout << "Node data: " << curr->data << ", Random data: ";
        if (curr->random)
            cout << curr->random->data;
        else
            cout << "NULL";
        cout << endl;
        curr = curr->next;
    }
}

int main()
{
    // Creating list: 1 -> 2 -> 3
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    // Setting random pointers
    head->random = head->next->next; // 1 -> 3
    head->next->random = head;       // 2 -> 1
    head->next->next->random = NULL; // 3 -> NULL

    cout << "Original list:" << endl;
    printList(head);

    Solution sol;
    Node *clonedHead = sol.cloneLinkedList(head);

    cout << "\nCloned list:" << endl;
    printList(clonedHead);

    return 0;
}
