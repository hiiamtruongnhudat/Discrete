#include<bits/stdc++.h>
using namespace std;

int n, matrix[1005][1005];
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
void DFS(int u)
{
    cout << u << " ";
    visited[u] = true;
    for ( int t = 1 ; t <= n; t++)
    {
        if ( visited[t] == false && matrix[u][t] == 1)
            DFS(t);
            
    }
}



int main()
{
    __init__();
    // pprint();
    DFS(1);
    return 0;
}