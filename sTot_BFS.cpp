#include<bits/stdc++.h>
using namespace std;

bool visited[1005];
vector<int> adjacent[1005];
int front[1005];

void BFS(int index, int end)
{
    queue<int> qe;
    qe.push(index);
    while(qe.size()>0)
        {
            int s = qe.front(); qe.pop();
            // cout << s << " ";
            visited[s] = true;
            if  (s == end) return;
            for ( int i = 0 ; i < adjacent[s].size(); i ++)
                if (!visited[adjacent[s][i]])
                    {
                        qe.push(adjacent[s][i]);
                        front[adjacent[s][i]] = s;
                        visited[adjacent[s][i]] = true;
                    }
        }
}
void Trance(int u, int v)
{
    if (!visited[v])
    {
        cout << -1;
        return;
    }
    vector<int> a;
    while (u!=v)
    {
        a.push_back(u);
        u = front[u];
    }
    a.push_back(v);
    reverse(a.begin(),a.end());
    for ( int i = 0 ; i < a.size(); i ++)
        cout << a[i] << " ";
}
int main()
{
    int t; cin >> t;
    while ( t--)
    {
        for ( int i = 0 ; i < 1001; i++)
            adjacent[i].clear();
        memset(visited,false,sizeof(visited));
        memset(front,0,sizeof(front));
        int vertex, edeg, index, end;
        cin >> vertex >> edeg >> index >> end;
        for ( int i = 0 ; i < edeg ; i++)
            {
                int u ,v;
                cin >> u >> v;
                adjacent[u].push_back(v);
                adjacent[v].push_back(u);
            }
        BFS(index,end);
        Trance(end,index);
        cout << "\n";
    }
    return 0;
}