#include <iostream>
using namespace std;

class Stack
{
    int top;
    int capacity;
    int *arr;

public:
    Stack(int size)
    {
        top = -1;
        capacity = size;
        arr = new int[capacity];
    }

    ~Stack()
    {
        delete[] arr;
    }

    void push(int x)
    {
        if (top == capacity - 1)
        {
            cout << "Stack overflow\n";
            return;
        }
        arr[++top] = x;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow\n";
            return;
        }
        top--;
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }

    int size()
    {
        return top + 1;
    }
};

int main()
{
    Stack stack(5);
    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element is: " << stack.peek() << endl; // Output: 30
    cout << "Stack size is: " << stack.size() << endl;  // Output: 3

    stack.pop();
    cout << "Top element after pop is: " << stack.peek() << endl; // Output: 20

    stack.pop();
    stack.pop();
    stack.pop(); // Attempt to pop from an empty stack

    return 0;
}