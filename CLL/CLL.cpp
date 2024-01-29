#include <iostream>
#include <stdio.h>
using namespace std;

struct node
{
    int item;
    node *next;
};

class CLL
{
private:
    node *last;

public:
    CLL();
    void insertAtStart(int);
    void insertAtLast(int);
    node *search(int);
    void insertAfter(node *, int);
    void deleteFirst();
    void deleteLast();
    void deleteNode(node *);
    ~CLL()
};
CLL::CLL()
{
    last = NULL;
}

void CLL::insertAtStart(int data)
{
    node *n = new node;
    n->item = data;
    if (last != NULL)
    {
        n->next = last->next;
        last->next = n;
    }
    else
    {
        n->next = n;
        last = n;
    }
}

void CLL::insertAtLast(int data)
{

    node *n = new node;
    n->item = data;
    if (last != NULL)
    {
        n->next = last->next;
        last->next = n;
    }
    else
    {
        n->next = n;
    }
    last = n;
}

node *CLL::search(int data)
{
    node *t;

    if (last != NULL)
    {
        t = last;
        do
        {
            t = t->next;
            if (t->item == data)
            {
                return t;
            }

        } while (t != last);
        return NULL;
    }
}

void CLL::insertAfter(node *temp, int data)
{

    if (temp != NULL)
    {

        node *n = new node;
        n->item = data;
        n->next = temp->next;
        temp->next = n;
        if (temp == last)
        {
            last = n;
        }
    }
}

void CLL::deleteFirst()
{
    if (last != NULL)
    {
        node *temp = last->next;
        if (last == last->next)
        {
            last = NULL;
        }
        else
        {
            last->next = temp->next;
        }
        delete temp;
    }
}

void CLL::deleteLast()
{

    // if (last != NULL)
    // {
    //     node *t;
    //     if (last == last->next)
    //     {
    //         t = last;
    //         last = NULL;
    //     }
    //     else
    //     {
    //         node *temp = last;
    //         while (temp->next != last)
    //         {
    //             temp = temp->next;
    //         }
    //         temp->next = last->next;
    //         t = last;
    //         last = temp;
    //     }
    //     delete t;
    // }
    if (last != NULL)
    {
        node *t;
        while (t->next != Last)
        {
            t = t->next;
        }
        if (t == last)
        {
            delete last;
            last = NULL;
        }
        else
        {
            t->next = last->next;
            delete last;
            last = t;
        }
    }
}

void CLL::deleteNode(node *temp)
{
    if (temp != NULL)
    {
        node *t;
        t = last->next;
        while (t->next != temp)
        {
            t = t->next;
        }
        t->next = temp->next;
        if (t == temp) // single node
        {

            last = NULL;
        }

        else if (temp == last)
        {
            last = t;
        }
        delete temp;
    }
}

CLL::~CLL()
{
    while (last != NULL)
    {
        deleteFirst();
    }
}