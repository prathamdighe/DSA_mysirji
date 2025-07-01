#include <iostream>
#include "GM.cpp"
#include "/workspaces/DSA_mysirji/QUEUE/USING_ARRAY/QA.CPP"

using namespace std;

void bfs(GM &G, int s)
{
    int n;
    bool status[G.getv_count()];

    Queue Q(G.getv_count());
    Q.insert(s);
    status[s] = true;

    while (!Q.isEmpty())
    {
        n = Q.getfront();
        Q.del();
        DynArray adjacent = G.adjnodes(n);
        for (int i = 0; i < adjacent.count(); i++)
        {
            int u = adjacent.get(i);

            if (status[u] == false)
            {
                Q.insert(u);
                status[u] = true;
            }
        }
    }
}
int main()
{
    GM G;
    G.createGraph(6, 9);
    bfs(G, 0);
    cout << endl;
    return 0;
}