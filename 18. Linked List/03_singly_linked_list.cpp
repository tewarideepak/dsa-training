#include <iostream>
using namespace std;

// 📘 Node Class
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }

    ~Node()
    {
        cout << "Node with data " << data << " deleted.\n";
    }
};

// 📘 Insert at Beginning
void insertAtBeginning(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// 📘 Insert at End
void insertAtEnd(Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (tail != nullptr)
    {
        tail->next = newNode;
    }
    tail = newNode;
}

// 📘 Insert at a Given Position (1-based index)
void insertAtPos(Node *&head, Node *&tail, int pos, int val)
{
    if (pos <= 1 || head == nullptr)
    {
        insertAtBeginning(head, val);
        if (tail == nullptr)
            tail = head;
        return;
    }

    Node *temp = head;
    int count = 1;

    while (count < pos - 1 && temp->next != nullptr)
    {
        temp = temp->next;
        count++;
    }

    Node *newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;

    if (newNode->next == nullptr)
    {
        tail = newNode;
    }
}

// 📘 Delete Node by Position (1-based index)
void deleteNode(Node *&head, Node *&tail, int pos)
{
    if (head == nullptr)
    {
        cout << "List is empty.\n";
        return;
    }

    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        if (head == nullptr)
            tail = nullptr; // If list becomes empty
        delete temp;
        return;
    }

    Node *prev = nullptr;
    Node *curr = head;
    int count = 1;

    while (curr != nullptr && count < pos)
    {
        prev = curr;
        curr = curr->next;
        count++;
    }

    if (curr == nullptr)
    {
        cout << "Position out of bounds.\n";
        return;
    }

    prev->next = curr->next;
    if (prev->next == nullptr)
    {
        tail = prev; // If last node is deleted, update tail
    }

    delete curr;
}

// 📘 Print the List
void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// 📘 Main Function
int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    insertAtBeginning(head, 10);
    tail = head; // Only one node now

    insertAtBeginning(head, 20);
    insertAtEnd(tail, 30);
    insertAtPos(head, tail, 2, 25);

    cout << "Initial List:\n";
    printList(head);

    cout << "\nDeleting 1st node:\n";
    deleteNode(head, tail, 1);
    printList(head);

    cout << "\nDeleting last node:\n";
    deleteNode(head, tail, 3);
    printList(head);

    cout << "\nDeleting node at position 2:\n";
    deleteNode(head, tail, 2);
    printList(head);

    cout << "\nDeleting node at position 5 (Invalid):\n";
    deleteNode(head, tail, 5);
    printList(head);

    return 0;
}
