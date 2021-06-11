#include<bits/stdc++.h>
using namespace std;
bool visited[1005];
vector<int> adjacent[1005];
void DFS(int index)
{
    visited[index] = true;
    cout << index << " ";
    for ( int i = 0 ; i < adjacent[index].size(); ++i)
    {
        if (!visited[adjacent[index][i]])
            DFS(adjacent[index][i]);
    }
}

void solve()
{
    int t; cin >> t;
    while (t--)
    {
        for ( int i = 0 ; i < 1001 ; ++i)
            adjacent[i].clear();
        memset(visited,false,sizeof(visited));
        int vertex, edeg, index;
        cin >> vertex >> edeg  >> index;
        for ( int i = 0 ; i < edeg ; ++i)
            {
                int u, v;
                cin >> u >> v;
                adjacent[u].push_back(v);
                adjacent[v].push_back(u);
            }
        DFS(index);
        cout << "\n";
    }
}

int main()
{
    solve();
    return 0;
}