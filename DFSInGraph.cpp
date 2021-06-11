#include<bits/stdc++.h>
using namespace std;

class Graph
{
private:
    /* data */
public:
    // int matrix[1005][1005];
    bool visited[1005];
    vector<int> ke[1005];
    void addEdge(int v, int w);
    void DFS(int v);
};
void Graph::addEdge(int v, int w)
{
    ke[v].push_back(w);
    ke[w].push_back(v);
}
void Graph::DFS(int index)
{
    cout << "DFS start at vertex: ";
    stack<int> st;
    st.push(index);
    visited[index] = true;
    while(!st.empty())
    {
        int v = st.top();
        st.pop();
        for ( int t = 1 ; t <= n; t ++)
            if ( visited[t] == false && matrix[v][t] == 1 )
                {
                    visited[t] = true;
                    cout << t << " ";
                    st.push(v);
                    st.push(t);
                    break;
                }
    }
}
