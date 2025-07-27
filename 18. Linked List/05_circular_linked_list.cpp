#include <iostream>
using namespace std;

// 📘 Node class
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
void insertAtBeginning(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = tail = newNode;
        newNode->next = head;
        return;
    }
    newNode->next = head;
    tail->next = newNode;
    head = newNode;
}

// 📘 Insert at End
void insertAtEnd(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = tail = newNode;
        newNode->next = head;
        return;
    }
    tail->next = newNode;
    newNode->next = head;
    tail = newNode;
}

// 📘 Insert at Given Position (1-based index)
void insertAtPos(Node *&head, Node *&tail, int pos, int val)
{
    if (pos == 1)
    {
        insertAtBeginning(head, tail, val);
        return;
    }

    Node *temp = head;
    int count = 1;

    while (count < pos - 1 && temp->next != head)
    {
        temp = temp->next;
        count++;
    }

    Node *newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;

    if (temp == tail)
        tail = newNode;
}

// 📘 Delete Node by Position (1-based index)
void deleteNode(Node *&head, Node *&tail, int pos)
{
    if (!head)
    {
        cout << "List is empty.\n";
        return;
    }

    if (pos == 1)
    {
        Node *temp = head;

        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            tail->next = head;
        }
        delete temp;
        return;
    }

    Node *prev = head;
    Node *curr = head->next;
    int count = 2;

    while (curr != head && count < pos)
    {
        prev = curr;
        curr = curr->next;
        count++;
    }

    if (curr == head)
    {
        cout << "Position out of bounds.\n";
        return;
    }

    prev->next = curr->next;
    if (curr == tail)
        tail = prev;

    delete curr;
}

// 📘 Print Circular Linked List
void printList(Node *head)
{
    if (!head)
    {
        cout << "List is empty.\n";
        return;
    }

    Node *temp = head;
    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(head)\n";
}

// 📘 Main Function
int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    insertAtBeginning(head, tail, 10);
    insertAtBeginning(head, tail, 20);
    insertAtEnd(head, tail, 30);
    insertAtPos(head, tail, 2, 25);

    cout << "Initial Circular List:\n";
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

    cout << "\nTrying to delete out of bounds:\n";
    deleteNode(head, tail, 5);
    printList(head);

    return 0;
}
