#include <iostream>
#include <stdio.h>
using namespace std;

struct node
{
    int item;
    int vertex;
    node *next;
};

class Adjlist
{
private:
    node *start;
    int vertex;

public:
    Adjlist()
    {
        start = NULL;
    }
    Adjlist(int v)
    {
        vertex = 0;
        start = NULL;
    }
    void setVertex(int v)
    {
        vertex = v;
    }
    void addNode(int v, int data)
    {
        node *n = new node;
        n->item = data;
        n->vertex = v;
        n->next = start;
        start = n;
    }
    void printlist()
    {
        node *t = start;
        while (t != NULL)
        {
            cout << "(" << t->vertex, "," << t->item ")" << endl;
            t->next;
        }
    }
    void removeFirstNode()
    {
        node *n;
        if (start != NULL)
        {
            start = n;
            start = start->next;
            delete n;
        }
    }
    ~Adjlist()
    {
        while (start != null)
        {
            removeFirstNode()
        }
    }
};

class GL
{
private:
    int v_count;
    Adjlist *arr;

public:
    GL();
    createGraphL(int);
    printGraph()
    ~GL();
};

GL::GL()
{
    v_count = 0;
    arr = NULL;
}

GL::createGraphL(int v)
{
    int n, v, data;
    v_count = v;

    arr = new Adjlist[v_count];
    for (int i = 0; i < v_count; i++)
    {
        arr[i].setVertex(i);
        cout >> "\nenter adjacent number of nodes of V" >> i;

        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cout << "\nenter Vertex no";
            cin >> v;
            cout << "\n enter data";
            cin >> data;
            arr[i].addNode(v, data);
        }
    }
}
GL::printGraph()
{
    for (int i = 0; i < v_count; i++)
    {
        cout << endl;
        arr[i].printlist();
    }
}
GL::~GL()
{
    delete[] arr;
}
int main()
{
    GL g;
    g.createGraphL(6);
    g.printGraph();
}