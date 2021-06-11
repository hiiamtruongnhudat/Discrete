#include<bits/stdc++.h>
using namespace std;

bool visited[1005];
vector<int> adjacent[1005];


void BFS(int index)
{
    queue<int> qe;
    qe.push(index);
    while(qe.size()>0)
        {
            int s = qe.front(); qe.pop();
            cout << s << " ";
            visited[s] = true;
            for ( int i = 0 ; i < adjacent[s].size(); i ++)
                if (!visited[adjacent[s][i]])
                    {
                        qe.push(adjacent[s][i]);
                        visited[adjacent[s][i]] = true;
                    }
        }
}
int main()
{
    int t; cin >> t;
    while ( t--)
    {
        for ( int i = 0 ; i < 1001; i++)
            adjacent[i].clear();
        // visited[1005] = {false};
        memset(visited,false,sizeof(visited));
        int vertex, edeg, index;
        cin >> vertex >> edeg >> index;
        for ( int i = 0 ; i < edeg ; i++)
            {
                int u ,v;
                cin >> u >> v;
                adjacent[u].push_back(v);
                adjacent[v].push_back(u);
            }
        BFS(index);
        cout << "\n";
    }
    return 0;
}