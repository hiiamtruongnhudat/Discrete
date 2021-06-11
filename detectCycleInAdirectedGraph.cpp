#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
int in_degree[1005] = {0};
int V, E;
bool isCycle()
{
    for (int v = 1; v <= V; v++)
        for (auto u: adj[v])
            in_degree[u]++;
    
    queue<int> q;
    for (int i = 1; i<= V; i++)
        if (in_degree[i] == 0)
            q.push(i);
    int cnt = 0;
    while (!q.empty())
    {
        int s = q.front(); q.pop();
        for (auto v: adj[s])
            if(--in_degree[v]==0)
                    q.push(v);
        cnt++;
    }
    if (cnt != V)
        return true;
    return false;
}


int main()
{
    int t; cin >> t;
    while (t--)
    {
        for (int i = 0 ; i <= 1005; i++)
            adj[i].clear();
        memset(in_degree,0,sizeof(in_degree));
        cin >> V >> E;
        for (int i = 0 ; i < E; i++)
            {
                int u, v;
                cin >> u >> v;
                adj[u].push_back(v);
                // adj[v].push_back(u);
            }
        if (isCycle())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;

}