#include <iostream>
using namespace std;

class Stack
{
private:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int val)
        {
            data = val;
            next = NULL;
        }
    };

    Node *topNode; // pointer to stack top

public:
    Stack()
    {
        topNode = NULL;
    }

    void push(int x)
    {
        Node *newNode = new Node(x);
        newNode->next = topNode; // new node points to old top
        topNode = newNode;       // update top
        cout << x << " pushed into stack\n";
    }

    void pop()
    {
        if (topNode == NULL)
        {
            cout << "Stack Underflow\n";
            return;
        }
        Node *temp = topNode;
        topNode = topNode->next;
        cout << temp->data << " popped from stack\n";
        delete temp; // free memory
    }

    int top()
    {
        if (topNode == NULL)
        {
            cout << "Stack is Empty\n";
            return -1;
        }
        return topNode->data;
    }

    bool empty()
    {
        return topNode == NULL;
    }

    ~Stack()
    {
        while (topNode != NULL)
        {
            Node *temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }
};

int main()
{
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl; // 30

    st.pop();                                      // removes 30
    cout << "Top after pop: " << st.top() << endl; // 20

    while (!st.empty())
    {
        cout << "Popping: " << st.top() << endl;
        st.pop();
    }

    return 0;
}
