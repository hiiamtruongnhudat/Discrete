#include<bits/stdc++.h>
using namespace std;

bool visited[1005];
vector<int> adjacent[1005];


int  BFS(int index)
{   
    int counter = 0;
    queue<int> qe;
    qe.push(index);
    while(!qe.empty())
        {
            int s = qe.front(); qe.pop();
            visited[s] = true;
            counter++;
            for ( int i = 0 ; i < adjacent[s].size(); i ++)
                if (!visited[adjacent[s][i]])
                    {   
                        qe.push(adjacent[s][i]);
                        visited[adjacent[s][i]] = true;
                    }
        }
    // cout << counter;
    return counter;
}
void reINIT()
{
    memset(visited,false,sizeof(visited));
}
bool isStrongConnected(int n)
{
    for ( int i = 1; i <= n;i++)
    {
        if (BFS(i)!=n)
            {
                return false;
                break;
            }
        else
            reINIT();
    }
    return true;
}
int main()
{
    int t; cin >> t;
    while ( t--)
    {
        for ( int i = 0 ; i < 1001; i++)
            adjacent[i].clear();
        memset(visited,false,sizeof(visited));
        int vertex, edeg;
        cin >> vertex >> edeg;
        for ( int i = 0 ; i < edeg ; i++)
            {
                int u ,v;
                cin >> u >> v;
                adjacent[u].push_back(v);
                // adjacent[v].push_back(u);
            }
        if (isStrongConnected(vertex))
            cout << "YES";
        else
            cout << "NO";
        cout << "\n";
    }
    return 0;
}