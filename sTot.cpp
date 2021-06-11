#include<bits/stdc++.h>
using namespace std;

bool visited[1005];
vector<int> adjacent[1005];
int frt[1005];
void DFS(int index, int end)
{
    if(visited[end]) return;
    visited[index] = true;
    for ( int i = 0 ; i < adjacent[index].size(); i ++)
        if (!visited[adjacent[index][i]])
            {
                frt[adjacent[index][i]] = index;
                DFS(adjacent[index][i],end);
            }
}
void Trance(int start, int end)
{
    if (!visited[end])
        {
            cout << "-1";
            return;
        }
    vector<int> out;
    while (start!=end)
    {
        out.push_back(start);
        start = frt[start];
    }
    out.push_back(end);
    reverse(out.begin(),out.end());
    for ( int i =0 ; i < out.size(); i++)
        cout << out[i] << " ";
}
int main()
{
    int t; cin >> t;
    while ( t-- )
    {
        for ( int i = 0 ; i < 1006 ; i++)
            adjacent[i].clear();
        memset(visited,false,sizeof(visited));
        memset(frt,0,sizeof(frt));
        int vertex, edeg, start, end;
        cin >> vertex >> edeg >> start >> end;
        for ( int i = 0 ; i < edeg; i ++)
        {
            int u ,v; 
            cin >> u >> v;
            adjacent[u].push_back(v);
            adjacent[v].push_back(u);
        }
        DFS(start,end);
        Trance(end,start);
        cout << "\n";
    }
}