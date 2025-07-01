#include <iostream>
#include <stdio.h>
using namespace std;

struct node
{
    int item;
    node *next;
};

class SLL
{
private:
    node *start;

public:
    SLL();
    void insertAtStart(int);
    void insertAtEnd(int);
    node *search(int); // node is return type
    void insertAfter(node *, int);
    void deleteFirst();
    void deleteLast();
    void deleteNode(node *);
    node *getFirst();
    ~SLL();
};

SLL::SLL()
{
    start = nullptr; // if writing NULL we need to include stdio.h
}

void SLL::insertAtStart(int data)
{
    node *n = new node;
    n->item = data;
    n->next = start; // basically address of node which start was pointing to the node
    start = n;
}

void SLL::insertAtEnd(int data)
{
    node *t = start;
    node *n = new node;
    n->item = data;
    n->next = NULL; // need since it will have a garbage value

    if (start == nullptr)
    {
        start = n;
    }
    else
    {
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = n;
    }
}

node *SLL::search(int data)
{
    node *t = start;
    while (t != NULL)
    {
        if (t->item == data)
        {
            return t;
        }
        t = t->next;
    }
    return t;
}
void SLL::insertAfter(node *ptr, int data)
{
    node *n = new node;
    n->item = data;
    n->next = ptr->next;
    ptr->next = n;
}

void SLL::deleteFirst()
{
    node *t;
    if (start) // if start=Null will not run the code

    {
        t = start;
        start = start->next;
        delete t;
    }
}
void SLL::deleteLast()
{
    node *t;
    if (start == NULL)
    {
        cout << "list Empty";
    }
    else if (start->next == NULL)
    {
        delete start;
        start = NULL;
    }
    else
    {
        t = start;
        while (t->next->next != NULL)
        {
            t = t->next;
        }
        delete t->next;
        t->next = NULL;
    }
}

void SLL::deleteNode(node *temp)
{
    node *t;
    if (start == NULL)
    {
        cout << "list is empty";
    }
    else
    {
        if (temp) // if temp null it will not run
        {
            if (start == temp)
            {
                delete start;
                start = NULL;
            }
            else
            {
                t = start;
                while (t->next != temp)
                {
                    t = t->next;
                }
                t->next = temp->next;
                delete temp;
            }
        }
    }
}

node *SLL::getFirst();
{
    return start;
}

SLL::~SLL()
{
    while (start)
    {
        deleteFirst();
    }
}
