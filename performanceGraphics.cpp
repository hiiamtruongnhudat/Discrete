#include<bits/stdc++.h>
using namespace std;

// vector<int> adjacent[1005];

void solve()
{
    int t; cin >> t;
    while ( t--)
    {   
        vector<int> adjacent[1005];
        int vertex, edeg;
        cin >> vertex >> edeg;
        for ( int i = 0 ; i < edeg ; ++i)
        {
            int a, b; 
            cin >> a >> b;
            adjacent[a].push_back(b);
            // adjacent[b].push_back(a);
        }
        for ( int i = 0 ; i < vertex ; ++i)
        {
            sort(adjacent[i].begin(),adjacent[i].end());
        }
        for ( int i = 1 ; i <= vertex; ++i)
            {
                cout << i << ":";
                for ( int j = 0 ; j < adjacent[i].size(); ++j)
                    cout << " "<< adjacent[i][j];
                cout << " \n";
            }
    }
}
int main()
{
    solve();
    return 0;
}