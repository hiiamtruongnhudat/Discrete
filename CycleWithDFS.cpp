#include<bits/stdc++.h>
using namespace std;

int visited[1005];
vector<int> adjacent[1005];
bool cycle = false;
void __reset__()
{
    for (int i = 0 ; i <= 1005; i++)
        adjacent[i].clear();
    memset(visited,0,sizeof(visited));
}
void DFS(int node)
{
    visited[node] = true;
    cout << node << " ";
    for (int i = 0 ; i < adjacent[node].size();i ++)
        if(!visited[adjacent[node][i]])
            DFS(adjacent[node][i]);
        else if( visited[adjacent[node][i]] == 1)
            {
                // cout << adjacent[node][i] << " ";
                cycle = true;
            }
    visited[node] = 2;
}
void solve(int V)
{
    for (int i = 1; i <= V; i++)
        {
            DFS(i);
            if (cycle == true)
            {
                break;
                return;
            }
            memset(visited,0,sizeof(visited));
        }
}   
int main()
{
    int t; cin >> t;
    while ( t-- )
    {
        __reset__();
        int V, E;
        cin >> V >> E;
        for (int i = 0 ; i < E ; i ++)
            {
                int u, v;
                cin >> u  >> v;
                adjacent[u].push_back(v);
                adjacent[v].push_back(u);
            }
        solve(V);
        if(cycle) cout << "YES\n";
        else cout << "NO\n";
    }
}