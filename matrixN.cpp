#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
int n,k;
long long a[10][10], b[10][10];

void Multipe(long long x[10][10], long long y[10][10])
{
    long long tmp[10][10];
    for ( int i = 0 ; i < n ; i ++)
        for ( int j = 0 ; j < n; j++)
            {
                long long res = 0;
                for ( int k = 0 ; k < n; k++)
                    {
                        res += (x[i][k]*y[k][j])%mod;
                        res %= mod;
                    }
                tmp[i][j] = res;
            }
    for ( int i = 0 ; i < n; i ++)
        for ( int j = 0 ; j < n ; j++)
            a[i][j] = tmp[i][j];
}
void output()
{
    for ( int i = 0 ; i < n ; i ++)
        {
            for ( int j = 0 ; j < n; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }   
    cout << endl;
    cout << endl;
}
void Pow(long long a[10][10], int n)
{
    if ( n <= 1 )
        return;
    Pow(a,n/2);
    Multipe(a,a);
    if (n&1)
        Multipe(a,b);
}
void Solve()
{
    cin >> n >> k;
    for ( int i = 0 ; i < n; i++)
        for ( int j = 0 ; j < n; j++)
            {
                cin >> a[i][j];
                b[i][j] = a[i][j];
            }
    Pow(a,k);
    cout << endl;
    cout << endl;
    output();
}
int main()
{
    int t; cin >> t;
    while ( t-- )
    {
        Solve();
    }
    return 0;
}