#include <iostream>
#include <stdio.h>
using namespace std;

struct node
{
    int item;
    node *next;
};

class QueueLL
{
private:
    node *front, *rear;

public:
    QueueLL();
    void insert(int);
    bool isempty();
    node *getfront();
    node *getback();
    void del();
    ~QueueLL();
};

QueueLL::QueueLL()
{
    front = rear = NULL;
}

bool QueueLL::isempty()
{
    return rear == NULL;
}

void QueueLL::insert(int data)
{
    node *a = new node;
    a->item = data;
    a->next = NULL;
    if (isempty())
    {
        front = rear = a;
    }
    else
    {
        rear->next = a;
        rear = a;
    }
}

node *QueueLL::getfront()
{
    return front;
}
node *QueueLL::getback()
{
    return rear;
}

void QueueLL::del()
{
    node *r;
    if (!isempty())
    {
        r = fornt;
        front = front->next;
        if (front == NULL)
        {
            rear == NULL;
        }
        delete r;
    }
}
QueueLL::~QueueLL()
{

    while (!isempty())
    {
        del();
    }
}

int QueueLL::count()
{
    node *t = front;
    int c = 0;
    while (t != NULL)
    {
        c++;
        t = t->next;
    }
    return c;
}