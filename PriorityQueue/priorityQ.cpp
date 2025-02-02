#include <iostream>
#include <stdio.h>
using namespace std;

struct node
{

    int item;
    int priority;
    node *next;
};

class PriorityQueue
{
private:
    node *start;

public:
    PriorityQueue();
    void insert(int, int);
    void del();
};

PriorityQueue::PriorityQueue()
{
    start = NULL;
}
void PriorityQueue::insert(int data, int pqn)
{

    node *t;
    node *n = new node;
    n->item = data;
    n->priority = pqn;

    if (start == NULL)
    {
        n->next = NULL;
        start = n;
    }
    else
    {
        while (t->next != NULL)
        {
            if (t->next->priority >= n->priority)
            {
                t = t->next;
            }
            else
            {
                break;
            }
        }
        n->next = t->next;
        t->next = n;
    }
}

void PriorityQueue::del(){
    
}
