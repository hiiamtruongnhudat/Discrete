#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;

long long Mul(long long a, long long b)
{
    if (b==0)
        return 0;
    if (b==1)
        return a%mod;
    long long tmp = Mul(a,b/2);
    if (b&1)
        return (tmp*2+a)%mod;
    return tmp*2%mod;
}
long long pow(long long x, long long n)
{
    if (n==0)
        return 1;
    if (n==1)
        return x%mod;
    long long tmp = pow(x,n/2);
    long long a = Mul(tmp,tmp);
    if (n&1)
        return x*a%mod;
    return a%mod;
}
double solve(long long n)
{   
    return (pow((1.0 + sqrt(5.0)), n) - pow((1.0 - sqrt(5.0)), n)) / (pow(2.0, n) * sqrt(5.0));
}

int main()
{   
    int t; cin >> t;
    while ( t-- )
    {
        long long n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}