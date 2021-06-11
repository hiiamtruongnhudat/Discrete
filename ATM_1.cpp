#include<bits/stdc++.h>
using namespace std;

int t[10] = {1000,500,200,100,50,20,10,5,2,1};
int n;

void Greedy()
{   
    // int x = [10];
    cin >> n;
    int sum = n;
    int i = 0;
    int cnt = 0;
    while ( i < 10)
    {
        while (t[i] <= sum)
        {
            // x[i] = 1;
            sum = sum - t[i];
            cout << t[i] << " ";
            cnt += 1;
        }
        i++;
    }
    cout << cnt << endl;

}
int main()
{
    // ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while( t--)
    {
        // solve();
        Greedy();
    }
    return 0;
}