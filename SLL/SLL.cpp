#include <iostream>
#include<stdio.h>
using namespace std;

struct node
{
    int item;
    node *next;
}

class SLL
{
private:
    node *start;

public:
    SLL();
    void insertAtStart(int);
    void insertAtEnd(int);
    node *search(int);// node is return type
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
        whlie(t->next != nullptr)
        {
            t = t->next;
        }
        t->next = n;
    }
}

node * SLL::search(int data){
    node*t=start;
    while (t!=NULL){
        if(t->item==data){
            return t;
        }
        t=t->next;

    }
    return t;
}

SLL::~SLL()
{
}
