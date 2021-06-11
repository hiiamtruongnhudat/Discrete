#include<bits/stdc++.h>
using namespace std;

long long F[101];
void init()
{
    F[1] = 1;
    F[2] = 1;
    for (int i = 3; i <= 93;i++)
        F[i] = F[i-2] + F[i-1];
}
char Fibo(int n, long long k)
{
    if ( n == 1) 
        return 'A';
    if ( n == 2)
        return 'B';
    if ( k <= F[n-2])    
        return Fibo(n-2,k);
    return Fibo(n-1,k-F[n-2]);
}
int main()
{
    init();
    cout << F[8] << endl;
    cout << Fibo(10,12) << endl;
    // int t; cin >> t;
    // while (t--)
    // {
    //     int n; long long k;
    //     cin >> n >> k;
    //     cout << Fibo(n,k) << endl;
    // }
    return 0;
}