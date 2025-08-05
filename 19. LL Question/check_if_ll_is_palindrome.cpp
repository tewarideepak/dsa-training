//  Problem statement

// You are given a Singly Linked List of integers. You have to return true if the linked list is palindrome, else return false.

// A Linked List is a palindrome if it reads the same from left to right and from right to left.

// Example:

// The lists (1 -> 2 -> 1), (3 -> 4 -> 4-> 3), and (1) are palindromes, while the lists (1 -> 2 -> 3) and (3 -> 4) are not.

// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:

// 1 2 2 1 -1

// Sample Output 1:

// True

// Explanation for Sample Input 1:

// The given list is a palindrome.

// Sample Input 2:

// 3 2 1 -1

// Sample Output 2:

// False

// Constraints :

// 1 <= 'N' <= 5 * 10^4
// -10^9 <= 'data' <= 10^9 and 'data' != -1

// Where 'N' is the number of nodes in the linked list and ‘data’ represents the value of the list's nodes.

// 1st Approach:
// Create Array and copy data then solve normally

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

Node *reverse(Node *node)
{
    Node *prev = nullptr;
    Node *curr = node;

    while (curr != nullptr)
    {
        Node *nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}

bool isPalindrome(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return true;

    // Find the middle
    Node *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half
    Node *secondHalf = reverse(slow);
    Node *firstHalf = head;

    // Compare both halves
    Node *check = secondHalf;
    while (check != nullptr)
    {
        if (firstHalf->data != check->data)
            return false;
        firstHalf = firstHalf->next;
        check = check->next;
    }

    return true; // Is a palindrome
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

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
    // head->next->next->next->next->next = new Node(4);

    printList(head);

    if (isPalindrome(head))
    {
        cout << "The linked list is a palindrome." << endl;
    }
    else
    {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}

// ⏱ Time Complexity:

//     O(N) – One pass to find the middle, one to reverse, and one to compare.

// 📦 Space Complexity:

//     O(1) – In-place reversal, no extra space used.