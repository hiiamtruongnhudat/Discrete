#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1005]; // khởi tạo vector chứa cạnh cề
bool visited[1005]; // khởi tạo mảng chứa đỉnh đã thăm;
int parent[1005];

void reset()
{
    for (int i = 0 ; i <= 1005;i++)
        adj[i].clear(); // khởi tạo ban đầu
}
bool BFS(int node)
{
    queue<int> q;
    q.push(node);
    while (!q.empty())
    {
        int u = q.front();q.pop();
        visited[u] = true;
        for (auto v : adj[u])
            if(!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                    parent[v] = u;
                }
            else if (parent[u] != v)
                return true;
    }
    return false;
}
bool check(int V)
{   
    memset(visited,false,sizeof(visited));
    for (int i = 1; i <= V; i++)
        if (!visited[i]&& BFS(i))
            return true;
    return false;
}
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        reset();
        for (int i = 0 ; i < E; i ++)
            {
                int u, v;
                cin >> u >> v;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        if (check(V))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}