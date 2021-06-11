#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
bool visited[1001] = {false};
int res = 1;
class Edge
{
public:
    int src;
    int dest;
};
Edge *edge = new Edge[1001];
int DFS(int node)
{
    visited[node] = true;
    for ( int i = 0 ; i < adj[node].size(); ++i)
    {
        if (!visited[adj[node][i]])
            {
                res++;
                DFS(adj[node][i]);
            }
    }
    return res;
}
bool isConnected(int N)
{
    for (int i = 1; i <= N; i++)
        if (DFS(i) != N)
            {
                return false;
                break;
            }
        else
            {
                memset(visited,false,sizeof(visited));
                res = 1;
            }
    return true;
}
int parent[1001];
int find(int x)
{
    if (parent[x] == -1)
        return x;
    return find(parent[x]);
}
void unionn(int x, int y)
{
    parent[x] = y;
}
bool isCycle(int N)
{   
    memset(parent,-1,sizeof(parent));
    for (int i = 0; i < N-1; i++)
        {
            int x = find(edge[i].src);
            int y = find(edge[i].dest);
            if (x==y)
                return true;
            unionn(x,y);
        }
    return false;
}
int main()
{
    int t;  cin >> t;
    while (t--)
    {
        for (int i = 0 ; i <= 1005; i++)
            {
                adj[i].clear();
            }
        int N;
        cin >> N;
        for (int i = 0; i < N-1; i++)
            {
                int u, w;
                cin >> u >> w;
                adj[u].push_back(w);
                adj[w].push_back(u);
                edge[i].src = u;
                edge[i].dest = w;
            }
        if (isConnected(N) == true && isCycle(N) == false)
            cout << "YES\n";
        else   
            cout << "NO\n";
    }
    return 0;
}