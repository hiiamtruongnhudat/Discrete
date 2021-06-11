#include<bits/stdc++.h>
using namespace std;

int parent[1005];
struct Edge
{
    int src,dest;
};
Edge edge[1005];
void reset()
{
    memset(parent,-1,sizeof(parent));
}

int find(int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent[i]);
}
void unionn(int x, int y)
{
    parent[x] = y;
}
int isCycle(int e)
{   
    reset();
    for ( int i = 0 ; i < e; i++)
    {
        int x = find(edge[i].src);
        int y = find(edge[i].dest);
        if (x == y)
            return 1;
        unionn(x,y);
    }
    return 0;
}
int main()
{   
    int t; cin >> t;
    while ( t--)
    {
        int v, e;
        cin >> v >> e;
        for (int i = 0 ; i < e; i++)
        {
            int u, v;
            cin >> u >> v;
            edge[i].src = u;
            edge[i].dest = v;
        }
        if (isCycle(e))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}