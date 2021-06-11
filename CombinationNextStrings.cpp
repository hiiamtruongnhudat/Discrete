#include<bits/stdc++.h>
using namespace std;
int n,k, x[16];
bool cauhinhcuoi = false;
void reset()
{
    for (int i = 1 ; i <= n; i++)
        x[i] = i;
    cauhinhcuoi = false;
}
void sinh()
{
    int i = k;
    while ( i > 0 && x[i] == n - k + i)
        i--;
    if (i>0)
    {
        x[i] = x[i] +1;
        for (int j = i + 1; j <= n ; j++)
            x[j] = x[j-1] + 1;
    }
    else
    {
        cauhinhcuoi = true;
        return;
    }
    return;
}
void print()
{
    for ( int j = 1 ; j <= k; j++)
        cout << x[j] << "";
    cout << " ";
}
int main ()
{
    int t; cin >> t;
    while ( t-- )
    {   
        cin >> n >> k;
        reset();
        while (!cauhinhcuoi)
            {
                print();
                sinh();
            }
        cout << "\n";
    }
    return 0;
}