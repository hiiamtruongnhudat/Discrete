#include<bits/stdc++.h>
using namespace std;

int matrix[1005][1005],n;
bool visited[1005];
int res = 1;
void reset()
{   
    res = 1;
    memset(visited,false,sizeof(visited));
}
void __init__()
{
    ifstream file("testMatrix.txt", ios::in);
    file >> n;
    for (int i = 1; i <=n ;i++)
        for (int j = 1 ;j <= n; j++)
            file >> matrix[i][j];
}
int DFS(int node)
{
    visited[node] = true;
    for (int i = 1; i <= n;i++)
        if(visited[i]==false && matrix[node][i]==1)
            {
                res++;
                DFS(i);
            }
    return res;
}
int isConnected()
{
    for (int i = 1; i<=n ;i++)
    {
        if (DFS(i) == n)
            {
                reset();
            }
        else
        {
            return 0;
            break;
        }
    }
    return 1;
}
int isEulerian()
{   
    int countt = 0;
    if (isConnected())
        for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j<=n ;j++)
                    if(matrix[i][j] == 1)
                        countt++;
                if (countt & 1)
                    {
                        return 0;
                        break;
                    }
                countt = 0;
            }
    else
        {
            return 0;
        }
    return 1;
}
void EulerCycle(int node)
{
    stack<int> st, CE;
    st.push(node);
    while (!st.empty())
    {   
        int counter = 0;
        int s = st.top();
        for (int i = 1; i <= n; i++)
            if (matrix[s][i]==0)
                counter++;
        if (counter != n)
        {
            for (int t = 1; t <= n; t++)
                {
                    if (matrix[s][t] == 1)
                        {
                            st.push(t);
                            matrix[s][t] = matrix[t][s] = 0;
                            break;
                        }
                }
        }
        else
        {
            CE.push(s);
            st.pop();
        }
        
    }
    cout << "\nEuler Cycle:" << endl;
    while(!CE.empty())
    {
        cout << CE.top() << " ";
        CE.pop();
    }
}

int main()
{
    __init__();
    reset();
    if (isEulerian())
        EulerCycle(1);
    return 0;
}