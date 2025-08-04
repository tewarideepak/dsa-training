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

// ✅ Remove duplicates from unsorted linked list
Node *removeDuplicatesUnsorted(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    unordered_set<int> seen;
    Node *current = head;
    Node *prev = nullptr;

    while (current != nullptr)
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
    Node *head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->next = new Node(-1);

    head = removeDuplicatesUnsorted(head); // If unsorted

    // 3. Print list
    printList(head);

    return 0;
}

// 🔷 Time Complexity: O(N)

//     Each node is visited once → O(N)

//     unordered_set insert and lookup are O(1) on average

//     So total time: O(N) per test case

// 🔷 Space Complexity: O(N)

//     unordered_set stores up to N unique elements

//     So additional space = O(N)

//     Where N is the number of nodes in the linked list.