#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> Mai;
vector<int> adj[1001];
bool visited[1001] = {false};

void TreeDFS(int node)
{
    visited[node] = true;
    for (int i = 0 ; i < adj[node].size();++i)
        if (!visited[adj[node][i]])
            {
                Mai.push_back({node,adj[node][i]});
                TreeDFS(adj[node][i]);
            }
}
void TreeGraph(int V, int pos)
{
    memset(visited,false,sizeof(visited));
    Mai.clear();
    TreeDFS(pos);
    if (Mai.size() < V-1)
        cout << -1 << endl;
    else
        for (int i = 0; i < Mai.size(); i++)
            {
                cout << Mai[i].first << " " << Mai[i].second;
                cout << endl;
            }
}
int main()
{
    int t; cin >> t;
    while (t--)
    {
    for (int i = 0; i<=1001;i++)
        adj[i].clear();
    int V,E, pos;
    cin >> V >> E >> pos;
    for (int i = 0 ; i < E ; i++)
        {
            int u,w;
            cin  >> u >> w;
            adj[u].push_back(w);
            adj[w].push_back(u);
        }
    TreeGraph(V,pos);
    }
    return 0;
}