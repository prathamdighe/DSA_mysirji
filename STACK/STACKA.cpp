#include "/workspaces/DSA_mysirji/ADT/adt.cpp"
#include <iostream>
using namespace std;

class Stack : private Array
{
public:
    Stack(int);
    Stack(Stack &);
    void push(int);
    int peek();
    void pop();
    virtual bool isEmpty();
    virtual bool isFull();
    void reverseStack(Stack &);
    int getStacksize();
    void operator=(Stack &);
    ~Stack();
};

Stack::Stack(int cap) : Array(cap) {}

// Copy constructor using base class constructor
Stack::Stack(Stack &S) : Array(S) {}

void Stack::reverseStack(Stack &s) {
    Stack temp1(s.getCapacity());
    Stack temp2(s.getCapacity());

    while (!s.isEmpty()) {
        temp1.push(s.peek());
        s.pop();
    }

    while (!temp1.isEmpty()) {
        temp2.push(temp1.peek());
        temp1.pop();
    }

    while (!temp2.isEmpty()) {
        s.push(temp2.peek());
        temp2.pop();
    }
}

int Stack::getStacksize() {
    return getCapacity();
}

void Stack::push(int data) {
    if (isFull()) {
        cout << "Stack Overflow";
    } else {
        append(data);
    }
}

int Stack::peek() {
    if (!isEmpty()) {
        return get(count() - 1);
    } else {
        cout << "Stack empty";
        return -1;
    }
}

void Stack::pop() {
    if (!isEmpty()) {
        del(count() - 1);
    }
}

bool Stack::isEmpty() {
    return Array::isEmpty();
}

bool Stack::isFull() {
    return Array::isFull();
}

void Stack::operator=(Stack &s) {
    Array::operator=(s);
}

Stack::~Stack() {}
