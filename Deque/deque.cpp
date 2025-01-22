#include <iostream>
#include <stdio.h>
using namespace std;

struct node
{
    node *prev;
    int item;
    node *next;
};

class Deque
{
private:
    node *front;
    node *rear;

public:
    Deque();
    void insertfront(int);
    void insertrear(int);
    void deletefront();
    void deleterear();
    node *getfront();
    node *getrear();
    bool isempty();
    ~Deque();
};

Deque::Deque()
{
    rear = front = NULL;
}

void Deque::insertfront(int data)
{
    node *n = new node;
    n->item = data;
    n->prev = NULL;
    n->next = front;
    if (front)
    {
        front->prev = n;
    }
    else
    {
        rear = n;
    }
    front = n;
}

void Deque::insertrear(int data)
{
    node *n = new node;
    n->item = data;
    n->prev = rear;
    n->next = NULL;
    if (front)
    {
        rear->prev = n;
    }
    else
    {
        front = n;
    }
    rear = n;
}

void Deque::deletefront()
{
    node *temp;
    if (front != NULL)
    {
        temp = front;
        if (front = rear)
        {
            front = rear = NULL;
        }
        else
        {
            front = front->next;
            front->prev = NULL;
        }
        delete temp;
    }
}
void Deque::deleterear()
{
    node *temp;
    if (front != NULL)
    {
        temp = rear;
        if (front = rear)
        {
            front = rear = NULL;
        }
        else
        {
            rear = rear->prev;
            rear->next = NULL;
        }
        delete temp;
    }
}
node *Deque::getfront()
{
    return front;
}
node *Deque::getrear()
{
    return rear;
}
bool Deque::isempty()
{
    if (front == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
Deque::~Deque()
{
    while (front != NULL)
    {
        deletefront();
    }
}



// create copy constructor and assignment copy consturctor.