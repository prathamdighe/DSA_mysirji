#include <iostream>
using namespace std;

class Queue
{
private:
    int capacity;
    int front, rear;
    int *ptr;

public:
    Queue(int);
    bool isFull();
    void insert(int);
    bool isEmpty();
};

Queue::Queue(int cap)
{
    capacity = cap;
    front = -1;
    rear = -1;
    ptr = new capacity[cap];
}

bool Queue::isFull()
{
    return front == 0 && rear == cap - 1 || rear + 1 == front;
}

void Queue::insert(int data)
{
    if (isFull())
    {
        cout << " Queue is full";
    }
    else if (isEmpty())
    {
        front = rear = 0;
        ptr[rear] = data;
    }
    else if (rear == cap - 1)
    {
        rear = 0;
        ptr[rear] = data;
    }
    else
    {
        ptr[rear] = data;
    }
}

int 