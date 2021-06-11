#include<bits/stdc++.h>
using namespace std;


int a[10] = {1000,500,200,100,50,20,10,5,2,1};
int n;
void solve()
{
    cin >> n;
    int sum = n;
    int t = 0;
    int countt= 0;
    while (t < 10)
    {
        while(a[t] <= sum)
        {
            sum -= a[t];
            countt++;
        }
        t++;
    }
    cout << countt << endl;
}
int main()
{
    int t; cin >> t;
    while ( t-- )
        solve();
    return 0;
}