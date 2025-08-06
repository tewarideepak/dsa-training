// Problem statement

//             You are given two non -
//         negative numbers 'num1' and
//     'num2' represented in the form of linked lists.

//     The digits in the linked lists are stored in reverse order,
//     i.e.starting from least significant digit(LSD)
// to the most significant digit(MSD), and each of their nodes contains a single digit.

//                                         Calculate the sum of the two numbers and return the head of the sum list.

//                                         Example :

//     Input : 'num1' : 1 -> 2->3->NULL
//             'num2' : 4->5->6->NULL

//             Output : 5->7->9->NULL

//             Explanation : 'num1' represents the number 321 and
//                                         'num2' represents 654. Their sum is 975.

//                                         Detailed explanation(Input / output format, Notes, Images)
// Sample Input 1 :

// 3
// 1 2 3
// 3
// 4 5 6

// Sample Output 1 :

// 5 7 9

// Explanation for Sample Input 1 :

// 'num1' represents the number 321 and 'num2' represents 654. Their sum is 975.

// Sample Input 2 :

// 2
// 0 1
// 1
// 0

// Sample Output 2 :

// 0 1

// Explanation for Sample Input 2 :

// 'num1' represents 10 and 'num2' represents 0. Their sum is 10.

// Sample Input 3 :

// 1
// 2
// 2
// 9 9

// Sample Output 3 :

// 1 0 1

// Explanation for Sample Input 3 :

// 'num1' represents 2 and 'num2' represents 99. Their sum is 101.

// Expected Time Complexity :

// The expected time complexity is O('m' + 'n').

// Constraints :

// 1 <= 'm', 'n' <= 5 * 10^4
// 0 <= 'data' in any Linked List node <= 9

// The numbers do not contain any leading zeros.
// If the number is zero, then there is one node having 'data' = 0.

#include <iostream>
using namespace std;

// Definition of singly linked list node
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

// Function to add two numbers represented by linked lists
Node *addTwoNumbers(Node *num1, Node *num2)
{
    Node *dummyHead = new Node(0); // Dummy node to start the result list
    Node *current = dummyHead;
    int carry = 0;

    while (num1 != NULL || num2 != NULL || carry != 0)
    {
        int val1 = (num1 != NULL) ? num1->data : 0;
        int val2 = (num2 != NULL) ? num2->data : 0;

        int sum = val1 + val2 + carry;
        carry = sum / 10;

        current->next = new Node(sum % 10);
        current = current->next;

        if (num1 != NULL)
            num1 = num1->next;
        if (num2 != NULL)
            num2 = num2->next;
    }

    return dummyHead->next;
}

// Helper function to insert a node at the end
Node *insertAtTail(Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (!head)
    {
        return newNode;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Helper function to build list from array
Node *buildList(int arr[], int n)
{
    Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        head = insertAtTail(head, arr[i]);
    }
    return head;
}

// Helper function to print the list
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data;
        if (head->next != NULL)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Main function to test the code
int main()
{
    // Sample Input:
    // num1: 1 -> 2 -> 3 (321)
    // num2: 4 -> 5 -> 6 (654)

    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5, 6};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    Node *num1 = buildList(arr1, n1);
    Node *num2 = buildList(arr2, n2);

    cout << "Input List 1: ";
    printList(num1);

    cout << "Input List 2: ";
    printList(num2);

    Node *result = addTwoNumbers(num1, num2);

    cout << "Sum List:     ";
    printList(result);

    return 0;
}

// ✅ Time Complexity (TC): O(m + n)
// Where:

//     m is the number of nodes in num1

//     n is the number of nodes in num2

// Why?

//     We traverse each node of both linked lists exactly once.

//     At each iteration, we:

//         Read a digit from num1 and num2 (if present)

//         Add the digits and the carry

//         Create a new node in the result list

//     The loop runs until both lists are exhausted and there's no carry left, so total operations are proportional to m + n.

// ✅ Space Complexity (SC): O(max(m, n) + 1)
// Why?

//     We create a new linked list to store the result:

//         In the worst case, the number of nodes in the result list is max(m, n) + 1

//             The +1 is for a possible extra carry at the end (e.g., 999 + 1 = 1000 → 4 digits)

//     Auxiliary space (temporary variables like val1, val2, sum, and carry) uses O(1) space, which is constant.