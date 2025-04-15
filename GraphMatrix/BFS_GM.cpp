#include <iostream>
#include "GraphMatrix/GM.cpp"
#include "QUEUE/USING_ARRAY/QA.CPP"
#include "/workspaces/DSA_mysirji/DADT/DADT.cpp"


using namespace std;

void bfs(GM &G, int s)
{
    int n;
    bool status[(G.getv_count()];
    Queue Q(G.getv_count());
    Q.insert(s);
    status[s]==true;
    while(!Q.isEmpty()){
        n = Q.getfront();
        Q.del();
        
    }
}
int main()
{
    GM G;
    G.createGraph(6, 9);
    bfs(G, 0);
}