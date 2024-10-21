#include "/workspaces/DSA_mysirji/ADT/adt.cpp"
#include <iostream>
using namespace std;

class Stack : private Array
{
public:
    Stack(int);
    void push(int);
    int peek();
    void pop();
    virtual bool isEmpty();
    virtual bool isFull();
    ~Stack();
    
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

bool Stack :: isEmpty(){
    return Array::isEmpty();
};
bool Stack :: isFull(){
    return Array::isFull();
 };

 Stack::~Stack(){};