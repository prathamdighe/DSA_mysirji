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
};

class GL
{
private:
    int v_count;
    Adjlist *arr;

public:
    GL();
    createGraphL(int);
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

int main()
{
    GL g;
}