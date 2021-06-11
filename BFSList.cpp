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
        int res = 0;
        for ( int i = 1; i <= vertex ; i ++)
        {
            if (!visited[i])
            {   
                res++;
                BFS(i);
            }
        }
        for ( int i = 1; i <= vertex; i++)
        {
            memset(visited,false,sizeof(visited));
            visited[i] = true;
            int counter  = 0;
            for ( int j = 1 ; j <= vertex; j ++)
            {
                if(!visited[j])
                    {
                        counter++;
                        BFS(j);
                    }
            }
            if (counter > res ) cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}