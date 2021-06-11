#include<bits/stdc++.h>
using namespace std;
int n;
int matrix[1005][1005];
bool visited[1005];
void __init__()
{
    ifstream file("matrix.txt", ios::in);
    file >> n;
    for ( int i = 1 ; i <= n; i++)
        for ( int j = 1 ; j <= n; j++)  
            file >> matrix[i][j]; 
}
void pprint()
{
    for ( int i = 1 ; i <= n; i++)
        {
            for ( int j = 1 ; j <= n; j++)  
                cout << matrix[i][j] << " "; 
            cout << endl;
        }
}
void DFS(int index)
{   
    cout << "DFS start at vertex: " << index << " ";
    stack<int> st;
    st.push(index);
    visited[index] = true;
    while(!st.empty())
    {
        int v = st.top(); st.pop();
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
int main()
{
    __init__();
    // pprint();
    DFS(1);
    cout << "\nWell done, luv Le Chieu Ha Vi so muchhh";
    return 0;
}