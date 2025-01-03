#include <stdio.h>
#include <iostream>
using namespace std;

struct node
{
    int item;
    node *next;
};

class Stack
{
private:
    node *top;

public:
    Stack();
    bool isEmpty();
    void push(int);
    int peek();
    void pop();
    void reverse();
    int len(int);
    bool palindrome(int);
    ~Stack();
};

Stack::Stack() { top = NULL; }

bool Stack::isEmpty()
{
    return top == NULL;
}

void Stack::push(int data)
{
    node *n;
    n = new node;
    n->item = data;
    n->next = top;
    top = n;
}

int Stack::peek()
{
    if (isEmpty())
    {
        cout << " nothing to peek";
        return -1;
    }
    else
    {
        return top->item;
    }
}

void Stack::pop()
{
    node *r; // for memory leak
    if (isEmpty())
    {

        cout << " nothing to pop";
    }
    else
    {
        r = top;
        top = top->next;
        delete r;
    }
}

void Stack::reverse()
{
    if (!top || !top->next) // If stack has 0 or 1 node, no reversal needed
        return;

    node *t2 = NULL; // This will hold the reversed part of the stack
    while (top != NULL)
    {
        node *t1 = top;  // Save the current top node
        top = top->next; // Move to the next node
        t1->next = t2;   // Reverse the link
        t2 = t1;         // Move t2 to the current node
    }
    top = t2; // Update top to the new reversed stack
}

int Stack::len(int x)
{
    int count = 0;
    while (x)
    {
        x /= 10;
        count++;
    }
    return count;
}

bool Stack::palindrome(int x) // Changed return type to bool
{
    Stack s;
    int length = len(x); // Renamed variable to avoid shadowing
    int halfLength = length / 2;

    // Simplified loop
    for (int i = 0; i < halfLength; i++)
    {
        s.push(x % 10);
        x /= 10;
    }

    if (length % 2 != 0) // Corrected len usage and clarified condition
    {
        x /= 10; // Skip the middle digit if length is odd
    }

    while (x)
    {
        if (x % 10 == s.peek())
        {
            s.pop();
            x /= 10;
        }
        else
        {
            return false; // Fixed logic to exit on mismatch
        }
    }

    return true; // Moved return true to ensure all checks are completed
}

Stack::~Stack()
{
    while (top)
    {
        node *temp = top;
        top = top->next;
        delete temp;
    }
}