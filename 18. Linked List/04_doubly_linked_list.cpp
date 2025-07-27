#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }

    // Destructor
    ~Node()
    {
        cout << "Node with data " << data << " deleted.\n";
    }
};

// Insert at beginning
void insertAtBeginning(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// Insert at end
void insertAtEnd(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (!tail)
    {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

// Insert at a specific position
void insertAtPos(Node *&head, Node *&tail, int pos, int val)
{
    if (pos == 1)
    {
        insertAtBeginning(head, tail, val);
        return;
    }

    Node *temp = head;
    int count = 1;

    while (temp && count < pos - 1)
    {
        temp = temp->next;
        count++;
    }

    // If inserting at end
    if (!temp || !temp->next)
    {
        insertAtEnd(head, tail, val);
        return;
    }

    Node *newNode = new Node(val);
    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;
}

// Delete node at position
void deleteAtPos(Node *&head, Node *&tail, int pos)
{
    if (!head)
        return;

    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        if (head)
            head->prev = nullptr;
        else
            tail = nullptr;
        delete temp;
        return;
    }

    Node *curr = head;
    int count = 1;

    while (curr && count < pos)
    {
        curr = curr->next;
        count++;
    }

    if (!curr)
        return;

    if (curr->next)
        curr->next->prev = curr->prev;
    else
        tail = curr->prev;

    if (curr->prev)
        curr->prev->next = curr->next;

    delete curr;
}

// Print list forward
void printForward(Node *head)
{
    cout << "Forward: ";
    while (head)
    {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Print list backward
void printBackward(Node *tail)
{
    cout << "Backward: ";
    while (tail)
    {
        cout << tail->data << " <-> ";
        tail = tail->prev;
    }
    cout << "NULL\n";
}

// Main function
int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    insertAtBeginning(head, tail, 10);
    insertAtBeginning(head, tail, 5);
    insertAtEnd(head, tail, 20);
    insertAtPos(head, tail, 2, 7);  // insert 7 at position 2
    insertAtPos(head, tail, 5, 25); // insert 25 at end

    printForward(head);
    printBackward(tail);

    deleteAtPos(head, tail, 1); // delete head
    deleteAtPos(head, tail, 3); // delete middle
    deleteAtPos(head, tail, 3); // delete tail

    printForward(head);
    printBackward(tail);

    return 0;
}
