#include "ADT/adt.cpp"
#include <iostream>
using namespace std;

class Stack : private Array
{
public:
    Stack(int);
    void push(int);
    int peek();
    void pop();
};

Stack::Stack(int cap) : Array( cap)
{
}

void Stack::push(int data)
{
    if (isFull())
    {
        cout << "Stack Overflow";
    }
    else
    {
        append(data);
    }
}
int Stack::peek()
{
    if (!isEmpty())
    {
        return get(count() - 1);
    }
    else{
        cout << "stack empty";
        return -1;
    }
}

void Stack::pop()
{
    if (!isEmpty())
    {
        del(count() - 1);
    }
}