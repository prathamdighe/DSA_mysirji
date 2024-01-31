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
    void insertAfter(node *, int);
    void deleteFirst();
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

void CDLL::insertAfter(node *temp, int data)
{

    if (temp != NULL)
    {
        node *n = new node;
        n->item = data;
        n->prev = temp;
        n->next = temp->next;
        temp->next->prev = n;
        temp->next = n;
    }
}

void CDLL::deleteFirst()
{
    if (start != NULL)
    {
        node *temp = start;
        if (temp != start)
        {
            start->next->prev = start->prev;
            start->prev->next = start->next;
        }
        else
        {
            start = NULL;
        }
        delete temp;
    }
}