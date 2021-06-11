#include<bits/stdc++.h>
using namespace std;


void solve()
{
    int n, k;
    cin >> n >> k;
    int x[n];
    for ( int i = 1; i <= k ; i++)
        cin >> x[i];
    int i = k;
    while (x[i] == n - k + i && i >0)
        i--;
    if ( i > 0)
    {
        x[i] = x[i] + 1;
        for (int j = i+1; j<=k; j++)
            x[j] = x[j-1] +1;
        for (int i = 1 ; i <= k; i++)
            cout << x[i] << " ";
    }
    else
    {
        for (int i = 1; i <= k ; i++)
            cout << i << " ";
    }
    cout << endl;
}
int main()
{
    int t; cin >> t;
    while ( t--)
        solve();
    return 0;
}