#include <iostream>
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
    ~SLL();
};

SLL::SLL()
{
    start = nullptr; // if writing NULL we need to include stdio.h
}

SLL::insertAtStart(int data)
{
    node *n = new node;
    n->item = data;
    n->next = start; // basically address of node which start was pointing to the node
    start = n;
}

SLL::~SLL()
{
}
