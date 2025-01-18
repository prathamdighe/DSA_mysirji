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
    void insert(int)
};

Deque::Deque()
{
    rear = front = NULL;
}

void Deque::Deque(int data)
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