#include <iostream>
#include <stdio.h>
#include "/workspaces/DSA_mysirji/DADT/DADT.cpp"
using namespace std;

class GM
{
private:
    int v_count;
    int e_count;
    int **adj;

public:
    int getv_count();
    void createGraph(int, int);
    void printGraph();
    void printAdjnodes(int);
    DynArray &adjnodes(int);
    bool isIsolated(int);
    ~GM();
};

void GM::createGraph(int vno, int eno)
{
    int u, v;
    v_count = vno;
    e_count = eno;
    adj = new int *[v_count];
    // create new row of matrix start pointers

    for (int i = 0; i < v_count; i++)
    {
        adj[i] = new int[v_count];

        for (int j = 0; j < v_count; j++) // assigning all as zero int the matrix
        {
            adj[i][j] = 0;
        }
    }
    for (int l = 0; l < e_count; l++) // snice zero zero cant have 1
    {
        cout << "enter node number connecting edge";
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
}
int GM::getv_count()
{
    return v_count;
}
DynArray &GM::adjnodes(int n)
{
    DynArray *p = new DynArray(1);
    if (n >= 0 && n < v_count)
    {
        for (int i = 0; i < v_count; i++)
        {
            if (adj[n][i] == 1)
            {
                p->append(i);
            }
        }
    }
    return *p;
}

void GM::printGraph()
{
    for (int i = 0; i < v_count; i++)
    {
        for (int j = 0; j < v_count; j++)
        {

            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}
void GM::printAdjnodes(int v)
{
    if (v >= 0 && v < v_count)
    {
        for (int i = 0; i < v_count; i++)
        {
            if (adj[v][i] == 1)
            {
                cout << "v" << i;
            }
        }
    }
}
bool GM::isIsolated(int v) // isolated(false) till an adj edge found.
{
    bool flag = false;
    if (v >= 0 && v < v_count)
    {
        for (int i = 0; i < v_count; i++)
        {
            if (adj[v][i] == 1)
            {
                return true;
                break;
            }
        }
    }
    return flag;
}

GM::~GM()
{

    for (int i = 0; i < v_count; i++)
    {
        delete[] adj[i]; // dels the start column of adjs
    }
    delete[] adj;
}
