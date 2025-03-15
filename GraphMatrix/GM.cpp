#include <iostream>
#include <stdio.h>
using namespace std;

class GM
{
private:
    int v_count;
    int e_count;
    int **adj;

public:
    void createGraph(int, int);
    void printGraph();
    void printAdjnodes(int);
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
bool GM::isIsolated(int v)
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
        delete[] adj[i] // dels the start column of adjs
    }
    delete[] adj;
}

int main()
{
    GM G;
    G.createGraph(5, 6);
    G.printGraph();
    G.printAdjnodes(2);
    return 0;
}