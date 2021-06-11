#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; 
    cin >> n;
    int x[n];
    for (int i = 1; i <=n ; i++)
        cin >> x[i];
    int i = n - 1;
    while ( i > 0 && x[i] > x[i+1])
        i--;
    if ( i > 0)
        {
            int k = n;
            while (x[k] < x[n])
                k--;
            swap(x[k],x[i]);
            int a = i + 1, b = n;
            while ( a < b)
            {
                swap(x[a],x[b]);
                a++;
                b--;
            }
            for (int i = 1 ; i <= n; i++)
                cout << x[i] << " ";
        }
    else
    {
        for (int  i = 1; i <= n;i++)
            cout << i << " ";
    }
    cout << endl;
    
}

int main()
{
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}