#include<bits/stdc++.h>
using namespace std;
 
bool visited[1005];
vector<int> adjacent[1005];
 
int BFS(int index)
{
    int count = 0;
    queue<int> qe;
    qe.push(index);
    while(qe.size()>0)
        {
            int s = qe.front(); qe.pop();
            visited[s] = true;
            for ( int i = 0 ; i < adjacent[s].size(); i ++)
                if (!visited[adjacent[s][i]])
                    {   
                        count++;
                        qe.push(adjacent[s][i]);
                        visited[adjacent[s][i]] = true;
                    }
        }
    return count;
}
void consider(int n)
{
    for ( int i = 1 ; i <= n ; i++)
    {
        visited[i] = true;
        if ( i == 1)
        {
            if (BFS(2) != n - 1)
                cout << i << " ";
        }
        else
        {
            if (BFS(1) != n -1 )
                cout << i << " ";
        }
        memset(visited,false,sizeof(visited));
    }
}

int main()
{
    int t; cin >> t;
    while ( t-- )
    {
        for ( int i = 0 ; i < 1006; i++)
            adjacent[i].clear();
        int vertex,edeg;
        cin >> vertex >> edeg;
        for ( int i = 0 ; i < edeg; i++)
        {
            int u ,v;
            cin >> u >> v;
            adjacent[u].push_back(v);
            adjacent[v].push_back(u);
        }
        memset(visited,false,sizeof(visited));
        consider(vertex);
        cout << "\n";
    }
    return 0;
}