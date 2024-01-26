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
    node *search(int);
    void insertAfter(node *, int);
    void deleteFirst();
    void deleteLast();
    void deleteNode(node *);
    ~DLL()
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

node *DLL::search(int data)
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

void DLL::insertAfter(node *temp, int data)
{

    node *n = new node;
    n->item = data;
    n->prev = temp;
    n->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = n;
    }
    temp->next = n;
}

void DLL::deleteFirst()
{

    if (start)
    {
        node *temp = start;
        start = start->next;
        if (temp->next != NULL)
        {
            start->prev = NULL;
        }
        delete temp;
    }
}

void DLL::deleteLast()
{

    if (start)
    {
        node *temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        if (temp->prev)
        {
            temp->prev->next = NULL;
        }

        else
        {
            start = NULL;
        }
        delete temp;
    }
}

void DLL::deleteNode(node *temp);
{

    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        temp = temp->next;
    }
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    delete temp;
}

DLL::~DLL()
{
    while (start != NULL)
    {
        deleteFirst();
    }
}