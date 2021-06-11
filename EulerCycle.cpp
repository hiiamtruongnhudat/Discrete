#include<bits/stdc++.h>
using namespace std;
int n;
int matrix[1005][1005];

void __init__()
{
    ifstream file("testMatrix.txt", ios::in);
    file >> n;
    for ( int i = 1 ; i <= n; i++)
        for ( int j = 1 ; j <= n; j++)
            file >> matrix[i][j];
}
void EulerCycle(int index)
{
    stack<int> st, CE;
    st.push(index);
    while (!st.empty())
    {   
        int counter = 0;
        int s = st.top();
        for ( int i = 1 ; i <= n ; i++)
            {
                if (matrix[s][i] == 0 )
                    counter++;
            }
        if (counter!=n)
        {
            for ( int t = 1 ; t <= n; t++)
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
    while (!CE.empty())
    {
        cout << CE.top() << "  ";
        CE.pop();
    }
}
void print()
{
    for ( int i = 1 ; i <= n; i++)
    {
        for ( int j = 1 ; j <= n; j++)
            cout <<  matrix[i][j] << " ";
        cout << endl;
    }
}
int main()
{
    __init__();
    // print();
    EulerCycle(1);
    return 0;
}