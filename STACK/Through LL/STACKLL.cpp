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

Stack::~Stack()
{
    while (top)
    {
        node *temp = top;
        top = top->next;
        delete temp;
    }
}