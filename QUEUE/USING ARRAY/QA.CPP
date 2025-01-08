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
    bool isEmpty();
    void insert(int);
    int getfront();
    int getrear();
};

Queue::Queue(int cap)
{
    capacity = cap;
    front = -1;
    rear = -1;
    ptr = new int[cap];
}

bool Queue::isFull()
{
    return front == 0 && rear == capacity - 1 || rear + 1 == front;
}
bool Queue::isEmpty()
{
    return rear == -1;
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
    else if (rear + 1 == capacity)
    {
        rear = (rear + 1) % capacity; // basically keep the counter in range of cap.
        ptr[rear] = data;
    }
    else
    {
        rear++;
        ptr[rear] = data;
    }
}

int getfront()
{
    return ptr[front];
};
int getrear()
{
    return ptr[rear];
};