#include <iostream>
#include <stdio.h>
using namespace std;

struct node
{
    node *prev;
    int item;
    node *next;
};

class CDLL
{
private:
    node *start;

public:
    CDLL();
    void insertAtStart(int);
    void insertAtLast(int);
    node *search(int);
};

CDLL::CDLL()
{
    start = NULL;
}

void CDLL::insertAtStart(int data)
{

    node *n = new node;
    n->item = data;
    if (start == NULL)
    {
        n->next = n;
        n->prev = n;
        start = n;
    }
    else
    {
        n->prev = start->prev;
        n->next = start;
        start->prev->next = n;
        start->prev = n;
        start = n;
    }
}

void CDLL::insertAtLast(int data)
{
    node *n = new node;

    n->item = data;

    if (start == NULL)
    {

        n->next = n;
        n->prev = n;
        start = n;
    }
    else
    {
        n->prev = start->prev;
        n->next = start;
        start->prev->next = n;
        start->prev = n;
    }
}

node *CDLL::search(int data)
{
    node *t = start;

    if (t != NULL)
    {
        do
        {
            if (t->item == data)
            {
                return t;
            }
            t = t->next;
        } while (t != start);
    }
    return NULL;
}