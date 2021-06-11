#include<bits/stdc++.h>
using namespace std;

bool visited[1005];
vector<int> adjacent[1005];

void DFS(int index)
{
    stack<int> st;
    st.push(index);
    while(!st.empty())
    {
        int s = st.top(); st.pop();
        visited[s] = true;
        for ( int i = 0 ; i < adjacent[s].size(); i ++)
            if (!visited[adjacent[s][i]])
            {   
                // cout << adjacent[s][i] << " ";
                visited[adjacent[s][i]] = true;
                st.push(s);
                st.push(adjacent[s][i]);
                break;
            }
    }
}
void TPLT(int n)
{
    int count = 0;
    for ( int i = 1; i <= n; i++)
    {
        if(!visited[i])
            {
                count++;
                DFS(i);
            }
    }
    cout << count << "\n";
}


int main()
{
    int t; cin >> t;
    while ( t-- )
    {
        for ( int i = 0 ; i < 1006 ; i++)
            adjacent[i].clear();
        memset(visited,false,sizeof(visited));
        int vertex, edeg;
        cin >> vertex >> edeg;
        for ( int i = 0 ; i < edeg; i ++)
        {
            int u ,v; 
            cin >> u >> v;
            adjacent[u].push_back(v);
            adjacent[v].push_back(u);
        }
        TPLT(vertex);
        // DFS(5);
    }
}