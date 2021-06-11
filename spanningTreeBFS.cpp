#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> T;
vector<int> adj[1001];
bool visited[1001];

void TreeBFS(int u)
{
    queue<int> q;
    q.push(u);
    while (!q.empty())
    {
        int s = q.front(); q.pop();
        visited[s] = true;
        for (int i = 0; i < adj[s].size(); i++)
            if(!visited[adj[s][i]])
                {
                    q.push(i);
                    T.push_back({s,adj[s][i]});
                    visited[adj[s][i]] = true;
                }
    }
}
void TreeGraphBFS(int V, int pos)
{
    for (int i = 1; i<= V; i++)
        visited[i] = false;
    T.clear();
    TreeBFS(pos);
    if (T.size() < V - 1)
        cout << -1 << endl;
    else
        for (int i = 0; i < T.size(); i++)
            {
                cout << T[i].first << " " << T[i].second;
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
    TreeGraphBFS(V,pos);
    }
    return 0;
}