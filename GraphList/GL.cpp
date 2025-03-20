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
};

class GL
{
private:
    int v_count;
    Adjlist *arr;
public:
    GL();
};

GL::GL(){
    v_count=0;
    arr=NULL;
}