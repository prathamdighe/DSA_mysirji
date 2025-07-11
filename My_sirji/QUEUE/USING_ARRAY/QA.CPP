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
    Queue(Queue &Q);
    Queue &operator=(Queue &);
    bool isFull();
    bool isEmpty();
    void insert(int);
    int getfront();
    int getrear();
    void del();
    int count();
    ~Queue();
};

Queue::Queue(int cap)
{
    capacity = cap;
    front = -1;
    rear = -1;
    ptr = new int[cap];
}
Queue::Queue(Queue &Q)
{ // deep copy constructor

    capacity = Q.capacity;
    front = Q.front;
    rear = Q.rear;
    ptr = new int[capacity];
    int n = Q.count();
    int i = front;
    while (n != 0)
    {
        ptr[i] = Q.ptr[i]; // copying data
        if (i == capacity - 1)
        {
            i = 0;
        }
        else
        {
            i++;
        }
        n--;
    }
}
Queue &Queue::operator=(Queue &Q)

{
    capacity = Q.capacity;
    front = Q.front;
    rear = Q.rear;
    if (ptr != nullptr)
    {
        delete[] ptr;
    }
    ptr = new int[capacity];
    int n = Q.count();
    int i = front;
    while (n != 0)
    {
        ptr[i] = Q.ptr[i]; // copying data
        if (i == capacity - 1)
        {
            i = 0;
        }
        else
        {
            i++;
        }
        n--;
    }return *this;

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

int Queue::getfront()
{
    return ptr[front];
};
int Queue::getrear()
{
    return ptr[rear];
};

void Queue::del()
{

    if (isEmpty())
    {
        cout << "empty";
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == capacity - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

int Queue::count()
{

    if (isEmpty())
    {
        return -1;
    }
    else
    {
        if (front <= rear)
        {
            return rear - front + 1; // single element also works
        }
        else
        {
            return capacity - (front - rear + 1); // front is bigger than rear
        }
    }
}

Queue::~Queue()
{
    delete[] ptr;
}