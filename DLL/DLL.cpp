#include <iostream>
#include <stdio.h>
using namespace std;

struct node
{
    node *prev;
    int item;
    node *next;
};

class DLL
{
private:
    node *start;

public:
    DLL();
    void insertAtStart(int);
    void insertAtLast(int);
    node *search(int)
};

DLL::DLL()
{
    start = NULL:
}

void DLL::insertAtStart(int data)
{

    node *n = new node;
    n->item = data;
    n->next = start;
    n->prev = NULL;
    if (start)
    {
        start->prev = n;
    }

    start = n;
}

void DLL::insertAtLast(int data)
{

    node *t;
    node *n = new node;
    n->item = data;
    n->next = NULL;
    if (start == NULL)
    {
        n->prev = NULL;
        start = n;
    }
    else
    {
        while (t->next != NULL)
        {
            t = t->next;
        }
        n->prev = t;
        t->next = n;
    }
}

node *search(int data)
{
    node *t;
    t = start;
    while (t != NULL)
    {
        if (t->item == data)
        {
            return t;
        }
        else
        {
            t = t - next;
        }
    }
    return t;
}